#include<stdio.h>
#include<stdlib.h>

void main()
{

	void swap(int *vet, int valor1, int valor2);
	void quicksort (int *v,int a, int b);
	
	int n,i=0;
		printf("Entre com o numero de elementos a serem armazenados");
		scanf("%d",&n);
	
	int *vet=(int*)calloc(n,sizeof(int));//aloca memoria para a quantidade de entradas definida pelo usu�rio
	
	for(i=0;i<n;i++){
		printf("\nEntre com o elemento %d do vetor: \n",i+1);
		scanf("%d",&vet[i]);
	}
	while (n<2)//garante que o usu�rio entre com um vetor v�lido
	{
		printf("\nErro!O vetor digitado deve possuir mais de um elemento!\nEntre com um valor maior que 1:\n");
		scanf("%d", &n);
	}
	
	quicksort (vet, 0, n-1 );
	
	int menordiferenca=vet[1]-vet[0],aux;//inicializa a menor diferen�a como a diferen�a entre os primeiros 2 elementos
	if(menordiferenca<0)
	{
		menordiferenca=-menordiferenca;//coloca a diferen�a em m�dulo
	}
	for(i=2;i<=n;i++)
	{
		aux=vet[i]-vet[i-1];
		if(aux<0){
			aux=-aux;
		}
		if(aux<=menordiferenca){
			menordiferenca=aux;//substitui o valor da menor diferen�a caso seja encontrado o=um valor menor
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
			printf("%d e %d \n",vet[i-1],vet[i]);//imprime os pares entre os quais ocorre a menor diferen�a encontrada
		}
		
	}
	getch();
}

void swap(int *vet, int valor1, int valor2){	//fun��o usada para trocar os elementos da fun��o quicksort
    int trocador;
	trocador = vet[valor1];
    vet[valor1] = vet[valor2];
    vet[valor2] = trocador;
}
void quicksort (int *v,int a, int b){ 		//fun��o que ordena o veotr para facilitar as compara��es
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






