/*
 * @file    Drama.cpp
 * @brief   This class represents a drama movie. It is a type of DVD media that
 *          is categorized, or sorted, by director then title. It also allows
 *          comparison operations, as well as assignment.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include "Drama.h"

Drama::Drama()
{
    KeyedItem tempKey("Item Code");

    tempKey.setValue("Drama");
    setField(tempKey);
} // end Default Constructor

Drama::Drama(const string& searchKey) : DVDMedia(searchKey)
{
    KeyedItem tempKey("Item Code");

    tempKey.setValue("Drama");
    setField(tempKey);
} // end Constructor

Drama::~Drama()
{
} // end Destructor

bool Drama::updateSearchKey(void)
{
    KeyedItem tempKey;
    string director, title, searchKey = "";

    try
    {
        tempKey.setKey("Director");
        getField(tempKey);
        director = tempKey.getValue();

        tempKey.setKey("Title");
        getField(tempKey);
        title = tempKey.getValue();

        searchKey += director;
        searchKey += ", ";
        searchKey += title;

        setSearchKey(searchKey);
    }
    catch (TreeException e)
    {
        cout << "ERROR: Could not update comedy movie search string." << endl;
        return false;
    } // end try

    return true;
} // end updateSearchKey()

Merch* Drama::copy() const
{
    Merch *tempMerch = new Drama();
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
    tempKey.setValue("Drama");
    tempMerch->setField(tempKey);

    tempMerch->updateSearchKey();

    return tempMerch;
} // end copy()

void Drama::display(void) const
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

void Drama::displayLine(void) const
{
    cout << right << setw(2) << getStockQty() - getOnHandQty();
    cout << right << setw(5) << getOnHandQty();
    cout << "  ";
    display();
    cout << endl;
} // end displayLine()

DVDMedia* Drama::create(ifstream& infile) const
{
    KeyedItem tempKey;
    Drama    *newDrama = new Drama;
    string    year;

    infile >> year;

    tempKey.setKey("Year");
    tempKey.setValue(year);

    newDrama->setField(tempKey);

    tempKey.setKey("Item Code");
    tempKey.setValue("Drama");

    newDrama->setField(tempKey);

    return newDrama;
} // end create()

DVDMedia* Drama::create(ifstream& infile, char mediaCode) const
{
    string searchKey;

    infile.get();
    getline(infile, searchKey);

    if (mediaCode == 'D')
    {
        return new Drama(searchKey);
    } // end if (mediaCode == 'D')

    cerr << mediaCode << " not a recognized media type.";

    return NULL;
} // end create()
