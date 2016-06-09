/*
 * @file    Lab4Manager.h
 * @brief   This class builds and acts on a MOVIE store. It reads in two files,
 *          tokenizes them, and constructs an inventory and customer database
 *          for the store. It then reads another file, tokenizes it, and
 *          performs a set of described actions and lookups within the store.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _LAB4MANAGER_H
#define	_LAB4MANAGER_H

#include <fstream>
#include "MOVIEStore.h"


class Lab4Manager
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates a Lab4Manager object with a MOVIEStore initialized to a carefully
 * selected set of default values.
 * @param newName  Name to identify this Business.
 * @param customerBase  Expected number of Customers this Business will have.
 *                      Must be positive.
 * @pre customerBase is positive.
 * @post A Business object exists with name newName and a Customer List of size
 *       customerBase.
 */
    Lab4Manager();

    ~Lab4Manager();

/**---------------------- buildInventory() ------------------------------------
 * Reads a file and uses it to build the store Inventory. The first character
 * is pulled from the file and used to determine the type of Merchandise that
 * will be added to the Inventory. If the character is not recognized, then the
 * rest of the line is discarded and the first character of the next line is
 * obtained. This process continues until the end of the file is reached.
 * @param filename  The name of the file to open. It should be the name of a
 *                  file that contains commands for building an Inventory.
 * @pre filename indicates a valid file for building an Inventory.
 * @post The MOVIE store will have an Inventory of Merchandise.
 */
    void buildInventory(const char* filename);

/**---------------------- buildCustomers() ------------------------------------
 * Reads a file and uses it to build a Customer List. An integer is pulled from
 * the first line to represent the Customer ID number. If the number is out of
 * the expected range, then the rest of the line is discarded and the next line
 * read for an integer. This process continues until the end of the file is
 * reached.
 * @param filename  The name of the file to open. It should be the name of a
 *                  file that contains commands for building a Customer List.
 * @pre filename indicates a valid file for building a Customer List.
 * @post The MOVIE store will have a List of Customers.
 */
    void buildCustomers(const char* filename);

/**---------------------- buildCommands() -------------------------------------
 * Reads a file and uses it to process a set of commands. The first character
 * is pulled from the file and used to determine the type of command that will
 * be performed. If the character is not recognized, then the rest of the line
 * is discarded and the first character of the next line is obtained. This
 * process continues until the end of the file is reached.
 * @param filename  The name of the file to open. It should be the name of a
 *                  file that contains recognized commands.
 * @pre filename indicates a valid file for performing commands.
 * @post All commands are processed and the MOVIE store contains a record of
 *       the ones that caused a change.
 */
    void buildCommands(const char* filename);

private:

    MOVIEStore scarecrow;

}; // end class Lab4Manager

#endif	/* _LAB4MANAGER_H */
