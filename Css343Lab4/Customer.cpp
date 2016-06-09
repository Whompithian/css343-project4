/*
 * @file    Customer.cpp
 * @brief   This class represents a single customer of a business. The customer
 *          has a an ID number that is unique within a single business. It also
 *          has a history of transactions with the business and a set of
 *          identifiers, chosen by the business, stored in key-value pairs.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "Customer.h"


Customer::Customer() : customerID(0)
{
} // end Default Constructor

Customer::Customer(int uniqueID = 0) : customerID(uniqueID)
{
} // end Constructor

Customer::~Customer()
{
} // end Destructor

bool Customer::operator==(const Customer& rhs) const
{
    return customerID == rhs.customerID;
} // end operator==(Customer&)

bool Customer::operator!=(const Customer& rhs) const
{
    return !(*this == rhs);
} // end operator!-(Customer&)

int Customer::getID(void) const
{
    return customerID;
} // end getID()

void Customer::setID(int newID)
{
    customerID = newID;
} // end setID(int)

bool Customer::getField(KeyedItem& target) const
{
    bool success;

    try
    {
        info.searchTreeRetrive(target.getKey(), target);
        success = true;     // field found and target parameter updated
    }
    catch (TreeException e)
    {
        cout << "ERROR: " << target.getKey() << " not found in customer with"
             << " ID number " << customerID << endl;
        success = false;    // field not found
    } // end try

    return success;
} // end getField(KeyedItem&)

void Customer::setField(const KeyedItem& newValue)
{
    try
    {
        info.searchTreeDelete(newValue.getKey());
    }
    catch (TreeException e)
    {
    } // end try

    try
    {
        info.searchTreeInsert(newValue);
    }
    catch (TreeException e)
    {
        cout << "ERROR: " << newValue.getKey() << " coult not be inserted into"
             << " customer with ID number " << customerID << endl;
    } // end try
} // end setField(KeyedItem&)

void Customer::displayInfo(ostream& output) const
{
    ThreadedBST::Inorder index(info.begin());

    while(index != info.end())
    {
        output << (*index).getKey() << ' ' << (*index).getValue() << endl;
        ++index;
    } // end while()
} // end getInfo()

bool Customer::isBorrowing(const Merch* target) const
{
    return activity.isBorrowed(target);
} // end isBorrowing(Merch*)

void Customer::newTransaction(const Transaction *latest)
{
    activity.insertItem(latest->copy());
} // end newTransaction()

Transaction* Customer::getMostRecent(void) const
{
    return activity.getLatest();
} // end getMostRecent(Transaction*)

void Customer::displayHistory(ostream& output) const
{
    KeyedItem tempKey;
    string nameFirst, nameLast;

    try
    {
        info.searchTreeRetrive("First Name", tempKey);
        nameFirst = tempKey.getValue();
        info.searchTreeRetrive("Last Name", tempKey);
        nameLast = tempKey.getValue();
    }
    catch(TreeException e)
    {
        cout << "ERROR: Could not find customer name." << endl;
    } // end try

    output << "  *** Customer ID = " << customerID << "  " << nameFirst
           << ' ' << nameLast << endl;
    activity.displayHistory(output);
} // end getHistory(ostream&)

void Customer::clearHistory(void)
{
    activity.clearHistory();
} // end clearHistory()
