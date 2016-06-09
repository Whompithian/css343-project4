/*
 * @file    Lab4Manager.h
 * @brief   This class represents the driver object for Lab 4.
 *          This class contains all I/O and instantiates all objects.
 *          After instantiating objects, this class passes pointers to those
 *          objects to the MOVIEStore object which, in turn, stores the pointers
 *          in various lists.
 * @author  Chris Grass
 * @date    February 15, 2012
 */
#include <string>
#include <iostream>
#include <fstream>
#include "merch.h"
#include "classicDVD.h"
#include "dramaDVD.h"
#include "comedyDVD.h"
#include "movieStore.h"
#include "customer.h"

using namespace std;

class Lab4Manager
{

public:
/**---------------------- Default Constructor ---------------------------------
 * Creates an empty Customer object.
 * @pre None.
 * @post An empty Customer object exists.
 */
	Lab4Manager();
//--------------------------- Destructor -------------------------------------
	~Lab4Manager();
/**---------------------- buildInventory ---------------------------------
 * Reads a text file and instantiates Merch items from that file. It then passes
 * pointers to those objects to the MOVIEStore object for storage.
 * @pre file.txt exists and is formatted correctly.
 * @post All merch items represented in file.txt are stored in Inventory object.
 */
	void buildInventory(file.txt);
/**---------------------- buildCustomersList ---------------------------------
 * Reads a text file and instantiates Customer items from that file.
 * It then passes pointers to those objects to the MOVIEStore object for storage.
 * @pre file.txt exists and is formatted correctly.
 * @post All customer objects represented in file.txt are stored in CustomerList
 * object.
 */
	void buildCustomersList(file.txt);
/**---------------------- processTransactions ---------------------------------
 * Reads a text file and instantiates Transaction items from that file.
 * It then passes pointers to those objects to the MOVIEStore object to be
 * processed.
 * @pre file.txt exists and is formatted correctly.
 * @post All transaction objects represented in file.txt are stored in History
 * object.
 */
	void processTransactions(file.txt);

private:

};
