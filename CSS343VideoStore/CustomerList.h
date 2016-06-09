/*
 * @file    CustomerList.h
 * @brief   This class represents the list of customers for a business. A hash
 *          table stores customers for fast insertion and retrieval. Customers
 *          are identified by a unique four-digit ID number that serves as the
 *          index into the hash table.
 * @author  Brendan Sweeney, SID 1161836
 * @date    February 15, 2012
 */

#ifndef _CUSTOMERLIST_H
#define	_CUSTOMERLIST_H
#include "Customer.h"

class CustomerList
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty Customer List.
 * @pre None.
 * @post An empty Customer List exists.
 */
    CustomerList();

/**---------------------- Copy Constructor ------------------------------------
 * Creates a duplicate of a Customer List.
 * @param orig  The Customer List to be copied.
 * @pre There is sufficient memory to copy the original Customer List.
 * @post This Customer List is a deep copy of the original. All Customers from
 *       the original List are copied into this one.
 */
    CustomerList(const CustomerList& orig);

/**---------------------- Destructor ------------------------------------------
 * Deletes all elements of this Customer List.
 * @pre None.
 * @post All List elements are cleanly deleted and all pointers set to NULL.
 */
    virtual ~CustomerList();

/**---------------------- isEmpty() -------------------------------------------
 * Indicates whether this Customer List contains any Customers.
 * @pre None.
 * @post None.
 * @return true if there are no Customers in this List; false, otherwise.
 */
    bool isEmpty(void) const;

/**---------------------- addCustomer() ---------------------------------------
 * Adds a Customer to this List.
 * @param customer  The Customer to add.
 * @pre customer has an ID number and no Customer in the list has that same ID
 *      number.
 * @post The specified Customer is copied into this list, indexed by ID number.
 * @return true if the specified Customer has an ID number unique to this List;
 *         false, otherwise.
 */
    bool addCustomer(const Customer& customer);

/**---------------------- removeCustomer() ------------------------------------
 * Removes a Customer from this List.
 * @param customer  A Customer that is equal to the one to be romvoed.
 * @pre There is a match for the specified Customer in this List.
 * @post The Customer has been removed from this List and the index that held
 *       that Customer is now vacant.
 * @return true if the Customer was found in this List; false, otherwise.
 */
    bool removeCustomer(const Customer& customer);

/**---------------------- retrieveCustomer() ----------------------------------
 * Retrieves a copy of a Customer from this List.
 * @param customer  A Customer that is equal to the one to be retrieved.
 * @param target  A container for the located Customer.
 * @pre A Customer equal to customer exists in this List.
 * @post target contains a duplicate of the specified Customer.
 * @return true if the specified Customer was found in this list; false,
 *         otherwise.
 */
   bool retrieveCustomer(const Customer& customer, Customer& target) const;

private:

    int LISTSIZE = 10000;           // 10007 is prime, but we assume unique ID
    Customer* customers[LISTSIZE];  // hash table of customers

/**---------------------- hashIndex() -----------------------------------------
 * Calculates the hash table index for a given Customer.
 * @param customer  The Customer whose index is to be found.
 * @pre customer contains an ID number that is unique for that Customer within
 *      this Customer List.
 * @post None.
 * @return The hash table index of the specified Customer.
 */
    int hashIndex(const Customer& customer);
}; // end class CustomerList

#endif	/* _CUSTOMERLIST_H */
