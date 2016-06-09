/*
 * @file    DVDFactory.cpp
 * @brief   This class produces objects derived from DVD media. It holds a hash
 *          table of DVD media pointers, with regognized objects at determined
 *          indexes. To get an instance of a desired object, a character
 *          representing that object is hashed to the index of the object and
 *          an ifstream is passed with information to initialize the object. A
 *          character may also be passed to specify a media type, but this
 *          functionality if not implemented. NULL is returned if the provided
 *          character does not hash to the location of a known object. This
 *          factory is static and its instances are immutable.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "DVDFactory.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

DVDFactory::DVDFactory()
{
    for (int i = 0; i < GENRESIZE; ++i)
    {
        factory[i] = NULL;  // initialize all elements
    } // end for (i < GENRESIZE)

    // set known elements to their proper objects
    factory[hashIndex('C')] = new Classic;
    factory[hashIndex('D')] = new Drama;
    factory[hashIndex('F')] = new Comedy;
} // end Default Constructor

DVDFactory::DVDFactory(const DVDFactory& orig)
{
    DVDFactory();       // make new default Factory
} // end Copy Constructor

DVDFactory::~DVDFactory()
{
    destroyFactory();
} // end Destructor

void DVDFactory::destroyFactory(void)
{
    for (int i = 0; i < GENRESIZE; ++i)
    {
        if (factory[i] != NULL)     // an object exists in the hash table
        {
            delete factory[i];      // free memory
            factory[i] = NULL;      // cover ourselves
        } // end if (factory[i] != NULL)
    } // end for (i < GENRESIZE)

    delete[] factory;   // ensure hash table is cleared cleanly
} // end destroyFactory()

DVDMedia* DVDFactory::buildMovie(char genreCode, ifstream& infile) const
{
    if (factory[hashIndex(genreCode)] == NULL)  // no object here
    {
        return NULL;
    } // end if (factory[hash(genre)] == NULL)

    // create a new object and return a pointer to it
    return factory[hashIndex(genreCode)]->create(infile);
} // end buildMovie(char, ifstream&)

DVDMedia* DVDFactory::buildMovie(char genreCode, ifstream& infile,
                                 char mediaCode) const
{
    if (factory[hashIndex(genreCode)] == NULL)  // no object here
    {
        return NULL;
    } // end if (factory[hash(genreCode)] == NULL)

    // create a new object and return a pointer to it
    return factory[hashIndex(genreCode)]->create(infile, mediaCode);
} // end buildMovie(char, ifstream&, char)

int DVDFactory::hashIndex(char basis) const
{
    return (basis - 'A') % GENRESIZE;   // index is offset from 'A' character
} // end hashIndex(char)
