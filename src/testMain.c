#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "PriorityQueueAPI.h"
#include "Patient.h"

void initTest( int *counter, char *info );
void evaluateTest( int pass, int *passedCount );

int main() {
	int *testCount = malloc(sizeof(int));
	*testCount = 0;

	int *passedCount = malloc(sizeof(int));
	*passedCount = 0;

	// Test 1: createPriorityQueue
	initTest(testCount, "Create new priority queue for patients with required user-defined functions");
	PriorityQueue *queue = createPriorityQueue(&printPatient, &deletePatient, &comparePatient);
	puts("Expected: queue points to an address in memory");
	printf("Received: queue = %p\n", (void*) queue);
	evaluateTest(queue != NULL, passedCount);

	// Test 2: insert
	initTest(testCount, "Insert 4 patients with different priorities into the queue");
	Patient *p1 = createPatient("sid", 5, "CV");
	Patient *p2 = createPatient("joe", 2, "HN");
	Patient *p3 = createPatient("kim", 1, "EV");
	Patient *p4 = createPatient("bob", 4, "GI");
	insert(queue, p1); insert(queue, p2); insert(queue, p3); insert(queue, p4);
	puts("Expected: queue->count == 4");
	printf("Received: queue->count == %d\n", queue->count);
	evaluateTest(queue->count == 4, passedCount);

	// Test 3: peek
	initTest(testCount, "Get the patient at the front of queue to ensure patients were enqueued in correct priority");
	Patient *frontPatient = peek(queue);
	puts("Expected: frontPatient->patientID == kim");
	printf("Received: frontPatient->patientID == %s\n", frontPatient->patientID);
	evaluateTest(strcmp(frontPatient->patientID, "kim") == 0, passedCount);

	// Test 4: pop
	initTest(testCount, "Pop the patient from the front of the queue");
	pop(queue);
	frontPatient = peek(queue);
	puts("Expected: frontPatient->patientID == joe");
	printf("Received: frontPatient->patientID == %s\n", frontPatient->patientID);
	evaluateTest(strcmp(frontPatient->patientID, "joe") == 0, passedCount);

	// Test 5: removeFromQueue
	initTest(testCount, "Remove the 2nd patient from the queue using removeFromQueue");
	removeFromQueue(queue, p2);
	puts("Expected: queue->count == 2");
	printf("Received: queue->count == %d\n", queue->count);
	evaluateTest(queue->count == 2, passedCount);

	// Test 6: deletePriorityQueue
	initTest(testCount, "Delete the entire priority queue of patients");
	deletePriorityQueue(queue);
	puts("Expected: queue->count == 0");
	printf("Received: queue->count == %d\n", queue->count);
	evaluateTest(queue->count == 0, passedCount);

	printf("%d / %d Tests Passed\n", *passedCount, *testCount);

	return 0;
}

void initTest(int *counter, char *info)
{
	*counter += 1;
	printf("Test %d: %s\n", *counter, info);
}

void evaluateTest(int pass, int *passedCount)
{
	if (pass) {
		*passedCount += 1;
		puts("Test Passed\n");
	}
	else {
		puts("Test Failed\n");
	}
}