struct Node {

	int data;
	struct Node *next;
};

int push(struct Node **head, int data) {

	struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->data = data;
	tmp->next = (*head);
	(*head) = tmp;
}

int insertAfter(struct Node *prevNode, int data) {

	if (prevNode == NULL) {
		return -1;
	}

	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
	tmp->data = data;
	tmp->next = prevNode->next;
	prevNode->next = tmp;

}

void append(struct Node **head, int data) {

	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));

	struct Node *last = *head;

	tmp->data = data;
	tmp->next = NULL;

	if (*head == NULL) {
		*head = tmp;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = tmp;

	return;
}

void printList(struct Node *node) {

	while(node != NULL) {

		printf("%d ", node->data);
		node = node->next;
	}
}