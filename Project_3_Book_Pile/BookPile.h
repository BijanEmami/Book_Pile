/**
* Bijan Emami
* BookPile Project 3
**/


#ifndef BOOKPILE_H
#define BOOKPILE_H
#include "Book.h"
#include <string>
using namespace std;

class BookPile
{
	private:
		Book* headPtr;
		int itemCount;

		/**
		* Helper function to find the position of a Book object.
		* @param position gets position of Book object.
		* @return curPtr current pointer to the position of the Book object.
		**/
		Book* getBookAt(int position) const;

		/**
		* Gets title length of specified book title
		* @param bookTitle specific title to get length of.
		* @return returns length of book title including spaces and punctuation.
		**/
		int getTitleLength(string bookTitle);

	public:

		/**
		* Default constructor
		**/
		BookPile();

		/**
		* Copy constructor.  Provides a deep copy.
		**/
		BookPile(const BookPile& aPile);

		/**
		* destructor
		**/
		virtual ~BookPile();

		/**
		* Removes book after being located by the string title
		* @param bookTitle desired title to locate for removal.
		* @return returns true if book was successfully removed.
		**/
		bool removeBook(string bookTitle);

		/**
		* Removes book after being located by the string title
		* @param position within the link to locate for removal.
		* @return returns true if book was successfully removed.
		**/
		bool removeBook(int position);

		/**
		* Adds a new book to the pile based of of the length of the title.
		* Does not add the book if the title is an empty string or ithe thitle already
		* exists.
		* @param bookTitle title of the new book to be added.
		* @return returns true if book was added.
		**/
		bool addBook(string bookTitle);

		/**
		* Finds a book within the pile by searching for the string title.
		* @param bookTitle desired title to search for.
		* @return returns the position within the pile as an integer
		**/
		int findBook(string bookTitle);

		/**
		* Traverses the pile and displays the books within as a numbered list with
		* the book title and the length of the title.
		* @return void
		**/
		void displayPile();

		/**
		* Returns the book at the given position number where 1 is the top of the pile. 
		*Returns empty string if the position is invalid.  Uses getBookAt function.
		* @param desired position to get the book title from within the pile.
		* @return returns the title of the book desired.
		**/
		string getBook(int position);

		/**
		* Changes the name of a book.  May change books position within the pile.  If newName
		* is an empty string or oldName doesn't exist within the pile, the pile will not change.
		* @param oldName name of book title you wish to change.
		* @param newName name you wish to change oldName into.
		* @return returns true if name change was successful.
		**/
		bool renameBook(string oldName, string newName);

		/**
		* finds amount of books within the pile.
		* return returns the amount of books within the pile.
		**/
		int bookCount();

		/**
		* removes all the books in the pile.
		* @return void
		**/
		void clear();

		/**
		* Checks to see if book pile is empty
		* used as a helper function for the clear() function
		* @return returns true if the book pile is empty.
		**/
		bool isEmpty();
	
};

#endif
