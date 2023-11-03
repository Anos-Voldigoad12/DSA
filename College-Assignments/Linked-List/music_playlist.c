#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
	char *title;
	char *artist;
	struct Song *next;
};
typedef struct
{
	struct Song* head;
	int length;
}Playlist;

Playlist* createPlaylist();
void addSong(char title[], char artist[],Playlist* p);
void deleteSong(char title[],Playlist* p);
void displayPlaylist(Playlist* p);
void playPlaylist(Playlist* p);
int searchSong(char title[],Playlist* p);

Playlist* createPlaylist()
{
	Playlist* newPlaylist = (Playlist *) malloc(sizeof(Playlist));
	newPlaylist->head = NULL;
	newPlaylist->length = 0;
	return newPlaylist;
}
void addSong(char title[], char artist[],Playlist* p)
{
	struct Song* newSong = (struct Song*) malloc(sizeof(struct Song));
	newSong->title = (char *) malloc((strlen(title)+1)*sizeof(char));
	newSong->artist = (char *) malloc((strlen(artist)+1)*sizeof(char));
	strcpy(newSong->title,title);
	strcpy(newSong->artist,artist);
	newSong->next = NULL;
	if(p->head==NULL)
		p->head = newSong;
	else
	{
		struct Song* cur = p->head;
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = newSong;
	}
	p->length++; 
}
void deleteSong(char title[],Playlist* p)
{
	if(p->head==NULL)
	{
		printf("\nEmpty Playlist Exception!\n");
		return;
	}
	if(strcmp(p->head->title,title)==0)
	{
		p->head = p->head->next;
		p->length--;
	}
	else if(p->head->next==NULL)
	{
		printf("\nTitle Not Found Exception!\n");
		return;
	}
	else
	{
		struct Song* cur = p->head;
		while(cur->next!=NULL)
		{
			if(strcmp(cur->next->title,title)!=0)
				cur = cur->next;
			else
			{
				struct Song* temp = cur->next; 
				cur->next = cur->next->next;
				free(temp->title);
				free(temp->artist);
				free(temp);
				p->length--;
				return;		
			}			
		}
		printf("\nTitle Not Found Exception!\n");
	}
}
void displayPlaylist(Playlist* p)
{
	if(p->head==NULL)
		printf("\nEmpty Playlist!\n");
	else
	{
		struct Song* cur = p->head;
		printf("========================\n");
		printf("         PLAYLIST       \n");
		printf("========================\n");
		while(cur!=NULL)
		{
			printf("\nSong Title  : %s\n",cur->title);
			printf("Song Artist : %s\n",cur->artist);
			cur = cur->next;
		}
		printf("========================\n");
	}
}
void playPlaylist(Playlist* p)
{
	if(p->head==NULL)
		printf("\nEmpty Playlist!\n");
	else
	{
		struct Song* cur = p->head;
		while(cur!=NULL)
		{
			printf("Now Playing: %s\n",cur->title);
			cur = cur->next;
		}
		printf("\n");
	}
}
int searchSong(char title[],Playlist* p)
{
	if(p->head!=NULL)
	{
		int i;
		struct Song* cur = p->head;
		for(i=0;cur!=NULL;i++)
		{
			if(strcmp(cur->title,title)==0)
				return i;
			cur = cur->next;
		}
		return -1;
	}
	else
	{
		printf("\nEmpty Playlist Exception!\n");
		return -1;
	}
} 
void main()
{
	Playlist* p = createPlaylist();
	char title[50], artist[20];
	//strcpy(song,"Tum Hi Ho");
	//strcpy(artist,"Arijit Singh");
	int n;
	while(1)
	{
		printf("\n\n\tMenu\t\n");
		printf("1. Add Song To Playlist\n");
		printf("2. Delete Song From Playlist\n");
		printf("3. Display Playlist\n");
		printf("4. Play Playlist\n");
		printf("5. Search Song\n");
		printf("6. Exit Program\n");
		printf("\nChoose a List Operation: "); scanf("%d",&n);
		switch(n)
		{
			case 1: 
				printf("Enter song title to insert: "); scanf(" %[^\n]s",title);
				printf("Enter song artist to insert: "); scanf(" %[^\n]s",artist);
				addSong(title,artist,p);
				break;
			case 2:
				printf("Enter song title to delete: "); scanf(" %[^\n]s",title);
				deleteSong(title,p);
				break;
			case 3: 
				displayPlaylist(p);
				break;
			case 4:
				playPlaylist(p);
				break;
			case 5:
				printf("Enter song to search: "); scanf(" %[^\n]s",title);
				printf("%s found at: position %d\n",title,searchSong(title,p));
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid Choice! Please try again!\n");
		}
	}	
}
