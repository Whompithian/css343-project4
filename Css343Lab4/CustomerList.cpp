/*
 * @file    CustomerList.cpp
 * @brief   This class represents the list of customers for a business. A hash
 *          table stores customers for fast insertion and retrieval. Customers
 *          are identified by a unique ID number that serves to derive an index
 *          into the hash table.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "CustomerList.h"


CustomerList::CustomerList(int sizeOfList = 10000) :
                  listSize(sizeOfList), count(0)
{
    customers = new Customer*[listSize];
} // end Constructor

CustomerList::CustomerList(const CustomerList& orig)
{
    copyList(orig);
} // end Copy Constructor

CustomerList::~CustomerList()
{
    destroyList();
} // end Destructor

void CustomerList::copyList(const CustomerList& orig)
{
    destroyList();          // ensure clean slate
    count = orig.count;
    listSize = orig.listSize;
    customers = new Customer*[listSize];

    if (!isEmpty())     // something needs to be done
    {
        for (int i = 0; i < listSize; ++i)
        {
            if (orig.customers[i] == NULL)  // avoid NULL references
            {
                customers[i] = NULL;
            }
            else
            {
                customers[i] = new Customer(*orig.customers[i]);    // copy
            } // end if (orig.customers[i] == NULL)
        } // end for (i < listSize)
    } // end if (!isEmpty())
} // end copyList(CustomerList&)

void CustomerList::destroyList(void)
{
    for (int i = 0; i < listSize; ++i)
    {
        if (customers[i] != NULL)
        {
            delete customers[i];    // delete each element
            customers[i] = NULL;    // NULL each pointer
        } // end if (customers[i] != NULL)
    } // end for (i < listSize)

    delete[] customers;     // delete pointer array
    count = 0;              // no more Customers
    listSize = 0;           // no elements in list
} // end destroyList()

int CustomerList::getListSize(void) const
{
    return listSize;
} // end getListSize()

bool CustomerList::setListSize(int newSize)
{
    bool success = newSize >= listSize;     // larger new size is less work

    if (isEmpty() && newSize > 0)   // nothing to copy, size is valid
    {
        listSize = newSize;                     // size should be good
        delete[] customers;                     // delete old pointer array
        customers = new Customer*[newSize];     // set new size
        success = true;                         // ensure exit status
    }
    else if (!success)  // Customers could be lost
    {
        for (int i = newSize; i < listSize; ++i)
        {
            if (customers[i] != NULL)   // Customer found out of new range
            {
                return false;           // refuse to resize
            } // end if (customers[i] != NULL)
        } // end for(i < listSize)

        resizeList(newSize);    // no Customers will be lost
        success = true;         // ensure exit status
    } // end if ()
    else    // new size acceptable, Customers need to be copied
    {
        resizeList(newSize);
    } // end if (isEmpty() && newSize > 0)

    return success;
} // end setListSize(int)

void CustomerList::resizeList(int newSize)
{
    Customer **newList = new Customer*[newSize];                // temp list
    int shorter = (listSize < newSize ? listSize : newSize);    // bounds check

    for (int i = 0; i < shorter; ++i)
    {
        newList[i] = customers[i];  // point new list to old element
        customers[i] = NULL;        // detach from any Customers
    } // end for (i < shorter)

    for (int i = shorter; i < newSize; ++i)
    {
        newList[i] = NULL;  // NULL remaining elements
    } // end for (i < newSize)

    listSize = newSize;     // update to new size
    customers = newList;    // transfer head to new array
    delete[] newList;       // delete temporary pointer array
} // end resizeList(int)

bool CustomerList::isEmpty(void) const
{
    return count == 0;
} // end isEmpty()

bool CustomerList::addCustomer(const Customer& newCustomer)
{
    int index = hashIndex(newCustomer);         // where to find newCustomer
    bool success = customers[index] == NULL;    // newCustomer is new to List

    if (success)
    {
        customers[index] = new Customer(newCustomer);   // store copy
        ++count;                                        // update count
    } // end if (success)

    return success;
} // end addCustomer(Customer&)

bool CustomerList::updateCustomer(const Customer& targetCustomer)
{
    int index = hashIndex(targetCustomer);      // where to find target
    bool success = customers[index] != NULL;    // target exists

    if (success)
    {
        delete customers[index];                            // remove old
        customers[index] = new Customer(targetCustomer);    // copy new
    } // end if (success)

    return success;
} // end updateCustomer()

bool CustomerList::removeCustomer(Customer& targetCustomer)
{
    int index = hashIndex(targetCustomer);      // where to find target
    bool success = customers[index] != NULL;    // target exists

    if (success)
    {
        delete customers[index];    // remove old
        customers[index] = NULL;    // NULL old element
        --count;                    // update count
    } // end if (success)

    return success;
} // end removeCustomer(Customer&)

bool CustomerList::retrieveCustomer(Customer& targetCustomer) const
{
    int index = hashIndex(targetCustomer);      // where to find target
    bool success = customers[index] != NULL;    // target exists

    if (success)
    {
        targetCustomer = *customers[index];     // copy target
    } // end if (success)

    return success;
} // end retrieveCustomer(Customer&)

void CustomerList::emptyList(void)
{
    destroyList();
} // end emptyList()

int CustomerList::hashIndex(const Customer& targetCustomer) const
{
    return targetCustomer.getID() % listSize;
} // end hashIndex(Customer&)
