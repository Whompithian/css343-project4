/*
 * @file    TransFactory.h
 * @brief   This class produces objects derived from a transaction. It holds a
 *          hash table of transaction pointers, with regognized objects at
 *          determined indexes. To get an instance of a desired object, a
 *          character representing that object is hashed to the index of the
 *          object and an ifstream is passed with information to initialize the
 *          object. NULL is returned if the provided character does not hash to
 *          the location of a known object. This factory is static and its
 *          instances are immutable.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _TRANSFACTORY_H
#define	_TRANSFACTORY_H

#include <fstream>

using namespace std;
class Transaction;                  // forward declaration for Transactions
const int ACTIONSIZE = 'Z' - 'A';   // size for hash table


class TransFactory
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates a TransFactory object with a full array of Transaction pointers. All
 * known descendants of Transaction have an object at an index that can be
 * found by hashing a capital letter character representing that object.
 * @pre None.
 * @post A TransFactory object exists with an array that contains an object for
 *       each known descendant of Transaction.
 */
    TransFactory();

/**---------------------- Copy Constructor ------------------------------------
 * Creates a TransFactory object with a full array of Transaction pointers. All
 * known descendants of Transaction have an object at an index that can be
 * found by hashing a capital letter character representing that object. A
 * Factory is immutable, so this just calls the default constructor.
 * @pre None.
 * @post A TransFactory object exists with an array that contains an object for
 *       each known descendant of Transaction.
 */
    TransFactory(const TransFactory& orig);

/**---------------------- Destructor ------------------------------------------
 * @pre None.
 * @post This TransFactory object has been cleanly deleted.
 */
    virtual ~TransFactory();

/**---------------------- buildAction() ---------------------------------------
 * Provides a Transaction pointer to a specified type of transaction. If there
 * is no transaction type at the index hashed to by the given character, then
 * a NULL pointer is returned.
 * @param actionCode  Character code for the desired type of transaction.
 *                    Should hash to the index of an actual object.
 * @param infile  Character stream used to initialize a type of transaction.
 *                This is passed to the Transaction that will be initialized.
 * @pre actionCode is a character that represents a type of transaction;
 *      current accepted values are 'B', 'H', 'R', and 'S'. infile contains a
 *      valid initialization string.
 * @post A new Transaction object exists. The characters used to initialize the
 *       Transaction have been removed from infile.
 * @return A pointer to a type of Transaction object.
 */
    Transaction* buildAction(char actionCode, ifstream& infile) const;

private:
    
    Transaction *factory[ACTIONSIZE];   // where the factory workers are held

/**---------------------- hashIndex() -----------------------------------------
 * Provides an index into this Factory based on the provided character.
 * @param basis  The character from which to derive an index. Should be a
 *               capital letter.
 * @pre basis is a character that represents a type of transaction. Current
 *      accepted values are 'B', 'H', 'R', and 'S'.
 * @post none.
 * @return A positive integer within the bounds of this Factory's hash table.
 */
    int hashIndex(char basis) const;

/**---------------------- destroyFactory() ------------------------------------
 * Cleanly deletes the elements of this Factory so that it can be discarded.
 * @pre None.
 * @post This TransFactory object has been cleanly deleted.
 */
    void destroyFactory(void);

}; // end class TransFactory

#endif	/* _TRANSFACTORY_H */
