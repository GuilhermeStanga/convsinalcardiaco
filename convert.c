#include<stdio.h>
#include<stdlib.h>
// entradas: bloco.txt somente contendo n d amostras e os valores

int main (){
    float min=100, max=-100, minx=0, maxx=0;
    int n_amostra=0;    int corte;
    char url[]="teste.txt", info[50],resultados []="resultado.txt";
    FILE *arq,*saida;
    char string[50];
    char complemento[]=",\t";
    float numero;
    int convertido;

    printf("ECG CONVERTER (0-255)-> VETOR\n");
    printf("informe a cada quantas amostras: \n");
    scanf("%d",&corte);

    int cont =1;
    saida = fopen(resultados , "w");
	arq = fopen(url, "r");
    int i=2;

     while( (fscanf(arq,"%s %s\n",string,string))!=EOF ){ //sobrescreve a string antes do valor
            if(atof(string)<min) min=atof(string);
            if(atof(string)>max) max = atof(string);
    }
    printf("\n\nmin: %f \nmax: %f",min,max);
    maxx = max - min;
    minx = min - min;
    printf("\n\nvalores normalisados\n\nmin: %f \nmax: %f\n\n\n",minx,maxx);

    saida = fopen(resultados , "w");//abriu de novo os arquivos
	arq = fopen(url, "r");

	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fscanf(arq,"%s %s\n",string,string))!=EOF ){ //sobrescreve a string antes do valor
            if(cont >= corte) {
                cont=1;
                n_amostra++;
                numero = atof(string) - min ; // converte a string para flutuante e soma |min|
                convertido = (numero *255) / maxx;
                sprintf(string, "%d", convertido); // converte de volta para string
                i =fputs(strcat(string,complemento),saida); // imprime no .txt, concatena o valor com o complemento
            }
            else{
               cont ++;
            }
        }
	fclose(arq);
	printf("\n  O numero de amostras eh: %d\n",n_amostra);
	system("pause");
   // exit( 1);
}



