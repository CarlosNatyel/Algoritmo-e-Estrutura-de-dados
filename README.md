Tarefas de Algoritmo e Estrutura de dados

 int mat;
 char nome[81];
 float notas[3];
 float media;
};

typedef struct aluno Aluno;

struct turma {
 char id; 
 int vagas; 
 Aluno* alunos[MAX_VAGAS];
};

typedef struct turma Turma;

Turma* turmas[MAX_TURMAS];

Turma* cria_turma(char id){
	turma*t = (Turma*) malloc(sizeof(Turma));
	t->id=id;
	t->vagas=0;
	int i;
	for(i=0;i< MAX_VAGAS; i++){
		t->alunos[i]=NULL;
	}
	return t;
}
void matricula_aluno(Turma* turma, int mat, char* nome){
	if(turma->vagas< MAX_VAGAS){
		a->mat=mat;
		strcpy(a->nome,nome);
		int i;
		for(i=0;i<4;i++){
			a->notas[i]=0
		}
			
	}
}
