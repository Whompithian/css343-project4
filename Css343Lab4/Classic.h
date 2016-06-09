/*
 * @file    Classic.h
 * @brief   This class represents a classic movie. It is a type of DVD media
 *          that is categorized, or sorted, by date then famous actor. It also
 *          allows comparison operations, as well as assignment.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _CLASSIC_H
#define	_CLASSIC_H

#include "DVDMedia.h"


class Classic : public DVDMedia
{
public:

    Classic();

    Classic(const string& searchKey);

    ~Classic();

    virtual bool updateSearchKey(void);

    virtual Merch* copy(void) const;

    virtual void display(void) const;

    virtual void displayLine(void) const;

    virtual DVDMedia* create(ifstream& infile) const;

    virtual DVDMedia* create(ifstream& infile, char mediaCode) const;

private:

}; // end class Classic

#endif	/* _CLASSIC_H */
