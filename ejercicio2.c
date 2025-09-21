#include <stdio.h>

#define SIZE 3

int findLargestLine(int matrix[][SIZE]) {
	//mi implementación
	return 0;
}

void printMatrix(int matrix[][SIZE]) {
        for(int y = 0; y < SIZE; y++){
		for(int x = 0; x < SIZE; x++){
			printf("%d  ",matrix[x][y]);
		}
		printf("\n");
	}
}


int main() {
	int matrix[SIZE][SIZE] = {
		{2, 7, 6},
		{9, 5, 1},
		{4, 3, 8}
	};

	int largestLine = findLargestLine(matrix);
	printf("La matriz utilizada corresponde a: %d\n", largestLine);
	printMatrix(matrix);

	return 0;
}
	
