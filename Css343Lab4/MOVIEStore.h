/*
 * @file    MOVIEStore.h
 * @brief   This class represents a video rental store in the MOVIE chain of
 *          rental outlets. It is a type of rental shop that deals only with
 *          movies and it has a franchise ID number to distinguish it from
 *          outlets in the chain.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 8, 2012
 */

#ifndef _MOVIESTORE_H
#define	_MOVIESTORE_H

#include "RentalShop.h"


class MOVIEStore : public RentalShop
{
public:

/**---------------------- Constructor -----------------------------------------
 * Creates a MOVIEStore object with a set of specified attributes.
 * @param name  Name to identify this franchise.
 * @param customerBase  Expected number of Customers this franchise will have.
 * @param idealStock  The expected number of unique items this franchise will
 *                     stock. Must be positive; should be prime.
 * @param maxQty  Maximum number of each item to stock. Must be positive.
 * @param newID  Franshice ID number for a specifice store location.
 * @pre None.
 * @post A MOVIEStore object exists with name newName, Customer List size of
 *       customerBase, and franchide ID number of newID.
 */
    MOVIEStore(const string& newName, int customerBase,
                 int idealStock, int maxQty, int newID);

    ~MOVIEStore();

/**---------------------- == Equality Operator --------------------------------
 * Tests this MOVIStore for equality with another one. Two MOVIEStores are
 * considered equal if they have the same franchise ID number.
 * @pre None.
 * @post None.
 * @return true if the franchise ID number of this MOVIEStore matches the
 *         franchise ID number of the rhs MOVIEStore; false, otherwise.
 */
    bool operator==(const MOVIEStore& rhs) const;

/**---------------------- getID() ---------------------------------------------
 * Retrieves the franchise ID number of this MOVIE location.
 * @pre None.
 * @post None.
 * @return The franchise ID number of this MOVIE location.
 */
    int getFranchiseID(void) const;

/**---------------------- setID() ---------------------------------------------
 * Sets the franchise ID number of this MOVIE location.
 * @param newFranchiseID  New ID number to identify this franchise location.
 * @pre None.
 * @post The franchise ID number of this store is now newFranchiseID.
 */
    void setFranchiseID(int newFranchiseID);

private:

    int franchiseID;    // franchise number for this branch of the chain

}; // end class MOVIEStore

#endif	/* _MOVIESTORE_H */
