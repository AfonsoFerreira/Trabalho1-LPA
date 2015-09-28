#include<stdio.h>
#include<stdlib.h>

void main()
{

	void swap(int *vet, int valor1, int valor2);
	void quicksort (int *v,int a, int b);
	
	int n,i=0;
		printf("Entre com o numero de elementos a serem armazenados");
		scanf("%d",&n);
	
	int *vet=(int*)calloc(n,sizeof(int));//aloca memoria para a quantidade de entradas definida pelo usuário
	
	for(i=0;i<n;i++){
		printf("\nEntre com o elemento %d do vetor: \n",i+1);
		scanf("%d",&vet[i]);
	}
	while (n<2)//garante que o usuário entre com um vetor válido
	{
		printf("\nErro!O vetor digitado deve possuir mais de um elemento!\nEntre com um valor maior que 1:\n");
		scanf("%d", &n);
	}
	
	quicksort (vet, 0, n-1 );
	
	int menordiferenca=vet[1]-vet[0],aux;//inicializa a menor diferença como a diferença entre os primeiros 2 elementos
	if(menordiferenca<0)
	{
		menordiferenca=-menordiferenca;//coloca a diferença em módulo
	}
	for(i=2;i<=n;i++)
	{
		aux=vet[i]-vet[i-1];
		if(aux<0){
			aux=-aux;
		}
		if(aux<=menordiferenca){
			menordiferenca=aux;//substitui o valor da menor diferença caso seja encontrado o=um valor menor
		}
	}
	
	printf("\nO valor da menor diferenca encontrada foi : %d\nEssa diferenca se deu entre os seguintes numeros do vetor:\n", menordiferenca);
	for(i=1;i<=n;i++)
	{
		aux=vet[i]-vet[i-1];
		if(aux<0){
			aux=-aux;
		}
		if(aux==menordiferenca){
			printf("%d e %d \n",vet[i-1],vet[i]);//imprime os pares entre os quais ocorre a menor diferença encontrada
		}
		
	}
	getch();
}

void swap(int *vet, int valor1, int valor2){	//função usada para trocar os elementos da função quicksort
    int trocador;
	trocador = vet[valor1];
    vet[valor1] = vet[valor2];
    vet[valor2] = trocador;
}
void quicksort (int *v,int a, int b){ 		//função que ordena o veotr para facilitar as comparações
    if(a>=b)
        return;
    int p=rand()%(b-a+1)+a;
    swap(v,p,a);
    p=a;
    int m=a, n=b;
    while(n>m){
        while (v[m]<=v[p]&&m<=b)
            m++;
        while (v[n]>v[p])
            n--;
        if (n>m)
            swap(v,m,n);
    }
    swap(v,n,p);
    quicksort(v,a,n-1);
    quicksort(v,n+1,b);
}






