/*
 * @file    MOVIETracker.cpp
 * @brief   This program is an inventory tracking system for a video rental
 *          store. A video rental store is a business that has a customer list
 *          and has an inventory of merchandise. A customers of the store has a
 *          set of identifying attributes, stored in key-value pairs, and has a
 *          history of transactions with the store. A transaction only has a
 *          piece of merchandise on which it was performed. Merchandise is a
 *          keyed item that can be sorted, with the calculation of the search
 *          key left to its subclasses. A DVD is a type of merchandise and
 *          there are three types of DVDs: Classic, Dramam, and Comedy. Each
 *          type of DVD calculates its search key differently, since the rental
 *          store organizes the categories differently.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 8, 2012
 */

#include "Lab4Manager.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    Lab4Manager director;

    director.buildInventory("data4movies.txt");
    director.buildCustomers("data4customers.txt");
    director.buildCommands("data4commands.txt");

    return (EXIT_SUCCESS);
} // end main(int, char**)
