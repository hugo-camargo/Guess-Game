/*
                    ***** TRABALHO PRÁTICO *****

REQUISITOS:

-   FAZER UM JOGO USANDO A TAD ÁRVORE (PODE SER QUALQUER UMA VISTA EM SALA);

-   A ÁRVORE NÃO DEVERÁ SER UTILIZADA PARA ARMAZENAR A PONTUAÇÃO DO JOGO;

-   O GRUPO SERÁ DE 3 NO MÁXIMO, DEVERÁ ENTREGARO CÓDIGO FONTE NO MOODLE E DEVERÁ APRESENTAR O JOGO FUNCIONANDO E EXPLICAR O CÓDIGO DURANTE A APRESENTAÇÃO DO TRABALHO;

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {

    int value;
    struct node *left;
    struct node *right;
} node;

int verify_malloc(node *n) {

    if(n != NULL) {

        return 1;
    }
    return 0;
}

node *create_node(int value) {

    node *new = (node*) malloc(sizeof(node));

    if(verify_malloc(new)) {

        new->value = value;
        new->left = NULL;
        new->right = NULL;

        return new;
    }
    return NULL;
}

node *insert(node *root,int value) {

    if(root == NULL) {

        return create_node(value);
    } 
    else if(value < root->value) {

        root->left = insert(root->left,value);
    } else if(value > root->value) {

        root->right = insert(root->right,value);
    }
    return root;
}

node *find(node *root,int value) {

    if(root == NULL || root->value == value) {

        return root;
    }
    else if(value < root->value) {

        return find(root->left,value);
    }
    return find(root->right,value);
}


node *create_tree(int min,int max) {

    node *root = NULL;

    for(int i = min;i <= max;i++) {

        root = insert(root,i);
    }
    return root;
}

void free_tree(node *root) {

    if(root != NULL) {

        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int rand_number(int min,int max) {

    int random = rand() % (max - min + 1) + min;

    return random;
}

int verify_input(int *input) {

    if(scanf("%d%*c",input) == 1) {

        if(*input < 0) {

            return 0;
        } else {

            return 1;
        }
    }
    while(getchar() != '\n');

    return 0;
}

void clear_terminal() {

    for(int i = 0;i < 50;i++) {

        printf("\n");
    }
}

int main() {

    int option = 1;
    srand(time(NULL));

    do {

        printf("\n\n\t\t\t\t\t***** JOGO DE ADIVINHACAO *****\n\n");

        int min,max,secret_number,bet,play = 0,try = 0;

        while(1) {

            printf("\n\nINSIRA UM INTERVALO MINIMO:\t");
            
            if(!verify_input(&min)) {

                printf("\nENTRADA INVALIDA!");
                printf("\n---------------------------------------------\n");
                continue;
                
            } 

            printf("\nINSIRA UM INTERVALO MAXIMO:\t");

            if(!verify_input(&max)) {

                printf("\nENTRADA INVALIDA!");
                printf("\n---------------------------------------------\n");
                continue;

            } 
            
            if(min >= max) {

                printf("\nINTERVALO INVALIDO!");
                printf("\n---------------------------------------------\n");
                continue;

            }
            break; 
        }

        play = max;
        node *tree = create_tree(min,max);
        secret_number = rand_number(min,max);
                
        do {

            printf("\n---------------------------------------------\n");
            printf("\n\t\tTENTATIVA %d\n\n",(try + 1));

            printf("\nINSIRA UM NUMERO:\t");
            
            if(!verify_input(&bet)) {

                printf("\nENTRADA INVALIDA!");
                continue;
            }

            if(bet < secret_number) {

                printf("\nO NUMERO E MAIOR QUE %d!",bet);
                play--;
            } 
            else if(bet > secret_number) {

                printf("\nO NUMERO E MENOR QUE %d!",bet);
                
                play--;
            } else {

                printf("\n\n\t\t\t\t\t***** PARABENS,VOCE ACERTOU!!! *****\n\n\nTOTAL DE PONTOS:\t[ %d ]",(play - 1));
            }
            try++;

        } while(bet != secret_number);

        free_tree(tree);

        printf("\n\n\nPARA JOGAR NOVAMENTE, DIGITE 1 (OU 0 PARA SAIR):\t");
        
        if(!verify_input(&option)) {

            printf("\nENTRADA INVALIDA! ENCERRANDO O JOGO...");
            option = 0;           
        }
        clear_terminal();
        
    } while(option == 1);
}