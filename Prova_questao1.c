#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int* vetor,int tamanho)
{
     int i;
     for(i= 0; i< tamanho;i++){
        printf(" %d ",vetor[i]);
    }
}

void  printMatrizComoVetor(int** matriz,int numeroLinhas,int numeroColunas)
{
    int* vetorPrinter;
    int tamanho = numeroColunas * numeroLinhas;

    int iterator_vetor = 0;

    int iterator,iteratorSecundario;

    vetorPrinter = malloc( tamanho * sizeof(int) );

    for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
    {

        for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

        {

            vetorPrinter[iterator_vetor] = matriz[iterator][iteratorSecundario];
            printf(" %d ",vetorPrinter[iterator_vetor]);
        }
        iterator_vetor++;
    }


        printVetor(*vetorPrinter,tamanho);
        free(vetorPrinter);

}




int randomNumero (void){

return rand()%2;

}

int** criarMatriz(int numeroLinhas,int numeroColunas)
{
    int** matriz;
    int iterator;

    matriz = malloc(numeroLinhas * sizeof(int*) );

    matriz[0] = malloc( numeroColunas * numeroLinhas * sizeof(int) );

    for ( iterator = 1 ; iterator < numeroLinhas ; iterator++ )
    {

        matriz[iterator] = matriz[iterator - 1] +  numeroColunas ;

    }


    return matriz;


}

void popularMatrizManualmente(int** matriz,int numeroLinhas,int numeroColunas)
{
    int iterator,iteratorSecundario,numero;

    for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
    {

        for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

        {
            printf("Digite o valor na posicao [ %d ][ %d ]",iterator,iteratorSecundario);
            scanf("%d",&numero);
            matriz[iterator][iteratorSecundario] = numero;
        }

    }
}

void popularMatrizAleatoriamente(int** matriz,int numeroLinhas,int numeroColunas)
{
    int iterator,iteratorSecundario;

    for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
    {

        for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

        {
            matriz[iterator][iteratorSecundario] = randomNumero();
        }

    }
}


void printMatriz(int** matriz,int numeroLinhas,int numeroColunas){
    int iterator,iteratorSecundario;


     for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
        {
            if(iterator == 0){
                    printf("\n\n----------------------------------------------- \n");
            }


            for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

            {

               printf("| %d | " ,matriz[iterator][iteratorSecundario]);
            }
            if(iterator< numeroLinhas){
            printf("\n");}

     }

      printf("-----------------------------------------------\n\n");
}





int main (void){

    int numeroLinhas = 8, numeroColunas = 8, iterator, iteratorSecundario;
    int **matriz;
    int popular;


    matriz = criarMatriz(numeroLinhas,numeroColunas);

    printf("Como deseja popular a Matriz:\n");
    printf("[0]: Manualmente; [1] Com seed aleatoria\n");

    scanf("%d", &popular);


    if(popular == 0){

         popularMatrizManualmente(matriz,numeroLinhas,numeroColunas);

    }else if (popular == 1){

        popularMatrizAleatoriamente(matriz,numeroLinhas,numeroColunas);
    }


    printMatriz(matriz,numeroLinhas,numeroColunas);


    printMatrizComoVetor(matriz,numeroLinhas,numeroColunas);


    free(matriz[0]);
    free(matriz);



    return 0;


}
