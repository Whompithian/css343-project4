/*
 * @file    ThreadedBST.cpp
 *          Addapted from:
 *          Carrano, F. M. (2007). Trees. In M. Hirsch (Ed.) "Data Abstraction
 *              & Problem Solving with C++: Walls and Mirrors" (5th ed.) pp.
 *              523-529, 559-563. Boston, MA: Pearson Education, Inc.
 * @brief   A binary search tree with threading added for simpler traversal.
 *          If a node has no left child, its left child pointer points to the
 *          inorder predecessor of that node. If a node has no right child, its
 *          right child pointer points to the inorder successor of that node.
 *          All child pointers that do not point to child nodes are considered
 *          thread pointers, so NULL pointers are treated as thread pointers.
 *          The inorder first item always has a NULL left thread pointer. The
 *          inorder last item always has a NULL right thread pointer. An int is
 *          used to keep track of the state of threads; 0 = no threads, 1 =
 *          left thread, 2 = right thread, 3 = both threads. Since left thread
 *          and right thread are both powers of 2, binary arithmetic is used to
 *          make comparisons and set the threads indicator element of a node.
 * @author  Brendan Sweeney, SID 1161836
 * @date    December 8, 2011
 */

#include <cstddef>          // definition of NULL
#include <new>              // for bad_alloc

#include "ThreadedBST.h"

using namespace std;


ThreadedBST::Inorder::Inorder(const ThreadedBST *aTree,
                                    ThreadedTreeNode *aNode) :
                      container(aTree), cur(aNode)
{
} // end constructor

ThreadedBST::Inorder::Inorder(const Inorder& orig) :
                      container(orig.container), cur(orig.cur)
{
} // end copy constructor

ThreadedBST::Inorder::~Inorder()
{
    container = NULL;
    cur = NULL;
} // end destructor

/** Assign an existing iterator's position to this object.
 * @param rhs  The PuzzleIterator with the values to be assigned.
 * @pre None
 * @post This object is a duplicate of rhs. rhs is unchanged
 */
void ThreadedBST::Inorder::operator=(const Inorder& rhs)
{
    container = rhs.container;
    cur = rhs.cur;
} // end operator=(Inorder&)

/** Obtain a reference to the item to which this iterator points.
 * @pre This iterator points to a node that contains a data item.
 * @post None
 */
const TreeItemType& ThreadedBST::Inorder::operator*(void)
{
    return cur->item;
} // end operator*(void)

/** Move this iterator to the next inorder node in its container.
 * @pre This iterator is not already at the last inorder element.
 * @post This iterator points to the inorder successor of its previous node.
 * @return This iterator.
 */
ThreadedBST::Inorder ThreadedBST::Inorder::operator++(void)
{
    if ((cur->threads & RIGHTTHREAD) == RIGHTTHREAD)
    {
        // Right pointer is thread pointer to inorder successor
        cur = cur->rightChildPtr;
    }
    else
    {
        // Check right branch
        cur = cur->rightChildPtr;

        while((cur->threads & LEFTTHREAD) != LEFTTHREAD)
        {
            // Find leftmost node of right branch
            cur = cur->leftChildPtr;
        } // end while((cur->threads & LEFTTHREAD) != LEFTTHREAD)
    } // end if ((cur->threads & RIGHTTHREAD) == RIGHTTHREAD)

    return *this;
} // end operator++(void)

/** Move this iterator to the previous inorder node in its container.
 * @pre This iterator is not already at the first inorder element.
 * @post This iterator points to the inorder predecessor of its previous node.
 * @return This iterator.
 */
ThreadedBST::Inorder ThreadedBST::Inorder::operator--(void)
{
    if ((cur->threads & LEFTTHREAD) == LEFTTHREAD)
    {
        // Left pointer is thread pointer to inorder predecessor
        cur = cur->leftChildPtr;
    }
    else
    {
        // Check left branch
        cur = cur->leftChildPtr;

        while((cur->threads & RIGHTTHREAD) != RIGHTTHREAD)
        {
            // Find rightmost node of left branch
            cur = cur->rightChildPtr;
        } // end while((cur->threads & RIGHTTHREAD) != RIGHTTHREAD)
    } // end if ((cur->threads & LEFTTHREAD) == LEFTTHREAD)

    return *this;
} // end operator--(void)

/** Compare the key value of this iterator's node item with another.
 * @param rhs  The iterator with which to compare.
 * @pre Both iterators reference the same container instance.
 * @post None.
 * @return true if this iterator's node item has a lower key value than the
 *         item in the rhs node, false otherwise.
 */
bool ThreadedBST::Inorder::operator<(const Inorder& rhs) const
{
    return cur->item.getKey() < rhs.cur->item.getKey();
} // end operator<(Inorder&)

/** Compare the key value of this iterator's node item with another.
 * @param rhs  The iterator with which to compare.
 * @pre Both iterators reference the same container instance.
 * @post None.
 * @return true if this iterator's node item has a higher key value than the
 *         item in the rhs node, false otherwise.
 */
bool ThreadedBST::Inorder::operator>(const Inorder& rhs) const
{
    return cur->item.getKey() > rhs.cur->item.getKey();
} // end operator>(Inorder&)

/** Compare this iterator for equality with another.
 * @param rhs  The iterator with which to compare.
 * @pre None.
 * @post None.
 * @return true if this iterator points to the same container and node as the
 *         rhs iterator, false otherwise.
 */
bool ThreadedBST::Inorder::operator==(const Inorder& rhs) const
{
    return ((container == rhs.container) && (cur == rhs.cur));
} // end operator==(Inorder&)

/** Compare this iterator for inequality with another.
 * @param rhs  The iterator with which to compare.
 * @pre None.
 * @post None.
 * @return true if this iterator points to a different container or node than
 *         the rhs iterator, false otherwise.
 */
bool ThreadedBST::Inorder::operator!=(const Inorder& rhs) const
{
    return !(*this == rhs);
} // end operator!=(Inorder&)
// end Inorder



ThreadedBST::ThreadedBST() : root(NULL)
{
} // end default constructor

ThreadedBST::ThreadedBST(const ThreadedBST& orig)
             throw(TreeException)
{
    copyTree(orig.root, root);
} // end copy constructor

ThreadedBST::~ThreadedBST()
{
    destroyTree(root);
} // end destructor

/** Determines whether a threaded binary search tree is empty.
 * @pre None.
 * @post None.
 * @return true if the tree is empty; othersie returns false.
 */
bool ThreadedBST::isEmpty() const
{
    return (root == NULL);
} // end isEmpty()

/** Inserts an item into a threaded binary search tree.
 * @param newItem  A value, passed by reference, to be added to the tree.
 * @pre The item to e inserted into the tree is newItem.
 * @post newItem is in its proper order in the tree. If newItem has an inorder
 *       successor or inorder predecessor already in the tree, a thread pointer
 *       is set in newItem's node to point to the nodes that contain those
 *       items.
 * @throw TreeException  If memory allocations fails.
 */
void ThreadedBST::searchTreeInsert(const TreeItemType& newItem)
                  throw(TreeException)
{
    insertItem(root, NULL, NULL, newItem);
} // end searchTreeInsert(TreeItemType&)

/** Deletes an item with a given search key from a threaded binary search tree.
 * @param searchKey  Key of the item to locate and remove from this tree.
 * @pre searchKey is the search key of the item to be deleted.
 * @post If the item whose search key equals searchKey existed in the tree, the
 *       item is deleted. Otherwise, the tree is unchanged.
 * @throw TreeException  If searchKey is not found in the tree.
 */
void ThreadedBST::searchTreeDelete(KeyType searchKey)
                  throw(TreeException)
{
    deleteItem(root, searchKey);
} // end searchTreeDelete(KeyType)

/** Retrieves an item with a given search key from a threaded binary search
 *  tree.
 * @param searchKey  The search key of the item to be located.
 * @param treeItem  A container for the found item.
 * @pre searchKey is the search key of the item to be retrieved.
 * @post If the retrieval was successful, treeItem contains the retrieved item.
 * @throw TreeException  If no such item exists.
 */
void ThreadedBST::searchTreeRetrive(KeyType searchKey,
                                    TreeItemType& treeItem) const
                  throw(TreeException)
{
    // if retrieveItem throws a TreeException, it is ignored here and passed
    // on to the point in the code where searchTreeRetrieve was called
    retrieveItem(root, searchKey, treeItem);
} // end searchTreeRetrieve(KeyType, TreeItemType)

/** Traverses a threaded binary search tree in preorder, calling function
 *  visit() once for each item.
 * @param visit  A function to perform on every traversed node.
 * @pre The function represented by visit() exists outside of the class
 *      implemenation.
 * @post visit's action occurred once for each item in the tree.
 * @note visit() can alter the tree.
 */
void ThreadedBST::preorderTraverse(FunctionType visit)
{
    preorder(root, visit);
} // end preorderTravers(FunctionType)

/** Traverses a threaded binary search tree in sorted order, calling function
 *  visit() once for each item.
 * @param visit  A function to perform on every traversed node.
 * @pre The function represented by visit() exists outside of the class
 *      implemenation.
 * @post visit's action occurred once for each item in the tree.
 * @note visit() can alter the tree.
 */
void ThreadedBST::inorderTraverse(FunctionType visit)
{
    inorder(root, visit);
} // end inorderTraverse(FunctionType)

/** Traverses a threaded binary search tree in postorder, calling function
 *  visit() once for each item.
 * @param visit  A function to perform on every traversed node.
 * @pre The function represented by visit() exists outside of the class
 *      implemenation.
 * @post visit's action occurred once for each item in the tree.
 * @note visit() can alter the tree.
 */
void ThreadedBST::postorderTraverse(FunctionType visit)
{
    postorder(root, visit);
} // end postorderTraverse(FunctionType)

/** Copies the contents of rhs into this tree.
 * @param rhs  The right-hand tree to be copied.
 * @pre There is sufficient memory to allocate a copy of rhs.
 * @post This tree is a structural copy of rhs; rhs remains unchanged.
 * @return The threaded binary search tree with newly-assigned values.
 * @throw TreeException  If memory allocation fails.
 */
ThreadedBST& ThreadedBST::operator=(const ThreadedBST& rhs)
                          throw(TreeException)
{
    if (this != &rhs)
    {
        destroyTree(root);          // deallocate left-hand side
        copyTree(rhs.root, root);   // copy right-hand side
    } // end if (this != &rhs)

    return *this;
} // end operator=(ThreadedBST&)

/** Returns an iterator for the inorder first element of this tree.
 * @pre Tree is not empty.
 * @post None.
 * @return An iterator that can access the element of the tree with the lowest
 *         key value.
 * @throw TreeException  If the tree is empty.
 */
ThreadedBST::Inorder ThreadedBST::begin() const
                                  throw(TreeException)
{
    ThreadedTreeNode *target = root;

    if (isEmpty())
    {
        throw TreeException(
                "TreeException: tree empty, cannot get begin()");
    }
    // Assert: there are no thread pointers in the path to the leftmost node
    while(target->leftChildPtr != NULL)
    {
        target = target->leftChildPtr;
    } // end while(target->leftChildPtr != NULL)

    return Inorder(this, target);
} // end begin()

/** Returns an iterator for the inorder last element of this tree.
 * @pre Tree is not empty.
 * @post None.
 * @return An iterator that can access the element of the tree with the highest
 *         key value.
 * @throw TreeException  If the tree is empty.
 */
ThreadedBST::Inorder ThreadedBST::end() const
                                  throw(TreeException)
{
    ThreadedTreeNode *target = root;

    if (isEmpty())
    {
        throw TreeException(
                "TreeException: tree empty, cannot get end()");
    }
    // Assert: there are no thread pointers in the path to the rightmost node
    while(target->rightChildPtr != NULL)
    {
        target = target->rightChildPtr;
    } // end while(target->leftChildPtr != NULL)

    return Inorder(this, target);
} // end end()

/** Recursively inserts an item into a threaded binary search tree.
 * @param treePtr  Pointer to the node to start a check for insertion.
 * @param predecessor  Thread pointer to the inorder predecessor of the
 *        calling node's leftmost right descendant; NULL if not yet found.
 * @param successor  Thread pointer to the inorder successor of the calling
 *        node's rightmost left descendant; NULL if not yet found.
 * @param newItem  The item to be inserted into this tree.
 * @pre treePtr points to a threaded binary search tree, newItem is the item to
 *      be inserted. If tree is empty or contains only root, predecessor and
 *      successor must both be NULL.
 * @post newItem is in its proper order in the tree. If newItem has an inorder
 *       successor or inorder predecessor already in the tree, a thread pointer
 *       is set in newItem's node to point to the nodes that contain those
 *       items.
 * @throw TreeException  If memory allocations fails.
 */
void ThreadedBST::insertItem(ThreadedTreeNode *& treePtr,
                             ThreadedTreeNode *predecessor,
                             ThreadedTreeNode *successor,
                       const TreeItemType& newItem)
                  throw(TreeException)
{
    if (treePtr == NULL)
    { // position of insertion found; insert as leaf
        // create a new node
        try
        {
            treePtr = new ThreadedTreeNode(newItem, predecessor, successor);
        }
        catch (bad_alloc e)
        {
            throw TreeException(
                    "TreeException: insertItem cannot allocate memory");
        } // end try
    }
    // else search for the insertion position
    else if (newItem.getKey() < treePtr->item.getKey())
    {
        if ((treePtr->threads & LEFTTHREAD) == LEFTTHREAD)
        {
            // Assert: treePtr->leftChildPtr == precedessor
            treePtr->leftChildPtr = NULL;           // set for base case
            treePtr->threads -= LEFTTHREAD;         // left pointer now child
        } // end if ((treePtr->threads & LEFTTHREAD) == LEFTTHREAD)

        // search the left subtree, keeping predecessor thread and setting
        // successor thread to current node
        insertItem(treePtr->leftChildPtr, predecessor, treePtr, newItem);
    }
    else
    {
        if ((treePtr->threads & RIGHTTHREAD) == RIGHTTHREAD)
        {
            // Assert: treePtr->rightChildPtr == successor
            treePtr->rightChildPtr = NULL;          // set for base case
            treePtr->threads -= RIGHTTHREAD;        // right pointer now child
        } // end if ((treePtr->threads & RIGHTTHREAD) == RIGHTTHREAD)

        // search the right subtree, keeping successor thread and setting
        // predecessor thread to current node
        insertItem(treePtr->rightChildPtr, treePtr, successor, newItem);
    } // end if (treePtr == NULL)
} // end insertItem(ThreadedTreeNode*&, ...)

/** Recursively deletes an item from a threaded binary search tree.
 * @param treePtr  Pointer to the node to start a check for deletion.
 * @parm searchKey  Search key of the item to be deleted from this tree.
 * @pre treePtr points to a binary search tree, searchKey is the search key of
 *      the item to be deleted.
 * @post If the item whose search key equals searchKey existed in the tree, the
 *       item is deleted. Otherwise, the tree is unchanged.
 * @throw TreeException  If searchKey is not found in the tree.
 */
void ThreadedBST::deleteItem(ThreadedTreeNode *& treePtr, KeyType searchKey)
                  throw(TreeException)
// Calls: deleteNodeItem.
{
    if (treePtr == NULL)
    {
        throw TreeException(
                "TreeException: delete failed");    // empty tree
    }
    else if (searchKey == treePtr->item.getKey())
    {
        // item is in the root of some subtree
        deleteNodeItem(treePtr);    // delete the item
    }
    // else search for the item
    else if (searchKey < treePtr->item.getKey())
    {
        // search the left subtree
        deleteItem(treePtr->leftChildPtr, searchKey);
    }
    else
    {
        // search the right subtree
        deleteItem(treePtr->rightChildPtr, searchKey);
    } // end if (treePtr == NULL)
} // end deleteItem(ThreadedTreeNode*&, KeyType)

/** Deletes the item in the root of a given tree.
 * @param nodePtr  Pointer to the node to be deleted.
 * @pre nodePtr points to the root of a threaded binary search tree;
 *      nodePtr !- NULL.
 * @post The item in the root of the given tree is deleted.
 */
void ThreadedBST::deleteNodeItem(ThreadedTreeNode *& nodePtr)
// Algorithm note: There are four cases to consider:
//   1. The root is a leaf (threads == BOTHTHREAD).
//   2. The root has no left child (threads == LEFTTHREAD).
//   3. The root has no right child (threads == RIGHTTHREAD).
//   4. The root has two children (threads == NOTHREAD).
// Calls: processLeftmost.
{
    ThreadedTreeNode *delPtr = nodePtr;
    TreeItemType      replacementItem;      // for deleting node with one child

    // test for a leaf
    if (nodePtr->threads == BOTHTHREAD)
    {
        // use thread to determine if parent is inorder successor
        if (nodePtr->rightChildPtr != NULL &&
            nodePtr->rightChildPtr->leftChildPtr == nodePtr)
        {
            // nodePtr is a left child - pass predecessor thread to parent
            nodePtr->rightChildPtr->threads += LEFTTHREAD;
            nodePtr = nodePtr->leftChildPtr;
        }
        else if (nodePtr->leftChildPtr != NULL)
        {
            // nodePtr is right child - pass successor thread to parent
            nodePtr->leftChildPtr->threads += RIGHTTHREAD;
            nodePtr = nodePtr->rightChildPtr;
        } // end if (nodePtr->rightChildPtr != NULL ...)

        delPtr->leftChildPtr = NULL;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    } // end if leaf
    // test for no left child
    else if (nodePtr->threads == LEFTTHREAD)
    {
        passPredecessor(nodePtr->rightChildPtr, nodePtr->leftChildPtr);
        nodePtr = nodePtr->rightChildPtr;
        delPtr->leftChildPtr = NULL;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    } // end if no left child
    // test for no right child
    else if (nodePtr->threads == RIGHTTHREAD)
    {
        passSuccessor(nodePtr->leftChildPtr, nodePtr->rightChildPtr);
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    } // end if no right child
    // there are two children:
    // retrieve and delete the inorder successor
    else
    {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    } // end if two children
} // end deleteNodeItem(ThreadedTreeNode*&)

/** Retrieves and deletes the leftmost descendant of a given node.
 * @param nodePtr  Pointer to the node to start processing.
 * @param treeItem  A container for the item in the node to be delete.
 * @pre nodePtr points to a node in a threaded binary search tree;
 *      nodePtr != NULL.
 * @post treeItem contains the item in the leftmost descendant of the node to
 *       which nodePtr points. The leftmost descendant of nodePtr is deleted.
 */
void ThreadedBST::processLeftmost(ThreadedTreeNode *& nodePtr,
                                  TreeItemType& treeItem)
{
    if ((nodePtr->threads & LEFTTHREAD) == LEFTTHREAD)
    {
        // found leftmost - get its item
        treeItem = nodePtr->item;
        deleteNodeItem(nodePtr);
    }
    else
    {
        processLeftmost(nodePtr->leftChildPtr, treeItem);
    } // end if ((nodePtr->threads & LEFTTHREAD) == LEFTTHREAD)
} // end processLeftmost(ThreadedTreeNode*&, TreeItemType&)

/** Recursively retrieves an item from a threaded binary search tree.
 * @param treePtr  Pointer to the node at which to start searching.
 * @param searchKey  Search key of the item to be retrieved.
 * @param treeItem  A container for the located item.
 * @pre treePtr points to a binary search tree, treeItem is the search key of
 *      the item to be retrieved.
 * @post If the retrieval was successful, treeItem contains the retrieved item.
 * @throw TreeException  If no such item exists.
 */
void ThreadedBST::retrieveItem(ThreadedTreeNode *treePtr,
                               KeyType searchKey,
                               TreeItemType& treeItem) const
                  throw(TreeException)
{
    if (treePtr == NULL)
    {
        throw TreeException(
                "TreeException: searchKey not found");
    }
    else if (searchKey == treePtr->item.getKey())
    {
        // item is in the root of some subtree
        treeItem = treePtr->item;
    }
    else if (searchKey < treePtr->item.getKey())
    {
        // search the left subtree
        retrieveItem(treePtr->leftChildPtr, searchKey, treeItem);
    }
    else
    {
        // search the right subtree
        retrieveItem(treePtr->rightChildPtr, searchKey, treeItem);
    } // end if (treePtr == NULL)
} // end retrieveItem(ThreadedTreeNode*, KeyType, TreeItemType&)

/** Copies the tree rooted at treePtr into a tree rooted at newTreePtr.
 * @param treePtr  The root of the tree to be copied.
 * @param newTreePtr  A container for the root of a copy of treePtr.
 * @pre There is sufficient memory to allocate a new tree.
 * @post newTreePtr points to the root of a structural copy of the tree whose
 *       root is pointed to by treePtr.
 * @throw TreeException  If a copy of the tree cannot be allocated.
 */
void ThreadedBST::copyTree(ThreadedTreeNode *treePtr,
                           ThreadedTreeNode *& newTreePtr)
                  throw(TreeException)
{
    // preorder traversal
    if (treePtr != NULL)
    {
        int thread = treePtr->threads;
        // copy node
        try
        {
            insertItem(newTreePtr, NULL, NULL, treePtr->item);

            if ((thread & LEFTTHREAD) != LEFTTHREAD)
            {
                // continue down left branch, if not a thread
                copyTree(treePtr->leftChildPtr, newTreePtr);
            } // end if ((thread & LEFTTHREAD) != LEFTTHREAD)

            if ((thread & RIGHTTHREAD) != RIGHTTHREAD)
            {
                // continue down right branch, if not a thread
                copyTree(treePtr->rightChildPtr, newTreePtr);
            } // end if ((thread & RIGHTTHREAD) != RIGHTTHREAD)
        }
        catch (bad_alloc e)
        {
            throw TreeException(
                    "TreeException: copyTree cannot allocate memory");
        } // end try
    }
    else
    {
        newTreePtr = NULL;  // copy empty tree
    } // end if (treePtr != NULL)
} // end copyTree(ThreadedTreeNode*, ThreadedTreeNode*&)

/** Deallocates memory for a tree.
 * @param treePtr  Pointer to the root of the tree to be deallocated.
 * @pre None.
 * @post treePtr is an empty tree.
 */
void ThreadedBST::destroyTree(ThreadedTreeNode *& treePtr)
{
    // postorder traversal
    if (treePtr != NULL)
    {
        if ((treePtr->threads & LEFTTHREAD) == LEFTTHREAD)
        {
            treePtr->leftChildPtr = NULL;
        } // end if ((treePtr->threads & LEFTTHREAD) == LEFTTHREAD)

        if ((treePtr->threads & RIGHTTHREAD) == RIGHTTHREAD)
        {
            treePtr->rightChildPtr = NULL;
        } // end if (treePtr->threads == RIGHTTHREAD)

        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    } // end if (treePtr != NULL)
} // end destroyTree(ThreadedTreeNode*&)

/** Retrieves the value of the private data member root.
 * @pre None.
 * @post None.
 * @return A pointer to the root of this tree, as a ThreadedTreeNode.
 */
ThreadedTreeNode* ThreadedBST::rootPtr() const
{
    return root;
} // end rootPtr()

/** Set the value of the private data member root.
 * @param newRoot  The root of a threaded binary search tree to be assigned to
 *        this tree.
 * @pre newRoot does not have a parent.
 */
void ThreadedBST::setRootPtr(ThreadedTreeNode *newRoot)
{
    root = newRoot;
} // end setRootPtr(ThreadedTreeNode*)

/** Retrieves the values of the left and right child pointers of a tree node.
 * @param nodePtr  The node from which to retrieve child pointers.
 * @param leftPtr  A container for the left child pointer.
 * @param rightPtr  A container for the right child pointer.
 * @pre None.
 * @post leftPtr and rightPtr contain the child pointers of nodePtr.
 */
void ThreadedBST::getChildPtrs(ThreadedTreeNode *nodePtr,
                               ThreadedTreeNode *& leftPtr,
                               ThreadedTreeNode *& rightPtr) const
{
    leftPtr = nodePtr->leftChildPtr;
    rightPtr = nodePtr->rightChildPtr;
} // end getChildPtrs(ThreadedTreeNode*, ThreadedTreeNode*&, ...)

/** Sets the values of the left and right child pointers of a tree node.
 * @param nodePtr  The node in which to set the child pointers.
 * @param leftPtr  Pointer to which to set the left child pointer.
 * @param rightPtr  Pointer to which to set the right child pointer.
 * @pre leftPtr and rightPtr are not in the same tree and at a higher level
 *      than nodePtr.
 * @post nodePtr's left child pointer is leftPtr and its right child pointer is
 *       rightPtr.
 */
void ThreadedBST::setChildPtrs(ThreadedTreeNode *nodePtr,
                               ThreadedTreeNode *leftPtr,
                               ThreadedTreeNode *rightPtr)
{
    nodePtr->leftChildPtr = leftPtr;
    nodePtr->rightChildPtr = rightPtr;
} // end setChildPtrs(ThreadedTreeNode*, ThreadedTreeNode*, ThreadedTreeNode*)

/** Traverses a threaded binary search tree in preorder, starting at treePtr,
 *  and calls function visit() once for each item.
 * @param treePtr  Node at which to begin traversal.
 * @param visit  A function to perform at every traversed node.
 * @pre The function represented by visit() exists outside of the class
 *      implemenation.
 * @post visit's action occurred once for each item in the tree from treePtr
 *       on.
 * @note visit() can alter the tree.
 */
void ThreadedBST::preorder(ThreadedTreeNode *treePtr, FunctionType visit)
{
    if (treePtr != NULL)
    {
        visit(treePtr->item);

        if ((treePtr->threads & LEFTTHREAD) != LEFTTHREAD)
        {
            preorder(treePtr->leftChildPtr, visit);
        } // end if ((treePtr->threads & LEFTTHREAD) != LEFTTHREAD)

        if ((treePtr->threads & RIGHTTHREAD) != RIGHTTHREAD)
        {
            preorder(treePtr->rightChildPtr, visit);
        } // end if ((treePtr->threads & RIGHTTHREAD) != RIGHTTHREAD)
    } // end if (treePtr != NULL)
} // end preorder(ThreadedTreeNode*, FunctionType)

/** Traverses a threaded binary search tree in sorted order, starting at
 *  treePtr, and calls function visit() once for each item.
 * @param treePtr  Node at which to begin traversal.
 * @param visit  A function to perform at every traversed node.
 * @pre The function represented by visit() exists outside of the class
 *      implemenation.
 * @post visit's action occurred once for each item in the tree from treePtr
 *       on.
 * @note visit() can alter the tree.
 */
void ThreadedBST::inorder(ThreadedTreeNode *treePtr, FunctionType visit)
{
    if (treePtr != NULL)
    {
        if ((treePtr->threads & LEFTTHREAD) != LEFTTHREAD)
        {
            inorder(treePtr->leftChildPtr, visit);
        } // end if ((treePtr->threads & LEFTTHREAD) != LEFTTHREAD)

        visit(treePtr->item);
        inorder(treePtr->rightChildPtr, visit);
    } // end if (treePtr != NULL)
} // end inorder(ThreadedTreeNode*, FunctionType)

/** Traverses a threaded binary search tree in postorder, starting at treePtr,
 *  and calls function visit() once for each item.
 * @param treePtr  Node at which to begin traversal.
 * @param visit  A function to perform at every traversed node.
 * @pre The function represented by visit() exists outside of the class
 *      implemenation.
 * @post visit's action occurred once for each item in the tree from treePtr
 *       on.
 * @note visit() can alter the tree.
 */
void ThreadedBST::postorder(ThreadedTreeNode *treePtr, FunctionType visit)
{
    if (treePtr != NULL)
    {
        if ((treePtr->threads & LEFTTHREAD) != LEFTTHREAD)
        {
            postorder(treePtr->leftChildPtr, visit);
        } // end if ((treePtr->threads & LEFTTHREAD) != LEFTTHREAD)

        if ((treePtr->threads & RIGHTTHREAD) != RIGHTTHREAD)
        {
            postorder(treePtr->rightChildPtr, visit);
        } // end if ((treePtr->threads & RIGHTTHREAD) != RIGHTTHREAD)

        visit(treePtr->item);
    } // end if (treePtr != NULL)
} // end preorder(ThreadedTreeNode*, FunctionType)

/** Locates the leftmost node in a subtree to connect its left thread pointer
 *  to a new predecessor. Called by deleteNodeItem().
 * @param nodePtr  Pointer to the node to check for predecessorship.
 * @param newPredecessor  Pointer to the node that will be the inorder
 *        predecessor of this node.
 * @pre newPredecessor points to the inorder predecessor of a node that will be
 *      deleted; the node that will be deleted is the old inorder predecessor
 *      of this node.
 * @post The left thread pointer of this node points to the predecessor of its
 *       inorder predecessor; may be NULL.
 */
void ThreadedBST::passPredecessor(ThreadedTreeNode *& nodePtr,
                                  ThreadedTreeNode *newPredecessor)
{
    if ((nodePtr->threads & LEFTTHREAD) == LEFTTHREAD)
    {
        // Leftmost descendant found - set left thread pointer
        // Assert: old predecessor must be deleted, or threads will break
        nodePtr->leftChildPtr = newPredecessor;
    }
    else
    {
        passPredecessor(nodePtr->leftChildPtr, newPredecessor);
    } // end if ((nodePtr->threads & LEFTTHREAD) == LEFTTHREAD)
}  // end passPredecessor(ThreadedTreeNode*&, ThreadedTreeNode*)

/** Locates the leftmost node in a subtree to connect its left thread pointer
 *  to a new successor. Called by deleteNodeItem().
 * @param nodePtr  Pointer to the node to check for successorship.
 * @param newSuccessor  Pointer to the node that will be the inorder successor
 *        of this node.
 * @pre newSuccessor points to the inorder successor of a node that will be
 *      deleted; the node that will be deleted is the old inorder successor of
 *      this node.
 * @post The right thread pointer of this node points to the successor of its
 *       inorder successor; may be NULL.
 */
void ThreadedBST::passSuccessor(ThreadedTreeNode *& nodePtr,
                                ThreadedTreeNode *newSuccessor)
{
    if ((nodePtr->threads & RIGHTTHREAD) == RIGHTTHREAD)
    {
        // Rightmost descendant found - set right thread pointer
        // Assert: old successor must be deleted, or threads will break
        nodePtr->rightChildPtr = newSuccessor;
    }
    else
    {
        passSuccessor(nodePtr->rightChildPtr, newSuccessor);
    } // end if ((nodePtr->threads & RIGHTTHREAD) == RIGHTTHREAD)
}  // end passSuccessor(ThreadedTreeNode*&, ThreadedTreeNode*)
