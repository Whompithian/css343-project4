/*
 * @file    History.h
 * @brief   This class represents a record of Transactions. It uses a linked-
 *          list implementation to allow the history to grow easily. The list
 *          is not sorted and all items are inserted at the head, so the order
 *          will be chronological with the most recent additions first. Since
 *          this is a history, removal of individual records is not permitted.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _HISTORY_H
#define	_HISTORY_H

#include <iostream>
#include "Transaction.h"

class History
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty Transaction History.
 * @pre None.
 * @post An empty Transaction History exists.
 */
    History();

/**---------------------- Copy Constructor ------------------------------------
 * Creates a duplicate of a Transaction History.
 * @param orig  The Transaction History to be copied.
 * @pre There is sufficient memory to copy the original Transaction History.
 * @post This History is a deep copy of the original. All Transactions from the
 *       original History are copied into this one.
 */
    History(const History& orig);

/**---------------------- Destructor ------------------------------------------
 * Deletes all elements in this Transaction History.
 * @pre None.
 * @post All History elements are cleanly deleted and all pointers set to NULL.
 */
    virtual ~History();

/**---------------------- itEmpty() -------------------------------------------
 * Indicates whether this Transaction History contains any Transactions.
 * @pre None.
 * @post None.
 * @return true if there are no Transactions in this History; false, otherwise.
 */
    bool isEmpty(void) const;

/**---------------------- rentItem() ------------------------------------------
 * Adds a Transaction with the "borrow" action code.
 * @param borrow  The merchandise item to be borrowed.
 * @pre There is sufficient memory to create a Transaction.
 * @post A new Transaction of type "borrow" with the specified merchandise is
 *       at the head of this list.
 */
    void rentItem(const Merch& borrow);

/**---------------------- returnItem() ----------------------------------------
 * Adds a Transaction with the "return" action code for a merchandise item that
 * was previously borrowed.
 * @param unBorrow  The merchandise item to be returned.
 * @pre There is sufficient memory to create a Transaction.
 * @post A new Transaction of type "return" with the specified merchandise is
 *       at the head of this list.
 * @return true if the merchandise had been borrowed; false, otherwise.
 */
    bool returnItem(const Merch& unBorrow);

/**---------------------- showHistory() ---------------------------------------
 * Provides a stream of Transactions in reverse chronological order.
 * @param output  The stream to write out a complete history.
 * @pre output can be written to.
 * @post output contains a complete record of this Transaction History.
 */
    void showHistory(ostream& output) const;

private:

    struct ListNode
    {
        ListNode* next;
        Transaction* record;
    }; // end struct ListNode

    ListNode* head;     // pointer to the head of history list

/**---------------------- clearHistory() --------------------------------------
 * Clears this History and cleanly deletes all nodes.
 * @pre None.
 * @post This Transaction History is empty.
 */
    void clearHistory(void);
}; // end class History

#endif	/* _HISTORY_H */
