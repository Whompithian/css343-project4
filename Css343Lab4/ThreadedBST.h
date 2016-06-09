/*
 * @file    ThreadedBST.h
 *          Addapted from:
 *          Carrano, F. M. (2007). Trees. In M. Hirsch (Ed.) "Data Abstraction
 *              & Problem Solving with C++: Walls and Mirrors" (5th ed.) pp.
 *              556-559. Boston, MA: Pearson Education, Inc.
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

#ifndef _THREADEDBST_H
#define	_THREADEDBST_H

#include "ThreadedTreeNode.h"
#include "TreeException.h"


typedef void (*FunctionType)(TreeItemType& anItem);

class ThreadedBST
{
public:

    friend class Inorder;

    class Inorder
    {
    public:

        friend class ThreadedBST;

        Inorder(const ThreadedBST *aTree, ThreadedTreeNode *aNode);

        Inorder(const Inorder& orig);

        virtual ~Inorder();

        /** Assign an existing iterator's position to this object.
         * @param rhs  The PuzzleIterator with the values to be assigned.
         * @pre None
         * @post This object is a duplicate of rhs. rhs is unchanged
         */
        void operator=(const Inorder& rhs);

        /** Obtain a reference to the item to which this iterator points.
         * @pre This iterator points to a node that contains a data item.
         * @post None
         */
        const TreeItemType& operator*(void);

        /** Move this iterator to the next inorder node in its container.
         * @pre This iterator is not already at the last inorder element.
         * @post This iterator points to the inorder successor of its previous
         *       node.
         * @return This iterator.
         */
        Inorder operator++(void);

        /** Move this iterator to the previous inorder node in its container.
         * @pre This iterator is not already at the first inorder element.
         * @post This iterator points to the inorder predecessor of its
         *       previous node.
         * @return This iterator.
         */
        Inorder operator--(void);

        /** Compare the key value of this iterator's node item with another.
         * @param rhs  The iterator with which to compare.
         * @pre Both iterators reference the same container instance.
         * @post None.
         * @return true if this iterator's node item has a lower key value than
         *         the item in the rhs node, false otherwise.
         */
        bool operator<(const Inorder& rhs) const;

        /** Compare the key value of this iterator's node item with another.
         * @param rhs  The iterator with which to compare.
         * @pre Both iterators reference the same container instance.
         * @post None.
         * @return true if this iterator's node item has a higher key value
         *         than the item in the rhs node, false otherwise.
         */
        bool operator>(const Inorder& rhs) const;

        /** Compare this iterator for equality with another.
         * @param rhs  The iterator with which to compare.
         * @pre None.
         * @post None.
         * @return true if this iterator points to the same container and node
         *         as the rhs iterator, false otherwise.
         */
        bool operator==(const Inorder& rhs) const;

        /** Compare this iterator for inequality with another.
         * @param rhs  The iterator with which to compare.
         * @pre None.
         * @post None.
         * @return true if this iterator points to a different container or
         *         node than the rhs iterator, false otherwise.
         */
        bool operator!=(const Inorder& rhs) const;

    private:

        const ThreadedBST *container;   // containing object
        ThreadedTreeNode  *cur;         // current element of container

    }; // end Inorder
    
    
    
 // constructors and destructor:
    ThreadedBST();

    ThreadedBST(const ThreadedBST& orig)
            throw(TreeException);

    virtual ~ThreadedBST();
    
    /** Determines whether a threaded binary search tree is empty.
     * @pre None.
     * @post None.
     * @return true if the tree is empty; othersie returns false.
     */
    virtual bool isEmpty() const;
    
    /** Inserts an item into a threaded binary search tree.
     * @param newItem  A value, passed by reference, to be added to the tree.
     * @pre The item to e inserted into the tree is newItem.
     * @post newItem is in its proper order in the tree. If newItem has an
     *       inorder successor or inorder predecessor already in the tree, a
     *       thread pointer is set in newItem's node to point to the nodes that
     *       contain those items.
     * @throw TreeException  If memory allocations fails.
     */
    virtual void searchTreeInsert(const TreeItemType& newItem)
                 throw(TreeException);
    
    /** Deletes an item with a given search key from a threaded binary search
     *  tree.
     * @param searchKey  Key of the item to locate and remove from this tree.
     * @pre searchKey is the search key of the item to be deleted.
     * @post If the item whose search key equals searchKey existed in the tree,
     *       the item is deleted. Otherwise, the tree is unchanged.
     * @throw TreeException  If searchKey is not found in the tree.
     */
    virtual void searchTreeDelete(KeyType searchKey)
                 throw(TreeException);
    
    /** Retrieves an item with a given search key from a threaded binary search
     *  tree.
     * @param searchKey  The search key of the item to be located.
     * @param treeItem  A container for the found item.
     * @pre searchKey is the search key of the item to be retrieved.
     * @post If the retrieval was successful, treeItem contains the retrieved
     *       item.
     * @throw TreeException  If no such item exists.
     */
    virtual void searchTreeRetrive(KeyType searchKey,
                                   TreeItemType& treeItem) const
                 throw(TreeException);
    
    /** Traverses a threaded binary search tree in preorder, calling function
     *  visit() once for each item.
     * @param visit  A function to perform on every traversed node.
     * @pre The function represented by visit() exists outside of the class
     *      implemenation.
     * @post visit's action occurred once for each item in the tree.
     * @note visit() can alter the tree.
     */
    virtual void preorderTraverse(FunctionType visit);
    
    /** Traverses a threaded binary search tree in sorted order, calling
     *  function visit() once for each item.
     * @param visit  A function to perform on every traversed node.
     * @pre The function represented by visit() exists outside of the class
     *      implemenation.
     * @post visit's action occurred once for each item in the tree.
     * @note visit() can alter the tree.
     */
    virtual void inorderTraverse(FunctionType visit);
    
    /** Traverses a threaded binary search tree in postorder, calling function
     *  visit() once for each item.
     * @param visit  A function to perform on every traversed node.
     * @pre The function represented by visit() exists outside of the class
     *      implemenation.
     * @post visit's action occurred once for each item in the tree.
     * @note visit() can alter the tree.
     */
    virtual void postorderTraverse(FunctionType visit);
    
    /** Copies the contents of rhs into this tree.
     * @param rhs  The right-hand tree to be copied.
     * @pre There is sufficient memory to allocate a copy of rhs.
     * @post This tree is a structural copy of rhs; rhs remains unchanged.
     * @return The threaded binary search tree with newly-assigned values.
     * @throw TreeException  If memory allocation fails.
     */
    virtual ThreadedBST& operator=(const ThreadedBST& rhs)
                         throw(TreeException);

    /** Returns an iterator for the inorder first element of this tree.
     * @pre Tree is not empty.
     * @post None.
     * @return An iterator that can access the element of the tree with the
     *         lowest key value.
     * @throw TreeException  If the tree is empty.
     */
    virtual Inorder begin(void) const
                    throw(TreeException);

    /** Returns an iterator for the inorder last element of this tree.
     * @pre Tree is not empty.
     * @post None.
     * @return An iterator that can access the element of the tree with the
     *         highest key value.
     * @throw TreeException  If the tree is empty.
     */
    virtual Inorder end(void) const
                    throw(TreeException);
    
protected:
    
    /** Recursively inserts an item into a threaded binary search tree.
     * @param treePtr  Pointer to the node to start a check for insertion.
     * @param predecessor  Thread pointer to the inorder predecessor of the
     *        calling node's leftmost right descendant; NULL if not yet found.
     * @param successor  Thread pointer to the inorder successor of the calling
     *        node's rightmost left descendant; NULL if not yet found.
     * @param newItem  The item to be inserted into this tree.
     * @pre treePtr points to a threaded binary search tree, newItem is the
     *      item to be inserted. If tree is empty or contains only root,
     *      predecessor and successor must both be NULL.
     * @post newItem is in its proper order in the tree. If newItem has an
     *       inorder successor or inorder predecessor already in the tree, a
     *       thread pointer is set in newItem's node to point to the nodes that
     *       contain those items.
     * @throw TreeException  If memory allocations fails.
     */
    void insertItem(ThreadedTreeNode *& treePtr,
                    ThreadedTreeNode *predecessor,
                    ThreadedTreeNode *successor,
              const TreeItemType& newItem)
         throw(TreeException);

    /** Recursively deletes an item from a threaded binary search tree.
     * @param treePtr  Pointer to the node to start a check for deletion.
     * @parm searchKey  Search key of the item to be deleted from this tree.
     * @pre treePtr points to a binary search tree, searchKey is the search key
     *      of the item to be deleted.
     * @post If the item whose search key equals searchKey existed in the tree,
     *       the item is deleted. Otherwise, the tree is unchanged.
     * @throw TreeException  If searchKey is not found in the tree.
     */
    void deleteItem(ThreadedTreeNode *& treePtr, KeyType searchKey)
         throw(TreeException);

    /** Deletes the item in the root of a given tree.
     * @param nodePtr  Pointer to the node to be deleted.
     * @pre nodePtr points to the root of a threaded binary search tree;
     *      nodePtr !- NULL.
     * @post The item in the root of the given tree is deleted.
     */
    void deleteNodeItem(ThreadedTreeNode *& nodePtr);

    /** Retrieves and deletes the leftmost descendant of a given node.
     * @param nodePtr  Pointer to the node to start processing.
     * @param treeItem  A container for the item in the node to be delete.
     * @pre nodePtr points to a node in a threaded binary search tree;
     *      nodePtr != NULL.
     * @post treeItem contains the item in the leftmost descendant of the node
     *       to which nodePtr points. The leftmost descendant of nodePtr is
     *       deleted.
     */
    void processLeftmost(ThreadedTreeNode *& nodePtr, TreeItemType& treeItem);

    /** Recursively retrieves an item from a threaded binary search tree.
     * @param treePtr  Pointer to the node at which to start searching.
     * @param searchKey  Search key of the item to be retrieved.
     * @param treeItem  A container for the located item.
     * @pre treePtr points to a binary search tree, treeItem is the search key
     *      of the item to be retrieved.
     * @post If the retrieval was successful, treeItem contains the retrieved
     *       item.
     * @throw TreeException  If no such item exists.
     */
    void retrieveItem(ThreadedTreeNode *treePtr,
                      KeyType searchKey,
                      TreeItemType& treeItem) const
         throw(TreeException);

    /** Copies the tree rooted at treePtr into a tree rooted at newTreePtr.
     * @param treePtr  The root of the tree to be copied.
     * @param newTreePtr  A container for the root of a copy of treePtr.
     * @pre There is sufficient memory to allocate a new tree.
     * @post newTreePtr points to the root of a structural copy of the tree
     *       whose root is pointed to by treePtr.
     * @throw TreeException  If a copy of the tree cannot be allocated.
     */
    void copyTree(ThreadedTreeNode *treePtr,
                  ThreadedTreeNode *& newTreePtr)
         throw(TreeException);

    /** Deallocates memory for a tree.
     * @param treePtr  Pointer to the root of the tree to be deallocated.
     * @pre None.
     * @post treePtr is an empty tree.
     */
    void destroyTree(ThreadedTreeNode *& treePtr);

    /** Retrieves the value of the private data member root.
     * @pre None.
     * @post None.
     * @return A pointer to the root of this tree, as a ThreadedTreeNode.
     */
    ThreadedTreeNode* rootPtr() const;

    /** Set the value of the private data member root.
     * @param newRoot  The root of a threaded binary search tree to be assigned
     *        to this tree.
     * @pre newRoot does not have a parent.
     */
    void setRootPtr(ThreadedTreeNode *newRoot);

    /** Retrieves the values of the left and right child pointers of a tree
     *  node.
     * @param nodePtr  The node from which to retrieve child pointers.
     * @param leftPtr  A container for the left child pointer.
     * @param rightPtr  A container for the right child pointer.
     * @pre None.
     * @post leftPtr and rightPtr contain the child pointers of nodePtr.
     */
    void getChildPtrs(ThreadedTreeNode *nodePtr,
                      ThreadedTreeNode *& leftPtr,
                      ThreadedTreeNode *& rightPtr) const;

    /** Sets the values of the left and right child pointers of a tree node.
     * @param nodePtr  The node in which to set the child pointers.
     * @param leftPtr  Pointer to which to set the left child pointer.
     * @param rightPtr  Pointer to which to set the right child pointer.
     * @pre leftPtr and rightPtr are not in the same tree and at a higher level
     *      than nodePtr.
     * @post nodePtr's left child pointer is leftPtr and its right child
     *       pointer is rightPtr.
     */
    void setChildPtrs(ThreadedTreeNode *nodePtr,
                      ThreadedTreeNode *leftPtr,
                      ThreadedTreeNode *rightPtr);
    
    /** Traverses a threaded binary search tree in preorder, starting at
     *  treePtr, and calls function visit() once for each item.
     * @param treePtr  Node at which to begin traversal.
     * @param visit  A function to perform at every traversed node.
     * @pre The function represented by visit() exists outside of the class
     *      implemenation.
     * @post visit's action occurred once for each item in the tree from
     *       treePtr on.
     * @note visit() can alter the tree.
     */
    void preorder(ThreadedTreeNode *treePtr, FunctionType visit);
    
    /** Traverses a threaded binary search tree in sorted order, starting at
     *  treePtr, and calls function visit() once for each item.
     * @param treePtr  Node at which to begin traversal.
     * @param visit  A function to perform at every traversed node.
     * @pre The function represented by visit() exists outside of the class
     *      implemenation.
     * @post visit's action occurred once for each item in the tree from
     *       treePtr on.
     * @note visit() can alter the tree.
     */
    void inorder(ThreadedTreeNode *treePtr, FunctionType visit);
    
    /** Traverses a threaded binary search tree in postorder, starting at
     *  treePtr, and calls function visit() once for each item.
     * @param treePtr  Node at which to begin traversal.
     * @param visit  A function to perform at every traversed node.
     * @pre The function represented by visit() exists outside of the class
     *      implemenation.
     * @post visit's action occurred once for each item in the tree from
     *       treePtr on.
     * @note visit() can alter the tree.
     */
    void postorder(ThreadedTreeNode *treePtr, FunctionType visit);
    
    /** Locates the leftmost node in a subtree to connect its left thread
     *  pointer to a new predecessor. Called by deleteNodeItem().
     * @param nodePtr  Pointer to the node to check for predecessorship.
     * @param newPredecessor  Pointer to the node that will be the inorder
     *        predecessor of this node.
     * @pre newPredecessor points to the inorder predecessor of a node that
     *      will be deleted; the node that will be deleted is the old inorder
     *      predecessor of this node.
     * @post The left thread pointer of this node points to the predecessor of
     *       its inorder predecessor; may be NULL.
     */
    void passPredecessor(ThreadedTreeNode *& nodePtr,
                         ThreadedTreeNode *newPredecessor);
    
    /** Locates the leftmost node in a subtree to connect its left thread
     *  pointer to a new successor. Called by deleteNodeItem().
     * @param nodePtr  Pointer to the node to check for successorship.
     * @param newSuccessor  Pointer to the node that will be the inorder
     *        successor of this node.
     * @pre newSuccessor points to the inorder successor of a node that will be
     *      deleted; the node that will be deleted is the old inorder successor
     *      of this node.
     * @post The right thread pointer of this node points to the successor of
     *       its inorder successor; may be NULL.
     */
    void passSuccessor(ThreadedTreeNode *& nodePtr,
                       ThreadedTreeNode *newSuccessor);

private:

    ThreadedTreeNode *root;     // Pointer to root of tree

}; // end ThreadedBST


#endif	/* _THREADEDBST_H */
