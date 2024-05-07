#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Read from the program command line 2 or 3 parameters, 
 * the 1st one is the number of rows, the 2nd one is the number of columns.
 * If present, the 3rd parameter must be used as the seed for the maze generation,
 * if the 3rd parameter isn't given generate random seed.
 */

int rows, cols;
int **maze;

int main(int argc, char *argv[]){
	int seed;
	rows = atoi(argv[1]);
	cols = atoi(argv[2]);
	if (argv[3])seed = atoi(argv[3]);
	else seed = time(0);
	srand(seed);
	fprintf(stderr, "Seed: %d\n",seed);
	return 0;
}
