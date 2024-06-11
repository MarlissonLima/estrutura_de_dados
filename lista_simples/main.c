#include "lista_sequencial.h"

int main(void){
    Lista *lista = cria_lista();
    Aluno aluno;

    

    aluno.matricula = 123;
    aluno.nome = "joao";
    aluno.n1 = 10;
    aluno.n2 = 7;
    aluno.n3 = 8;
    insere_lista_inicio(lista,aluno);
    mostra_lista(lista);
    //inicio -> joao -> ||
    //aqui estamos reaproveitando a variavel aluno e alterando seus valores, porem o valor na lista nao foi alterado
    //ou seja, ainda temos o aluno "joao" de matricula "123" na nossa lista
    aluno.matricula = 231;
    aluno.nome = "maria";
    aluno.n1 = 5;
    aluno.n2 = 10;
    aluno.n3 = 10;
    insere_lista_final(lista,aluno);
    mostra_lista(lista);
    //inicio -> joao -> maria -> ||
    
    aluno.matricula = 111;
    aluno.nome = "ana";
    aluno.n1 = 10;
    aluno.n2 = 10;
    aluno.n3 = 10;
    insere_lista_ordenada(lista,aluno);
    mostra_lista(lista);
    //inicio -> ana -> joao -> maria -> ||

    remove_lista_inicio(lista);
    mostra_lista(lista);
    //inicio -> joao -> maria -> ||

    insere_lista_final(lista,aluno);
    mostra_lista(lista);
    //inicio -> joao -> maria -> ana -> ||

    remove_lista(lista,231);
    mostra_lista(lista);
    //inicio -> joao -> ana -> ||

    remove_lista_inicio(lista);
    mostra_lista(lista);
    //inicio -> ana -> ||

    remove_lista_final(lista); // ou remove_lista_inicio, já que so tem um elemento
    mostra_lista(lista);
    //inicio -> ||
    

    return 0;
}
