/*
 * @file    Comedy.h
 * @brief   This class represents a comedy movie. It is a type of DVD media
 *          that is categorized, or sorted, by title then date. It also allows
 *          comparison operations, as well as assignment.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _COMEDY_H
#define	_COMEDY_H

#include "DVDMedia.h"


class Comedy : public DVDMedia
{
public:

    Comedy();

    Comedy(const string& searchKey);

    ~Comedy();

    virtual bool updateSearchKey(void);

    virtual Merch* copy(void) const;

    virtual void display(void) const;

    virtual void displayLine(void) const;

    virtual DVDMedia* create(ifstream& infile) const;

    virtual DVDMedia* create(ifstream& infile, char mediaCode) const;

private:

}; // end class Comedy

#endif	/* _COMEDY_H */
