/*
 * @file    Merch.h
 * @brief   This class represents some merchandise that may be carried in a
 *          shop. Merchandise maintains a set of attributes about itself, in
 *          key-value pairs. In order to be sortable, any merchandise in a
 *          collection must contain at least one mutual key by which the items
 *          may be sorted.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _MERCH_H
#define	_MERCH_H

#include "ThreadedBST.h"


class Merch
{
public:

    Merch();

    Merch(const string& searchKey);

    Merch(const KeyType& newKey, const KeyType& newValue,
            int newStockQty, int newOnHandQty);

    ~Merch();

    virtual bool updateSearchKey(void) = 0;

    virtual Merch* copy(void) const = 0;

    virtual void display(void) const = 0;

    virtual void displayLine(void) const = 0;

    string getSearchKey(void) const;

    void setSearchKey(const string& newSearchKey);

/**---------------------- getStockQty() ---------------------------------------
 * Retrieves the quantity of each type of merchandise this Inventory can hold.
 * @pre None.
 * @post None.
 * @return The quantity of each type of merchandise this Inventory can hold.
 */
    int getStockQty(void) const;

/**---------------------- setStockQty() ---------------------------------------
 * Sets the quantity of each type of merchandise this Inventory can hold.
 * @param newQty  The new maximum quantity of each merchandise; must be
 *                positive.
 * @pre None.
 * @post This Inventory can now hold newQty of each type of merchandise.
 */
    bool setStockQty(int newStockQty);

/**---------------------- getOnHandQty() --------------------------------------
 * Retrieves the quantity of each type of merchandise this Inventory can hold.
 * @pre None.
 * @post None.
 * @return The quantity of each type of merchandise this Inventory can hold.
 */
    int getOnHandQty(void) const;

/**---------------------- setOnHandQty() --------------------------------------
 * Sets the quantity of each type of merchandise this Inventory can hold.
 * @param newQty  The new maximum quantity of each merchandise; must be
 *                positive.
 * @pre None.
 * @post This Inventory can now hold newQty of each type of merchandise.
 */
    bool setOnHandQty(int newOnHandQty);

/**---------------------- getField() ------------------------------------------
 * Retrieves the value of a specified field of this Merch's information.
 * @param target  A key-value pair whose key matches a key in this Merch's
 *                information. Will be updated with the corresponding value, if
 *                found.
 * @pre This Merchandise has a value in the specified field.
 * @post target contains the located value.
 * @return true if this Merch has a value in the specified field and target was
 *         updated with that value; false, otherwise.
 */
    bool getField(KeyedItem& target) const;

/**---------------------- setField() ------------------------------------------
 * Sets the value of a specified field of this Merch's information to a
 * specified value. If the field does not exist, it is created. Once a field
 * has been added, its key becomes permanent within the Merchandise.
 * @param newValue  A key-value pair whose value will be applied to its key in
 *                  this Merch's information.
 * @pre None.
 * @post This Customer contains a field whose key and value are the same as
 *       those of newValue.
 */
    void setField(const KeyedItem& newValue);

private:

    string      searchKey;  // search key for sorting
    int         stockQty;   // quantity of this item that is normally stocked
    int         onHandQty;  // quantity of this item that is available
    ThreadedBST info;       // collection of attributes in key-value pairs

}; // end class Merch

#endif	/* _MERCH_H */
