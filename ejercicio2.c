#include <stdio.h>

#define SIZE 3

int magicSquare(int matrix[][SIZE]) {
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
                        rowSum += matrix[x][y];
                }
                if (rowSum != magicSum) return false;//si se demuestra lo contrario retorna falso
        }

	return true; //debe ser verdadero que es una matriz mágica, ya que no se demostró lo contrario
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

	
	printf("La matriz utilizada corresponde a: %d\n", largestLine);
	printMatrix(matrix);

	return 0;
}
	
