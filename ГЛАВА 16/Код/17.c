#include <stdio.h>
#include <string.h>
#define TSIZE 45 		

struct film
{
	char title[TSIZE];
	int rating; 
};
typedef struct film Item;

typedef struct node
{
	Item item;
	struct node * next;
} Node;
typedef Node * List;


int main(void)
{
	Item temp;
	Node st_node;
	Node * pt_node;
	List pt_list;

	struct node sample =
	{
		{"Hello", 10}
	};

	st_node = sample;

	pt_node = &sample;

	pt_list = &sample;

	printf("sample - %s %d\n", sample.item.title, sample.item.rating);
	printf("st_node - %s %d\n", st_node.item.title, st_node.item.rating);

	printf("&sample - %p\n", &sample);

	printf("&pt_node - %p\n", &pt_node);
	printf("&pt_node->item.title[0] - %p\n", &pt_node->item.title[0]);
	printf("pt_node - %p\n", pt_node);

	printf("&pt_list - %p\n", &pt_list);
	printf("pt_list - %p\n", pt_list);

	printf("pt_node - %s %d\n", pt_node->item.title, pt_node->item.rating);
	printf("pt_list - %s %d\n", pt_list->item.title, pt_list->item.rating);






	return 0;
}
