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

int main(){
	int k;
	int arr[23] = {0};
	char *str;
	char str_in[255];//={"7E 45 00 FF FF 00 05 0A 3F 0C 40 44 00 BD 00 BD 1D 3F 02 27 48 81 7E"}; //teste
	double t, h;
	
	
	while(1){
		k = 0;
		fgets(str_in, 255, stdin);
		str = strtok(str_in, " ");
		while(str != NULL){
			arr[k] = strtol(str,NULL,16);
			printf("%d ",arr[k]);
			str = strtok(NULL, " ");
			k++;
		}
		t = tempt(arr[16],arr[17]);
		h = relahumi(arr[18],arr[19]);
		printf("\n Temperatura: %fC\n Humidade rel: %f%% \n Humidade comp: %f %%\n Voltage: %fV\n \
Visible light: %flux \n Infrared light: %flux \n", t, h, \
		humicomp(arr[18],arr[19],t,h), voltage(arr[10],arr[11]), vlight(arr[12],arr[13]), \
		ilight(arr[14],arr[15]));
		if(h>100 || h<0){
			printf("Valor da humidade relativa e compensada impossível.\n");
		}
		
		if(t>50 || t<-10){
			printf("Valor da temperatura impossível.\n");
		}
		
		if(vlight(arr[12],arr[13])<0 || ilight(arr[14],arr[15])<0){
			printf("Valor de luminosidade impossível.\n");
		}

		printf("\n\n");
		//getchar(); //escrever um nº e depois enter para fazer mais um ciclo
	}
	return 0; 
}

