#include<stdio.h>
#include<stdlib.h>

int main (){
char str[100];
FILE* fp;
fp= fopen("arquivo.txt","r");
if (fp==NULL){
	printf("Erro ao abrir o arquivo.\n");
	return 1;
}
fscanf(fp,"%s",str);
printf("%s",str);
fclose(fp);
return 0;
}
