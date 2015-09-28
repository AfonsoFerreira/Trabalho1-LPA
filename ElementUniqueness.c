#include<stdio.h>
#include<stdlib.h>

void main(){
	
	void swap(int *vet, int valor1, int valor2);
	void quicksort (int *v,int a, int b);
	int n, i;
	
	printf("Entre com o numero de elementos a serem armazenados");
	scanf("%d",&n);
	while (n<2)//garante que o usuário entre com um veotr válido
	{
		printf("\nErro!O vetor digitado deve possuir mais de um elemento!\nEntre com um valor maior que 1:\n");
		scanf("%d", &n);
	}

	int *vet=(int*)calloc(n,sizeof(int));//aloca memoria para a quantidade de entradas definida pelo usuário
	
	for(i=0;i<n;i++){				//recebe o vetor do usuario
		printf("Entre com o elemento %d do vetor: \n",i+1);
		scanf("%d",&vet[i]);
	}
	quicksort (vet,0, n-1 );		//organiza o vetor para facilitar as comparações
	int *umarepeticao=(int*)calloc(sizeof(int),n);
	int j=0, count=0;

	for(i=1; i<=n-2; i++){		//compara os numeros desconsiderando os extremos do vetor
		
		if(vet[i]!=vet[i-1] && vet[i]!=vet[i+1])
		{
			umarepeticao[j]=vet[i];
			count++;//variável que determinaráa quantos elementos armazenar no vetor a ser impresso
			j++;
		}
	}
		
		//testando os extremos
		if(vet[0]!=vet[1]){
			umarepeticao[j]=vet[0];
			j++;
			count++;
		}

		if(vet[n-2]!=vet[n-1]){
			umarepeticao[j]=vet[n-1];
			j++;
			count++;
		}
			
		//copia o vetor de únicos para um vetor que utiliza apenas o tamanho necessario, pois podem haver poquissimos elementos que nao se repetem:
		int *vetorimpresso=(int*)calloc(sizeof(int),count);
	
		for(i=0;i<=count;i++){
			vetorimpresso[i]=umarepeticao[i];
		}

		free(umarepeticao);//libera a memoria do primeiro vetor
	    quicksort (vetorimpresso,0, count-1);
		if(count!=0){
			printf("Os numeros que ocorrem so uma vez no vetor digitado sao: \n");
			for(i=0;i<count;i++){
			printf("%d ",vetorimpresso[i]);
		}
	}
	
	if(count==0){
		printf("Todos os elementos do vetor digitado ocorrem mais de uma vez no vetor!");
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
