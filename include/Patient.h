/**
 * @file Patient.h
 * @author Anirduh Sodhi
 * @date October 2017
 * @brief File containing the data definitions of a Patient struct
 */

#ifndef PATIENT_H
#define PATIENT_H

/**
 * Struct definition of a Patient and its data fields
 */
typedef struct patient {
	char *patientID;
	int priority;
	char *symptomCode;
	int timeFinished;
} Patient;

/**
 * @brief      Creates a patient.
 *
 * @param      patientID     The patient id
 * @param[in]  priority      The priority
 * @param      symptomCode   The symptom code
 *
 * @return     The pointer to the newly initialized Patient struct
 */
Patient *createPatient(char *patientID,
					   int priority,
					   char *symptomCode);

/**
 * @brief      Deletes a patient and frees memory
 *
 * @param      patient  The patient to be deleted
 */
void deletePatient(void *patient);

/**
 * @brief      Compares two patients based on priority
 *
 * @param[in]  a     The pointer to the first patient struct
 * @param[in]  b     The pointer to the second patient struct
 *
 * @return     -1 if a is higher priority, 1 if b is higher, 0 if both are same priority
 */
int comparePatient(const void *a, const void *b);

/**
 * @brief      Prints information about a patient to the console
 *
 * @param      patient  The patient
 */
void printPatient(void *patient);

/**
 * @brief      Determines the processing time for the patient based on symptom code
 *
 * @param      patient  The patient
 *
 * @return     The required processing time. 0 if no match for symptom code is found;
 */
int getProcessingTime(Patient *patient);

#endif