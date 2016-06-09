/* 
 * File:   ShowInventory.h
 * Author: brendan
 *
 * Created on March 2, 2012, 4:27 PM
 */

#ifndef _SHOWINVENTORY_H
#define	_SHOWINVENTORY_H

#include "Transaction.h"


class ShowInventory : public Transaction
{
public:

    ShowInventory();

    virtual ~ShowInventory();

/**---------------------- create() --------------------------------------------
 * Creates a new ShowInventory object and returns a Transaction pointer to it.
 * @param infile  Not used by this type of Transaction.
 * @pre None.
 * @post A new ShowInventory object exists.
 * @return A Transaction pointer to a ShowInventory object.
 */
    virtual Transaction* create(ifstream& infile) const;

/**---------------------- copy() ----------------------------------------------
 * Creates a new ShowInventory object that is a copy of this one and returns a
 * Transaction pointer to it.
 * @pre None.
 * @post A new ShowInventory object exists that is a copy of this one.
 * @return A Transaction pointer to a new ShowInventory object.
 */
    virtual Transaction* copy(void) const;

/**---------------------- process() -------------------------------------------
 * Processes this ShowInventory in some MOVIEStore. target's showInventory()
 * method is called.
 * @param target  A pointer to a MOVIEStore to act upon.
 * @pre MOVIEStore provides the expected interface. The Customer identified by
 *      this Transaction exists in the target.
 * @post target remains unaltered.
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

}; // end class ShowInventory

#endif	/* _SHOWINVENTORY_H */

