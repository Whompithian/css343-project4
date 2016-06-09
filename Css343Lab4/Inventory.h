/*
 * @file    Inventory.h
 * @brief   This class represents the merchandise inventory of a rental shop.
 *          Each unique piece of merchandise is stored in a chained hash table,
 *          along with the quantity that the shop owns and the quantity that is
 *          currently available for rent. A limit may be set on the amount of
 *          merchandise expected in the inventory, as well as the quantity of
 *          each type of merchandise allowed.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _INVENTORY_H
#define	_INVENTORY_H

#include "Merch.h"

const int INVENTORYSIZE = 'F' - 'A';


class Inventory
{
public:

/**---------------------- Constructor -----------------------------------------
 * Creates a Merchandise Inventory of a specified target size and with a limit
 * on the quantity of each item that will be held.
 * @param idealQty  A positive value indicating how many unique types of
 *                  merchandise this Inventory can hold. Should be prime.
 * @param qtyCap  A positive value indicating how many of each type of
 *                Merchandise this Inventory can hold.
 * @pre merchCap and qtyCap are greater than zero.
 * @post A Merchandise Inventory exists with target size of idealQty and a
 *       limit on each unique item of qtyCap.
 */
    Inventory(int idealQty, int qtyCap);

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
 * exists in this Inventory, it is not changed. To alter quantities, use
 * updateItem() instead.
 * @param item  The merchandise to add.
 * @pre There is sufficient room in this Inventory for the merchandise.
 * @post The specified merchandise is copied into this Inventory, indexed by a
 *       hash of its descriptive name.
 * @return true if there was sufficient space in this Inventory for the
 *         merchandise; false, otherwise.
 */
    bool addItem(const Merch *item);

/**---------------------- updateItem() ----------------------------------------
 * Updates the values of a piece of Merchandise. The provided Merchandise will
 * replace the original. If the Merchandise cannot be found, it will not be
 * added. To add new Merchandise, use addItem() instead.
 * @pre The specified Merchandise exists in this Inventory.
 * @post The specified merchandise replaces the one that was in this Inventory.
 * @return true if the Merchandise was found and replaced; false, otherwise.
 */
    bool updateItem(const Merch *item);

/**---------------------- removeItem() ----------------------------------------
 * Removes a piece of merchandise from this Inventory.
 * @param item  The merchandise to remove.
 * @pre The specified merchandise exists in this Inventory.
 * @post The specified merchandise no longer exists in this Inventory.
 * @return true if the Merchandise was found and removed; false, otherwise.
 */
    bool removeItem(const Merch *item);

/**---------------------- retrieveItem() --------------------------------------
 * Retrieves a piece of merchandise from this Inventory. The item is copied and
 * a pointer returned.
 * @param item  The merchandise to retrieve.
 * @pre The specified merchandise exists in this Inventory.
 * @post A new copy of the specified Merchandise exists.
 * @return A pointer to a new copy of the specified Merchandise.
 */
    Merch* retrieveItem(const Merch *item) const;

/**---------------------- getItemQty() ----------------------------------------
 * Retrieves the maximum number of unique merchandise this Inventory can hold.
 * @pre None.
 * @post None.
 * @return The number of unique merchandise items this Inventory can hold.
 */
    int getItemQty(void) const;

/**---------------------- setItemQty() ----------------------------------------
 * Sets the maximum number of unique merchdise this Inventory can hold.
 * @param newMax  The new maximum number of unique merchandise; must be
 *                positive, should be prime.
 * @pre None.
 * @post This Inventory can now hold newMax unique merchandise.
 */
    bool setItemQty(int newMax);

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
    bool setMaxQty(int newQty);

/**---------------------- displayInventory() ----------------------------------
 * Displays the complete contents of this Inventory.
 * @pre None.
 * @post The contents of this Inventory are displayed to cout.
 */
    void displayInventory(void) const;

private:

    int         itemQty;        // maximum number of unique items to hold
    int         maxQty;         // maximum number of each item to hold
    ThreadedBST allItems[INVENTORYSIZE];    // hash table of unique items

/**---------------------- hashIndex() -----------------------------------------
 * Calculates the hash table index for some given merchandise.
 * @param item  The merchandise whose index is to be found.
 * @pre item contains a descriptive name that is unique for that type of
 *      merchandise.
 * @post None.
 * @return The hash table index of the specified merchandise.
 */
    int hashIndex(const Merch *item) const;

}; // end class Inventory

#endif	/* _INVENTORY_H */
