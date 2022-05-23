#include <stdio.h>
 
int main(){
    int matriz1[5][5], matriz2[5][5], mult[5][5];
    printf("Insira a primeira matriz:\n");
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\nInsira a segunda matriz:\n");
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &matriz2[i][j]);
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int soma=0;
            for(int k=0; k<5; k++){
                soma+=matriz1[i][k]*matriz2[k][j];
            }
            mult[i][j]=sum;
            soma=0;
        }
    }
    printf("A multiplicação das duas matrizes é igual a\n");
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }
    return 0;
}
