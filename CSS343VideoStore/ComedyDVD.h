/*
 * @file    ComedyDVD.h
 * @brief   This class represents a single ComedyDVD item.
 *          This class is derived from DVD.
 * @author  Chris Grass
 * @date    February 15, 2012
 */

#include <string>
#include "dvd.h"

using namespace std;

class ComedyDVD: public DVD
{
public:
/**---------------------- Default Constructor ---------------------------------
 * Creates an empty ComedyDVD object.
 * @pre None.
 * @post An empty ComedyDVD object exists.
*/
	ComedyDVD();
//---------------------------- Destructor -------------------------------------
	virtual ~ComedyDVD();
//-------------------------- Copy Constructor ---------------------------------
	ComedyDVD(const ComedyDVD& copy);
private:

};
