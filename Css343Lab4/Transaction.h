/*
 * @file    Transaction.h
 * @brief   This class represents a retail transaction. It stores a Merch
 *          object as a record of the merchandise involved in the transaction.
 *          A transaction is abstract and needs to be extended to achieve the
 *          characteristics of specific types of transactions.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _TRANSACTION_H
#define	_TRANSACTION_H

#include <cstdlib>
#include <string>
//#include "Merch.h"

using namespace std;

class Merch;
class MOVIEStore;


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
 * Creates a Transaction object holding a specified piece of merchandise.
 * @param newItem  The Merchandise involved in this Transaction.
 * @pre None.
 * @post A Transaction object exists with a specified piece of merchandise.
 */
    Transaction(Merch *newItem);

/**---------------------- Copy Constructor ------------------------------------
 * Creates a Transaction object that is a copy of an existing Transaction.
 * @param orig  The original Transaction to be copied.
 * @pre Merch defines a copy() method.
 * @post A Transaction object exists that is a copy of orig.
 */
    //Transaction(const Transaction& orig);

/**---------------------- Destructor ------------------------------------------
 * @pre None.
 * @post This Transaction object has been cleanly deleted.
 */
    ~Transaction();

/**---------------------- create() --------------------------------------------
 * Creates a new object descended from Transaction and returns a Transaction
 * pointer to that object.
 * @param infile  A character stream containing information used to create the
 *                desired type of Transaction.
 * @pre infile contains a valid initialization string.
 * @post A new Transaction object exists. The characters used to initialize the
 *       Transaction have been removed from infile.
 * @return A pointer to a type of Transaction object.
 */
    virtual Transaction* create(ifstream& infile) const = 0;

/**---------------------- copy() ----------------------------------------------
 * Creates a Transaction object that is a copy of an existing Transaction and
 * returns a pointer to that Transaction.
 * @param orig  Pointer to the original Transaction to be copied.
 * @pre orig points to a Transaction that holds a type of media that implements
 *      a copy method.
 * @post A Transaction object exists that is a copy of orig.
 * @return A pointer to a new Transaction that is a copy of orig.
 */
    virtual Transaction* copy(void) const = 0;

/**---------------------- process() -------------------------------------------
 * Processes this Transaction in some MOVIEStore. The MOVIEStore may be changed
 * to reflect the Transaction. This may be done by creating a copy of the
 * Transaction in a Customer of the MOVIEStore or by changing the quantity of
 * some Merchandise in the target's Inventory.
 * @param target  A pointer to a MOVIEStore to act upon. May be altered.
 * @pre MOVIEStore provides the expected interface.
 * @post This Transaction has been performed on the target, either resulting in
 *       a Customer now containing this transation, or a report of some content
 *       of the target being generated.
 */
    virtual bool process(MOVIEStore& target) const = 0;

/**---------------------- display() -------------------------------------------
 * Displays information about this Transaction, including its type. If this
 * Transaction holds a Merch object, then display() is called on that object to
 * also display its information.
 * @param output  The character stream to which this Transaction will display
 *                its information.
 * @pre Merch defines a display() method.
 * @post output contains a character string that describes this Transaction.
 */
    virtual void display(ostream& output) const = 0;

/**---------------------- getItem() -------------------------------------------
 * Retrieves the Merchandise item from this Transaction.
 * @pre None.
 * @post None.
 * @return Merchandise item from this Transaction.
 */
    Merch* getItem(void) const;

/**---------------------- setItem() -------------------------------------------
 * Sets the Merchandise item of this Transaction.
 * @param newItem  The new Merchandise item for this Transaction.
 * @pre None.
 * @post This Transaction contains a valid Merchandise item.
 */
    void setItem(const Merch *newItem);

/**---------------------- getMediaCode() --------------------------------------
 * Retrieves the character representing a type of media from this Transaction.
 * @pre None.
 * @post None.
 * @return Character code for the media type from this Transaction.
 */
    char getMediaCode(void) const;

/**---------------------- setMediaCode() --------------------------------------
 * Sets the character representing a type of media in this Transaction.
 * @param newMediaCode  The new character code for a type of media for this
 *                      Transaction.
 * @pre None.
 * @post This Transaction contains a character code that represents a type of
 *       media.
 */
    void setMediaCode(char newMediaCode);

/**---------------------- getCustID() -----------------------------------------
 * Retrieves the customer ID from this Transaction.
 * @pre None.
 * @post None.
 * @return Customer ID from this Transaction.
 */
    int getCustID(void) const;

/**---------------------- setCustID() -----------------------------------------
 * Sets the customer ID for this Transaction.
 * @param newCustID  The new ID for a Customer this Transaction should belong
 *                   to.
 * @pre None.
 * @post This Transaction contains an ID number for a Customer.
 */
    void setCustID(int newCustID);

private:

    Merch *item;        // item on which the transaction was performed
    char   mediaCode;   // code for type of media involved
    int    custID;      // ID of a customer involved in this transaction

}; // end class Transaction

#endif	/* _TRANSACTION_H */

