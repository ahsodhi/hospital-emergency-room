/**
 * @file PriorityQueueAPI.h
 * @author Anirduh Sodhi
 * @date October 2017
 * @brief File containing the function definitions of a priority queue data structure
 */

#ifndef QUEUE_API
#define QUEUE_API

/**
 * A priority queue is a wrapper around the Linked List Struct
 */
typedef struct priorityQueue {
	List *list;
	int count;
} PriorityQueue;

/**
 * @brief      Creates a Priority Queue.
 *
 * @param[in]  printFunction    The print function for the queue
 * @param[in]  deleteFunction   The delete function for a single item in the queue
 * @param[in]  compareFunction  The compare function for two items in the queue
 *
 * @return     Pointer to the newly created priority queue
 */
PriorityQueue *createPriorityQueue(void (*printFunction)(void *toBePrinted),
					 void (*deleteFunction)(void *toBeDeleted),
					 int (*compareFunction)(const void *first,const void *second));

/**
 * @brief      Deletes the priority queue
 *
 * @param      queue  The pointer to the initialized Priority Queue
 */
void deletePriorityQueue(PriorityQueue *queue);

/**
 * @brief      Inserts a data item to the queue based on priority
 *
 * @param      queue  The priority queue
 * @param      data   The data to be inesert
 */
void insert(PriorityQueue *queue, void *data);

/**
 * @brief      Removes The data item from the front of the priority queue
 *
 * @param      queue  The pointer to the initialized Priority Queue 
 */
void pop(PriorityQueue *queue);

/**
 * @brief      Gets the item at the front of the queue
 *
 * @param      queue  The priority queue
 *
 * @return     The item at the front of the queue
 */
void *peek(PriorityQueue *queue);

/**
 * @brief      Removes the given item from the queue
 *
 * @param      queue  The priority queue
 * @param      data   The data item to be removed
 */
void removeFromQueue(PriorityQueue *queue, void *data);

/**
 * @brief      Determines if priority queue empty.
 *
 * @param      queue  The priority queue
 *
 * @return     1 if empty, 0 otherwise.
 */
int isEmpty(PriorityQueue *queue);

#endif