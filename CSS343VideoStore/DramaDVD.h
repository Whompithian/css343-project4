/*
 * @file    DramaDVD.h
 * @brief   This class represents a single DramaDVD item.
 *          This class is derived from DVD.
 * @author  Chris Grass
 * @date    February 15, 2012
 */
#include <string>
#include "dvd.h"
using namespace std;

class DramaDVD: public DVD
{
public:
/**---------------------- Default Constructor ---------------------------------
 * Creates an empty DramaDVD object.
 * @pre None.
 * @post An empty DramaDVD object exists.
 */
	DramaDVD();
//---------------------------- Destructor -------------------------------------
	virtual ~DramaDVD();
//-------------------------- Copy Constructor ---------------------------------
	DramaDVD(const DramaDVD& copy);

private:
};
