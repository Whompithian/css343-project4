/*
 * @file    Inventory.h
 * @brief   This class represents the merchandise inventory of a rental shop.
 *          Each unique piece of merchandise is stored in a chained hash table,
 *          along with the quantity that the shop owns and the quantity that is
 *          currently available for rent. A limit may be set on the amount of
 *          merchandise permitted in the inventory, as well as the quantity of
 *          each type of merchandise.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _INVENTORY_H
#define	_INVENTORY_H

#include <cstdlib>
#include <string>
#include "Merch.h"

class Inventory
{
public:

/**---------------------- Default Constructor -------------------------------
 * Creates an empty merchandise Inventory.
 * @param merchCap  A positive value indicating how many unique types of
 *                  merchandise this Inventory can hold. Should be prime.
 * @param qtyCap  A positive value indicating how many of each type of
 *                merchandise this Inventory can hold.
 * @pre merchCap and qtyCap are greater than zero.
 * @post An empty merchandise Inventory exists.
 */
    Inventory(int merchCap = 10007, int qtyCap = 10);

/**---------------------- Copy Constructor ------------------------------------
 * Creates a duplicate of a merchandise Inventory.
 * @param orig  The merchandise Inventory to be copied.
 * @pre There is sufficient memory to copy the original merchandise Inventory.
 * @post This merchandise Inventory is a deep copy of the original. All
 *       merchandise form the original Inventory is copied into this one.
 */
    Inventory(const Inventory& orig);

/**---------------------- Destructor ------------------------------------------
 * Deletes all elements of this merchandise Inventory.
 * @pre None.
 * @post All Inventory elements are cleanly deleted and all pointers set to
 *       NULL.
 */
    virtual ~Inventory();

/**---------------------- isEmpty() -------------------------------------------
 * Indicates whether this Inventory contains any merchandise.
 * @pre None.
 * @post None.
 * @return true if there is no merchandise in this Inventory; false, otherwise.
 */
    bool isEmpty(void) const;

/**---------------------- addItem() -------------------------------------------
 * Adds a piece of merchandise to this Inventory. If the merchandise already
 * exists in this Inventory, its stock quantity is updated.
 * @param item  The merchandise to add.
 * @pre There is sufficient room in this Inventory for the merchandise.
 * @post The specified merchandise is copied into this Inventory, indexed by a
 *       hash of its descriptive name.
 * @return true if there was sufficient space in this Inventory for the
 *         merchandise; false, otherwise.
 */
    bool addItem(const Merch& item);

/**---------------------- removeItem() ----------------------------------------
 * Removes a piece of merchandise from this Inventory by updating the stock
 * quantity.
 * @param item  The merchandise to remove.
 * @pre The specified merchandise exists in this Inventory with a stock
 *      quantity greater than zero.
 * @post The stock quantity for the specified merchandise is decreased by one.
 * @return true if a sufficient quantity of the specified merchandise existed
 *         in this Inventory; false, otherwise.
 */
    bool removeItem(const Merch& item);

/**---------------------- clearItem() -----------------------------------------
 * Completely removes a type of merchandise from this Inventory.
 * @param item  The merchandise to clear from this Inventory.
 * @pre The specified merchandise exists in this Inventory.
 * @post The specified merchandise no longer exists in this Inventory.
 * @return true if the specified merchandise existed in this Inventory; false,
 *         otherwise.
 */
    bool clearItem(const Merch& item);

/**---------------------- rentItem() ------------------------------------------
 * Updates the available quantity for a specified piece of merchandise.
 * @param item  The merchandise whose available quantity will be decreased.
 * @pre item is a type of merchandise that exists in this Inventory and its
 *      available quantity is greater than zero.
 * @post item's available quantity is decreased by one.
 * @return true if item is a type of merchandise that exists in this inventory
 *         and its available quantity was greater than zero; false, otherwise.
 */
    bool rentItem(const Merch& item);

/**---------------------- returnItem() ----------------------------------------
 * Updates the available quantity for a specified piece of merchandise.
 * @param item  The merchandise whose availabe quantity will be increased.
 * @pre item is a type of merchandise that exists in this Inventory and its
 *      available quantity is less than its stock quantity.
 * @post item's available quantity is increased by one.
 * @return true if item is a type of merchandise that exists in this Inventory
 *         and its available quantity was less than its stock quantity; false,
 *         otherwise.
 */
    bool returnItem(const Merch& item);

/**---------------------- getMaxMerch() ---------------------------------------
 * Retrieves the maximum number of unique merchandise this Inventory can hold.
 * @pre None.
 * @post None.
 * @return The number of unique merchandise items this Inventory can hold.
 */
    int getMaxMerch(void) const;

/**---------------------- setMaxMerch() ---------------------------------------
 * Sets the maximum number of unique merchdise this Inventory can hold.
 * @param newMax  The new maximum number of unique merchandise; must be
 *                positive, should be prime.
 * @pre None.
 * @post This Inventory can now hold newMax unique merchandise.
 */
    void setMaxMerch(int newMax);

/**---------------------- getMaxQty() -----------------------------------------
 * Retrieves the quantity of each type of merchandise this Inventory can hold.
 * @pre None.
 * @post None.
 * @return The quantity of each type of merchandise this Inventory can hold.
 */
    int getMaxQty() const;

/**---------------------- setMaxQty() -----------------------------------------
 * Sets the quantity of each type of merchandise this Inventory can hold.
 * @param newQty  The new maximum quantity of each merchandise; must be
 *                positive.
 * @pre None.
 * @post This Inventory can now hold newQty of each type of merchandise.
 */
    void setMaxQty(int newQty);

private:

    struct MerchNode
    {
        MerchNode* next;
        Merch* item;
        int stockQty;
        int currentQty;
    }; // end struct MerchNode

    int        maxMerch;    // maximum number of unique items to hold
    int        maxQty;      // maximum number of each item to hold
    MerchNode* allItems[];  // chained hash table of unique items

/**---------------------- hashIndex() -----------------------------------------
 * Calculates the hash table index for some given merchandise.
 * @param item  The merchandise whose index is to be found.
 * @pre item contains a descriptive name that is unique for that type of
 *      merchandise.
 * @post None.
 * @return The hash table index of the specified merchandise.
 */
    int hashIndex(const Merch*& item);
}; // end class Inventory

#endif	/* _INVENTORY_H */
