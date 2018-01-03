#include "LinkedListAPI.h"
#include "PriorityQueueAPI.h"

PriorityQueue *createPriorityQueue(void (*printFunction)(void *toBePrinted),
					 void (*deleteFunction)(void *toBeDeleted),
					 int (*compareFunction)(const void *first,const void *second)) {
	PriorityQueue *queue = malloc(sizeof(PriorityQueue));
	queue->list = initializeList(printFunction, deleteFunction, compareFunction);
	queue->count = 0;
	return queue;
}

void deletePriorityQueue(PriorityQueue *queue) {
	deleteList(queue->list);
	queue->count = 0;
	free(queue);
}

void insert(PriorityQueue *queue, void *data) {
	insertSorted(queue->list, data);
	queue->count += 1;
}

void pop(PriorityQueue *queue) {
	void *front = getFromFront(queue->list);
	if (front) {
		queue->count -= 1;
		deleteNodeFromList(queue->list, front);
	}
}

void *peek(PriorityQueue *queue) {
	return getFromFront(queue->list);
}

void removeFromQueue(PriorityQueue *queue, void *data) {
	deleteNodeFromList(queue->list, data);
	queue->count -= 1;
}

int isEmpty(PriorityQueue *queue) {
	if (queue->count == 0)
		return 1;
	return 0;
}