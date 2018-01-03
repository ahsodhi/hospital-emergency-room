#include <stdio.h>
#include <ctype.h>
#include "LinkedListAPI.h"
#include "PriorityQueueAPI.h"
#include "Patient.h"

int main(int argc, char **argv) {

	if (!argv[1]) {
		puts("Input file unspecified. Exiting");
		return -1;
	}

	FILE *inputFile = fopen(argv[1], "r");

	if (!inputFile) {
		puts("Error opening input file. Exiting.");
		return -1;
	}

	PriorityQueue *queue = createPriorityQueue(&printPatient, &deletePatient, &comparePatient);
	List *patientList = initializeList(&printPatient, &deletePatient, &comparePatient);

	while (!feof(inputFile)) {
		char buf[256];
		fgets(buf, 256, inputFile);
		char *patientID = malloc(sizeof(char) * 64);
		char *patientSymptomCode = malloc(sizeof(char) * 64);
		int patientPriority;
		sscanf(buf, "%s %d %s", patientID, &patientPriority, patientSymptomCode);
		Patient *patient = createPatient(patientID, patientPriority, patientSymptomCode);
		insert(queue, patient);
		insertBack(patientList, patient);
	}

	fclose(inputFile);

	// TODO: handle incorrect menu choice
	int choice = 0;
	while (choice != 3 && choice != 2) {
		puts("1. Add new patient");
		puts("2. Process full simulation");
		puts("3. Exit");
		char *input = malloc(sizeof(char) * 256);
		scanf("%s", input);
		choice = atoi(input);
		if (choice > 3 || choice <= 0)
			puts("Invalid Choice.");
		if (choice == 1) {
			char *patientID = malloc(sizeof(char) * 64);
			char *patientSymptomCode = malloc(sizeof(char) * 64);
			int patientPriority;
			printf("Enter patient ID: ");
			scanf("%s", patientID);
			printf("Enter patient priority (1-5): ");
			scanf("%d", &patientPriority);
			printf("Enter patient symptom code: ");
			scanf("%s", patientSymptomCode);
			Patient *patient = createPatient(patientID, patientPriority, patientSymptomCode);
			insert(queue, patient);
			insertBack(patientList, patient);
			puts("New patient added.");
		}
	}

	if (choice == 3)
		return 0;

	int time = 0;
	while (!isEmpty(queue)) {
		Patient *patient = (Patient*) peek(queue);
		int processingTime = getProcessingTime(patient) + 1;
		time += processingTime;
		patient->timeFinished = time;
		pop(queue);
	}

	puts("Patient ID\tPriority\tSymptom Code\tTime Finished");
	printForward(patientList);

	getchar();
	char c = 0;
	scanf("%c", &c);
	while (c != '\n')
		scanf("%c", &c);

	return 0;
}