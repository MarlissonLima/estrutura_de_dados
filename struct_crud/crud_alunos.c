#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//structs de livro e aluno
typedef struct Livro{
    char titulo[100];
    unsigned int num_pag; //numero de paginas nao pode ser negativo
    float preco;

}Livro;

typedef struct Aluno{
    char nome[100];
    int idade;
    Livro *livro_fav;
}Aluno;




//"construtor" para livros
Livro *criar_livro(const char *titulo,unsigned int num_pag,float preco){
    Livro *livro = (Livro*) calloc(1,sizeof(Livro));


    strcpy(livro->titulo,titulo);
    livro->num_pag = num_pag;
    livro->preco = preco;

    return livro;
}


void destruir_livro(Livro **livro_ref){
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref  = NULL;

}

Livro *copia_livro(const Livro *livro){
    return criar_livro(livro->titulo,livro->num_pag,livro->preco);
}

void print_livro(const Livro *livro){
    printf("Titulo: %s\n",livro->titulo);
    printf("Numero de paginas: %ld\n", livro->num_pag);
    printf("Preco: R$ %.2f\n",livro->preco);

}

//"construtor" para aluno
Aluno *criar_aluno(const char *nome,int idade,const Livro *livro_fav){
    Aluno *aluno = (Aluno*) calloc(1,sizeof(Aluno));

    strcpy(aluno->nome,nome);
    aluno->idade = idade;
    aluno->livro_fav = copia_livro(livro_fav);

    return aluno;
}


void destruir_aluno(Aluno **aluno_ref){
    Aluno *aluno = *aluno_ref;
    destruir_livro(&aluno->livro_fav);
    free(aluno);
    *aluno_ref = NULL;
}

void print_aluno(const Aluno *aluno){
    printf("Nome: %s\n",aluno->nome);
    printf("Idade: %d\n",aluno->idade);
    puts("Livro favorito");
    puts("-------");
    print_livro(aluno->livro_fav);


}


//função principal
int main(){

    Livro *livro_hobbit = criar_livro("O Hobbit",300,50);

    print_livro(livro_hobbit);

    Aluno *ted = criar_aluno("Ted",20,livro_hobbit);
    print_aluno(ted);

    destruir_livro(&livro_hobbit);
    
    print_aluno(ted);

    destruir_aluno(&ted);



    return 0;
}