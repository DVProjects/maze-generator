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
	RIGHT	  = 0b0010,
	TOP	    = 0b0100,
	LEFT	  = 0b1000,
};

int rows, cols;
int **maze;

void mazeInit(void){
  maze = (int**)malloc(sizeof(int*)*rows);
  if (!maze){ //filled dynamic memory, malloc() returns NULL
    fprintf(stderr, "ERROR: not enough dynamic memory for maze allocation\n");
    return;
  }
	for (int i = 0; i< rows;i++){
		maze[i] = (int*)malloc(sizeof(int)*cols);
    if (!maze[i]) { //filled dynamic memory, malloc() returns NULL
      fprintf(stderr, "ERROR: reached dynamic memory limit\n");
      return;
    }
		for (int j = 0;j<cols;j++){
			maze[i][j] = BOTTOM + RIGHT + TOP + LEFT;
		}
	}
}

void mazePrint(){
	for (int i = 0;i< rows;i++){
		putchar('+');
		for (int j = 0;j<cols;j++){ //upper wall of cell
			if (maze[i][j] & TOP)printf("---+");
      else if (i> 0 && (maze[i-1][j] & RIGHT))printf("   +");
      else if (maze[i][j] & RIGHT)printf("   +");
      else if (j<cols-1 && maze[i][j+1] & TOP)printf("   +");
			else printf("    ");
		}
		printf("\b+\n|"); //end the line with +
		for (int j = 0;j<cols;j++){ //middle of the cell
			printf("  ");
			if (maze[i][j] & RIGHT)printf(" |");
			else printf("  ");
		}
		printf("\b|\n");
	}
	putchar('+');
	for (int i = 0; i < cols; i++)printf("---+"); //lower walls of the maze
	putchar('\n');
}

void mazeFree(void){
	for (int i = 0; i< rows;i++){
    free(maze[i]);
  } free(maze);
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
  mazePrint();
	mazeFree();
	fprintf(stderr, "#Ended at %ld\t####\n",time(0));
	return 0;
}
