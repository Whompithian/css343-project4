/*
 * @file    Business.cpp
 * @brief   This class represents a business that deals with customers. A
 *          business has a name and a list of customers. Customers may be added
 *          to or removed from the list.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "Business.h"


Business::Business(const string& newName = "MOVIE", int customerBase = 10000) :
                   name(newName), allCustomers(customerBase)
{
} // end Constructor

Business::~Business()
{
} // end Destructor

string Business::getName(void) const
{
    return name;
} // end getName()

void Business::setName(const string& newName)
{
    name = newName;
} // end setName(string&)

int Business::getListSize(void) const
{
    return allCustomers.getListSize();
} // end getListSize()

bool Business::setListSize(int newSize)
{
    return allCustomers.setListSize(newSize);
} // end setListSize(int)

bool Business::addCustomer(const Customer& newCustomer)
{
    return allCustomers.addCustomer(newCustomer);
} // end addCustomer(Customer&)

bool Business::updateCustomer(const Customer& customer)
{
    return allCustomers.updateCustomer(customer);
} // end updateCustomer(Customer&)

bool Business::removeCustomer(Customer& customer)
{
    return allCustomers.removeCustomer(customer);
} // end removeCustomer(Customer&)

bool Business::retrieveCustomer(Customer& customer) const
{
    return allCustomers.retrieveCustomer(customer);
} // end retrieveCustomer(Customer&)

void Business::emptyCustomerList(void)
{
    allCustomers.emptyList();
} // end emptyCustomerList()
