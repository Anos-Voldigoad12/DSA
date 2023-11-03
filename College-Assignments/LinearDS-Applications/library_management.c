#define _XOPEN_SOURCE_EXTENDED 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct Book
{
	char title[50];
	char author[20];
	int publicationYear;
}Book;

typedef struct BookNode
{
	Book *data;
	struct BookNode* next;
}BookNode;
typedef struct
{
	BookNode* front;
}BookList;

typedef struct Genre
{
	char genreName[20];
	BookList *books;
}Genre;

typedef struct GenreNode
{
	Genre *data;
	struct GenreNode* next;
}GenreNode;
typedef struct
{
	GenreNode* front;
}GenreList;

BookList* initBookList()
{
	BookList* list = (BookList *) malloc(sizeof(BookList));
	list->front = NULL;
	return list;
}
BookNode* createBookNode(const char *title, const char *author, int pub)
{
	BookNode* newNode = (BookNode *) malloc(sizeof(BookNode));
	newNode->data = (Book *) malloc(sizeof(Book));
	strcpy(newNode->data->title,title);
	strcpy(newNode->data->author,author);
	newNode->data->publicationYear = pub;
	newNode->next = NULL;
	return newNode;
}
void insertBookAtFront(BookNode* book, BookList* list)
{
	if(book && list)
	{
		book->next = list->front;
		list->front = book;
	}
}
void deleteBookAtFront(BookList* list)
{
	if(list && list->front)
	{
		BookNode *temp = list->front;
		list->front = list->front->next;
		free(temp);
	}
}
void displayBooks(BookList* list)
{
	if(list)
	{
		BookNode *cur;
		printf("======================\n");
		printf("       BOOK LIST      \n");
		printf("======================\n\n");
		for(cur = list->front; cur!=NULL; cur = cur->next)
		{
			printf("Title: %s\n",cur->data->title);
			printf("Author: %s\n",cur->data->author);
			printf("Publication Year: %d\n\n",cur->data->publicationYear);
		}
		printf("======================\n");
	}
}

GenreList* initGenreList()
{
	GenreList* list = (GenreList *) malloc(sizeof(GenreList));
	list->front = NULL;
	return list;
}
GenreNode* createGenreNode(const char *genreName)
{
	GenreNode* newNode = (GenreNode *) malloc(sizeof(GenreNode));
	newNode->data = (Genre *) malloc(sizeof(Genre));
	strcpy(newNode->data->genreName,genreName);
	newNode->data->books = initBookList();
	newNode->next = NULL;
	return newNode;
}
void insertGenreAtFront(GenreNode* genre, GenreList* list)
{
	if(genre && list)
	{
		genre->next = list->front;
		list->front = genre;
	}
}
void deleteGenreAtFront(GenreList* list)
{
	if(list && list->front)
	{
		GenreNode *temp = list->front;
		list->front = list->front->next;
		while(temp->data->books->front)
			deleteBookAtFront(temp->data->books);
		free(temp);
	}
}
void displayGenres(GenreList* list)
{
	if(list)
	{
		GenreNode *cur;
		printf("======================\n");
		printf("       GENRE LIST     \n");
		printf("======================\n\n");
		for(cur = list->front; cur!=NULL; cur = cur->next)
		{
			printf("Genre Name: %s\n",cur->data->genreName);
			printf("Books: \n"); displayBooks(cur->data->books);
			printf("\n\n");
		}
		printf("======================\n");
	}
}

void searchBookByTitle(const char *title, GenreList* list)
{
	GenreNode *curGen;
	BookNode *curBk;
	if(list)
	{
		for(curGen = list->front; curGen!=NULL; curGen = curGen->next)
		{
			for(curBk = curGen->data->books->front; curBk!=NULL; curBk = curBk->next)
			{
				if(strcasecmp(title,curBk->data->title)==0)
				{
					printf("\nTitle: %s\n",curBk->data->title);
					printf("Author: %s\n",curBk->data->author);
					printf("Genre: %s\n",curGen->data->genreName);
					printf("Publication Year: %d\n\n",curBk->data->publicationYear);
					return;
				}
			}
		}
		printf("\n\nBook Not Found!\n\\n");
	}
}
void updateBookDetails(const char *title, const char *author, int pub, GenreList* list)
{
	GenreNode *curGen;
	BookNode *curBk;
	if(list)
	{
		for(curGen = list->front; curGen!=NULL; curGen = curGen->next)
		{
			for(curBk = curGen->data->books->front; curBk!=NULL; curBk = curBk->next)
			{
				if(strcasecmp(title,curBk->data->title)==0)
				{
					strcpy(curBk->data->author,author);
					curBk->data->publicationYear = pub;
					return;
				}
			}
		}
		printf("\n\nBook Not Found!\n\\n");
	}
}
void deleteBookFromGenre(const char* genreName, GenreList *list)
{
	GenreNode *curGen;
	if(list)
	{
		for(curGen = list->front; curGen!=NULL; curGen = curGen->next)
		{
			if(strcasecmp(genreName,curGen->data->genreName)==0)
			{
				if(curGen->data->books->front)
				{
					char *title;
					strcpy(title, curGen->data->books->front->data->title);
					deleteBookAtFront(curGen->data->books);
					printf("Successfully Deleted The Book: %s\n",title);
				}
				else
					printf("No Books Under This Genre\n");
				return;
			}
		}
		printf("\n\nGenre Not Found!\n\\n");
	}
}
void addBookToGenre(BookNode* book, const char* genreName, GenreList *list)
{
	GenreNode *curGen;
	if(list)
	{
		for(curGen = list->front; curGen!=NULL; curGen = curGen->next)
		{
			if(strcasecmp(genreName,curGen->data->genreName)==0)
			{
				insertBookAtFront(book, curGen->data->books);
				return;
			}
		}
		printf("\n\nGenre Not Found!\n\\n");
	}
}
void displayMenu()
{
	printf("\nLIBRARY CATALOG MANAGEMENT SYSTEM\n");
	printf("1. Add new genres to the library catalog.\n");
	printf("2. Add new books under a specific genre.\n");
	printf("3. Delete a genre from the library catalog (and all books under it).\n");
	printf("4. Delete a book from a specific genre.\n");
	printf("5. Display all genres and books in the library catalog.\n");
	printf("6. Exit\n");
	printf("\nChoice: ");
}
void main()
{
	GenreList* list = initGenreList();
	char title[50];
	char author[20];
	char genreName[20];
	int n;
	
	do
	{
		displayMenu(); scanf("%d",&n); fflush(stdin);
		switch(n)
		{
			case 1:
				printf("Genre Name: "); scanf("%s",genreName); fflush(stdin);
				insertGenreAtFront(createGenreNode(genreName),list);
				printf("Genre Added Successfully!\n");
				break;
			case 2:
				printf("Genre Name: "); scanf("%s",genreName); fflush(stdin);
				printf("Book Title: "); scanf(" %[^\n]s",title); fflush(stdin);
				printf("Author: "); scanf(" %[^\n]s",author); fflush(stdin);
				printf("Publication Year: "); scanf("%d",&n); fflush(stdin);
				addBookToGenre(createBookNode(title,author,n),genreName,list);
				printf("Book Added Successfully!\n");
				break;
			case 3:
				if(list->front!=NULL)
				{
					strcpy(genreName,list->front->data->genreName);
					deleteGenreAtFront(list);
					printf("Successfully Deleted The Genre: %s\n",genreName);
				}
				else
					printf("Empty List!\n");
				break;
			case 4:
				if(list->front!=NULL)
				{
					printf("Genre Name: "); scanf("%s",genreName); fflush(stdin);
					deleteBookFromGenre(genreName,list);
				}
				else
					printf("Empty List!\n");
				break;
			case 5:
				displayGenres(list);
				break;
			case 6:
				break;
			default :
				printf("Invalid Choice! Try Again!\n"); 			
		}
	}while(n!=6);
}
