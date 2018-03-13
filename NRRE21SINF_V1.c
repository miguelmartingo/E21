#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int voltage (int arr10, int arr11){
	int v;
	v = arr10*16*16+arr11;
	v = (v/4096)*1.5;
	return v;
}
	
int vlight (int arr12, int arr13){
	int v;
	v = arr12*16*16+arr13;
	v = (0.625*pow(10,6)*(v/4096)*1.5)/100;
	return v;
}

int ilight (int arr14, int arr15){
	int i;
	i = arr14*16*16+arr15;
	i = (0.769*pow(10,5)*(i/4096)*1.5)/100;
	return i; 
}

int tempt (int arr16, int arr17){
	int t;
	t = arr16*16*16+arr17;
	t = -39.6+0.01*t;
	return t;
}

int relahumi (int arr18, int arr19){
	int r;
	r = arr18*16*16+arr19;
	r = -2.0468+.0367*r-1.5955*pow(10,-6)*r*r;
	return r;
}

int humicomp (int arr18, int arr19, int temptfunc, int relahumifunc){
	int h;
	h = arr18*16*16+arr19;
	h = (temptfunc-25)*(0.01+0.00008*h)+relahumifunc;
	return h;
}

int main(){
	int k;
	int arr[23] = {0};
	char *str;
	char str_in[255];
	
	while(1){
		k = 0;
		fgets(str_in, 255, stdin);
		str = strtok(str_in, " ");
		while(str != NULL){
			arr[k] = strtol(str,NULL,16);
			printf("%d",arr[k]);
			str = strtok(NULL, " ");
			k++;
		}
		printf("\n\n");
	}
	return 0;
}

