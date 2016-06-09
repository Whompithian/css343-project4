/*
 * @file    MOVIEStore.cpp
 * @brief   This class represents a video rental store in the MOVIE chain of
 *          rental outlets. It is a type of rental shop that deals only with
 *          movies and it has a franchise ID number to distinguish it from
 *          outlets in the chain.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 8, 2012
 */

#include "MOVIEStore.h"


MOVIEStore::MOVIEStore(const string& newName, int customerBase,
                         int idealStock, int maxQty, int newID = 1896) :
            RentalShop(newName, customerBase, idealStock, maxQty),
            franchiseID(newID)
{
} // end Constructor

MOVIEStore::~MOVIEStore()
{
} // end Destructor

bool MOVIEStore::operator==(const MOVIEStore& rhs) const
{
    return franchiseID == rhs.franchiseID;
} // end operator==(MOVIEStore&)

int MOVIEStore::getFranchiseID(void) const
{
    return franchiseID;
} // end getFranchiseID()

void MOVIEStore::setFranchiseID(int newFranchiseID)
{
    franchiseID = newFranchiseID;
} // end setFranchiseID()
