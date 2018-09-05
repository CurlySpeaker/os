#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node * next;
}node;

typedef struct LinkedList{
	node * head;
}list;

void print_list(list * l){
	if (l->head == NULL){
		printf("Linked list is empty\n");
		return;
	}
	node * cursor = l->head;
	while (cursor != NULL){
		printf("%d ", cursor->data);
		cursor = cursor->next;
	}
	printf ("\n");
}

void insert_node(node* n, int val){
	if (n == NULL) {
		printf("Your node is NULL, so you can't insert something after it\n");
		return;
	}
	else{
		node * tmp = malloc(sizeof(node));
		tmp->data = val;
		tmp->next = n->next;
		n->next = tmp;
	}
}

void delete_node(list * l, node * n){
	if (l->head == NULL || n == NULL){//list is empty or node is empty
		printf("There is nothing to delete\n");
		return;
	}
	if (l->head == n){//node is a head of the list
		l->head = l->head->next;
		return;
	}
	//node is not head
	node * cursor = l->head;
	while(cursor->next != NULL && cursor->next != n ){
		cursor = cursor->next;
	}
	if (cursor->next == NULL){
			printf ("No such node in this list\n");
			return;
	}
	cursor->next = cursor->next->next;
}


int main(){
	
	list * list = NULL;
	list = malloc(sizeof(list));
	node * root = malloc(sizeof(node));
	root->data = 2;
	root->next = NULL;
	
	delete_node(list, root);
	print_list(list);		
	
	list->head = root;
	print_list(list);

	insert_node(root, 0);
	print_list(list);

	insert_node(root->next, -1);
	print_list(list);
	
	insert_node(root, 0);
	print_list(list);
	
	delete_node(list, list->head->next);
	print_list(list);		
	
	insert_node(list->head->next->next,3);
	print_list(list);
	
	delete_node(list, list->head);
	print_list(list);
	
	insert_node(list->head->next, 7);
	print_list(list);

	delete_node(list, list->head->next);
	print_list(list);		
	
	node * a = malloc(sizeof(node));
	a->next = NULL;
	a->data = 5;
	delete_node(list, a);
	
	delete_node(list, list->head->next->next);
	print_list(list);
	
	delete_node(list, list->head);
	print_list(list);
	
	return 0;
}

