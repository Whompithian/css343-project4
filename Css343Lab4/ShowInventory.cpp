/* 
 * File:   ShowInventory.cpp
 * Author: brendan
 * 
 * Created on March 2, 2012, 4:27 PM
 */
#include <fstream>
#include "ShowInventory.h"
#include "MOVIEStore.h"


ShowInventory::ShowInventory()
{
} // end Default Constructor

ShowInventory::~ShowInventory()
{
} // end Destructor

Transaction* ShowInventory::create(ifstream& infile) const
{
    Transaction *tempTrans = new ShowInventory;

    tempTrans->setMediaCode('S');       // set type of action

    return tempTrans;
} // end create(ifstream&)

Transaction* ShowInventory::copy(void) const
{
    return new ShowInventory;   // data members not used for ShowInventory
} // end copy()

bool ShowInventory::process(MOVIEStore& target) const
{
    target.showInventory();     // display target's Inventory

    return true;
} // end process(MOVIEStore&)

void ShowInventory::display(ostream& output) const
{
    // only implemented to make ShowInventory non-abstract
} // end display(ostream&)
