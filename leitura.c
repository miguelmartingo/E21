#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main(){
	
	FILE * file;
	int NELEMENTOSMATRIX = 12;
	const char espaco[2]=" ";
	char conteudo[500]={};
	char *valor;
	int i=0;
	int j=0;
	int k=0;
	int n=0;
	int v[12][12]={0};
	int vetor[500];
	
	
	file=fopen("teste.txt","r");
	
	if(file==NULL)printf("erro leitura\n");
	
	
	while((conteudo[i] = fgetc(file)) != EOF){
		
		
		printf("%c", conteudo[i]);
		i++;
		}
		
		printf("\n confirmaçao inicial\n");
	
	valor=strtok(conteudo, espaco);
		
		while(valor != NULL){
			
			
			vetor[n]=atoi(valor);
			printf(" %d", vetor[n]);
			valor=strtok(NULL,espaco);
			//printf("%d\n", vetor[n]);
			n++;
			
		}
		
		//printf("\n%d",n);
		
	printf("\nULTIMA FASE:\n");	
	
	i=0; //linha
	j=0; //coluna 
	k=0; //percorrer vetor
	
	for(i=0;i<(NELEMENTOSMATRIX-1);i++){
			
			for(j=0;j<(NELEMENTOSMATRIX-1);j++){
				
				v[i][j]=vetor[k];
				printf(" %d", v[i][j]);
				k++;
			}
			}
		
	printf("\n teste %d", v[1][0]);
	printf("\n s %d", vetor[12]);

	fclose(file);
	return 0;
	
}
