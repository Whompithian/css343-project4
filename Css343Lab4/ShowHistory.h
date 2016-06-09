/* 
 * File:   ShowHistory.h
 * Author: brendan
 *
 * Created on March 2, 2012, 4:27 PM
 */

#ifndef _SHOWHISTORY_H
#define	_SHOWHISTORY_H

#include "Transaction.h"


class ShowHistory : public Transaction
{
public:

    ShowHistory();

    virtual ~ShowHistory();

/**---------------------- create() --------------------------------------------
 * Creates a new ShowHistory object and returns a Transaction pointer to it.
 * @param infile  A character stream containing information used to create the
 *                desired type of Transaction. The first line must consist only
 *                of an integer.
 * @pre infile contains a valid initialization string.
 * @post A new ShowHistory object exists. The characters used to initialize the
 *       ShowHistory have been removed from infile.
 * @return A Transaction pointer to a ShowHistory object.
 */
    virtual Transaction* create(ifstream& infile) const;

/**---------------------- copy() ----------------------------------------------
 * Creates a new ShowHistory object that is a copy of this one and returns a
 * Transaction pointer to it.
 * @pre None.
 * @post A new ShowHistory object exists that is a copy of this one.
 * @return A Transaction pointer to a new ShowHistory object.
 */
    virtual Transaction* copy(void) const;

/**---------------------- process() -------------------------------------------
 * Processes this ShowHistory in some MOVIEStore. A Customer is located in the
 * target and that Customer's showHitory() method is called.
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

}; // end class ShowHistory

#endif	/* _SHOWHISTORY_H */

