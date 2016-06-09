/*
 * @file    DVDFactory.h
 * @brief   This class produces objects derived from DVD media. It holds a hash
 *          table of DVD media pointers, with regognized objects at determined
 *          indexes. To get an instance of a desired object, a character
 *          representing that object is hashed to the index of the object and
 *          an ifstream is passed with information to initialize the object. A
 *          character may also be passed to specify a media type, but this
 *          functionality if not implemented. NULL is returned if the provided
 *          character does not hash to the location of a known object. This
 *          factory is static and its instances are immutable.
 * @author  Brendan Sweeney, SID 1161836
 * @date    March 9, 2012
 */

#ifndef _DVDFACTORY_H
#define	_DVDFACTORY_H

#include <fstream>

using namespace std;
class DVDMedia;                     // forward declaration for DVDMedia
const int GENRESIZE = 'Z' - 'A';    // size for hash table


class DVDFactory
{
public:

/**---------------------- Default Constructor ---------------------------------
 * Creates a DVDFactory object with a full array of DVDMedia pointers. All
 * known descendants of DVDMedia have an object at an index that can be found
 * by hashing a capital letter character representing that object.
 * @pre None.
 * @post A DVDFactory object exists with an array that contains an object for
 *       each known descendant of DVDMedia.
 */
    DVDFactory();

/**---------------------- Default Constructor ---------------------------------
 * Creates a DVDFactory object with a full array of DVDMedia pointers. All
 * known descendants of DVDMedia have an object at an index that can be found
 * by hashing a capital letter character representing that object. A Factory is
 * immutable, so this just calls the default constructor.
 * @pre None.
 * @post A DVDFactory object exists with an array that contains an object for
 *       each known descendant of DVDMedia.
 */
    DVDFactory(const DVDFactory& orig);

/**---------------------- Destructor ------------------------------------------
 * @pre None.
 * @post This DVDFactory object has been cleanly deleted.
 */
    virtual ~DVDFactory();

/**---------------------- buildMovie() ----------------------------------------
 * Provides a DVDMedia pointer to a specified type of movie. If there is no
 * movie type at the index hashed to by the given character, then a NULL
 * pointer is returned.
 * @param genreCode  Character code for the desired bype of movie. Should hash
 *                   to the index of an actual object.
 * @param infile  Character stream used to initialize a type of movie. This is
 *                passed to the DVDMedia that will be initialized.
 * @pre genreCode is a character that represents a type of movie; current
 *      accepted values are 'C', 'D', and 'F'. infile contains a valid
 *      initialization string.
 * @post A new DVDMedia object exists. The characters used to initialize the
 *       DVDMedia have been removed from infile.
 * @return A pointer to a type of DVDMedia object.
 */
    DVDMedia* buildMovie(char genreCode, ifstream& infile) const;

/**---------------------- buildMovie() ----------------------------------------
 * Provides a DVDMedia pointer to a specified type of movie. If there is no
 * movie type at the index hashed to by the given character, then a NULL
 * pointer is returned.
 * @param genreCode  Character code for the desired type of movie. Should hash
 *                   to the index of an actual object.
 * @param infile  Character stream used to initialize a type of movie. This is
 *                passed to the DVDMedia that will be initialized.
 * @param mediaCode  Character code for the desired type of media. Should hash
 *                   to the index of an actual object. NOTE: This functionality
 *                   has not been implemented. Instead, this character just
 *                   tells the target DVDMedia object to expect a different
 *                   format when reading infile.
 * @pre genreCode is a character that represents a type of movie; current
 *      accepted values are 'C', 'D', and 'F'. infile contains a valid
 *      initialization string.
 * @post A new DVDMedia object exists. The characters used to initialize the
 *       DVDMedia have been removed from infile.
 * @return A pointer to a type of DVDMedia object.
 */
    DVDMedia* buildMovie(char genreCode, ifstream& infile,
                         char mediaCode) const;

private:

    DVDMedia *factory[GENRESIZE];   // where the factory workers are held

/**---------------------- hashIndex() -----------------------------------------
 * Provides an index into this Factory based on the provided character.
 * @param basis  The character from which to derive an index. Should be a
 *               capital letter.
 * @pre basis is a character that represents a type of DVD media. Current
 *      accepted values are 'C', 'D', and 'F'.
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

}; // end class DVDFactory

#endif	/* _DVDFACTORY_H */
