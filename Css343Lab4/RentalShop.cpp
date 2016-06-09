/*
 * @file    RentalShop.cpp
 * @brief   This class represents a shop that rents items to customers. It is a
 *          type of business that deals with material goods, so it has a
 *          merchandise inventory. A rental shop may have an expected number of
 *          unique items it will hold in inventory and may have a set limit on
 *          the number of each item it will carry.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "RentalShop.h"


RentalShop::RentalShop(const string& newName, int customerBase,
                         int idealStock = 47, int maxQty = 10) :
            Business(newName, customerBase), stock(idealStock, maxQty)
{
} // end Constructor

RentalShop::~RentalShop()
{
} // end Destructor

int RentalShop::getItemQty(void) const
{
    return stock.getItemQty();
} // end getItemQty()

bool RentalShop::setItemQty(int stockSize)
{
    stock.setItemQty(stockSize);
} // end setItemQty(int)

int RentalShop::getMaxQty(void) const
{
    return stock.getMaxQty();
} // end getMaxQty()

bool RentalShop::setMaxQty(int newQty)
{
    return stock.setMaxQty(newQty);
} // end setMaxQty(int)

bool RentalShop::addItem(const Merch *newItem)
{
    return stock.addItem(newItem);
} // end addItem(Merch*)

bool RentalShop::updateItem(const Merch *item)
{
    return stock.updateItem(item);
} // end updateItem(Merch*)

bool RentalShop::removeItem(const Merch *item)
{
    return stock.removeItem(item);
} // end removeItem(Merch*)

bool RentalShop::retrieveItem(Merch *& target) const
{
    return stock.retrieveItem(target);
} // end findItem(Merch*&)

void RentalShop::showInventory(void) const
{
    stock.displayInventory();
} // end showInventory()
