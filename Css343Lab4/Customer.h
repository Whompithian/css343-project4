/*
 * @file    Customer.h
 * @brief   This class represents a single customer of a business. The customer
 *          has a an ID number that is unique within a single business. It also
 *          has a history of transactions with the business and a set of
 *          identifiers, chosen by the business, stored in key-value pairs.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _CUSTOMER_H
#define	_CUSTOMER_H

#include "History.h"
#include "ThreadedBST.h"


class Customer
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty Customer object.
 * @pre None.
 * @post An empty Customer object exists.
 */
    Customer();

/**---------------------- Constructor -----------------------------------------
 * Creates a Customer object with an ID number.
 * @param uniqueID  A number to uniquely identiy this Customer in a Business.
 * @pre None.
 * @post A Customer object exists with a ID number uniqueID.
 */
    Customer(int uniqueID);

    ~Customer();

/**---------------------- == Equality Operator --------------------------------
 * Tests two Customers for identical attributes. Only identifiers are checked,
 * not history.
 * @param rhs  The Customer with which to compare for equality.
 * @pre None.
 * @post None.
 * @return true if this Customer has the same identifying information as rhs;
 *         false, otherwise.
 */
    virtual bool operator==(const Customer& rhs) const;

/**---------------------- != Inequality Operator ------------------------------
 * Tests two Customers for differing attributes. Only identifiers are checked,
 * not history.
 * @param rhs  The Customer with which to compare for inequality.
 * @pre None.
 * @post None.
 * @return true if this Customer has different identifying information from
 *         rhs; false, otherwise.
 */
    virtual bool operator!=(const Customer& rhs) const;

/**---------------------- getID() ---------------------------------------------
 * Retrieves the ID number of this Customer.
 * @pre None.
 * @post None.
 * @return The unique ID number of this customer.
 */
    int getID(void) const;

/**---------------------- setID() ---------------------------------------------
 * Sets the ID number of this Customer.
 * @param newID  The new ID number for this Customer.
 * @pre None.
 * @post This Customer contains the ID number newID.
 */
    void setID(int newID);

/**---------------------- getField() ------------------------------------------
 * Retrieves the value of a specified field of this Customer's information.
 * @param target  A key-value pair whose key matches a key in this Customer's
 *                information. Will be updated with the corresponding value, if
 *                found.
 * @pre This Customer has a value in the specified field.
 * @post target contains the located value.
 * @return true if this Customer has a value in the specified field and target
 *         was updated with that value; false, otherwise.
 */
    bool getField(KeyedItem& target) const;

/**---------------------- setField() ------------------------------------------
 * Sets the value of a specified field of this Customer's information to a
 * specified value. If the field does not exist, it is created. Once a field
 * has been added, its key becomes permanent within the Customer.
 * @param newValue  A key-value pair whose value will be applied to its key in
 *                  this Customer's information.
 * @pre None.
 * @post This Customer contains a field whose key and value are the same as
 *       those of newValue.
 */
    void setField(const KeyedItem& newValue);

/**---------------------- displayInfo() ---------------------------------------
 * Writes the information of this Customer to an output stream.
 * @param output  The output stream to which information will be written.
 * @pre ouput is writable. This Customer has identifying information.
 * @post output contains a string representing this Customer's information, in
 *       key-sorted order.
 * @return true if this Customer has information to write out; false,
 *         othwerwise.
 */
    void displayInfo(ostream& output) const;

/**---------------------- isBorrowing() ---------------------------------------
 * Indicates whether this Customer is borrowing some specified Merchandise.
 * @param target  A pointer to the type of Merchandise to search for in this
 *                Customer's History.
 * @pre None.
 * @post None.
 * @return true if this Customer has a Borrow Transaction for the specified
 *         Merchandise more recently than a return Transaction for it.
 */
    bool isBorrowing(const Merch *target) const;

/**---------------------- newTransaction() ------------------------------------
 * Adds a new Transaction to this Customer's History.
 * @param latest  Transaction to add to this Customer's History.
 * @pre The transaction is valid in the context of this Customer's History.
 * @post A new Transaction has been placed in this Customer's History.
 * @return true if the Transaction is valid; false, otherwise.
 */
    void newTransaction(const Transaction *latest);

/**---------------------- getMostRecent() -------------------------------------
 * Retrieves the most recent Transaction from this Customer's History.
 * @param latest  Target for the most recent Transaction, if found.
 * @pre This Customer's History is not empty.
 * @post latest is a copy of the Transaction at the head of this Customer's
 *       History.
 * @return true if this Customer's History contains at least one Transaction;
 *         false, otherwise.
 */
    Transaction* getMostRecent(void) const;

/**---------------------- displayHistory() ------------------------------------
 * Writes the History of this Customer to an output stream.
 * @param output  The output stream to which History will be written.
 * @pre ouput is writable. This Customer has some History.
 * @post output contains a string representing this Customer's History, in
 *       reverse chronological order.
 */
    void displayHistory(ostream& output) const;

/**---------------------- clearHistory() --------------------------------------
 * Completely removes the History of this Customer. All Transactions will be
 * lost and this cation cannot be undone.
 * @pre None.
 * @post This Customer's History is empty.
 */
    void clearHistory(void);

private:

    int         customerID;     // identifier unique within a business
    History     activity;       // history of transactions with a business
    ThreadedBST info;           // customer identifying information

}; // end class Customer

#endif	/* _CUSTOMER_H */
