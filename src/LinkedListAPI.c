#include <stdlib.h>
#include "LinkedListAPI.h"

List *initializeList(void (*printFunction)(void *toBePrinted),
					 void (*deleteFunction)(void *toBeDeleted),
					 int (*compareFunction)(const void *first, const void *second)) {

	List *list = malloc(sizeof(List));
	list->compare = compareFunction;
	list->deleteNode = deleteFunction;
	list->printNode = printFunction;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

Node *initializeNode(void *data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

void insertFront(List *list, void *toBeAdded) {
	Node *newNode = initializeNode(toBeAdded);
	if (list->head) {
		Node *oldHead = list->head;
		newNode->next = oldHead;
		oldHead->previous = newNode;
	}
	list->head = newNode;
	if (list->tail == NULL) {
		list->tail = newNode;
	}
}

void insertBack(List *list, void *toBeAdded) {
	Node *newNode = initializeNode(toBeAdded);
	if (list->tail) {
		Node *oldTail = list->tail;
		newNode->previous = oldTail;
		oldTail->next = newNode;
	}
	list->tail = newNode;
	if (list->head == NULL) {
		list->head = newNode;
	}
}

void insertSorted(List *list, void *toBeAdded) {
	Node *target = (Node*) list->head;
	while (target != NULL && list->compare(toBeAdded, target->data) >= 0) {
		target = target->next;
	}
	if (target == list->head) {
		insertFront(list, toBeAdded);
	}
	else if (target == NULL) {
		insertBack(list, toBeAdded);
	}
	else {
		Node *newNode = initializeNode(toBeAdded);
		newNode->next = target;
		newNode->previous = target->previous;
		target->previous->next = newNode;
		target->previous = newNode;
	}
}

void deleteList(List *list) {
	Node *curNode = list->head;
	while (curNode != NULL) {
		list->deleteNode(curNode->data);
		Node *next = curNode->next;
		free(curNode);
		curNode = next;
	}
	free(list);
}

int deleteNodeFromList(List *list, void *toBeDeleted) {
	Node *curNode = list->head;
	if (curNode == NULL) {
		return EXIT_FAILURE;
	}
	while (curNode != NULL) {
		if (curNode->data == toBeDeleted) {
			list->deleteNode(curNode->data);
			Node *next = curNode->next;
			Node *previous = curNode->previous;
			if (list->head == curNode) {
				list->head = next;
			}
			if (list->tail == curNode) {
				list->tail = previous;
			}
			if (next) {
				next->previous = previous;
			}
			if (previous) {
				previous->next = next;
			}
			free(curNode);
			return EXIT_SUCCESS;
		}
		curNode = curNode->next;
	}
	return -1;
}

void *getFromFront(List *list) {
	if (list->head)
		return list->head->data;
	else
		return NULL;
}

void *getFromBack(List *list) {
	if (list->tail)
		return list->tail->data;
	else
		return NULL;
}

void printForward(List *list) {
	Node *curNode = list->head;
	while (curNode != NULL) {
		list->printNode(curNode->data);
		curNode = curNode->next;
	}
}

void printBackwards(List *list) {
	Node *curNode = list->tail;
	while (curNode != NULL) {
		list->printNode(curNode->data);
		curNode = curNode->previous;
	}
}