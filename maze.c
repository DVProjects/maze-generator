#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Read from the program command line 2 or 3 parameters, 
 * the 1st one is the number of rows, the 2nd one is the number of columns.
 * If present, the 3rd parameter must be used as the seed for the maze generation,
 * if the 3rd parameter isn't given generate random seed.
 */

enum side {
	BOTTOM	= 0b0001,
	RIGHT	= 0b0010,
	TOP	= 0b0100,
	LEFT	= 0b1000,
};

int rows, cols;
int **maze;

void mazeInit(void){
  maze = (int**)malloc(sizeof(int*)*rows);
	for (int i = 0; i< rows;i++){
		maze[i] = (int*)malloc(sizeof(int)*cols);
		for (int j = 0;j<cols;j++){
			maze[i][j] = BOTTOM + RIGHT + TOP + LEFT;
		}
	}
}

void mazeFree(void){
	for (int i = 0; i< rows;i++){
    free(maze[i]);
  }
  free(maze);
}

int main(int argc, char *argv[]){
	fprintf(stderr, "#Run at %ld\t####\n",time(0));
	int seed;
	rows = atoi(argv[1]);
	cols = atoi(argv[2]);
	if (argv[3])seed = atoi(argv[3]);
	else seed = time(0);
	srand(seed);
	fprintf(stderr, "Seed: %d\n",seed);
  mazeInit();
	mazeFree();
	fprintf(stderr, "#Ended at %ld\t####\n",time(0));
	return 0;
}
