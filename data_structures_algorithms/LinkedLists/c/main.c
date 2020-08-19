#include <stdio.h>
#include <stdlib.h>
#include "singlyLL.c"

int main() {

	struct Node *head = NULL;

	append(&head, 6); 
	append(&head, 2); 
	append(&head, 5); 
	insertAfter(head, 1);
	push(&head, 0);
	printList(head);
}