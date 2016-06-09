/*
 * @file    Borrow.h
 * @brief   This class represents a borrow transaction. It stores a Merch
 *          object as a record of the merchandise involved in the transaction.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 8, 2012
 */

#ifndef _BORROW_H
#define	_BORROW_H

#include "Transaction.h"


class Borrow : public Transaction
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty Borrow object.
 * @pre None.
 * @post An empty Borrow object exists.
 */
    Borrow();

    ~Borrow();

/**---------------------- create() --------------------------------------------
 * Creates a new Borrow object and returns a Transaction pointer to it.
 * @param infile  A character stream containing information used to create the
 *                desired Borrow object. The first line must consist of an
 *                integer, two characters, and a string, each separated by
 *                white space. The string should describe a DVDMedia oabject.
 * @pre infile contains a valid initialization string.
 * @post A new Borrow object exists. The characters used to initialize the
 *       Borrow have been removed from infile. This Borrow contains a type of
 *       DVDMedia object.
 * @return A Transaction pointer to a new Borrow object.
 */
    virtual Transaction* create(ifstream& infile) const;

/**---------------------- copy() ----------------------------------------------
 * Creates a new Borrow object that is a copy of this one and returns a
 * Transaction pointer to it. The Merchandise item is copied, as well.
 * @pre This Borrow holds a type of Merch that implements a copy() method.
 * @post A new Borrow object exists that is a copy of this one.
 * @return A Transaction pointer to a new Borrow object.
 */
    virtual Transaction* copy(void) const;

/**---------------------- process() -------------------------------------------
 * Processes this Borrow in some MOVIEStore. This Transaction is added to the
 * History of a Customer and the item in this Borrow has its available quantity
 * decreased by one in the target's Inventory.
 * @param target  A pointer to a MOVIEStore to act upon. May be altered.
 * @pre MOVIEStore provides the expected interface. The target's Inventory has
 *      this Borrow's item with an available quantity greater than zero. The
 *      borrowing Customer does not have this item in a Borrow in its History
 *      without a Corresponding TakeBack.
 * @post This Borrow has been performed on the target, resulting in a Customer
 *       now containing this Borrow. This Borrow's item has its available
 *       quantity decreased by one in the target's Inventory.
 */
    virtual bool process(MOVIEStore& target) const;

/**---------------------- display() -------------------------------------------
 * Displays information about this Transaction, including its type. If this
 * Transaction holds a Merch object, then display() is called on that object to
 * also display its information.
 * @param output  The character stream to which this Transaction will display
 *                its information.
 * @pre Merch defines a display() method.
 * @post output contains a character string that describes this Transaction.
 */
    virtual void display(ostream& output) const;

private:

}; // end class Borrow

#endif	/* _BORROW_H */

