/*
 * @file    Inventory.cpp
 * @brief   This class represents the merchandise inventory of a rental shop.
 *          Each unique piece of merchandise is stored in a chained hash table,
 *          along with the quantity that the shop owns and the quantity that is
 *          currently available for rent. A limit may be set on the amount of
 *          merchandise expected in the inventory, as well as the quantity of
 *          each type of merchandise allowed.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include <iostream>
#include "Inventory.h"


Inventory::Inventory(int idealQty = 47, int qtyCap = 10) :
             itemQty(idealQty), maxQty(qtyCap)
{
    allItems[itemQty];
} // end Constructor

Inventory::~Inventory()
{
    delete[] allItems;
} // end Destructor

bool Inventory::isEmpty(void) const
{
    for (int i = 0; i < itemQty; ++i)
    {
        if (!allItems[i].isEmpty())
        {
            return false;
        } // end if (!allItems[i].isEmpty())
    } // end for (i < itemQty)

    return true;
} // end isEmpty()

bool Inventory::addItem(const Merch *item)
{
    KeyedItem keyedMerch(item);
    bool success = item != NULL;

    if (success)
    {
        try
        {
            allItems[hashIndex(item)].searchTreeInsert(keyedMerch);
            success = true;     // the item was inserted successfully
        }
        catch (TreeException e)
        {
            cout << "ERROR: Could not add ";
            item->display();
            cout << " to inventory." << endl;
            success = false;    // item could not be inserted
        } // end try
    } // end if (success)

    return success;
} // end addItem(Merch*)

bool Inventory::updateItem(const Merch *item)
{
    KeyedItem keyedMerch(item);
    bool success = item != NULL;

    if (success)
    {
        try
        {
            allItems[hashIndex(item)].searchTreeDelete(keyedMerch.getKey());
            allItems[hashIndex(item)].searchTreeInsert(keyedMerch);
            success = true;     // the item was updated successfully
        }
        catch (TreeException e)
        {
            cout << "ERROR: Could not update ";
            item->display();
            cout << " in inventory." << endl;
            success = false;    // item could not be updated
        } // end try
    } // end if (success)

    return success;
} // end updateItem(Merch*)

bool Inventory::removeItem(const Merch *item)
{
    KeyedItem keyedMerch(item);
    bool success = item != NULL;

    if (success)
    {
        try
        {
            allItems[hashIndex(item)].searchTreeDelete(keyedMerch.getKey());
            success = true;     // the item was deleted successfully
        }
        catch (TreeException e)
        {
            cout << "ERROR: Could not delete ";
            item->display();
            cout << " from inventory." << endl;
            success = false;    // item could not be deleted
        } // end try
    } // end if (success)

    return success;
} // end removeItem(Merch*)

Merch* Inventory::retrieveItem(const Merch *item) const
{
    KeyedItem keyedMerch(item);

    if (item != NULL)
    {
        try
        {
            // get a copy of the full record
            allItems[hashIndex(item)].searchTreeRetrive(keyedMerch.getKey(),
                                                        keyedMerch);
        }
        catch (TreeException e)
        {
            cout << "ERROR: could not retrieve ";
            item->display();
            cout << " from inventory." << endl;
            return NULL;
        } // end try
    } // end if (item != NULL)

    return keyedMerch.getItem();
} // end retrieveItem(Merch*)

int Inventory::getItemQty(void) const
{
    return itemQty;
} // end getItemQty()

bool Inventory::setItemQty(int newQty)
{
    bool success = newQty > 0;

    if (success)
    {
        itemQty = newQty;
    } // end if (success)

    return success;
} // end setItemQty(int)

int Inventory::getMaxQty(void) const
{
    return maxQty;
} // end getMaxQty()

bool Inventory::setMaxQty(int newQty)
{
    bool success = newQty > 0;

    if (success)
    {
        maxQty = newQty;
    } // end if (success)

    return success;
} // end setMaxQty(int)

void Inventory::displayInventory(void) const
{
    for (int i = 0; i < itemQty; ++i)           // step through hash table
    {
        ThreadedBST::Inorder index(allItems[i].begin());

        while(index != allItems[i].end())       // step through container
        {
            (*index).getItem()->displayLine();  // display contents of item
            ++index;
        } // end while(index != allItems[i].end())
    } // end for (i < itemQty)
} // end showInventory()

int Inventory::hashIndex(const Merch *item) const
{
    KeyedItem tempKey("Item Code");

    if (item != NULL)
    {
        try
        {
            if (item->getField(tempKey))
            {
                return (tempKey.getValue().at(0) - 'A') % itemQty;
            } // end if (item->getField(tempKey))
        }
        catch (TreeException e)
        {
            cout << "ERROR: Could not hash value in Inventory." << endl;
        } // end try
    } // end if (item != NULL)

    return 0;   // default if given NULL pointer or item code not found
} // end hashIndex(Merch*)
