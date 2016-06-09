/*
 * @file    Lab4Manager.cpp
 * @brief   This class builds and acts on a MOVIE store. It reads in two files,
 *          tokenizes them, and constructs an inventory and customer database
 *          for the store. It then reads another file, tokenizes it, and
 *          performs a set of described actions and lookups within the store.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "Lab4Manager.h"
#include "DVDFactory.h"
#include "DVDMedia.h"
#include "TransFactory.h"


Lab4Manager::Lab4Manager() : scarecrow("MOVIE", 10000, 47, 10, 1896)
{
} // end Default Constructor

Lab4Manager::~Lab4Manager()
{
} // end Destructor

void Lab4Manager::buildInventory(const char* filename)
{
    DVDFactory  DVDMaker;
    KeyedItem   searchKey;
    DVDMedia   *tempPtr = NULL;
    ifstream    infile(filename);
    string      director, title;
    char        genreCode;

    if (!infile)    // nothing to read
    {
        cout << "ERROR: Movies file could not be opened." << endl;
        return;
    } // end if (!infile)
    
    infile >> genreCode;    // look for first genre code character

    for (;;)    // go until finished
    {
        if (infile.eof())   // done reading input
        {
            return;
        } // end if (infile.eof())

        infile.get();                       // discard white space
        getline(infile, director, ',');     // get name of director

        infile.get();                       // discard white space
        getline(infile, title, ',');        // get title of movie

        infile.get();                       // discard white space

        // pass file to DVD Factory to get proper DVD movie
        tempPtr = DVDMaker.buildMovie(genreCode, infile);

        if (tempPtr != NULL)    // there is a movie to work with
        {
            if (searchKey.setKey("Director"))   // director field can be set
            {
                searchKey.setValue(director);
            } // end if (searchKey.setKey("Director"))

            tempPtr->setField(searchKey);       // set the director field

            if (searchKey.setKey("Title"))      // title field can be set
            {
                searchKey.setValue(title);
            } // end if (searchKey.setKey("Title"))

            tempPtr->setField(searchKey);   // set the title field
            tempPtr->setStockQty(10);       // default stock quantity
            tempPtr->setOnHandQty(10);      // default available quantity
            tempPtr->updateSearchKey();     // ensure search key is valid

            scarecrow.addItem(tempPtr);     // copy new item into store

            delete tempPtr;     // should be no other references to tempPtr
            tempPtr = NULL;
        }
        else
        {
            cout << "ERROR: " << genreCode << " is not a recognized genre."
                 << endl;
        } // if (tempPtr != NULL)

        infile >> genreCode;    // look for next genre code character
    } // end for (;;)
} // end buildInventory(char*)

void Lab4Manager::buildCustomers(const char* filename)
{
    KeyedItem  searchKey;
    Customer   tempCust;
    ifstream   infile(filename);
    string     nameFirst, nameLast;
    int        custID;

    if (!infile)    // nothing to read
    {
        cout << "ERROR: Customers file could not be opened." << endl;
        return;
    } // end if (!infile)

    infile >> custID;   // look for first Customer ID

    for (;;)    // go until finished
    {
        if (infile.eof())   // done reading input
        {
            return;
        } // end if (infile.eof())

        if (custID >= 0 && custID < 10000)  // valid range for Customer ID
        {
            tempCust.setID(custID);

            infile >> nameLast >> nameFirst;

            if (searchKey.setKey("First Name"))     // name field can be set
            {
                searchKey.setValue(nameFirst);
            }

            tempCust.setField(searchKey);           // set name field

            if (searchKey.setKey("Last Name"))      // name field can be set
            {
                searchKey.setValue(nameLast);
            }

            tempCust.setField(searchKey);           // set name field

            scarecrow.addCustomer(tempCust);        // add customer to store
        }
        else
        {
            cout << "ERROR: " << custID << " is not a valid customer ID."
                 << endl;
        } // end if (uniqueID >= 0 && uniqueID < 10000)

        infile >> custID;   // look for next Customer ID
    } // end for (;;)
} // end buildCustomers(char*)

void Lab4Manager::buildCommands(const char* filename)
{
    TransFactory  transMaker;
    Transaction  *tempTrans;
    ifstream      infile(filename);
    char          commandCode;

    if (!infile)    // nothing to read
    {
        cout << "ERROR: Commands file could not be opened." << endl;
        return;
    } // end if (!infile)

    infile >> commandCode;  // look for first command code character

    for (;;)
    {
        if (infile.eof())   // done reading input
        {
            return;
        } // end if (infile.eof())

        // discard white space and create a new Transaction from infile
        infile.get();
        tempTrans = transMaker.buildAction(commandCode, infile);

        if (tempTrans != NULL)    // there is a Transaction to work with
        {
            tempTrans->process(scarecrow);  // Transaction decides what to do
        }
        else
        {
            cout << "ERROR: " << commandCode << " is not a recognized command."
                 << endl;
        } // end if (tempTrans != NULL)

        infile >> commandCode;  // look for next command code character
    } // end for (;;)
} // end buildCommands(char*)
