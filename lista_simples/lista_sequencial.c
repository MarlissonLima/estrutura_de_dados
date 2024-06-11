#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"
#define MAX 20

struct lista{
    int qtd;
    Aluno dados[MAX];
};

Lista *cria_lista(){
    Lista *li = (Lista *) malloc(sizeof(Lista));

    if(li != NULL){
        li->qtd = 0;
    }

    return li;
}

//as funções lista_cheia() e lista_vazia() nao sao funções de verificação,elas sao funções para
//"setar" valores referente a qtd da lista
int lista_cheia(Lista *li){
    if(li==NULL) return -1;
    return(li->qtd==MAX);
}

int lista_vazia(Lista *li){
    if(li==NULL) return -1;
    
    return (li->qtd==0);
}


void libera_lista(Lista *li){
    free(li);
}

int busca_lista_pos(Lista *li,int pos,Aluno *al){
    if(li==NULL || pos <=0 || pos>li->qtd){
        return 0;
    }

    *al = li->dados[pos-1];

    return 1;
}

int busca_lista_mat(Lista *li,int mat,Aluno *al){
    if(li==NULL) return 0;
    int i = 0; //contador para verificar onde esta a matricula no vetor de alunos

    while(i < li->qtd && li->dados[i].matricula != mat) i++;

    if(i==li->qtd){ //se o contador extrapolar a quantidade da lista 
        return 0;
    }
    // se achou, entao coloque o aluno achado na variavel *al
    *al = li->dados[i];
    return 1;
}

//nao precisamos passar o al como endereço, já que estamos inserindo um novo aluno e nao modificando um já existente
int insere_lista_final(Lista *li,Aluno al){
    if(li==NULL || lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista *li,Aluno al){
    if(li==NULL||lista_cheia(li)){
        return 0;
    }

    int i;
    
    //deslocamento dos valores da lista da esquerda para a direita para inserir um novo valor no inicio
    for(i=li->qtd-1;i>=0;i--){
        li->dados[i+1] = li->dados[i];  
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

//insere de forma ordenada baseado na matricula do aluno
int insere_lista_ordenada(Lista *li, Aluno al){
    if(li==NULL|| lista_cheia(li)){
        return 0;
    }

    int k,i=0;

    while(i < li->qtd && li->dados[i].matricula < al.matricula) i++;
    for(k=li->qtd-1;k>=i;k--) li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}


int remove_lista(Lista *li,int mat){
    if(li==NULL || lista_vazia(li)) return 0;
    int k,i=0;

    while(i < li->qtd && li->dados[i].matricula != mat) i++;
    if(i == li->qtd) return 0;
    for(k=i;k < li->qtd-1;k++) li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
    
}

int remove_lista_inicio(Lista *li){
    if(lista_vazia(li)) return 0;
    int k=0;
    for(k=0;k < li->qtd-1;k++) li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1;
}

int remove_lista_final(Lista *li){
    if(li==NULL || lista_vazia(li)) return 0;
    li->qtd--;
    return 1;

}

int tamanho_lista(Lista *li){
    if(li==NULL) return -1;
    return li->qtd;
}

void mostra_lista(Lista *li){
    if(lista_vazia(li)){
        printf("\nInicio ->|| ");
    }
    else{
        printf("\nInicio -> ");
        int i = 0;

        while(i<tamanho_lista(li)){
            printf("|%s,%d| -> ",li->dados[i].nome,li->dados[i].matricula);
            i++;
        }
        printf("||");
    }
}