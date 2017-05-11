//Author: Filiberto Reyes
//California State University Northridge

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// converts integer to its binary representation
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
	int virMemAddress;
	int physMemAddress;
	int currVp,currMarker,topMarker = 0;
	int policy;
	int i, j =0;
	int fifoCounter = 0;
	int emptyTable = 0;
	int pageFound = 0;

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
			printf("Enter a virtual memory address to access: ");
			scanf_s("%i", &virMemAddress);

			// when page table is empty
			if (emptyTable == 1) {
				table1.vp[0] = virMemAddress/pageSize;
				table1.pf[0] = 0;
				table1.marker[0] = 0;

				//Fifo
				if (policy == 1)
				{
					fifoCounter++;
				}

			}

			// When it is not empty
			else {
				pageFound = 0;
				currVp = virMemAddress / pageSize;
				// Searches for vp in page table and calculates phys mem address if found
				for (int i = 0; i < table1.length; i++) {
					if (currVp == table1.vp[i]) {
						physMemAddress = virMemAddress - (pageSize * currVp);
						printf("Virtual Address: %d maps to physical address: %d \n",virMemAddress,physMemAddress);
						pageFound = 1;
					}

				}

				// if page is not found page fault and save page in page frame
				if(pageFound == 0) {
					printf("Page fault!");
					if(emptyTable == 1) {
						emptyTable = 0;
						table1.vp[0] = currVp;
						table1.pf[0] = 1;
						// markers for differing policies
						if(policy == 1) {
							table1.marker[0] = fifoCounter;
							fifoCounter++;
						}
						else {
							for (int i=0; i < table1.length; i++) {
								table1.marker[i]++;
							}
						}
					}

					// page is found
					else {
						// for Fifo
						if(policy == 1) {
							for (int i = 0; i < table1.length; ++i)
							{
								if(table1.marker[i] == fifoCounter - 1) {
									table1.vp[i] = currVp;
									table1.pf[i] = 0;
									table1.marker[i] = fifoCounter;
									fifoCounter++;
								}
							}
						}

						//for LRU
						else {
							topMarker = 0;
							for (int i = 0; i < table1.length; ++i)
							{
								currMarker = table1.marker[i];
								if(currMarker > topMarker) {
									topMarker = currMarker;
									j = i; // j is the index with the highest marker
								}
							}
							table1.vp[j] = currVp;
							table1.pf[j] = 0;
							table1.marker[j] = 0;
						}
					}

				}
			}

			// print out page table
			printf("This is where the page table goes \n");
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

