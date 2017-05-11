//Author: Filiberto Reyes
//California State University Northridge

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned int int_to_int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
}

struct pageTable {
	int vp[100];
	int pf[100];
	int marker[100];
	int length;
};


int main()
{
	int choice;
	int mainMemSize;
	int pageSize;
	int policy;
	int i, j;
	int test;

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

			struct pageTable table1;

			// initialize page table
			for (i = 0; i < 100; i++) {
				table1.vp[i] = 0;
				table1.pf[i] = 0;
				table1.marker[i] = 0;
			}

			printf("Enter page size (words/page): ");
			scanf_s("%i", &pageSize);
			printf("\n");

			// set page table size
			table1.length = mainMemSize / pageSize;

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

