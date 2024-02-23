#include <stdio.h>

int max2(int a, int b) {
    return a > b ? a : b;
}

int max3(int a, int b, int c) {
    return c > max2(a, b) ? c : max2(a, b);
}


int main()
{
    int cases;
    
    scanf("%d", &cases);
    
    int rows = 0;
    int cols = 0;
    
    for(int i = 0; i < cases; i++) {
        scanf("%d %d", &rows, &cols);
        
        int matrix[rows][cols];
        
        //initializing matrix with zeros
        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                matrix[j][k] = 0;
            }
        }
        
        //scaning the values from the input
        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                
                int value;
                scanf("%d", &value);
                
                if(j > 0) {
                    if(k == 0) {
                        value += max2(matrix[j-1][k], matrix[j-1][k+1]);
                    } else if(k == cols-1) {
                        value += max2(matrix[j-1][k-1], matrix[j-1][k]);
                    } else {
                        value += max3(matrix[j-1][k-1], matrix[j-1][k], matrix[j-1][k+1]);
                    }
                }
                matrix[j][k] = value;
            }
        }
        
        int max = 0;
        for(int j = 0; j < cols; j++) {
            if(matrix[rows-1][j] > max) {
                max = matrix[rows-1][j];
            }
        }
        printf("%d\n", max);
        
        /*
        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                printf("%d ", matrix[j][k]);
            }
            printf("\n");
        }*/
    }

    return 0;
}
