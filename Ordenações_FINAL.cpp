#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

//Enumera os elementos totais do vetor
void numeroElementos(int n){
	int numeroElementos=n;
}

void copiaVetor(int *v, int *vaux, int numeroElementos){
	int i;
	for (i = 1; i <= numeroElementos; i++){
		vaux[i]=v[i];	
	}
}

//efetua a leitura do vetor e o coloca em uma função auxiliar
void le(int *v, int *vaux, int numeroElementos){
	copiaVetor(v,vaux,numeroElementos);
	}

//exibição do vetor
void exibe(int v[], int numeroElementos) {
                int x;
                printf("\n");
                for (x = 0; x < numeroElementos; x++)
                               printf("%d ", v[x]);
                               printf("\n");
}

// Troca de valores entre duas posições
void permuta(int *var1, int *var2) {
                
                int aux;
                aux = *var1;
                *var1 = *var2;
                *var2 = aux;
				printf("\nPasso mais externo: "); 
                printf("\n%d ",*var1);
                printf("%d \n",aux);
}

void numeroElementos(int n, int numeroElementos){
     numeroElementos=n;
}

/* Abaixo seguem as funções das ordenações a serem utilizadas
pelo main a partir do chamado do switch*/
 
void selectionSort2(int v[], int n) {
   int c, d, certo=0,passoTotal=0;
   printf("Numeros digitados: ");
   exibe(v, n);
   for (c = 0; c < n - 1; c++) {
        for (d = c+1; d < n; d++) {
			passoTotal=passoTotal+1;
			if (v[d] < v[c]){
				certo=certo+1;
				printf("\nComparacao %d",certo);
                permuta(&v[c], &v[d]);
			}
		}
   }
   		printf("\nTotal de passos: %d",passoTotal);
		printf("\nOrdenacao concluida...");
        exibe(v, n);
}

void bubbleSort1(int v[], int numeroElementos) {
                int i,j,certo=0,total=0;
   				printf("Numeros digitados: ");
                exibe(v, numeroElementos);
                for (i = 1; i < numeroElementos; i++) {
					total=total+1;
                               for (j = numeroElementos - 1; j >= i; j--){
                                               if (v[j-1] > v[j]){
                                                               certo=certo+1;
															   printf("\nComparacao %d",certo);
															   permuta(&v[j-1], &v[j]);
                                                               }
                               }
                }
   		 		printf("\nTotal de passos %d",total);
				printf("\nOrdenacao concluida...");
                exibe(v, numeroElementos);
}

void selectionSort1(int v[], int n) {
   int c, d, min,total=0,certo=0;
   printf("Numeros digitados: ");
   exibe(v, n);
   for (c = 0; c < n - 1; c++) {
		total=total+1; 
                               min = c;
        for (d = c+1; d < n; d++) {
            if (v[d] < v[min])
                min = d;
        }
        if(min != c) {
		certo=certo+1;	
        printf("\nComparacao %d ",certo);
		permuta(&v[min], &v[c]);
	}
    }
   		printf("\nTotal de passos %d",total);   		
		printf("\nOrdenacao concluida...");
        exibe(v, n);
}

void insertionSort(int v[], int n) {
   int c, d, k,certo=0,total=0;
   printf("Numeros digitados: ");
   exibe(v, n);
   for (c = 1; c < n; c++) { 
		total=total+1;
		k = v[c];
        d = c-1;
        printf("\nComparacao %d",total);
        while (d >= 0 && v[d] > k) {
            certo=certo+1;
			v[d+1] = v[d];
            d--;
            }
        v[d+1] = k;
		printf("\nPasso mais externo: \n%d ",v[c-1]);
        printf("%d \n",v[c]);
   }
   printf("\nTotal de passos %d",n);
   printf("\nOrdenacao concluida...");
   exibe(v, n);
}

main (){
	int v[100],i,n,opcao;
	char opcao2;
	system("cls"); // Limpa a tela para a execução dos menus
	printf("Digite a quantidade de numeros desejados: ");
	scanf("%d",&n); // Entrada de dados para o usuário
	for(i=0; i<n; i++)
	{
	printf("\nDigite um dos elementos: "); // Entrada de outros dados para o usuário
	scanf("%i",&v[i]);}
	le(v,v,n);
	do {//inicia i laço para o switch
	system("cls");//limpa tela
	printf("\n [1] Bubble \n"); //seleciona Bubble Sort
	printf("\n [2] Selection \n"); // Seleciona Selection Sort
	printf("\n [3] Insert \n"); // Seleciona Insertion Sort
	printf("\n [4] Selection 2 \n")	; // Seleciona a segunda opção de selection sort
	printf("\n Escolha uma opcao: "); // Abre a opção do switch para interação do usuário
	scanf("%d",&opcao);
	switch (opcao){
	case 1: 
	bubbleSort1(v,n);
    printf("\nO numero de elementos digitados e: %d\n",n);
	break;
	case 2: 
	selectionSort1(v,n);
    printf("\nO numero de elementos digitados e: %d\n",n);
	break;
	case 3: 
	insertionSort(v,n);
    printf("\nO numero de elementos digitados e: %d\n",n);
	break;
	case 4: 
	selectionSort2(v,n);
    printf("\nO numero de elementos digitados e: %d\n",n);
	break;
		default:
		printf("\nOpcao invalida\nPressione enter para retornar...");
		getch();
	}
} 
	while(opcao > 5);
	printf("\nTermino de processo. \nPressione qualquer tecla para encerrar...");
	system("pause>>null");
}
