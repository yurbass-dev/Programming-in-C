#include <stdio.h>
#include <stdlib.h>
#include "17_3list.h"

/* прототип локальной функции */
static void CopyToNode(Item source, Item * destination);

/* функции интерфейса */
/* устанавливает список в пустое состояние */ 
void InitializeList(List * plist)
{
	plist->items = 0;
}

/* возвращает true, если список пуст */ 
bool ListIsEmpty(const List * plist)
{
	if (plist->items == 0)
		return true; 
	else
		return false;
}

/* возвращает true, если список полон */ 
bool ListIsFull(const List * plist)
{
	if (plist->items == MAXSIZE)
		return true;
	else
		return false;
}

/* возвращает количество узлов */
unsigned int ListItemCount(const List * plist)
{
	return plist->items; 
}

/* создает узел для хранения элемента и добавляет его в конец */
/* списка, указанного переменной plist (медленная реализация) */ 
bool AddItem(Item item, List * plist)
{
	if (plist->items >= MAXSIZE)
		return false;
	else
	{
		CopyToNode(item, &plist->entries[plist->items]);
		plist->items++;
	}
	
	return true;
}

/* посещает каждый узел и выполняет функцию, указанную pfun */ 
void Traverse (const List * plist, void (* pfun)(Item item))
{
	int index = 0;

	while (index < plist->items) 
	{
		(*pfun)(plist->entries[index]) ; /* применение функции к элементу */ 
		index++;
	}
}

/* освобождает память, выделенную функцией malloc() */ 
/* устанавливает указатель списка в NULL */ 
void EmptyTheList(List * plist)
{
	plist->items = 0;
}

/* определение локальной функции */
/* копирует элемент в узел */
static void CopyToNode (Item source, Item * destination) 
{
	*destination = source; 		/* копирование структуры */ 
}