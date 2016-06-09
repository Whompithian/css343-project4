/*
 * @file    DVDMedia.cpp
 * @brief   This class represents a digital versatile disc, which would usually
 *          hold a movie or other intellectual properties. This DVD is a type
 *          of merchandise that keeps track of the quantity that a shop keeps
 *          in stock and how many it currently has on hand. It also introduces
 *          a method for updating its ancestor's search key according to rules
 *          that should be defined in a derived class.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#include "DVDMedia.h"


DVDMedia::DVDMedia()
{
} // end Default Constructor

DVDMedia::DVDMedia(const string& searchKey) : Merch(searchKey)
{
} // end Constructor (Key)

DVDMedia::DVDMedia(const KeyType& newKey, const KeyType& newValue,
                     int newStockQty, int newOnHandQty) :
             Merch(newKey, newValue, newStockQty, newOnHandQty)
{
} // end Constructor

DVDMedia::~DVDMedia()
{
} // end Destructor
