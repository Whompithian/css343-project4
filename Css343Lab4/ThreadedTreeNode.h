/*
 * @file    ThreadedTreeNode.h
 *          Addapted from:
 *          Carrano, F. M. (2007). Trees. In M. Hirsch (Ed.) "Data Abstraction
 *              & Problem Solving with C++: Walls and Mirrors" (5th ed.) p.
 *              518. Boston, MA: Pearson Education, Inc.
 * @brief   A pointer-based tree node with an added data member to indicate if
 *          the child pointers are actually thread pointers.
 * @author  Brendan Sweeney, SID 1161836
 * @date    December 8, 2011
 */

#ifndef _THREADEDTREENODE_H
#define	_THREADEDTREENODE_H

#include "KeyedItem.h"

using namespace std;


typedef KeyedItem TreeItemType;
enum {NOTHREAD = 0, LEFTTHREAD = 1, RIGHTTHREAD = 2, BOTHTHREAD = 3};

class ThreadedTreeNode
{
private:

    ThreadedTreeNode();

    ThreadedTreeNode(const TreeItemType& nodeItem,
                           ThreadedTreeNode *left,
                           ThreadedTreeNode *right);

    TreeItemType      item;             // data portion
    int               threads;          // thread position indicator
    ThreadedTreeNode *leftChildPtr;     // pointer to left child
    ThreadedTreeNode *rightChildPtr;    // pointer to right child

    friend class ThreadedBST;
}; // end ThreadedTreeNode


#endif	/* _THREADEDTREENODE_H */
