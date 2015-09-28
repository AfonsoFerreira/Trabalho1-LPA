#include<stdio.h>
#include<stdlib.h>

void main()
{

	void swap(int *vet, int valor1, int valor2);
	void quicksort (int *v,int a, int b);
	
	int n, i, count=0, quantidaderep=0;
	
	printf("Entre com o numero de elementos a serem armazenados:");
	scanf("%d",&n);
	while (n<2)//garante que o usuário entre com um veotr válido
	{
		printf("\nErro!O vetor digitado deve possuir mais de um elemento!\nEntre com um valor maior que 1:\n\n");
		scanf("%d", &n);
	}
	int *vet=(int*)calloc(n,sizeof(int));//aloca memoria para a quantidade de entradas definida pelo usuário
	
	for(i=0;i<n;i++){
		printf("\nEntre com o elemento %d do vetor: \n",i+1);
		scanf("%d",&vet[i]);
	}
	
	quicksort (vet,0,n-1 );
	
	for(i=0;i<=n-1;i++){
		if(vet[i]==vet[i+1])
		{
			count++;//incremento uma variavel que representa quantas vezes um determinado numero se repete
		}
		else
		{
			if(count>quantidaderep)
			{
				quantidaderep=count;//comparação com a maior quantidade de repetições encontrada até agora.Caso a repetição do numero em questão seja maior, substituir a quantidade de repetições máximas
			}	
			count = 0;
		}
	}
	printf("\nA quantidade maxima de vezes que um elemento se repetiu foi: %d\n\nO(s) numero(s)  que se repetiram %d vezes: \n", quantidaderep+1, quantidaderep+1);
	
	for(i=0;i<=n-1;i++)//checar os numeros de ocorreências
	{
		if(vet[i]==vet[i+1])
		{
			count++;
		}
		else{
			count=0;
		}
		
		if(count==quantidaderep){//caso o número de ocorrências seja igual ao número máximo,imprimir esse número
			printf("%d ",vet[i]);
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
