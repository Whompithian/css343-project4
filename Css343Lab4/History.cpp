/* 
 * File:   history.cpp
 * Author: brendan
 * 
 * Created on February 14, 2012, 8:13 PM
 */

#include "History.h"
#include "Merch.h"

History::History() : head(NULL)
{
} // end Default Constructor

History::History(const History& orig)
{
    if (orig.head == NULL)
    {
        head = NULL;    // original list is empty
    }
    else
    {
        // copy first node
        head = new ListNode;
        head->record = orig.head->record;

        // copy rest of list
        ListNode *newPtr = head;    // new list pointer
        // newPtr points to last node in new list
        // origPtr points to nodes in original list
        for (ListNode *origPtr = orig.head->next;
                origPtr != NULL;
                origPtr = origPtr->next)
        {
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->record = origPtr->record;
        } // end for (ListNode *origPtr = orig.head->next;

        newPtr->next = NULL;
    } // end if (orig.head == NULL)
} // end Copy Constructor

History::~History()
{
    clearHistory();
} // end Destructor

void History::clearHistory(void)
{
    ListNode *tempPtr;

    while(head != NULL)     // still items in History
    {
        tempPtr = head;     // keep first item available
        head = head->next;  // move up list
        delete tempPtr;     // delete previous first item
    } // end while(head != NULL)

    tempPtr = NULL;
} // end clearHistory()

void History::insertItem(Transaction *latest)
{
    ListNode *tempNode = new ListNode;

    tempNode->record = latest->copy();  // copy record into new node
    tempNode->next = head->next;        // new link to rest of chain
    head = tempNode;                    // insert at head of list
} // end insertItem()

Transaction* History::getLatest(void) const
{
    return head->record->copy();    // create copy and return pointer
} // end getLatest()

bool History::isBorrowed(const Merch *target) const
{
    ListNode *tempNode = head;
    Merch *tempMerch = NULL;
    
    while(tempNode != NULL)     // there is something to check
    {
        tempMerch = tempNode->record->getItem();

        // item found - determine if last Transaction was a Borrow and return
        if (tempMerch->getSearchKey() == target->getSearchKey())
        {
            delete tempMerch;
            tempMerch = NULL;
            return tempNode->record->getMediaCode() == 'B';
        } // end if (tempMerch->getSearchKey() == target->getSearchKey())

        tempNode = tempNode->next;  // set to search next node
        delete tempMerch;           // delete copy of Merchandise
    } // end while(tempNode != NULL)

    tempMerch = NULL;   // clean up pointer
    
    return false;       // no Borrow Transaction found for target item
} // end isBorrowed(Transaction*)

void History::displayHistory(ostream& output) const
{
    ListNode *tempPtr = head;

    while(tempPtr != NULL)
    {
        tempPtr->record->display(output);
        tempPtr = tempPtr->next;
    } // end while()
} // end showHistory()
