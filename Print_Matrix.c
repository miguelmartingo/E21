#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//0-preto - nao existe
//1-vermelho - deastivado - atuadores
//2-verde - ativado - atuadores
//3-azul - valores baixos - sensores
//4-amarelo - valores medios - sensores
//5-laranja - valores altos - sensores

int rtemp(int vtemp){
	int v;
	if(vtemp < 20){
		v = 0;
	}
	if(vtemp >= 20){
		v = 255;
	}
	return v;
}

int gtemp(int vtemp){
	int v;
	if(vtemp < 20){
		v = 0;
	}
	if(vtemp >= 20 && vtemp <= 30){
		v = 255;
	}
	if(vtemp > 30){
		v = 165;
	}
	return v;
}

int btemp(int vtemp){
	int v;
	if(vtemp < 20){
		v = 255;
	}
	if(vtemp >= 20){
		v = 0;
	}
	return v;
}

int rhum(int vhum){
	int v;
	if(vhum < 20){
		v = 0;
	}
	if(vhum >= 20){
		v = 255;
	}
	return v;
}

int ghum(int vhum){
	int v;
	if(vhum < 20){
		v = 0;
	}
	if(vhum >= 20 && vhum <= 40){
		v = 255;
	}
	if(vhum > 40){
		v = 165;
	}
	return v;
}

int bhum(int vhum){
	int v;
	if(vhum < 20){
		v = 255;
	}
	if(vhum >= 20){
		v = 0;
	}
	return v;
}

int rlig(int vlig){
	int v;
	if(vlig == 0){
		v = 0;
	}
	if(vlig > 0){
		v = 255;
	}
	return v;
}

int glig(int vlig){
	int v;
	if(vlig == 0){
		v = 0;
	}
	if(vlig > 0 && vlig <= 200){
		v = 255;
	}
	if(vlig > 200){
		v = 165;
	}
	return v;
}

int blig(int vlig){
	int v;
	if(vlig == 0){
		v = 255;
	}
	if(vlig > 0){
		v = 0;
	}
	return v;
}

int rgeral(int sen){
	int s;
	if(sen == 0){
		s = 0;
	}
	if(sen == 1){
		s = 255;
	}
	if(sen == 2){
		s=0;
	}
	return s;
}

int ggeral(int sen){
	int s;
	if(sen == 0){
		s = 0;
	}
	if(sen == 1){
		s = 0;
	}
	if(sen == 2){
		s = 128;
	}
	return s;
}

int bgeral(int sen){
	int s;
	if(sen == 0 || sen == 1 || sen == 2 ){
		s = 0;
	}
	return s;
}

void printmatrix(int a, FILE *fp, int v[a][a]){
	int h,j;
	for(h = 0; h!= a; h++){
		for(j = 0;j != a;j++){
			if(j == 0){
				fprintf(fp, "[[%d ,%d ,%d ],", rtemp(v[h][j]),gtemp(v[h][j]),btemp(v[h][j]));//ordem dos sensores
			}
			if(j == 1){
				fprintf(fp, "[%d ,%d ,%d ],", rhum(v[h][j]),ghum(v[h][j]),bhum(v[h][j]));
			}
			if(j == 2 || j == 3){
				fprintf(fp, "[%d ,%d ,%d ],", rlig(v[h][j]),glig(v[h][j]),blig(v[h][j]));
			}
			if(j>3 || j != a-1){
				fprintf(fp, "[%d ,%d ,%d ],", rgeral(v[h][j]),ggeral(v[h][j]),bgeral(v[h][j]));
			}
			if(j == a-1){
				fprintf(fp, "[%d ,%d ,%d ]]\n", rgeral(v[h][j]),ggeral(v[h][j]),bgeral(v[h][j]));
			}
		}
	}
}

int main(){
	int v[12][12]={0}, i, menu;
	double a;
	FILE * fp;

	fp = fopen("matrix.txt","w+");
	i = sizeof(v)/sizeof(int); //tamanho do vetor
	a = sqrt(i); //erro nao deteta a função
	printmatrix(a,fp,v);
	printf("Menu\n\r");
	printf("(1) Adicionar conjunto de sensores \n\r");
	printf("(2) Remover conjunto de sensores \n\r");
	printf("(3) Continuar a ler valores \n\r");
	printf("(4) Sair \n\r");
	scanf("%d",&menu);
		
	if(menu == 1){
		printf("Quantos conjuntos de sensores pretende adicionar?\n\r");
		scanf("%d",&adele);
		//função de leiura do ficheiro//
	}
	if(menu == 2){
		printf("Quantos conjuntos de sensores pretende remover?\n\r");
		scanf("%d",&adele);		
		adele=-adele;
		//função de leiura do ficheiro//
	} 
	
	if(menu == 3){
		//função de leiura do ficheiro//
	}
		
	if(menu == 4){
		exit(0);
	}
	if(menu != 1 || menu != 2 || menu != 3 || menu != 4){
		printf("Erro! O programa irá fechar");
		exit(0);
	}	
}


