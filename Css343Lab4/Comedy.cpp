/*
 * @file    Comedy.cpp
 * @brief   This class represents a comedy movie. It is a type of DVD media
 *          that is categorized, or sorted, by title then date. It also allows
 *          comparison operations, as well as assignment.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include "Comedy.h"


Comedy::Comedy()
{
    KeyedItem tempKey("Item Code");

    tempKey.setValue("Funny");
    setField(tempKey);
} // end Default Constructor

Comedy::Comedy(const string& searchKey) : DVDMedia(searchKey)
{
    KeyedItem tempKey("Item Code");

    tempKey.setValue("Funny");
    setField(tempKey);
} // end Constructor

Comedy::~Comedy()
{
} // end Destructor

bool Comedy::updateSearchKey(void)
{
    KeyedItem tempKey;
    string title, year, searchKey = "";

    try
    {
        tempKey.setKey("Title");
        getField(tempKey);
        title = tempKey.getValue();
        
        tempKey.setKey("Year");
        getField(tempKey);
        year = tempKey.getValue();

        searchKey += title;
        searchKey += " ";
        searchKey += year;

        setSearchKey(searchKey);
    }
    catch (TreeException e)
    {
        cout << "ERROR: Could not update comedy movie search string." << endl;
        return false;
    } // end try

    return true;
} // end updateSearchKey()

Merch* Comedy::copy() const
{
    Merch *tempMerch = new Comedy();
    KeyedItem tempKey("Director");

    tempMerch->setStockQty(getStockQty());
    tempMerch->setOnHandQty(getOnHandQty());
    getField(tempKey);
    tempMerch->setField(tempKey);

    tempKey.setKey("Title");
    getField(tempKey);
    tempMerch->setField(tempKey);

    tempKey.setKey("Year");
    getField(tempKey);
    tempMerch->setField(tempKey);

    tempKey.setKey("Item Code");
    tempKey.setValue("Funny");
    tempMerch->setField(tempKey);

    tempMerch->updateSearchKey();

    return tempMerch;
} // end copy()

void Comedy::display(void) const
{
    KeyedItem tempKey("Title");

    getField(tempKey);
    cout << left << tempKey.getValue().substr(0, 20);

    tempKey.setKey("Director");
    getField(tempKey);
    cout << left << tempKey.getValue().substr(0, 15);

    tempKey.setKey("Year");
    getField(tempKey);
    cout << right << setw(6) << tempKey.getValue();
} // end display()

void Comedy::displayLine(void) const
{
    cout << right << setw(2) << getStockQty() - getOnHandQty();
    cout << right << setw(5) << getOnHandQty();
    cout << "  ";
    display();
    cout << endl;
} // end displayLine()

DVDMedia* Comedy::create(ifstream& infile) const
{
    string    year;
    KeyedItem tempKey;
    Comedy   *newComedy = new Comedy;

    infile >> year;

    tempKey.setKey("Year");
    tempKey.setValue(year);

    newComedy->setField(tempKey);

    tempKey.setKey("Item Code");
    tempKey.setValue("Funny");

    newComedy->setField(tempKey);

    return newComedy;
} // end create()

DVDMedia* Comedy::create(ifstream& infile, char mediaCode) const
{
    string searchKey;

    infile.get();
    getline(infile, searchKey);

    if (mediaCode == 'D')
    {
        return new Comedy(searchKey);
    } // end if (mediaCode == 'D')

    cerr << mediaCode << " not a recognized media type.";

    return NULL;
} // end create()
