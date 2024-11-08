/*
 * main.c
 *
 *  Created on: Nov 7, 2024
 *      Author: vishw
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	int rollNo;
	char name[20];
	char dept[20];
	struct student *newStudent;

} Student;

Student *firstStudent;

void Insert();
void Delete(int position);
void EditUpdate(int position);
void PrintStudents();
void FreeMemory();

int main() {
	firstStudent = NULL;
	int i;

//	for (i = 0; i < 3; i++) {
//		Insert();
//	}
	printf("---------student records ------ \n");
	Delete(2);
	EditUpdate(1);
	PrintStudents();
	FreeMemory();
	return 0;
}

void Insert() {
	Student *temp = (Student*) malloc(sizeof(Student));

	if (temp == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	printf("Enter the RollNumber \n");
	fflush(stdout);
	scanf("%d", &temp->rollNo);
	printf("Enter the name \n");
	fflush(stdout);
	scanf("%20s", temp->name);
	printf("Enter the department \n");
	fflush(stdout);
	scanf("%20s", temp->dept);
	temp->newStudent = NULL;

	if (firstStudent == NULL) {
		firstStudent = temp;
		return;
	}

	Student *current = firstStudent;
	while (current->newStudent != NULL) {
		current = current->newStudent;
	}
	current->newStudent = temp;

}

void EditUpdate(int position) {
	Student *temp = firstStudent;

	if (temp == NULL) {
		printf("List does not exist");
		return;
	}

	int i;
	for (i = 0; i < position; i++) {
		if (temp == NULL) {
			printf("Out of bounds");
			return;
		}
		temp = temp->newStudent;
	}

	Student *studentToBeEdited = temp;
	printf("Edit and update the record \n");
	printf("Enter the RollNumber \n");
	fflush(stdout);
	scanf("%d", &studentToBeEdited->rollNo);
	printf("Enter the name \n");
	fflush(stdout);
	scanf("%20s", studentToBeEdited->name);
	printf("Enter the department \n");
	fflush(stdout);
	scanf("%20s", studentToBeEdited->dept);

}

void Delete(int position) {
	Student *temp = firstStudent;

	if (temp == NULL) {
		printf("List does not exist");
		return;
	}

	if (position == 0) {
		firstStudent = temp->newStudent;
		free(temp);
		return;
	}

	int i;
	for (i = 0; i < position - 2; i++) {
		if (temp == NULL) {
			printf("Out of bounds");
			return;
		}
		temp = temp->newStudent;
	}

	Student *studentToBeDeleted = temp->newStudent;
	temp->newStudent = studentToBeDeleted->newStudent;
	free(studentToBeDeleted);
}

void PrintStudents() {
	Student *temp = firstStudent;
	while (temp != NULL) {
		printf("RollNumber:  %d\n", temp->rollNo);
		printf("Name: %s \n", temp->name);
		printf("dept: %s \n", temp->dept);

		temp = temp->newStudent;
	}
}

void FreeMemory() {
	Student *temp = firstStudent;
	while (temp != NULL) {
		temp = temp->newStudent;
		free(temp);
	}
	firstStudent = NULL;
}

