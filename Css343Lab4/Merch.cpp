/*
 * @file    Merch.cpp
 * @brief   This class represents some merchandise that may be carried in a
 *          shop. Merchandise maintains a set of attributes about itself, in
 *          key-value pairs. In order to be sortable, any merchandise in a
 *          collection must contain at least one mutual key by which the items
 *          may be sorted.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include <iostream>
#include "Merch.h"


Merch::Merch()
{
} // end Default Constructor

Merch::Merch(const string& searchKey)
{
} // end Constructor (Key)

Merch::Merch(const KeyType& newKey, const KeyType& newValue,
               int newStockQty = 10, int newOnHandQty = 10) :
    stockQty(newStockQty), onHandQty(newOnHandQty)
{
} // end Constructor

Merch::~Merch()
{
} // end Destructor

string Merch::getSearchKey(void) const
{
    return searchKey;
} // end getKey()

void Merch::setSearchKey(const string& newSearchKey)
{
    searchKey = newSearchKey;
} // end setKey(string&)

int Merch::getStockQty(void) const
{
    return stockQty;
} // end getStockQty()

bool Merch::setStockQty(int newQty)
{
    bool success = newQty >= onHandQty;

    if (success)    // enough room for new quantity
    {
        stockQty = newQty;
    } // end if (success)

    return success;
} // end setStockQty(int)

int Merch::getOnHandQty(void) const
{
    return onHandQty;
} // end getOnHandQty()

bool Merch::setOnHandQty(int newQty)
{
    bool success = newQty > 0;

    if (success)    // quantity is positive, so this item can exist
    {
        onHandQty = newQty;
    } // end if (success)

    return success;
} // end setOnHandQty(int)

bool Merch::getField(KeyedItem& target) const
{
    try
    {
        info.searchTreeRetrive(target.getKey(), target);
    }
    catch (TreeException e)
    {
        cout << "ERROR: Could not find field ";
        target.getItem()->display();
        cout << " in item " << searchKey << endl;
        return false;   // Desired field does not exist in this Merchandise
    } // end try

    return true;
} // end getField(KeyedItem&)

void Merch::setField(const KeyedItem& newValue)
{
    try
    {
        info.searchTreeInsert(newValue);
    }
    catch (TreeException e)
    {
        cout << "ERROR: Could not set field ";
        newValue.getItem()->display();
        cout << " in item " << searchKey << endl;
    } // end try
} // end setField()
