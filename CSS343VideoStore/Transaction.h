/*
 * @file    Transaction.h
 * @brief   This class represents a retail transaction. It stores a code for
 *          the type of transaction and a Merch object as a record of the
 *          merchandise involved in the transaction. Any other information is
 *          assumed to be maintained by the calling class.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _TRANSACTION_H
#define	_TRANSACTION_H

#include <cstdlib>
#include <string>
using namespace std;

class Transaction
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty Transaction object.
 * @pre None.
 * @post An empty Transaction object exists.
 */
    Transaction();

/**---------------------- Constructor -----------------------------------------
 * Creates a Transaction of a specified action on some specified merchandise.
 * @param anAction  char code for the type of transaction.
 * @param anItem  The merchandise on which the action is performed.
 * @pre None.
 * @post A Transaction exists that represents an action performed on some
 *       merchandise.
 */
    Transaction(const char& anAction, const Merch& anItem);

// Copy constructor and destructor provided by compiler

/**---------------------- == Equality Operator --------------------------------
 * Tests two Transactions for identical content.
 * @param rhs  The Transaction to compare with for equality.
 * @pre None.
 * @post None.
 * @return true if this Transaction is equal to rhs; false, otherwise.
 */
    virtual bool operator==(const Transaction& rhs) const;

/**---------------------- != Inequality Operator ------------------------------
 * Tests two Transactions for differing content.
 * @param rhs  The Transaction to compare with for inequality.
 * @pre None.
 * @post None.
 * @return true if this Transaction is not equal to rhs; false, otherwise.
 */
    virtual bool operator!=(const Transaction& rhs) const;

/**---------------------- getAction() -----------------------------------------
 * Retrieves the action code of this Transaction.
 * @pre This Transaction has been initialized.
 * @post None.
 * @return char representation of the action code of this Transaction.
 */
    char getAction(void) const;

/**---------------------- setAction() -----------------------------------------
 * Sets the action code of this Transaction.
 * @param newAction  The new action code for this Transaction; may be the same
 *                   as the old action.
 * @pre None.
 * @post This Transaction has a valid action code.
 */
    void setAction(const char& newAction);

/**---------------------- getItem() -------------------------------------------
 * Retrieves the merchandise item from this Transaction.
 * @pre This Transaction has been initialized.
 * @post None.
 * @return Merchandise item from this Transaction.
 */
    Merch getItem(void) const;

/**---------------------- setItem() -------------------------------------------
 * Sets the merchandise item of this Transaction.
 * @param newItem  The new merchandise item for this Transaction; may be the
 *                 same as the old item.
 * @pre None.
 * @post This Transaction has a valid merchandise item.
 */
    void setItem(const Merch& newItem);

private:

    char  action;   // code for the type of transaction performed
    Merch item;     // item on which the transaction was performed
}; // end class Transaction

#endif	/* _TRANSACTION_H */

