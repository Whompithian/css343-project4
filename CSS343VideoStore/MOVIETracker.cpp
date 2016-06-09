/* 
 * File:   rentmovies.cpp
 * Author: brendan
 *
 * Created on February 14, 2012, 8:10 PM
 */

#include <cstdlib>
#include "Lab4Manager.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    Lab4Manager action;

    action.buildInventory();
    action.buildCustomersList();
    action.processTransactions();

    return (EXIT_SUCCESS);
}

