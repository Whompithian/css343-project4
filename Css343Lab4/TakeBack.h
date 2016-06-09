/*
 * @file    Transaction.h
 * @brief   This class represents a return transaction. It stores a Merch
 *          object as a record of the merchandise involved in the transaction.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 8, 2012
 */

#ifndef _TAKEBACK_H
#define	_TAKEBACK_H

#include "Transaction.h"


class TakeBack : public Transaction
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty TkaeBack object.
 * @pre None.
 * @post An empty TakeBack object exists.
 */
    TakeBack();

    ~TakeBack();

/**---------------------- create() --------------------------------------------
 * Creates a new TakeBack object and returns a Transaction pointer to it.
 * @param infile  A character stream containing information used to create the
 *                desired TakeBack object. The first line must consist of an
 *                integer, two characters, and a string, each separated by
 *                white space. The string should describe a DVDMedia oabject.
 * @pre infile contains a valid initialization string.
 * @post A new TakeBack object exists. The characters used to initialize the
 *       TakeBack have been removed from infile.
 * @return A Transaction pointer to a TakeBack object.
 */
    virtual Transaction* create(ifstream& infile) const;

/**---------------------- copy() ----------------------------------------------
 * Creates a new TakeBack object that is a copy of this one and returns a
 * Transaction pointer to it. The Merchandise item is copied, as well.
 * @pre This TakeBack holds a type of Merch that implements a copy() method.
 * @post A new TakeBack object exists that is a copy of this one.
 * @return A Transaction pointer to a new TakeBack object.
 */
    virtual Transaction* copy(void) const;

/**---------------------- process() -------------------------------------------
 * Processes this TakeBack in some MOVIEStore. This Transaction is added to the
 * History of a Customer and the item in this TakeBack has its available
 * quantity increased by one in the target's Inventory.
 * @param target  A pointer to a MOVIEStore to act upon. May be altered.
 * @pre MOVIEStore provides the expected interface. A Customer in the target
 *      contains a Borrow for this TakeBack's item in its History, without any
 *      corresponding TakeBack.
 * @post This TakeBack has been performed on the target, resulting in a Customer
 *       now containing this TakeBack in its History. This TakeBack's item has
 *       its available quantity increased by one in the target's Inventory.
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

}; // end class TakeBack

#endif	/* _TAKEBACK_H */

