/*
 * @file    Drama.h
 * @brief   This class represents a drama movie. It is a type of DVD media that
 *          is categorized, or sorted, by director then title. It also allows
 *          comparison operations, as well as assignment.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _DRAMA_H
#define	_DRAMA_H

#include "DVDMedia.h"


class Drama : public DVDMedia
{
public:

    Drama();

    Drama(const string& searchKey);

    ~Drama();

    virtual bool updateSearchKey(void);

    virtual Merch* copy(void) const;

    virtual void display(void) const;

    virtual void displayLine(void) const;

    virtual DVDMedia* create(ifstream& infile) const;

    virtual DVDMedia* create(ifstream& infile, char mediaCode) const;

private:

}; // end class Drama

#endif	/* _DRAMA_H */
