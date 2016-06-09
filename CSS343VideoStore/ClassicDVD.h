/*
 * @file    ClassicDVD.h
 * @brief   This class represents a single ClassicDVD item.
 *          This class is derived from DVD.
 * @author  Chris Grass
 * @date    February 15, 2012
 */

#include <string>
#include "dvd.h"

using namespace std;

class ClassicDVD: public DVD
{
public:
/**---------------------- Default Constructor ---------------------------------
 * Creates an empty ClassicDVD object.
 * @pre None.
 * @post An empty ClassicDVD object exists.
 */
	ClassicDVD();
//----------------------- Default Destructor ---------------------------------
	virtual ~ClassicDVD();
//------------------------- Copy Constructor ---------------------------------
	ClassicDVD(const ClassicDVD& copy);
/**------------------------ getFamousActor-- ---------------------------------
 * Retrieves famousActor string from ClassicDVD object
 * @pre ClassicDVD object exists and contains valid famousActor string
 * @post famousActor is returns as string
 */
	string getFamousActor()const;
private:
// additional member variable for ClassicDVD. Used for sort criteria
	string famousActor;
};
