/*
 * @file    Transaction.cpp
 * @brief   This class represents a retail transaction. It stores a Merch
 *          object as a record of the merchandise involved in the transaction.
 *          A transaction is abstract and needs to be extended to achieve the
 *          characteristics of specific types of transactions.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "Transaction.h"
#include "Merch.h"
#include "MOVIEStore.h"

Transaction::Transaction() : item(NULL), mediaCode('A'), custID(-1)
{
} // end Default Constructor

Transaction::Transaction(Merch *newItem) :
                    item(NULL), mediaCode('A'), custID(-1)
{
    if (newItem != NULL)    // newItem must be copied
    {
        item = newItem->copy();
    } // end if (newItem != NULL)
} // end Constructor

Transaction::~Transaction()
{
    if (item != NULL)       // item must be destroyed
    {
        delete item;
        item = NULL;
    } // end if (item != NULL)
} // end Destructor

Merch* Transaction::getItem(void) const
{
    if (item == NULL)   // no item to return
    {
        return NULL;
    } // end if (item == NULL)

    return item->copy();
} // end getItem()

void Transaction::setItem(const Merch *newItem)
{
    if (item != NULL)       // current item must be destroyed
    {
        delete item;
        item = NULL;
    } // end if (item != NULL)

    if (newItem != NULL)    // newItem must be copied
    {
        item = newItem->copy();
    } // end if (newItem != NULL)
} // end setItem(Merch*)

char Transaction::getMediaCode(void) const
{
    return mediaCode;
} // end getMediaCode()

void Transaction::setMediaCode(char newMediaCode)
{
    mediaCode = newMediaCode;
} // end setMediaCode

int Transaction::getCustID(void) const
{
    return custID;
} // end getCustID()

void Transaction::setCustID(int newCustID)
{
    custID = newCustID;
} // end setCustID()
