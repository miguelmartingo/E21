#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double voltage (int arr10, int arr11){
	double v;
	v = arr10*16*16+arr11;
	v = (v/4096)*1.5*0.5;
	return v;
}
	
double vlight (int arr12, int arr13){
	double v;
	v = arr12*16*16+arr13;
	v = (0.625*pow(10,6)*(v/4096)*1.5)/100;
	return v;
}

double ilight (int arr14, int arr15){
	double i;
	i = arr14*16*16+arr15;
	i = (0.769*pow(10,5)*(i/4096)*1.5)/100;
	return i; 
}

double tempt (int arr16, int arr17){
	double t;
	t = arr16*16*16+arr17;
	t = -39.6+0.01*t;
	return t;
}

double relahumi (int arr18, int arr19){
	double r;
	r = arr18*16*16+arr19;
	r = -2.0468+.0367*r-1.5955*pow(10,-6)*r*r;
	return r;
}

double humicomp (int arr18, int arr19, double temptfunc, double relahumifunc){
	double h;
	h = arr18*16*16+arr19;
	h = (temptfunc-25)*(0.01+0.00008*h)+relahumifunc;
	return h;
}

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

void printmatrix(int a, double v[a][a]){
	int h,j;
	for(h = 0; h < a; h++){
		for(j = 0;j < a;j++){
			if(j == 0){
				printf("[[%d ,%d ,%d],", rtemp(v[h][0]),gtemp(v[h][0]),btemp(v[h][0]));//ordem dos sensores
			}
			if(j == 1){
				printf("[%d ,%d ,%d],", rhum(v[h][1]),ghum(v[h][1]),bhum(v[h][1]));
			}
			if(j == 2 || j == 3){
				printf("[%d ,%d ,%d],", rlig(v[h][j]),glig(v[h][j]),blig(v[h][j]));
			}
			if(j > 4 || j < a-1){
				printf("[%d ,%d ,%d ],", rgeral(v[h][j]),ggeral(v[h][j]),bgeral(v[h][j]));
			}
			if(j == a-1){
				printf("[%d ,%d ,%d]]\n", rgeral(v[h][j]),ggeral(v[h][j]),bgeral(v[h][j]));
			}
		}
	}
}

void leitura(int a, double v[a][a], int x, char str_in[x]){
	int k,i, arr[23]={0};
	char *str; 

	for(i=0; i < a ;i++){
		k = 0;
		fgets(str_in, 255, stdin);
		str = strtok(str_in, " ");
		while(str != NULL){
			arr[k] = strtol(str,NULL,16);
			str = strtok(NULL, " ");
			k++;
		}
		v[i][0] = tempt(arr[16],arr[17]);
		v[i][1] = humicomp(arr[18],arr[19],tempt(arr[16],arr[17]),relahumi(arr[18],arr[19]));
		v[i][2] = vlight(arr[12],arr[13]);
		v[i][3] = ilight(arr[14],arr[15]);
	} 
}
	
int main(){
	int i, a;
	double v[12][12]={0};
	char str_in[255];

	i = sizeof(v)/sizeof(double); //no linhas ou colunas
	a = sqrt(i); 
	leitura(a, v,255,str_in);
	printmatrix(a,v);

	return 0; 
}
