#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

arvore inserir (arvore raiz, int valor, int *cresceu){
    //caso base
    if(raiz == NULL) {
        //1. Alocar espaço em memória
        arvore nova = (arvore) malloc(sizeof(struct no));
        //2. Inicializar o novo nó
        nova->valor = valor;
        nova->esq = NULL;
        nova->dir = NULL;
        nova->fb = 0;

        //3. Retornar o ponteiro para a raiz (relativa) da nova árvore
        *cresceu = 1;
        return nova;
    }
    //caso indutivo
    else {
        if(valor > raiz->valor) {
            raiz->dir = inserir(raiz->dir, valor);
            //após inserir, é preciso atualizar os fatores de balanço
            //fator de balanço "atual" => raiz->fb
            //sub-árvore cresceu ou não => *cresceu
            if(*cresceu) {
                switch(raiz->fb) {
                    case 0:
                        raiz->fb = 1;
                        *cresceu = 1;
                        break;
                    case 1:
                        *cresceu = 0;
                        return rotacao(raiz);
                        break;
                    case -1:
                         raiz->fb = 0;
                        *cresceu = 0;
                        break;

                }


            }


        } else {
            raiz->esq = inserir(raiz->esq, valor);
            //aqui
        }
        return raiz;
    }
}

arvore rotacao (arvore pivo) {
    if(pivo->fb > 0) {
        //Rotação esquerda
        if(pivo->dir->fb >= 0) {
            if(pivo->dir->fb == 0) {
                pivo->fb = 1;
                pivo->dir->fb = -1;
            } else {
                pivo->fb = 0;
                pivo->dir->fb = 0;
            }
            //rotação simples esquerda
        } else {
            //rotação dupla esquerda
        }

    } else {
        //Rotação direita

    }

}


/*
    inicialização
    p
   / \
  t1  u
     / \
    t2  t3


    final
    u
   / \
  p   t3
 / \
t1  t2

*/
arvore rotacao_simples_esquerda(arvore pivo) {
    //inicialização
    arvore u, t1, t2, t3;
    u = pivo->dir;
    t1 = pivo->esq;
    t2 = u->esq;
    t3 = u->dir;


    //Atualização dos ponteiros
    u->esq = pivo;
    pivo->dir = t2;

    return u;

}

arvore rotacao_dupla_direita(arvore pivo) {
    pivo->esq = rotacao_simples_esquerda(pivo->esq);
    return rotacao_simples_direita(pivo);
}



void preorder(arvore raiz){
    //caso indutivo...
    if(raiz != NULL) {
        //pre-order: processa raiz, depois esq e direita
        printf("[%d]", raiz->valor);

        //... chamadas recursivas
        preorder(raiz->esq);
        preorder(raiz->dir);
    }

    //caso base, fim da recursão
    else {
        //imprimir uma árvore vazia é não fazer nada
    }
}

void inorder(arvore raiz){
    if(raiz != NULL) {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }

}
void posorder(arvore raiz) {
    if(raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

/*int somatorio(arvore raiz){
    int soma = 0;

    if(raiz != NULL) {
        soma += raiz->valor +
            somatorio(raiz->esq) +
            somatorio(raiz->dir);
    }
    return soma;
}*/

int somatorio(arvore raiz){
return (raiz==NULL)?0: raiz->valor + somatorio(raiz->esq) + somatorio(raiz->dir);

}


arvore remover (arvore raiz, int valor){
 /*   if(raiz == NULL)
        return NULL;

    if(raiz->valor == valor) {
        //caso 1: elemento não possui filhos (folha)
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        //caso 2a: elemento possui exatamente um filho(esq)
        if(raiz->esq != NULL && raiz->dir == NULL) {
            arvore retorno = raiz->esq;
            free(raiz);
            return retorno;

        }
        //caso 2b: elemento possui exatamente um filho(dir)
        //TODO


        //caso 3: dois filhos
        if(//) {
           //localizar o maior elemento da sub arvore esquerda

          //copiar o valor desse elemento para a raiz relativa
            //raiz->valor = maior(raiz->esq);


            //remover a duplicata NA SUB-ÁRVORE ESQ
            //raiz->esq = remover(raiz->esq, raiz->valor);
            return raiz;
        }

    }

    else {
        if(valor > raiz->valor) {
            raiz->dir = remover(raiz->dir, valor);
        } else {
            raiz->esq = remover(raiz->esq, valor);
        }
        return raiz;
    }

 return raiz;
*/
}

ant() {
 /*  arvore temp, candidato_ant;
   temp = raiz;
   candidato_ant = NULL;

   while(não encontrou o elemento com o ponteiro temp) {

       CUIDADO!!!! Verifique se o elemento existe

    temp = temp->esq ou
    {candidato_ant = temp; temp = temp->dir;}


    }

    Se o temp possui filho esquerdo o antecessor é o maior
    da esquerda

    Se não possui o antecessor é o candidato_ant (que pode ser NULL)*/




}

