/*
 * @file    TransFactory.cpp
 * @brief   This class produces objects derived from a transaction. It holds a
 *          hash table of transaction pointers, with regognized objects at
 *          determined indexes. To get an instance of a desired object, a
 *          character representing that object is hashed to the index of the
 *          object and an ifstream is passed with information to initialize the
 *          object. NULL is returned if the provided character does not hash to
 *          the location of a known object. This factory is static and its
 *          instances are immutable.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "TransFactory.h"
#include "Borrow.h"
#include "ShowHistory.h"
#include "ShowInventory.h"
#include "TakeBack.h"

TransFactory::TransFactory()
{
    for (int i = 0; i < ACTIONSIZE; ++i)
    {
        factory[i] = NULL;  // initialize all elements
    } // end for (i < ACTIONSIZE)

    // set known elements to their proper objects
    factory[hashIndex('B')] = new Borrow;
    factory[hashIndex('H')] = new ShowHistory;
    factory[hashIndex('R')] = new TakeBack;
    factory[hashIndex('S')] = new ShowInventory;
} // end Defualt Constructor

TransFactory::TransFactory(const TransFactory& orig)
{
    TransFactory();     // make new default Factory
} // end Copy Constructor

TransFactory::~TransFactory()
{
} // end Destructor

void TransFactory::destroyFactory(void)
{
    for (int i = 0; i < ACTIONSIZE; ++i)
    {
        if (factory[i] != NULL)     // an object exists in the hash table
        {
            delete factory[i];      // free memory
            factory[i] = NULL;      // cover ourselves
        } // end if (factory[i] != NULL)
    } // end for (i < ACTIONSIZE)

    delete[] factory;   // ensure hash table is cleared cleanly
} // end destroyFactory()

Transaction* TransFactory::buildAction(char actionCode, ifstream& infile) const
{
    if (factory[hashIndex(actionCode)] == NULL)     // no object here
    {
        return NULL;
    } // end if (factory[hash(actionCode)] == NULL)

    // create a new object and return a pointer to it
    return factory[hashIndex(actionCode)]->create(infile);
} // end buildMovie(char, ifstream&)

int TransFactory::hashIndex(char basis) const
{
    return (basis - 'A') % ACTIONSIZE;  // index is offset from 'A' character
} // end hashIndex(char)
