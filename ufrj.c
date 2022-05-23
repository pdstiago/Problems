#include <stdio.h>
 
int main(){
    char primeira[40], segunda[40], juntas[80], funcao, quero;
    int maior=0;
    int tampri=0, tamseg=0;
    printf("a. Mostra as strings invertidas\nb. Imprime a concatenação das duas strings\nc. Compara as duas strings e informa quem é a string maior\nd. Informa a string de maior tamanho\ne. Identifica a ocorrência de determinado caractere na string e informa sua posição\n\nInsira o caractere da função desejada: ");
    scanf("%c", &funcao);
    printf("\nInsira a primeira string: ");
    scanf("%s", primeira);
    printf("Insira a segunda string: ");
    scanf("%s", segunda);
    for(int i=0; ; i++){
        if(primeira[i]=='\0') break;
        tampri++;
    }
    for(int i=0; ; i++){
        if(segunda[i]=='\0') break;
        tamseg++;
    }
    if(funcao=='a'){
        printf("\nA primeira string invertida é ");
        for(int i=tampri-1; i>=0; i--){
            printf("%c", primeira[i]);
        }
        printf("\nA segunda string invertida é ");
        for(int i=tamseg-1; i>=0; i--){
            printf("%c", segunda[i]);
        }
        printf("\n");
    }
    for(int i=0; i<tampri; i++){
        juntas[i]=primeira[i];
    }
    for(int i=0; i<tamseg; i++){
        juntas[i+tampri]=segunda[i];
    }
    if(funcao=='b'){
        printf("\nA concatenação das duas strings é igual a %s\n", juntas);
    }
    if(tampri>tamseg){
        for(int i=0; i<tampri; i++){
            if(primeira[i]>segunda[i]){
                maior=1;
                break;
            }
            if(primeira[i]<segunda[i]){
                maior=2;
                break;
            }
        }
    }else{
        for(int i=0; i<tamseg; i++){
            if(primeira[i]>segunda[i]){
                maior=1;
                break;
            }
            if(primeira[i]<segunda[i]){
                maior=2;
                break;
            }
        }
    }
    if(funcao=='c'){
        if(maior==1){
        printf("\nA maior string é a primeira\n");
        }else if(maior==2){
            printf("\nA maior string é a segunda\n");
        }else{
            printf("\nAs duas strings são iguais\n");
        }
    }
    if(funcao=='d'){
        if(tampri>tamseg){
        printf("\nA string de maior tamanho é a primeira\n");
        }else if(tampri<tamseg){
            printf("\nA string de maior tamanho é a segunda\n");
        }else{
            printf("\nAs duas strings têm o mesmo tamanho\n");
        }
    }
    if(funcao=='e'){
        getchar();
        printf("\nInsira o cararactere desejado: ");
        scanf("%c", &quero);
        int tem1=0, tem2=0;
        for(int i=0; i<tampri; i++){
            if(primeira[i]==quero){
                printf("\nO caractere %c está na posição %d da primeira string", quero, i);
                tem1=1;
            }
        }
        if(!tem1){
            printf("\nNão há ocorrência do caractere %c na primeira string", quero);
        }
        printf("\n");
        for(int i=0; i<tampri; i++){
            if(segunda[i]==quero){
                printf("\nO caractere %c está na posição %d da segunda string", quero, i);
                tem2=1;
            }
        }
        if(!tem2){
            printf("\nNão há ocorrência do caractere %c na segunda string", quero);
        }
        printf("\n");
    }
    return 0;
}
--------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
 
int main(){
    int matriz1[2][3], matriz2[2][3];
    printf("Insira a primeira matriz:\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\nInsira a segunda matriz:\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &matriz2[i][j]);
        }
    }
    printf("\nA soma das matrizes é \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matriz1[i][j]+matriz2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
