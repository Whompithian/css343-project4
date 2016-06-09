/* 
 * File:   ShowHistory.cpp
 * Author: brendan
 * 
 * Created on March 2, 2012, 4:27 PM
 */

#include <fstream>
#include "ShowHistory.h"
#include "MOVIEStore.h"


ShowHistory::ShowHistory()
{
} // end Default Constructor

ShowHistory::~ShowHistory()
{
} // end Destructor

Transaction* ShowHistory::create(ifstream& infile) const
{
    Transaction *tempTrans = NULL;
    int          tempCustID;

    infile >> tempCustID;               // get customer ID
    infile.get();                       // discard white space
    tempTrans->setCustID(tempCustID);   // set target Customer ID
    tempTrans->setMediaCode('H');       // set type of action

    return tempTrans;
} // end create(ifstream&)

Transaction* ShowHistory::copy(void) const
{
    Transaction *tempTrans = new ShowHistory;

    tempTrans->setCustID(getCustID());

    return tempTrans;
} // end copy()

bool ShowHistory::process(MOVIEStore& target) const
{
    Customer tempCust(getCustID());

    if (!target.retrieveCustomer(tempCust))     // get full Customer record
    {
        return false;
    } // end if (!target.retrieveCustomer(tempCust))
    
    tempCust.displayHistory(cout);

    return true;
} // end process(MOVIEStore&)

void ShowHistory::display(ostream& output) const
{
    // only implemented to make ShowHistory non-abstract
} // end display(ostream&)
