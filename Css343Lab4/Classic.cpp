/*
 * @file    Classic.cpp
 * @brief   This class represents a classic movie. It is a type of DVD media
 *          that is categorized, or sorted, by date then famous actor. It also
 *          allows comparison operations, as well as assignment.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include "Classic.h"


Classic::Classic()
{
    KeyedItem tempKey("Item Code");

    tempKey.setValue("Classic");
    setField(tempKey);
} // end Default Constructor

Classic::Classic(const string& searchKey) : DVDMedia(searchKey)
{
    KeyedItem tempKey("Item Code");

    tempKey.setValue("Classic");
    setField(tempKey);
} // end Constructor

Classic::~Classic()
{
} // end Destructor

bool Classic::updateSearchKey(void)
{
    KeyedItem tempKey;
    string year, month, majorActor, searchKey = "";

    try
    {
        tempKey.setKey("Year");
        getField(tempKey);
        year = tempKey.getValue();

        tempKey.setKey("Month");
        getField(tempKey);
        month = tempKey.getValue();

        tempKey.setKey("Major Actor");
        getField(tempKey);
        majorActor = tempKey.getValue();

        searchKey += year;
        searchKey += " ";

        if (month.length() < 2)     // single digit month
        {
            searchKey += "0";       // leading zero for sorting
        } // end if (month.length() < 2)

        searchKey += month;
        searchKey += ", ";
        searchKey += majorActor;

        setSearchKey(searchKey);
    }
    catch (TreeException e)
    {
        cout << "ERROR: Could not update classic movie search string." << endl;
        return false;
    } // end try

    return true;
} // end updateSearchKey()

Merch* Classic::copy(void) const
{
    Merch *tempMerch = new Classic();
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

    tempKey.setKey("Month");
    getField(tempKey);
    tempMerch->setField(tempKey);

    tempKey.setKey("Major Actor");
    getField(tempKey);
    tempMerch->setField(tempKey);

    tempKey.setKey("Item Code");
    tempKey.setValue("Classic");
    tempMerch->setField(tempKey);

    tempMerch->updateSearchKey();

    return tempMerch;
} // end copy()

void Classic::display(void) const
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

    tempKey.setKey("Month");
    getField(tempKey);
    cout << right << setw(3) << tempKey.getValue();

    tempKey.setKey("Major Actor");
    getField(tempKey);
    cout << left << tempKey.getValue().substr(0, 15);
} // end display()

void Classic::displayLine(void) const
{
    cout << right << setw(2) << getStockQty() - getOnHandQty();
    cout << right << setw(5) << getOnHandQty();
    cout << "  ";
    display();
    cout << endl;
} // end displayLine()

DVDMedia* Classic::create(ifstream& infile) const
{
    string    month, year, actorFirst, actorLast;
    KeyedItem tempKey;
    Classic  *newClassic = new Classic;

    infile >> actorFirst >> actorLast;  // input star's name
    infile >> month >> year;            // input month and year;

    if (tempKey.setKey("Major Actor"))
    {
        tempKey.setValue(actorFirst + " " + actorLast);
    } // end if (key.setKey("Major Actor"))

    newClassic->setField(tempKey);

    if (tempKey.setKey("Month"))
    {
        tempKey.setValue(month);
    } // end if (tempKey.setKey("Month"))

    newClassic->setField(tempKey);

    tempKey.setKey("Year");
    tempKey.setValue(year);
    
    newClassic->setField(tempKey);

    tempKey.setKey("Item Code");
    tempKey.setValue("Classic");

    newClassic->setField(tempKey);

    return newClassic;
} // end create()

DVDMedia* Classic::create(ifstream& infile, char mediaCode) const
{
    string searchKey, textMonth;
    int month;

    infile >> month;
    infile.get();
    getline(infile, searchKey);

    if (mediaCode == 'D')
    {
        if (month < 10)
        {
            textMonth.push_back('0');
            textMonth.push_back('0' + month);
        }
        else
        {
            textMonth.push_back('1');
            textMonth.push_back('0' + month % 10);
        } // end if (month < 10)

        textMonth.push_back(' ');
        searchKey.insert(5, textMonth);

        return new Classic(searchKey);
    } // end if (mediaCode == 'D')

    cerr << mediaCode << " not a recognized media type.";

    return NULL;
} // end create()
