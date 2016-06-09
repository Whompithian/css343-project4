/*
 * @file    ThreadedTreeNode.cpp
 *          Addapted from:
 *          Carrano, F. M. (2007). Trees. In M. Hirsch (Ed.) "Data Abstraction
 *              & Problem Solving with C++: Walls and Mirrors" (5th ed.) pp.
 *              555-556. Boston, MA: Pearson Education, Inc.
 * @brief   A pointer-based tree node with an added data member to indicate if
 *          the child pointers are actually thread pointers.
 * @author  Brendan Sweeney, SID 1161836
 * @date    December 8, 2011
 */

#include "ThreadedTreeNode.h"

using namespace std;


ThreadedTreeNode::ThreadedTreeNode()
{
} // end default constructor

ThreadedTreeNode::ThreadedTreeNode(const TreeItemType& nodeItem,
                                         ThreadedTreeNode *left,
                                         ThreadedTreeNode *right) :
  item(nodeItem), leftChildPtr(left), rightChildPtr(right), threads(BOTHTHREAD)
{
} // end constructor
