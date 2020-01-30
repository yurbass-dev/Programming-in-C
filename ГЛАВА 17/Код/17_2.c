#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h> /* функциональная возможность С99 */
/* объявления, специфичные для програ!^ш */
#define TSIZE 45 /* размер массива для хранения названия */ 
struct film
{
	char title[TSIZE];
	int rating; 
};
/* определения общих типов */
typedef struct film Item;
typedef struct node
{
	Item item;
	struct node * next; 
} Node;
typedef Node * List;

void InitializeList(List * plist);
bool ListlsEmpty(const List *plist);
bool ListlsFull(const List *plist);
unsigned int ListltemCount(const List *plist);
bool AddItem(Item item, List * plist);
void Traverse (const List *plist, void (* pfun)(Item item) );
void EmptyTheList(List * plist);

#endif
