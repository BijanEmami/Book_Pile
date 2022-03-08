/**
* Bijan Emami
* BookPile Project 3
**/

#include "BookPile.h"
#include "Book.h"
#include <iostream>
#include <string>
using namespace std;



Book* BookPile::getBookAt(int position) const  
{
	bool isValidPos = (position > 0) && (position <= itemCount);
	
	Book* curPtr = nullptr;

	if (isValidPos)
	{
		int posCount = 1;
		curPtr = headPtr;

		while (posCount < position)
		{
			curPtr = curPtr->getNext();
			posCount++;
		}
	}

	return curPtr;
}

int BookPile::getTitleLength(string bookTitle)
{
	return bookTitle.length();
}

BookPile::BookPile() : headPtr(nullptr), itemCount(0)
{
	
}


BookPile::BookPile(const BookPile& aPile)  
{
	
	
	Book* origBookPtr = aPile.headPtr;

	if (origBookPtr == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		//process to make deep copy
		itemCount = 1;

		headPtr = new Book();

		headPtr->setTitle(origBookPtr->getTitle());

		Book* newBookPtr = headPtr;

		origBookPtr = origBookPtr->getNext();

		//traverse Book Pile to copy each Book in the pile
		while (origBookPtr != nullptr)
		{
			
			string nextBook = origBookPtr->getTitle();

			Book* bookPtr = new Book(nextBook);

			newBookPtr->setNext(bookPtr);

			newBookPtr = newBookPtr->getNext();

			origBookPtr = origBookPtr->getNext();

			itemCount++;
		}

		newBookPtr->setNext(nullptr);
	}
}

BookPile::~BookPile()
{
	clear();
}

bool BookPile::removeBook(string bookTitle)
{
	bool isValidPos = (findBook(bookTitle) > 0) && (findBook(bookTitle) <= itemCount);
Book* curPtr = nullptr;
Book* delPtr = nullptr;

if (isValidPos)
{
	// removal of headPtr
	if (headPtr->getTitle() == bookTitle)
	{
		delPtr = headPtr;
		headPtr = delPtr->getNext();
	}
	// removal if any other position in pile
	else
	{
		int position = findBook(bookTitle);
		curPtr = getBookAt(position - 1);  // Book to be removed
		delPtr = curPtr->getNext();			// copy Book to be removed
		curPtr->setNext(delPtr->getNext()); // set curPtr to next book that is after the book to be deleted
	}

	//deletes the book
	delete delPtr;
	itemCount--;

}

return isValidPos;
}

bool BookPile::removeBook(int position)
{
	bool isValidPos = (position > 0) && (position <= itemCount);
	Book* curPtr = nullptr;
	Book* delPtr = nullptr;


	if (isValidPos)
	{	//removal of headptr
		if (position == 1)
		{
			delPtr = headPtr;
			headPtr = delPtr->getNext();
		}
		else
		{
			curPtr = getBookAt(position - 1);	// Book to be removed
			delPtr = curPtr->getNext();			// copy Book to be removed
			curPtr->setNext(delPtr->getNext());  // set curPtr to next book that is after the book to be deleted
		}
		//deletes the book
		delete delPtr;
		itemCount--;
	}

	return isValidPos;
}


bool BookPile::addBook(string bookTitle)
{
	Book* newPtr = new Book(bookTitle);
	Book* curPtr = headPtr;
	Book* prevPtr = nullptr;

	bool canAddBook = (getTitleLength(bookTitle) != 0);

	if (canAddBook)
	{
		// adds Book as the headPtr checks if null or if headPtr needs to be replaced
		if ((headPtr == nullptr) || (itemCount >= 1) && ((getTitleLength(newPtr->getTitle()) > getTitleLength(curPtr->getTitle()))))
		{
			newPtr->setNext(headPtr);
			headPtr = newPtr;	
			
		}
		//adds Book in order from title length largest to smallest
		else
		{
		
			prevPtr = headPtr;
			curPtr = headPtr->getNext();
			
			//traverse Book Pile to find placement of new Book
			while (curPtr != nullptr && (getTitleLength(newPtr->getTitle()) <= getTitleLength(curPtr->getTitle())))
			{		
				//pointer to previous Book
				prevPtr = curPtr;
				
				//finds next curPtr
				curPtr = curPtr->getNext();
			}

			// new Book placement based on title length
			newPtr->setNext(prevPtr->getNext());
			//moves prevPtr
			prevPtr->setNext(newPtr);
			
		}

		itemCount++;
		
	}

	return canAddBook;
}

int BookPile::findBook(string bookTitle) 
{
	Book* curPtr = headPtr;

	int bookPosition = 1;

	//travers Book pile to find bookTitle
	while (curPtr != nullptr)
	{
		
		curPtr->getTitle();

		if (curPtr->getTitle() == bookTitle)
		{
			return bookPosition;
			break;
		}
		
		curPtr = curPtr->getNext();

		bookPosition++;

	}
	// if book not found
	return -1;

}

void BookPile::displayPile()
{
	int num = 1;
	Book* curPtr = headPtr;
	if (isEmpty())
	{
		cout << "Book pile is empty." << endl;
	}
	//traverse Book Pile to print each entry
	while (curPtr != nullptr)
	{
		
		cout << num << ". " << curPtr->getTitle() << " (" << getTitleLength(curPtr->getTitle()) << ")";
		curPtr = curPtr->getNext();
		cout << endl;
		num++;
	}
	
}

string BookPile::getBook(int position)
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Book* nodePtr = getBookAt(position);
		return nodePtr->getTitle();
	}
	else
	{
		return "";
	}

}

bool BookPile::renameBook(string oldName, string newName)  
{
	int position = findBook(oldName);
	Book* curPtr = nullptr;

	bool isValidPos = (position > 0) && (position <= itemCount);

	if (isValidPos)
	{	
		//gets Book at position
		curPtr = getBookAt(position);
		
		//sets oldName to newName
		curPtr->setTitle(newName);
	}

	return isValidPos;
}

int BookPile::bookCount()
{
	return itemCount;
}

void BookPile::clear()
{
	while (!isEmpty())
		removeBook(1);
}

bool BookPile::isEmpty()
{
	return itemCount == 0;
}