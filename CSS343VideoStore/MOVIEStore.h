/*
 * @file    MOVIEStore.h
 * @brief   This class represents a video rental store. It is a type of rental
 *          shop that deals only with movies and it sets a limit on the number
 *          of each movie it carries.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _MOVIESTORE_H
#define	_MOVIESTORE_H

class MOVIEStore: public RentalShop
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty MOVIEStore object.
 * @param qtyStock  Maximum number of each item to stock.
 * @pre None.
 * @post An empty MOVIEStore object exists.
 */
    MOVIEStore(int qtyStock = 10);

// Copy constructor and destructor provided by compiler.

/**---------------------- getStockQty() ---------------------------------------
 * Retrieves the maximum number of each item this store can stock.
 * @pre None.
 * @post None.
 * @return The maximum number of each item this store can stock.
 */
    int getStockQty() const;

/**---------------------- setStockQty() ---------------------------------------
 * Sets the maximum number of each item this store can stock.
 * @param newQty  The new maximum quantity of each item.
 * @pre newQty is less than or equal to the highest number of any item already
 *      in stock.
 * @post This store can now stock newQty of each item.
 * @return true if no current item quantities exceed newQty; false, otherwise.
 */
    bool setStockQty(int newQty);

private:

    int stockQty;   // default number of each movie to stock
}; // end class MOVIEStore

#endif	/* _MOVIESTORE_H */
