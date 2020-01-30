#include <stdio.h>
#include <stdlib.h>
#include "17_2list.h"

/* прототип локальной функции */
static void CopyToNode(Item item, Node * pnode);

/* функции интерфейса */
/* устанавливает список в пустое состояние */ 
void InitializeList(List * plist)
{
	plist->head = NULL; 
	plist->end = NULL;
}

/* возвращает true, если список пуст */ 
bool ListIsEmpty(const List * plist)
{
	if (plist->head == NULL)
		return true; 
	else
		return false;
}

/* возвращает true, если список полон */ 
bool ListIsFull(const List * plist)
{
	Node * pt;
	bool full;
	pt = (Node *) malloc(sizeof(Node)); 
	if (pt == NULL)
		full = true; 
	else
		full = false; 
	free(pt);

	return full; 
}

/* возвращает количество узлов */
unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = plist->head;	/* установка в начало списка */

	while (pnode != NULL) 
	{
		++count;
		pnode = pnode->next; /*установка в следующии узел*/ 
	}

	return count; 
}

/* создает узел для хранения элемента и добавляет его в конец */
/* списка, указанного переменной plist (медленная реализация) */ 
bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = plist->head;
	
	pnew = (Node *) malloc(sizeof(Node)); 
	if (pnew == NULL)
		return false; 				/* выход из функции в случае ошибки */

	CopyToNode (item, pnew);
	
	pnew->next = NULL;
	if (scan == NULL)
	{
		plist->head = pnew;
	}
	else
	{
		scan = plist->end;
		scan->next = pnew;
	}
	plist->end = pnew;
	
	return true;
}

/* посещает каждый узел и выполняет функцию, указанную pfun */ 
void Traverse (const List * plist, void (* pfun)(Item item))
{
	Node * pnode = plist->head; /* установка в начало списка */

	while (pnode != NULL) 
	{
		(*pfun)(pnode->item) ; /* применение функции к элементу */ 
		pnode = pnode->next; /* переход к следующему элементу */
	}
}

/* освобождает память, выделенную функцией malloc() */ 
/* устанавливает указатель списка в NULL */ 
void EmptyTheList(List * plist)
{
	Node * psave;

	while (plist->head != NULL) 
	{
		psave = plist->head->next;		 /* сохранение адреса следующего узла */ 
		free(plist->head); 				 /* освобождение текущего узла */ 
		plist->head = psave;				 /* переход к следующему узлу */
	}
}

/* определение локальной функции */
/* копирует элемент в узел */
static void CopyToNode (Item item, Node * pnode) 
{
	pnode->item = item; 		/* копирование структуры */ 
}