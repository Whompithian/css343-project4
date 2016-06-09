/*
 * @file    Business.h
 * @brief   This class represents a business that deals with customers. A
 *          business has a name and a list of customers. Customers may be added
 *          to or removed from the list.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _BUSINESS_H
#define	_BUSINESS_H

#include "CustomerList.h"


class Business
{
public:

/**---------------------- Constructor -----------------------------------------
 * Creates a Business object with a specified name that may deal with a
 * specified number of Customers.
 * @param newName  Name to identify this Business.
 * @param customerBase  Expected number of Customers this Business will have.
 *                      Must be positive.
 * @pre customerBase is positive.
 * @post A Business object exists with name newName and a Customer List of size
 *       customerBase.
 */
    Business(const string& newName, int customerBase);

/**---------------------- Destructor ------------------------------------------
 * @pre None.
 * @post This Business object has been cleanly deleted.
 */
    ~Business();

/**---------------------- getName() -------------------------------------------
 * Retrieves the name of this Business.
 * @pre None.
 * @post None.
 * @return The name of this Business.
 */
    string getName(void) const;

/**---------------------- setName() -------------------------------------------
 * Sets the name of this Business to a specified value.
 * @param newName  The new name for this Business.
 * @pre None.
 * @post The name of this Business is now newName.
 */
    void setName(const string& newName);

/**---------------------- getListSize() ---------------------------------------
 * Retrieves the size of the Customer List of this Business.
 * @pre None.
 * @post None.
 * @return The Customer List size for this Business.
 */
    int getListSize(void) const;

/**---------------------- setListSize() ---------------------------------------
 * Sets the size of the Customer List of this Business to a new value. If the
 * specified size would result in a loss of Customers, the List will not be
 * resized. The List must either be trimmed manually down to the desired size,
 * or it must be purged using emptyCustomerList() before the new, smaller size
 * can be used. Specifying a larger size will result in all Customers remaining
 * in their same absolute positions in the List.
 * @param newSize  The new size of the Customer List for this Business.
 * @pre newSize is sufficient for the List to hold the last Customer currently
 *      in the List.
 * @post The size of the Customer List for this Business is now newSize.
 * @return true if the Customer List could be set to newSize; false, otherwise.
 */
    bool setListSize(int newSize);

/**---------------------- addCustomer() ---------------------------------------
 * Adds a new Customer to the List. Customers are identified by an ID number
 * that is unique within a Business. If the Customer provided has an ID number
 * that matches a Customer in the List, the record for the matching Customer
 * will not be updated. To change the record for an existing Customer, use
 * updateCustomer() instead.
 * @param newCustomer  The Customer to be added to the Customer List.
 * @pre newCustomer does not have an ID number that already exists in the List.
 * @post A new Customer has been added to the List.
 * @return true if the Customer was not already in the List and could be added;
 *         false, otherwise.
 */
    bool addCustomer(const Customer& newCustomer);

/**---------------------- updateCustomer() ------------------------------------
 * Updates the record of an existing Customer. If a Customer is found in the
 * List with an ID number matching that of the provided Customer, then the
 * original record will be overwritten with the new one. If the ID number is
 * not found in the List, the provided Customer will not be added. To add a new
 * Customer to the List, use addCustomer() instead. This functionality is kept
 * separate to ensure the caller can decide which action should be taken.
 * @param customer  The Customer whose record will be updated.
 * @pre customer has an ID number that matches a Customer that already exists
 *      in the List.
 * @post A Customer record has been updated in the List.
 * @return true if the Customer was found in the List and could be updated;
 *         false, otherwise.
 */
    bool updateCustomer(const Customer& customer);

/**---------------------- removeCustomer() ------------------------------------
 * Removes an existing customer from the List. The full Customer record is
 * copied into the parameter customer so that it is not immediately lost and
 * could later be added back into the List.
 * @param customer  The Customer to be removed. If the Customer exists, this
 *                  parameter is updated with the full Customer record.
 * @pre customer exists in the List.
 * @post customer has been removed from the List; customer contains the full
 *       record of the located Customer.
 * @return true if the Customer was found and removed; false, otherwise.
 */
    bool removeCustomer(Customer& customer);

/**---------------------- retrieveCustomer() ----------------------------------
 * Retrieves the record for a specified Customer. A copy of the Customer is
 * returned for editing. The edited Customer can then be submitted, if need be,
 * using updateCustomer().
 * @param customer  A copy of the Customer to locate. Will be replaced with the
 *                  full Customer record, if found.
 * @pre customer exists in the Customer List.
 * @post customer contains a full copy of the appropriate Customer record.
 * @return true if the Customer was found in the List and its record retrieved;
 *         false, otherwise.
 */
    bool retrieveCustomer(Customer& customer) const;

/**---------------------- emptyCustomerList() ---------------------------------
 * Removes all existing Customers from the List. This operation will destroy
 * all Customer records and cannot be undone.
 * @pre None.
 * @post The Customer List is completely empty, but retains its original size.
 */
    void emptyCustomerList(void);

private:

    string       name;          // Business name
    CustomerList allCustomers;  // List of active Customers

}; // end class Business

#endif	/* _BUSINESS_H */
