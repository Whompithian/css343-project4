/*
 * @file    KeyedItem.cpp
 *          Addapted from:
 *          Carrano, F. M. (2007). Trees. In M. Hirsch (Ed.) "Data Abstraction
 *              & Problem Solving with C++: Walls and Mirrors" (5th ed.) p.
 *              555. Boston, MA: Pearson Education, Inc.
 * @brief   KeyedItem class for the threaded binary search tree. Only contains
 *          the search key value. Needs to be changed or subclassed to add
 *          other data elements.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "KeyedItem.h"
#include "Merch.h"


KeyedItem::KeyedItem() :
             itemPtr(NULL), searchKey(""), value("")
{
} // end Default Constructor

KeyedItem::KeyedItem(const KeyType& newSearchKey) :
             itemPtr(NULL), searchKey(newSearchKey), value("")
{
} // end Constructor (Key)

KeyedItem::KeyedItem(const KeyType& newSearchKey, const ValueType& newValue) :
           itemPtr(NULL), searchKey(newSearchKey), value(newValue)
{
} // end Constructor (Key / Value)

KeyedItem::KeyedItem(const Merch *newItemPtr) :
             itemPtr(NULL), searchKey(""), value("")
{
    if (newItemPtr != NULL)
    {
        itemPtr = newItemPtr->copy();
        searchKey = itemPtr->getSearchKey();
    } // end if (newItemPtr != NULL)
} // end Constructor (Item)

KeyedItem::KeyedItem(const KeyedItem& orig) :
             itemPtr(NULL), searchKey(orig.searchKey), value(orig.value)
{
    if (orig.itemPtr != NULL)
    {
        itemPtr = orig.itemPtr->copy();
    } // end if (orig.itemPtr != NULL)
} // end Copy Constructor

KeyedItem::~KeyedItem()
{
    if (itemPtr != NULL)
    {
        delete itemPtr;
        itemPtr = NULL;
    }
} // end Destructor

bool KeyedItem::operator==(const KeyedItem& rhs) const
{
    return searchKey == rhs.searchKey;
} // end operator==(KeyedItem&)

bool KeyedItem::operator!=(const KeyedItem& rhs) const
{
    return !(*this == rhs);
} // end operator!=(KeyedItem&)

bool KeyedItem::operator<(const KeyedItem& rhs) const
{
    return searchKey < rhs.searchKey;
} // end operator<(KeyedItem&)

bool KeyedItem::operator>(const KeyedItem& rhs) const
{
    return searchKey > rhs.searchKey;
} // end operator>(KeyedItem&)

bool KeyedItem::operator<=(const KeyedItem& rhs) const
{
    return !(*this > rhs);
} // end operator<=(KeyedItem&)

bool KeyedItem::operator>=(const KeyedItem& rhs) const
{
    return !(*this < rhs);
} // end operator>=(KeyedItem&)

KeyType KeyedItem::getKey(void) const
{
    return searchKey;
} // end getKey()

bool KeyedItem::setKey(const KeyType& newSearchKey)
{
    bool success = itemPtr == NULL;

    if (success)
    {
        searchKey = newSearchKey;
    } // end if (success)

    return success;
} // end setKey(KeyType&)

ValueType KeyedItem::getValue(void) const
{
    return value;
} // end getValue()

void KeyedItem::setValue(const ValueType& newValue)
{
    value = newValue;
} // end setValue(ValueType&)

Merch* KeyedItem::getItem(void) const
{
    if (itemPtr == NULL)
    {
        return NULL;
    } // end if (itemPtr == NULL)

    return itemPtr->copy();
} // end getItem()
