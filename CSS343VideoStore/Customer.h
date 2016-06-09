/*
 * @file    Customer.h
 * @brief   This class represents a single customer of a business. The customer
 *          has a first name and last name, which may not be unique amongst all
 *          customers of the business. A customer also has an ID number that is
 *          unique within a single business, and a history of transactions with
 *          the business.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _CUSTOMER_H
#define	_CUSTOMER_H

#include "History.h"

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
 * Creates an instantiated Customer object with a full name and ID number.
 * @param uniqueID  A number to uniquely identiy this Customer in a business.
 * @param firstName  The given name of this Customer.
 * @param lastName  The surname of this Customer.
 * @pre None.
 * @post A Customer object exists with a full name and ID number.
 */
    Customer(int uniqueID, string firstName, string lastName);
    
// Copy constructor and destructor prvided by compiler

/**---------------------- == Equality Operator --------------------------------
 * Tests two Customers for identical attributes. Only identifiers are checked,
 * not history.
 * @param rhs  The Customer to compare with for equality.
 * @pre None.
 * @post None.
 * @return true if this Customer has the same identifying information as rhs;
 *         false, otherwise.
 */
    virtual bool operator==(const Customer& rhs) const;

/**---------------------- != Inequality Operator ------------------------------
 * Tests two Customers for differing attributes. Only identifiers are checked,
 * not history.
 * @param rhs  The Customer to compare with for inequality.
 * @pre None.
 * @post None.
 * @return true if this Customer has different identifying information from
 *         rhs; false, otherwise.
 */
    virtual bool operator!=(const Customer& rhs) const;

/**---------------------- getID() ---------------------------------------------
 * Retrieves the ID number of this Customer.
 * @pre This customer has been instantiated.
 * @post None.
 * @return The unique ID number of this customer.
 */
    int getID(void) const;

/**---------------------- setID() ---------------------------------------------
 * Sets the ID number of this Customer.
 * @param newID  The new ID number for this Customer; may be the same as the
 *               old ID number.
 * @pre None.
 * @post This Customer contains a valid ID number.
 */
    void setID(int newID);

/**---------------------- getFirstName() --------------------------------------
 * Retrieves the given name of this Customer.
 * @pre This customer has been instantiated.
 * @post None.
 * @return The given name of this Customer.
 */
    string getFirstName() const;

/**---------------------- setFirstName() --------------------------------------
 * Sets the given name of this Customer.
 * @param newName  The new given name for this Customer; may be the same as the
 *                 old given name.
 * @pre None.
 * @post This Customer contains a valid given name.
 */
    void setFirstName(string newName);

/**---------------------- getLastName() ---------------------------------------
 * Retrieves the surname of this Customer.
 * @pre This Customer has been instantiated.
 * @post None.
 * @return The surname of this Customer.
 */
    string getLastName(void) const;

/**---------------------- setLastName() ---------------------------------------
 * Sets the surname of this Customer.
 * @param newName  The new surname for this Customer; may be the same as the
 *                 old surname.
 * @pre None.
 * @post This Customer contains a valid surname.
 */
    void setLastName(string newName);

/**---------------------- newTransaction() ------------------------------------
 * Adds a new Transaction to this Customer's history.
 * @param latest  Transaction to add to this Customer's history.
 * @pre The transaction is valid in the context of this Customer's history.
 * @post A new Transaction has been placed in this Customer's history.
 * @return true if the Transaction is valid; false, otherwise.
 */
    bool newTransaction(const Transaction& latest);

/**---------------------- getMostRecent() -------------------------------------
 * Retrieves the most recent Transaction in this Customer's history.
 * @param latest  Target for the most recent Transaction, if found.
 * @pre This Customer's history is not empty.
 * @post latest is a copy of the Transaction at the head of this Customer's
 *       history.
 * @return true if this Customer's history contains at least one Transaction;
 *         false, otherwise.
 */
    bool getMostRecent(Transaction& latest) const;

/**---------------------- getHistory() ----------------------------------------
 * Writes the history of this Customer to an output stream.
 * @param output  The output stream to write history out to.
 * @pre ouput is writable.
 * @post output contains a string representing this Customer's history, in
 *       reverse chronological order.
 * @return true if this Customer has a history to write out; false, othwerwise.
 */
    bool getHistory(ostream& output) const;

/**---------------------- clearHistory() --------------------------------------
 * Completely removes the history of this Customer.
 * @pre None.
 * @post This Customer's history is empty.
 */
    void clearHistory(void);

private:

    int     customerID;     // identifier unique within a business
    string  surname;        // customer last name
    string  givenName;      // customer first name
    History activity;       // history of transaction with a business
}; // end class Customer

#endif	/* _CUSTOMER_H */
