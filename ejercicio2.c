#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

bool magicSquare(int matrix[][SIZE]) {
	//se va a asumir que la matriz es mágica hasta que se demuestre lo contrario. si no se demuestra lo contrario, al final se retorna true, de otra forma retorna false

	int magicSum = 0; //primero que nada se va a encontrar un posible valor para la suma magica usando la primera diagonal
	for (int d = 0; d < SIZE; d++){
		magicSum += matrix[d][d]; //se le suma el siguiente número de la diagonal
	}
	int diagonalSum = 0;
	for (int d = 1; d <= SIZE; d++){//a continuación se calcula la suma de la siguiente diagonal:
		diagonalSum += matrix[SIZE - d][d - 1];//se suman los números sobre la diagonal
	}
	if (diagonalSum != magicSum) return false; // si son diferentes las sumas de las diagonales, se demostró lo contrario, por lo que retorna falso

        for(int y = 0; y < SIZE; y++){//se calcula la suma para cada fila
                int rowSum = 0;// suma de la fila "y"
                for(int x = 0; x < SIZE; x++){
                        rowSum += matrix[x][y];
                }
                if (rowSum != magicSum) return false;// si es diferente a la suma mágica, se demostró lo contrario, retorna falso 
        }

	for(int x = 0; x < SIZE; x++){//se verifican las sumas de las columnas
		int colSum = 0;//se calcula fila de columna "x"
                for(int y = 0; y < SIZE; y++){
                        colSum += matrix[x][y];
                }
                if (colSum != magicSum) return false;//si se demuestra lo contrario retorna falso
        }

	return true; //debe ser verdadero que es una matriz mágica, ya que no se demostró lo contrario
}


void fillRandomly(int matrix[][SIZE]){//llena una matriz con números random
	srand(time(NULL));
	for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){
                        matrix[x][y] = rand()%100; //genera un valor random menor a 100
                }
        }
}

void printMatrix(int matrix[][SIZE]) { //imprime una matriz
        for(int y = 0; y < SIZE; y++){
		for(int x = 0; x < SIZE; x++){
			printf("%d  ",matrix[x][y]); //imprimir posición
		}
		printf("\n");//siguiente fila!
	}
}




int main() {
	int matrix[SIZE][SIZE] = {
		{16, 3, 2,13},
		{ 5,10,11, 8},
		{ 9, 6, 7,12},
		{ 4,15,14, 1}
	};

	
	
	printf("la matriz utilizada fue:\n");
	printMatrix(matrix);
	printf("%s es un cuadrado mágico\n", magicSquare(matrix) ? "Sí" : "No");


	fillRandomly(matrix);
        printf("la matriz aleatoria utilizada fue:\n");
        printMatrix(matrix);
        printf("%s es un cuadrado mágico\n", magicSquare(matrix) ? "Sí" : "No");
	


	return 0;
}
	
