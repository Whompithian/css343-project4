/* 
 * @file    TreeException.h
 *          Addapted from:
 *          Carrano, F. M. (2007). Trees. In M. Hirsch (Ed.) "Data Abstraction
 *              & Problem Solving with C++: Walls and Mirrors" (5th ed.) p.
 *              519. Boston, MA: Pearson Education, Inc.
 * @brief   Exception class for the threaded binary search tree.
 * @author  Brendan Sweeney, SID 1161836
 * @date    December 8, 2011
 */

#ifndef _TREEEXCEPTION_H
#define	_TREEEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;


class TreeException : public logic_error
{
public:

    TreeException(const string& message = "") : logic_error(message.c_str())
    {
    } // end constructor
}; // end TreeException


#endif	/* _TREEEXCEPTION_H */
