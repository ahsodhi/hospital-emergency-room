#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Patient.h"

Patient *createPatient(char *patientID,
					   int priority,
					   char *symptomCode) {
	Patient *newPatient = malloc(sizeof(Patient));
	newPatient->patientID = patientID;
	newPatient->priority = priority;
	newPatient->symptomCode = symptomCode;
	newPatient->timeFinished = -1;
	return newPatient;
}

void printPatient(void *patient) {
	Patient *p = (Patient*) patient;
	printf("%s\t\t%d\t\t%s\t\t%d\n", p->patientID, p->priority, p->symptomCode, p->timeFinished);
}

int comparePatient(const void *a, const void *b) {
	Patient *p1 = (Patient*) a;
	Patient *p2 = (Patient*) b;
	if (p1->priority < p2->priority)
		return -1;
	else if (p1->priority > p2->priority)
		return 1;
	else
		return 0;
}

void deletePatient(void *patient) {
	// dummy function
	// patient is still needed for output even if its removed from ADT
	// free(patient)
}

int getProcessingTime(Patient *patient) {
	char *code = patient->symptomCode;
	if (!strcmp(code, "CV") ||
		!strcmp(code, "MH") ||
		!strcmp(code, "NC"))
		return 5;
	else if (!strcmp(code, "HN"))
		return 3;
	else if (!strcmp(code, "EV"))
		return 10;
	else if (!strcmp(code, "GI") ||
			 !strcmp(code, "SK"))
		return 2;
	else if (!strcmp(code, "EC") ||
			 !strcmp(code, "RC"))
		return 1;
	else if (!strcmp(code, "SA"))
		return 7;
	else if (!strcmp(code, "TR"))
		return 4;
	return 0;
}