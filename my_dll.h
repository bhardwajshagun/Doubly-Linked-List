#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node {
	int data;
	struct node* next;
	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL {
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
	node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
dll_t* create_dll() {
	dll_t* myDLL = NULL;
	myDLL = malloc(sizeof(dll_t));
	myDLL->count = 0;
	myDLL->head = NULL;
	myDLL->tail = NULL;
	return myDLL;
}

// Free DLL
// Removes a DLL and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t) {
	if (t == NULL) {
		exit(1);
	}
	else {
		node_t* temp = NULL;
		while (t->head != NULL) {
			temp = t->head;
			t->head = t->head->next;
			free(temp);
		}
		free(t);
	}
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t* l) {
	if (l == NULL) {
		exit(1);
	}
	if (l->count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item) {
	if (l == NULL) {
		free_dll(l);
		exit(1);
	}
	else {
		node_t* temp = NULL;
		temp = malloc(sizeof(node_t));
		if (temp == NULL) {
			return -1;
		}
		temp->data = item;
		temp->previous = NULL;
		if (dll_empty(l) == 1) {
			l->tail = temp;
		}
		else {
			l->head->previous = temp;
		}
		temp->next = l->head;
		l->head = temp;
		l->count++;
		return 0;
	}
}

// push a new item to the end of the DLL ( after the last node in the list).
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item) {
	if (l == NULL) {
		exit(1);
	}
	node_t* temp = NULL;
	temp = malloc(sizeof(node_t));
	if (temp == NULL) {
		return -1;
	}
	temp->data = item;
	temp->next = NULL;
	if (dll_empty(l) == 1) {
		l->head = temp;
	}
	else {
		l->tail->next = temp;
	}
	temp->previous = l->tail;
	l->tail = temp;
	l->count++;
	return 0;
}

// Returns the first item in the DLL. 
// Removes an item from the DLL.
// Removing from an empty DLL should crash the program, call exit(1).
int dll_pop_front(dll_t* t) {
	if (t == NULL) {
		exit(1);
	}
	if (dll_empty(t) == 1) {
		free_dll(t);
		exit(1);
	}
	node_t* temp = t->head;
	int num = t->head->data;
	if (t->head->next == NULL) {
		t->tail = NULL;
	}
	else {
		t->head->next->previous = NULL;
	}
	t->head = t->head->next;
	t->count--;
	temp->next = NULL;
	free(temp);
	return num;
}

// Returns the last item in the DLL. 
// Removes the last item from the DLL.
// Removing from an empty DLL should crash the program, call exit(1).
int dll_pop_back(dll_t* t) {
	if (t == NULL) {
		exit(1);
	}
	if (dll_empty(t) == 1) {
		free_dll(t);
		exit(1);
	}
	node_t* temp = t->tail;
	int num = t->tail->data;
	if (t->tail->previous == NULL) {
		t->head = NULL;
	}
	else {
		t->tail->previous->next = NULL;
	}
	t->tail = t->tail->previous;
	t->count--;
	temp->previous = NULL;
	free(temp);
	return num;
}

// Inserts a new node before the node at the specified position.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed or trying to insert at a negative position or at 
//  a position past the size of the DLL ).
int dll_insert(dll_t* l, int pos, int item) {
	if (pos < 0 || pos > l->count) {
		return -1;
	}
	else if (pos == 0) {
		dll_push_front(l, item);
	}
	else if (pos == l->count) {
		dll_push_back(l, item);
	}
	else {
		node_t* counter = l->head;
		int i;
		for (i = 0; i < pos - 1; i++) {
			counter = counter->next;
		}
		node_t* temp = malloc(sizeof(node_t));
		if (temp == NULL) {
			return -1;
		}
		temp->data = item;
		temp->next = counter->next;
		counter->next->previous = temp;
		counter->next = temp;
		temp->previous = counter;
		l->count++;
		return 0;
	}
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the position is negative or trying to retrive an item at or past the size,
// or the list is empty.
int dll_get(dll_t* l, int pos) {
	if (l == NULL) {
		exit(1);
	}
	if (dll_empty(l) == 1 || pos < 0 || pos > l->count - 1) {
		return -1;
	}
	node_t* counter = l->head;
	int i;
	for (i = 0; i < pos; i++) {
		counter = counter->next;
	}
	return counter->data;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the position is negative or trying to remove an item at or past the size,
// or if the list is empty
int dll_remove(dll_t* l, int pos) {
	if (l == NULL) {
		exit(1);
	}
	if (dll_empty(l) == 1 || pos < 0 || pos > l->count - 1) {
		return -1;
	}
	int item;
	if (pos == 0) {
		item = dll_pop_front(l);
		return item;
	}
	else if (pos == l->count - 1) {
		item = dll_pop_back(l);
		return item;
	}
	else {
		node_t* counter = l->head;
		int i;
		for (i = 0; i < pos; i++) {
			counter = counter->next;
		}
		item = counter->data;
		counter->previous->next = counter->next;
		counter->next->previous = counter->previous;
		l->count--;
		free(counter);
		return item;
	}
}

// DLL Size
// Queries the current size of a DLL
// A DLL that has not been previously created will crash the program.
// (i.e. A NULL DLL cannot return the size)
unsigned int dll_size(dll_t* t) {
	if (t == NULL) {
		exit(1);
	}
	return (unsigned int)t->count;
}

//Prints dll
void dll_print(dll_t* t) {
	if (t == NULL) {
		exit(1);
	}
	printf("Count: %d\n", dll_size(t));
	printf("Printing head to tail:\n");
	printf("Items: ");
	node_t* iterator = t->head;
	while (iterator != NULL) {
		printf("%d ", iterator->data);
		iterator = iterator->next;
	}
	printf("\n");
	printf("Printing tail to head:\n");
	printf("Items: ");
	node_t* reverse_iterator = t->tail;
	while (reverse_iterator != NULL) {
		printf("%d ", reverse_iterator->data);
		reverse_iterator = reverse_iterator->previous;
	}
	printf("\n\n");
}



#endif
