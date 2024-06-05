#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>

struct float_vector{
    int capacity; //num max de elemntos
    int size; //qtd de elementos armazenados atualmente
    float *data; //vetor de floats
};

/*
    brief:
        Cria(aloca) um vetor de floats com uma dada capacidade
    param:
        capacity:capacidade do vetor
    return:
        FloatVector* um vetor de floats alocado/criado
*/
FloatVector *create(int capacity){
    FloatVector *vec = (FloatVector*) calloc(1,sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity,sizeof(float));

    return vec;

}

//brief: destroi(desaloca) o vetor
//param: referencia ao vetor "data" pois precisamos desalocar primeiro o data depois o FloatVector para n perder referencia
//return: vazio
void destroy(FloatVector **vec_ref){
    FloatVector *vec = *vec_ref;

    free(vec->data);
    free(vec);
    *vec_ref = NULL;

}

void append(FloatVector *vec, float val){
    if(vec->size==vec->capacity){
        fprintf(stderr,"ERROR in append\n");
        fprintf(stderr,"Vector is full\n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size] = val;
    vec->size++;

}

void print(const FloatVector *vec){
    puts("----------------");
    printf("Size: %d\n",vec->size);
    printf("Capacity: %d\n",vec->capacity);
    puts("----");

    for(int i=0;i<vec->size;i++){
        printf("[%d] = %f\n",i,vec->data[i]);
    }
    puts("--------------------------\n");
}           


//mais segurança,menos desempenho
float at(const FloatVector *vec,int index){
    if(index<0||index>=vec->size){
        fprintf(stderr,"ERROR in 'at'\n");
        fprintf(stderr,"Index [%d] is out of bounds: [0,%d]\n",index,vec->size);
        exit(EXIT_FAILURE); 
    }

    return vec->data[index];
}

//menos segurança,mais desemepenho
float get(const FloatVector *vec, int index){
    return vec->data[index];
}

void set(FloatVector *vec, int index, float val){
    if(index<0 || index>= vec->size){
        fprintf(stderr,"ERROR in 'set'\n");
        fprintf(stderr,"Index [%d] is out of bounds: [0,%d]\n",index,vec->size);
        exit(EXIT_FAILURE);
    }
    vec->data[index] = val;
}