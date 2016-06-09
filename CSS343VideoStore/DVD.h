/*
 * @file    DVD.h
 * @brief   This class represents a single DVD disc. This class is derived
 *          from Merch. DVD contains three member variables:
 *          director, title, date.
 *          It is assumed that no two DVD's will have the same director
 *          and title, which makes the combination of variables unique.
 *          Children of DVD include:
 *          DramaDVD, ClassicDVD, and ComedyDVD.
 * @author  Chris Grass
 * @date    February 15, 2012
 */
#include <string>
#include "merch.h"

using namespace std;

class DVD : public Merch
{
public:
/**---------------------- Default Constructor ---------------------------------
 * Creates an empty DVD object.
 * @pre None.
 * @post An empty DVD object exists.
 */
	DVD();
//--------------------------- Destructor ---------------------------------------
	virtual ~DVD();
//-------------------------- Copy Constructor ----------------------------------
	DVD(const DVD& copy);
/**----------------------------- destroyDVD------------------------------------
 * Deletes a specific DVD object
 * @pre DVD object exists
 * @post DVD object is deleted
 */
	virtual void destroyDVD();
/**---------------------------- getDirector-------------------------------------
 * Retrieves director string contained within object
 * @pre DVD object exists and has director string
 * @post director is returned as string
 */
	virtual string getDirector()const;
/**---------------------------- getTitle-------------------------------------
 * Retrieves title string contained within object
 * @pre DVD object exists and has title string
 * @post title is returned as string
 */
	virtual string getTitle()const;
/**---------------------------- getDate-------------------------------------
 * Retrieves date string contained within object
 * @pre DVD object exists and has date string
 * @post date is returned as string
 */
	virtual string getDate()const;
/**---------------------------- getDetails-------------------------------------
 * Retrieves full details of a DVD, i,e, Title, Director, Date.
 * @pre DVD object exists and all member variables are valid.
 * @post details are returned as string.
 */
	virtual string getDetails()const;

private:
	string director;
	string title;
	string date;
};
