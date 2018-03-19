#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


int main(){
	
	FILE * file;
	char conteudo[500]={};
	char *str;
	int i=0;
	int j=0;
	int k=0;
	int vetor[12][12]={0};
	char *as;
	
	as = " ";
	
	file=fopen("teste.txt","r");
	
	if(file==NULL)printf("erro leitura\n");
	
	
	while((conteudo[i] = fgetc(file)) != EOF){
		
		
		printf("%c", conteudo[i]);
		i++;
		}
		
		printf("\n confirmaçao inicial\n");
	
	
	
	i=0; //linha
	j=0; //coluna
	k=0; //nºelemento
	
	
	while( conteudo[k] != '\0'){
	
		j=0;
		
		//printf("\nteste");	
		
	
	while(conteudo[k]!= '\n'){


		//str = strtok(NULL, " ");
		
		str=strtok(conteudo,as);
		
		printf("%d", atoi(str));
		vetor[i][j]=atoi(str);	
		j++;	
		k++;
		str = strtok(NULL, " ");
		printf(" teste %d", vetor[i][j]); 
	
}
	i++;
	k++;

}	
	/*
		
		j = 0;
		//fgets(conteudo, 500, stdin);
		printf("teste1");
		str = strtok(conteudo, "\n");
		printf(" teste2 ");
		
		for(i=0;str != NULL;i++){
			for(j=0;strcmp(str,as)==0;j++){
				vetor[i][j] = atoi(str);
				printf("%d ",vetor[i][j]);
				str = strtok(NULL, " ");
			}
}
}	
	*/
	/*
	while((conteudo[i] = fgetc(file)) != EOF){
		
		
		printf("%c", conteudo[i]);
		i++;
		}
		
	
	
		i=0;
		j=0;
		aux=0;
		

		while(conteudo[i] != EOF){
		
		//escreve se nao estiver nada no vetor
		if(conteudo[i] != ' '){		
			
			i++;
			aux++;
		}
		//não é necessario juntar numeros
		else if (conteudo[i] == ' ' && aux==1){
			
			
			//vetor[j]=conteudo[i]; 
			i++;
			j++;
			aux=0;
			continue;
			
		
		}
		//caso algarismo 2 numeros
		else if(conteudo[i] == ' ' && aux==2){
			
			//strcpy(vetor[j], conteudo[i-1]);
			//strcat(vetor[j], conteudo[i]);
			i++;
			j++;
			aux=0;
			
			//printf("%c", vetor[j]);
			
		}
		
	}
		//printf("%c", vetor[i]);
		
		
		
*/	

	fclose(file);
	return 0;
	
}



/*
int main () {
	
	
	
	
}
*/ 
