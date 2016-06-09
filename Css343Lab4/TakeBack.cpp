/* 
 * File:   TakeBack.cpp
 * Author: brendan
 * 
 * Created on February 24, 2012, 3:11 PM
 */

#include "TakeBack.h"
#include "DVDFactory.h"
#include "DVDMedia.h"
#include "MOVIEStore.h"

TakeBack::TakeBack()
{
} // end Default Constructor

TakeBack::~TakeBack()
{
}

Transaction* TakeBack::create(ifstream& infile) const
{
    DVDFactory   DVDMaker;
    Transaction *tempTrans = NULL;
    Merch       *tempMerch = NULL;
    string       garbage;       // to discard bad line from infile
    char         tempMediaCode, genreCode;
    int          tempCustID;

    infile >> tempCustID;       // get customer ID
    infile >> tempMediaCode;    // get next character (media code)
    infile >> genreCode;        // get next character (genre code)
    infile.get();               // discard white space

    if (tempMediaCode == 'D')   // D is only valid media type
    {
        // build Merchandise and add it to new Transaction
        tempMerch = DVDMaker.buildMovie(genreCode, infile, tempMediaCode);
        tempTrans->setItem(tempMerch);              // add item to Transaction
        tempTrans->setMediaCode('R');               // set type of action
        tempTrans->setCustID(tempCustID);           // set target Customer ID
    }
    else    // invalid input; ignore rest of line
    {
        cout << "ERROR: " << tempMediaCode << " not a recognized media type."
             << endl;
        getline(infile, garbage);       // discard rest of line
    } // end if (tempMediaCode == 'D')

    return tempTrans;
} // end create(ifstream&)

Transaction* TakeBack::copy(void) const
{
    Transaction *tempTrans = new TakeBack;

    // copy each data member
    tempTrans->setMediaCode(getMediaCode());
    tempTrans->setCustID(getCustID());
    tempTrans->setItem(getItem());

    return tempTrans;
} // end copy()

bool TakeBack::process(MOVIEStore& target) const
{
    Merch *tempMerch = getItem();
    Customer tempCust(getCustID());

    if (!target.retrieveItem(tempMerch))    // tempMerch updated during check
    {
        return false;
    } // end if (!target.findItem(tempMerch))

    target.retrieveCustomer(tempCust);      // get full Customer record

    // ensure stock can be increased
    if (!tempMerch->setOnHandQty(tempMerch->getOnHandQty() + 1) ||
            !tempCust.isBorrowing(tempMerch))
    {
        return false;   // item is not being borrowed
    } // end if (tempMerch->setOnHandQty(...) ...)

    // room in stock for item and Customer is renting it
    target.updateItem(tempMerch);       // add one back to Inventory
    tempCust.newTransaction(this);      // add this Transaction to History
    target.updateCustomer(tempCust);    // update target's Customer List

    delete tempMerch;
    tempMerch = NULL;

    return true;
} // end process(MOVIEStore&)

void TakeBack::display(ostream& output) const
{
    Merch *tempMerch = getItem();

    if (tempMerch != NULL)          // there is an item
    {
        cout << "DVD Borrow  ";     // type of Transaction
        tempMerch->display();       // Merchandise information
        cout << endl;
    } // end if (tempMerch != NULL)
} // end display(ostream&)
