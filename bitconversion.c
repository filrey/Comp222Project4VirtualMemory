#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Converts an integer 

unsigned int int_to_int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
}

int main()
{

	int x = 323;
	int z = int_to_int(x);

	printf("%d \n", z );


	return 0;
}