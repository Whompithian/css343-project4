/*
 * @file    KeyedItem.h
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

#ifndef _KEYEDITEM_H
#define	_KEYEDITEM_H

#include <cstdlib>
#include <string>

using namespace std;

typedef string KeyType;
typedef string ValueType;

class Merch;    // forward declaration to use Merch


class KeyedItem
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates an empty KeyedItem object.
 * @pre None.
 * @post An empty KeyedItem object exists.
 */
    KeyedItem();

/**---------------------- Constructor (Key) -----------------------------------
 * Creates a KeyedItem object with a set search key.
 * @param newKey  A search key to identify this Keyed Item.
 * @pre None.
 * @post A KeyeedItem object exists and its search key is newKey.
 */
    KeyedItem(const string& newKey);

/**---------------------- Constructor (Key / Value) ---------------------------
 * Creates a KeyedItem object with a set search key and value.
 * @param newKey  A search key to identify this Keyed Item.
 * @param newValue  A value to correspond with the search key of this Keyed
 *                  Item.
 * @pre None.
 * @post A KeyeedItem object exists, its search key is newKey, and it value is
 *       newValue.
 */
    KeyedItem(const KeyType& newKey, const ValueType& newValue);

/**---------------------- Constructor (Item) ----------------------------------
 * Creates a KeyedItem object with a set item.
 * @param newItemPtr  A pointer to a piece of Merchandise to copy into this
 *                    Keyed Item.
 * @pre None.
 * @post A KeyeedItem object exists and its item is a copy of the object that
 *       newItemPtr points to.
 */
    KeyedItem(const Merch *newItemPtr);

/**---------------------- Copy Constructor ------------------------------------
 * Creates a KeyedItem object that is a copy of another one.
 * @param orig  The Keyed Item to be copied.
 * @pre None.
 * @post A KeyedItem object exists and it is a copy of orig.
 */
    KeyedItem(const KeyedItem& orig);

/**---------------------- Destructor ------------------------------------------
 * Deletes all elements of this Keyed Item.
 * @pre None.
 * @post The item has been deleted and its pointer set to NULL.
 */
    ~KeyedItem();

/**---------------------- operator==() ----------------------------------------
 * Compares this KeyedItem with another one for equality.
 * @param rhs  The Keyed Item to compare with this one for equality.
 * @pre None.
 * @post None.
 * @return true if this Keyed Item has the same search key as rhs; false,
 *         otherwise.
 */
    virtual bool operator==(const KeyedItem& rhs) const;

/**---------------------- operator!=() ----------------------------------------
 * Compares this KeyedItem with another one for inequality.
 * @param rhs  The Keyed Item to compare with this one for inequality.
 * @pre None.
 * @post None.
 * @return true if this Keyed Item has a different search key from rhs; false,
 *         otherwise.
 */
    virtual bool operator!=(const KeyedItem& rhs) const;

/**---------------------- operator<() -----------------------------------------
 * Determines whether the search key of this Keyed Item is less than that of
 * another.
 * @param rhs  The Keyed Item to compare with this one.
 * @pre None.
 * @post None.
 * @return true if this Keyed Item has a smaller search key than rhs; false,
 *         otherwise.
 */
    virtual bool operator<(const KeyedItem& rhs) const;

/**---------------------- operator>() -----------------------------------------
 * Determines whether the search key of this Keyed Item is greater than that of
 * another.
 * @param rhs  The Keyed Item to compare with this one.
 * @pre None.
 * @post None.
 * @return true if this Keyed Item has a larger search key than rhs; false,
 *         otherwise.
 */
    virtual bool operator>(const KeyedItem& rhs) const;

/**---------------------- operator<=() ----------------------------------------
 * Determines whether the search key of this Keyed Item is not greater than
 * that of another.
 * @param rhs  The Keyed Item to compare with this one.
 * @pre None.
 * @post None.
 * @return true if this Keyed Item does not have a larger search key than rhs;
 *         false, otherwise.
 */
    virtual bool operator<=(const KeyedItem& rhs) const;

/**---------------------- operator>=() ----------------------------------------
 * Determines whether the search key of this Keyed Item is not less than that
 * of another.
 * @param rhs  The Keyed Item to compare with this one.
 * @pre None.
 * @post None.
 * @return true if this Keyed Item does not have a smaller search key than rhs;
 *         false, otherwise.
 */
    virtual bool operator>=(const KeyedItem& rhs) const;

/**---------------------- getKey() --------------------------------------------
 * Gets the search key of this Keyed Item.
 * @pre None.
 * @post None.
 * @return A (presumably) unique key value to identify this item.
 */
    KeyType getKey() const;

/**---------------------- setKey() --------------------------------------------
 * Sets the key of this Keyed Item.
 * @parm newKey  The new key value to use when sorting this Keyed Item.
 * @pre None.
 * @post The search key for this Keyed Item is now newKey.
 * @return true if the new key is acceptable; false, otherwise.
 */
    bool setKey(const KeyType& newKey);

/**---------------------- getValue() ------------------------------------------
 * Gets the value of this Keyed Item.
 * @pre This item has a value to complement its search key.
 * @post None.
 * @return A value to match the search key of this Keyed Item.
 */
    ValueType getValue() const;

/**---------------------- setValue() ------------------------------------------
 * Sets the value of this Keyed Item.
 * @pre None.
 * @post The value for this Keyed Item is now newValue.
 */
    void setValue(const ValueType& newValue);

/**---------------------- getItem() -------------------------------------------
 * Provides a pointer to a copy of the Merchandise pointed to by this Keyed
 * Item.
 * @pre None.
 * @post None.
 * @return A Merch pointer to a new piece of Merchandise that is a copy of the
 *         one held by this Keyed Item.
 */
    Merch* getItem(void) const;

private:

    Merch     *itemPtr;     // pointer to some piece of merchandise
    KeyType    searchKey;   // searchable key for this item
    ValueType  value;       // some value to match the search key

}; // end class KeyedItem


#endif	/* _KEYEDITEM_H */
