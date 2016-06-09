/*
 * @file    RentalShop.h
 * @brief   This class represents a shop that rents items to customers. It is a
 *          type of business that deals with material goods, so it has a
 *          merchandise inventory. A rental shop may have an expected number of
 *          unique items it will hold in inventory and may have a set limit on
 *          the number of each item it will carry.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _RENTALSHOP_H
#define	_RENTALSHOP_H

#include "Business.h"
#include "Inventory.h"


class RentalShop : public Business
{
public:

/**---------------------- Constructor -----------------------------------------
 * Creates a RentalShop object with a specified set of attributes.
 * @param newName  Name to identify this Shop.
 * @param customerBase  Expected number of Customers this Shop will have. Must
 *                      be positive.
 * @param idealStock  The expected number of unique items this Shop will stock.
 *                    Must be positive; should be prime.
 * @param maxQty  Maximum number of each item to stock. Must be positive.
 * @pre customerBase, idealStock, and maxQty are all positive.
 * @post A RantalShop object exists with name newName, Customer List size of
 *       customerBase, and an expected Inventory size of idealStock.
 */
    RentalShop(const string& newName, int customerBase,
                 int idealStock, int maxQty);

/**---------------------- Destructor ------------------------------------------
 * @pre None.
 * @post This RentalShop object has been cleanly deleted.
 */
    ~RentalShop();

/**---------------------- getItemQty() ----------------------------------------
 * Retrieves the ideal quantity of unique items set for this Shop from its
 * Inventory.
 * @pre None.
 * @post None.
 * @return The ideal quantity of unique items set for this Shop.
 */
    int getItemQty(void) const;

/**---------------------- setItemQty() ----------------------------------------
 * Sets the ideal quantity of unique items for this Shop to a new value. If the
 * specified size would result in a loss of Merchandise, the Inventory will not
 * be resized. The Inventory must be trimmed manually down to the desired size
 * before the new, smaller size can be used. Specifying a larger size will not
 * pose such an aversion.
 * @param stockSize  The new ideal quantity of unique items for this Shop.
 * @pre stockSize is a positive value large enough to accomodate all current
 *      Merchandise in the Inventory.
 * @post The ideal quantity of unique items for this Shop has been set to
 *       stockSize in its Inventory.
 */
    bool setItemQty(int stockSize);

/**---------------------- getMaxQty() -----------------------------------------
 * Retrieves the maximum quantity for each item in this Shop from its
 * Inventory.
 * @pre None.
 * @post None.
 * @return The maximum quantity for each item in this Shop.
 */
    int getMaxQty(void) const;

/**---------------------- setMaxQty() -----------------------------------------
 * Sets the maximum quantity for each item for this Shop in its Inventory to a
 * specified value. If there are items in stock that exceed the new maximum
 * quantity, the new quantity will not be set. These items must be manually
 * removed before the smaller quantity can be set.
 * @param newQty  The new maximum quantity for each item in this Shop.
 * @pre None.
 * @post The maximum quantity for each item in this Shop is now newQty.
 * @return true if the specified maximum quantity for each item in this Shop
 *         could accommodate all items in the Inventory; false, otherwise.
 */
    bool setMaxQty(int newQty);

/**---------------------- addItem() -------------------------------------------
 * Adds some Merchandise to the Inventory.
 * @param newItem  The Merchandise to add.
 * @pre There is sufficent space in the Inventory for the Merchandise.
 * @post If this type of Merchandise already exists in the Inventory, then the
 *       quantity is increased by one. If it did not previously exist, then the
 *       new Merchandise exists in this Shop's Inventory with a quantity of
 *       one.
 * @return true if there was sufficient space in the Inventory for the
 *         Merchandise and it was added; false, otherwise.
 */
    bool addItem(const Merch *newItem);

    bool updateItem(const Merch *item);

/**---------------------- removeItem() ----------------------------------------
 * Removes some Merchandise from the Inventory.
 * @param item  The Merchandise to remove.
 * @pre The specified Merchandise has a positive quantity in the Inventory.
 * @post The quantity of the specified Merchandise has been decreased by one in
 *       the Inventory.
 * @return true if the item was found and one was removed; false, otherwise.
 */
    bool removeItem(const Merch *item);

/**---------------------- findItem() ------------------------------------------
 * Locates some Merchandise in the Inventory.
 * @param item  The Merchandise to locate.
 * @param total  Container for the quantity of the item normally stocked.
 * @param available  Container for the quantity of the item currently in stock.
 * @pre The specified Merchandise exists in the Inventory.
 * @post total contains the quantity of the item normally stocked; available
 *       contains the quantity of the item currently in stock.
 * @return true if the item was found; false, otherwise.
 */
    bool retrieveItem(Merch *& target) const;

/**---------------------- showInventory() -------------------------------------
 * Displays the contents of the Inventory of this Shop. Relies on Merchandise
 * providing a display() method.
 * @pre Merchandise provides a display() method.
 * @post The entire contents of this Shop's Inventory is displayed to cout.
 */
    void showInventory(void) const;

private:

    Inventory stock;    // list of items and their stock quantities

}; // end class RentalShop

#endif	/* _RENTALSHOP_H */
