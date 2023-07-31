#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct professor {
	char nome[30];
	char disciplina[30];
	float horas;
	
}Professor;

void preencheProfessor(Professor *Prof) {
    printf("Digite o nome do professor: ");
    scanf(" %[^\n]",&Prof->nome);
    printf("Digite carga horaria: ");
    scanf("%f", &Prof->horas);
    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", &Prof->disciplina);
}
    
    	void imprimeProfessor(Professor *Prof) {
    printf("Nome do: %s, : %.2f, disciplina: %s ", Prof->nome, Prof->horas, Prof->disciplina);
}
int main(){
	
	printf("Nome do: %s, : %.2f, disciplina: %s ", Prof->nome, Prof->horas, Prof->disciplina);
	}
