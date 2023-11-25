#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    //declarar e inicializar como árvore vazia
    arvore a = NULL;
    int cresceu;
    int opcao;
    int temp;

    while(1) {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                scanf("%d", &temp);
                a = inserir(a, temp, &cresceu);
                break;
            case 2:
                preorder(a);
                printf("\n");
                break;


            case 99:
                exit(0);
        }

    }

}
