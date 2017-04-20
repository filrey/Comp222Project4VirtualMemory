//Author: Filiberto Reyes
//California State University Northridge

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
	int choice;
	int mainMemSize;
	int pageSize;
	int policy;

	while (1 == 1) {
		printf("\n");
		printf("Comp222 Assignment#4 Filiberto Reyes\n \n");
		printf("Virtual memory to Main memory mapping: \n");
		printf("--------------------------- \n");
		printf("Choose one of the following options:\n"
			"1) Enter Parameters\n"
			"2) Map Virtual Address\n"
			"3) Quit\n");

		scanf_s("%i", &choice);

		switch (choice) {
		// Enter parameters
		case 1:
			printf("Enter main memory size (words): ");
			scanf_s("%i", &mainMemSize);
			printf("\n");
			printf("Enter page size (words/page): ");
			scanf_s("%i", &pageSize);
			printf("\n");
			printf("Enter replacement policy (0=LRU, 1=FIFO): ");
			scanf_s("%i", &policy);
			printf("\n");
			break;
		
		// Map Virtual Address
		case 2:
			break;

		// Quit Program
		case 3:
			printf("Exiting....\n");
			exit(0);
			break;

		default:
			printf("Error! No selection has been made. Please try again.\n");
		}
	}
    return 0;
}

