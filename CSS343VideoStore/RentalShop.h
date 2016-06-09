/*
 * @file    RentalShop.h
 * @brief   This class represents shop that rents items to customers. It is a
 *          type of business that deals with material goods and has a
 *          merchandise inventory.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _RENTALSHOP_H
#define	_RENTALSHOP_H

#include "Inventory.h"

class RentalShop : public Business
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty RantalShop object.
 * @pre None.
 * @post An empty RantalShop object exists.
 */
    RentalShop();

// Copy constructor and destructor provided by compiler

/**---------------------- addItem() -------------------------------------------
 * Adds some merchandise to the Inventory.
 * @param newItem  The merchandise to add.
 * @pre There is sufficent space in the Inventory for the merchandise.
 * @post The new merchandise exists in this shop's Inventory.
 * @return true if there was sufficient space in the Inventory for the
 *         merchandise; false, otherwise.
 */
    bool addItem(const Merch& newItem);

/**---------------------- removeItem() ----------------------------------------
 * Removes some merchandise form the Inventory.
 * @param item  The merchandise to remove.
 * @pre The specified merchandise has a positive quantity in this shop's
 *      Inventory.
 * @post The merchandise has been removed from this shop's Inventory.
 * @return true if the item was found and removed; false, otherwise.
 */
    bool removeItem(Merch*& item);

private:

    Inventory stock;    // list of items and their stock quantities
};

#endif	/* _RENTALSHOP_H */
