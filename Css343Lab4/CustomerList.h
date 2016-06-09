/*
 * @file    CustomerList.h
 * @brief   This class represents the list of customers for a business. A hash
 *          table stores customers for fast insertion and retrieval. Customers
 *          are identified by a unique ID number that serves to derive an index
 *          into the hash table.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _CUSTOMERLIST_H
#define	_CUSTOMERLIST_H

#include "Customer.h"


class CustomerList
{
public:

/**---------------------- Constructor -----------------------------------------
 * Creates a CustomerList.
 * @param sizeOfList  The expected number of Customers this List should hold.
 * @pre sizeOfList is positive.
 * @post A CustomerList of size sizeOfList exists.
 */
    CustomerList(int sizeOfList);

/**---------------------- Copy Constructor ------------------------------------
 * Creates a duplicate of a CustomerList.
 * @param orig  The CustomerList to be copied.
 * @pre There is sufficient memory to copy the original CustomerList.
 * @post This CustomerList is a deep copy of the original. All Customers from
 *       the original List are copied into this one.
 */
    CustomerList(const CustomerList& orig);

/**---------------------- Destructor ------------------------------------------
 * Deletes all elements of this CustomerList.
 * @pre None.
 * @post All List elements are cleanly deleted and all pointers set to NULL.
 */
    virtual ~CustomerList();

/**---------------------- getListSize() ---------------------------------------
 * Retrieves the size of this CustomerList.
 * @pre None.
 * @post None.
 * @return The size of this CustomerList.
 */
    int getListSize(void) const;

/**---------------------- setListSize() ---------------------------------------
 * Sets the size of this CustomerList to a new value. If the specified size
 * would result in a loss of Customers, the List will not be resized. This List
 * must either be trimmed manually down to the desired size, or it must be
 * purged using emptyList() before the new, smaller size can be used.
 * Specifying a larger size will result in all Customers remaining in their
 * same absolute positions in this List.
 * @param newSize  The new size for this CustomerList.
 * @pre newSize is sufficient for this List to hold the last Customer currently
 *      in this List.
 * @post The size of this CustomerList is now newSize.
 * @return true if this CustomerList could be set to newSize; false, otherwise.
 */
    bool setListSize(int newSize);

/**---------------------- isEmpty() -------------------------------------------
 * Indicates whether this CustomerList contains any Customers.
 * @pre None.
 * @post None.
 * @return true if there are no Customers in this List; false, otherwise.
 */
    bool isEmpty(void) const;

/**---------------------- addCustomer() ---------------------------------------
 * Adds a new Customer to this List. Customers are identified by an ID number
 * that is unique within a List. If the Customer provided has an ID number that
 * matches a Customer in this List, the record for the matching Customer will
 * not be updated. To change the record for an existing Customer, use
 * updateCustomer() instead.
 * @param newCustomer  The Customer to be added.
 * @pre newCustomer does not already exist in this List.
 * @post A new Customer has been added to this List.
 * @return true if the Customer was not already in this List and could be
 *         added; false, otherwise.
 */
    bool addCustomer(const Customer& newCustomer);

/**---------------------- updateCustomer() ------------------------------------
 * Updates the record of an existing Customer. If a Customer is found in this
 * List with an ID number matching that of the provided Customer, then the
 * original record will be overwritten with the new one. If the ID number is
 * not found in this List, the provided Customer will not be added. To add a
 * new Customer to the List, use addCustomer() instead. This functionality is
 * kept separate to ensure the caller can decide which action should be taken.
 * @param customer  The Customer whose record will be updated.
 * @pre customer has an ID number that matches a Customer that already exists
 *      in this List.
 * @post A Customer record has been updated in this List.
 * @return true if the Customer was found in this List and could be updated;
 *         false, otherwise.
 */
    bool updateCustomer(const Customer& customer);

/**---------------------- removeCustomer() ------------------------------------
 * Removes an existing customer from this List. The full Customer record is
 * copied into the parameter customer so that it is not immediately lost and
 * could be added back into this List.
 * @param customer  The customer to be removed. If the Customer exists, this
 *                  parameter is updated with the full Customer record.
 * @pre customer exists in this List.
 * @post A Customer has been removed from this List; customer contains its full
 *       Customer record.
 * @return true if the Customer was found and removed; false, otherwise.
 */
    bool removeCustomer(Customer& customer);

/**---------------------- retrieveCustomer() ----------------------------------
 * Retrieves the record for a specified Customer. A copy of the Customer is
 * returned for editing. The edited Customer can then be submitted, if need be,
 * using updateCustomer().
 * @param customer  A copy of the Customer to locate. Will be replaced with the
 *                  full Customer record, if found.
 * @pre customer exists in this CustomerList.
 * @post customer contains a full copy of the appropriate Customer record.
 * @return true if the Customer was found in this List and its record
 *         retrieved; false, otherwise.
 */
   bool retrieveCustomer(Customer& customer) const;

/**---------------------- emptyList() -----------------------------------------
 * Removes all existing Customers from this List. This operation will destroy
 * all Customer records and cannot be undone.
 * @pre None.
 * @post This CustomerList is completely empty, but retains its original size.
 */
    void emptyList(void);

private:

    int        count;       // number of Customers in this List
    int        listSize;    // expected number of Customers
    Customer **customers;   // hash table of Customer pointers

/**---------------------- hashIndex() -----------------------------------------
 * Calculates the hash table index for a given Customer.
 * @param customer  The Customer whose index is to be found.
 * @pre customer contains an ID number that is unique for that Customer within
 *      this List.
 * @post None.
 * @return The hash table index of the specified Customer.
 */
    int hashIndex(const Customer& customer) const;

/**---------------------- copyList() ------------------------------------------
 * Creates a duplicate of a CustomerList.
 * @param orig  The CustomerList to be copied.
 * @pre There is sufficient memory to copy the original CustomerList.
 * @post This CustomerList is a deep copy of the original. All Customers from
 *       the original List are copied into this one.
 */
    void copyList(const CustomerList& orig);

/**---------------------- destroyList() ---------------------------------------
 * Deletes all elements of this CustomerList.
 * @pre None.
 * @post All List elements are cleanly deleted and all pointers set to NULL.
 */
    void destroyList(void);

/**---------------------- resizeList() ----------------------------------------
 * Sets the size of this CustomerList to a new value. If the new size is less
 * than the original size, only Customers in the original List up to the new
 * size will be kept in the new List. If the new size is larger, then all new
 * elements in the List are set to NULL.
 * @param newSize  The new size for this CustomerList.
 * @pre newSize is sufficient for this List to hold the last Customer currently
 *      in this List.
 * @post The size of this CustomerList is now newSize.
 * @return true if this CustomerList could be set to newSize; false, otherwise.
 */
    void resizeList(int newSize);

}; // end class CustomerList

#endif	/* _CUSTOMERLIST_H */
