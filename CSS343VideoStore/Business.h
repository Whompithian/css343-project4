/*
 * @file    Business.h
 * @brief   This class represents a business that deals with customers. The
 *          class only has a name and a list of customers.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _BUSINESS_H
#define	_BUSINESS_H

#include "CustomerList.h"

class Business
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty Business object.
 * @param name  Name for this business.
 * @pre None.
 * @post An empty Business object exists.
 */
    Business(const string name = "MOVIE");

// Copy constructor and destructor provided by compiler.

/**---------------------- getName() -------------------------------------------
 * Retrieves the name of this Business.
 * @pre None.
 * @post None.
 * @return The name of this Business
 */
    string getName(void) const;

/**---------------------- setName() -------------------------------------------
 * Sets the name of this Business.
 * @param newName  The new name for this Business.
 * @pre None.
 * @post The name of this Business is now newName.
 */
    void setName(const string& newName);

/**---------------------- addCustomer() ---------------------------------------
 * Adds a Customer to the list.
 * @param newCustomer  The Customer to be added.
 * @pre newCustomer does not already exist in the list.
 * @post A new customer has been added to the list.
 * @return true if the Customer was not already in the list; false, otherwise.
 */
    bool addCustomer(const Customer& newCustomer);

/**---------------------- removeCustomer() ------------------------------------
 * Removes a customer form the list.
 * @param customer  The customer to be removed.
 * @pre customer exists in the lsit.
 * @post suctomer has been removed from the list.
 * @return true if the Customer was found and removed; false, otherwise.
 */
    bool removeCustomer(const Customer& customer);

/**---------------------- findCustomer() --------------------------------------
 * Retrieves the record for a specified Customer.
 * @param customer  A container for the customer, if found.
 * @param custName  A copy of the Customer to locate.
 * @pre custName exists in the Customer list.
 * @post customer contains a copy of the proper Customer record.
 * @return
 */
    bool findCustomer(Customer*& customer, const Customer& custName) const;

private:

    string       name;          // company name
    CustomerList customers;     // list of active customers
}; // end class Business

#endif	/* _BUSINESS_H */
