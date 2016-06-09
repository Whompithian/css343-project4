/*
 * @file    DVDMedia.h
 * @brief   This class represents a digital versatile disc, which would usually
 *          hold a movie or other intellectual properties. This DVD is a type
 *          of merchandise that keeps track of the quantity that a shop keeps
 *          in stock and how many it currently has on hand. It also introduces
 *          a method for updating its ancestor's search key according to rules
 *          that should be defined in a derived class.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _DVDMEDIA_H
#define	_DVDMEDIA_H

#include "Merch.h"


class DVDMedia : public Merch
{
public:

    DVDMedia();

    DVDMedia(const string& searchKey);

    DVDMedia(const KeyType& newKey, const KeyType& newValue,
               int stock, int onHand);

    ~DVDMedia();

    virtual DVDMedia* create(ifstream& infile) const = 0;

    virtual DVDMedia* create(ifstream& infile, char mediaCode) const = 0;

private:

}; // end class DVDMedia

#endif	/* _DVDMEDIA_H */
