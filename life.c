#include <stdio.h>
#include <stdlib.h>
int** newBoard(int** GRID,  int height, int width);
int numNeighbors(int i, int j, int** GRID, int width, int height);
int main(int argc, char** argv) {

FILE *filePointer;
filePointer = fopen(argv[2], "r");
if (filePointer == NULL) {
        return EXIT_SUCCESS;
}
int height, width, i , j;
int numTimes = atoi(argv[1]);
fscanf(filePointer, "%d %d\n", &height, &width);
int** GRID;
int** newGRID;
char exchange;
//int genCount = 1;
//allocte memory for grid and new grid 
GRID = (int**)malloc(height * sizeof(int*));
for (i = 0; i < height; i = i + 1) {
        GRID[i] = (int*)malloc(width * sizeof(int*));
}
newGRID = (int**)malloc(height * sizeof(int*));
for (i = 0; i < height; i = i + 1) {
        newGRID[i] = (int*)malloc(width * sizeof(int*));
}// create an binary grid for easy mainpulation of populateed cells
for (i = 0; i < height; i = i + 1) {
        for (j = 0; j < width; j = j + 1) {
                fscanf(filePointer, "%c",&exchange);
                if (exchange == '.') {
                        GRID[i][j] = 0;
        } else {
GRID[i][j] = 1;
}
}
        fscanf(filePointer,"\n");
}

for (i = 0; i < numTimes; i = i + 1) {
GRID = newBoard(GRID, height, width);
}
// convert from binary back to * and .
for (i = 0; i < height; i = i + 1) {
        for (j = 0; j < width; j = j + 1) {
        if (GRID[i][j] == 0) {
        printf(".");
} else {
printf("*");
        }
}
        printf("\n");
}
return 0;
}
// function to chnage cells based on simple rules
int** newBoard(int** GRID, int height, int width) {
int i,j,popNeighbors = 0;
int** newGRID = (int**)malloc(height * sizeof(int*));
for (i = 0; i < height; i++) {
newGRID[i] = (int*)malloc(width * sizeof(int*));
}
for (i = 0; i < height; i = i + 1) {
        for (j = 0; j < width; j = j + 1) {
                popNeighbors = 0;
                popNeighbors = numNeighbors(i,j,GRID, width, height);
        if (GRID[i][j] == 0) {
                if (popNeighbors == 3) {
                       newGRID[i][j] = 1;
                } else {
                        newGRID[i][j] = 0;
                }
        }
        if (GRID[i][j] == 1) {
                if (popNeighbors < 2 || popNeighbors > 3) {
                        newGRID[i][j] = 0;
                } else {
                        newGRID[i][j] = 1;
                }
        }
}
}
return newGRID;
}
// somewhat working function to count neighbors of a cell NEEDS FIXING
int numNeighbors(int x, int y, int** GRID, int width, int height) {
int i, j;
int numNeighbors = 0;
/*
failed implemenations lol
 for (x = -1; x <= 1; x++){ 
                    for (y = -1; y <= 1; y++) {
                 numNeighbors = numNeighbors + GRID[i + x][j + y]; 
  }}
   numNeighbors = numNeighbors - GRID[i][j]; 
                //                                                   
    for (x = i-1; x <= i+1; x++) {
        for (y = j-1; y <= j+1; y++)
            if (!(i == x && j==y)
                    && GRID[(x+height) % height][(y+width) % width])
                numNeighbors++;
    }

   int l, k;
   for (x = -1; x < 2; x = x + 1) {
	for (y = -1; y < 2; y = y + 1) {
	l = y + i;
	k = x + j;
if (l >= 0 && l < height && k >= 0 && k < width && !(y == 0 && x == 0) && GRID[l][k]) {
                    numNeighbors += 1;
                }	
}} 
*/
  for (i = x - 1; i < x + 2; i = i + 1) {
for (j = y - 1; j < y + 2; j = j + 1) {
if (i == x && j == y) {
continue;
}
if (i > -1 && j > -1 && i < height && j < width) {
numNeighbors = numNeighbors + GRID[i][j];
}}}
    return numNeighbors;
}
