#include <stdio.h>
#include <stdlib.h>

typedef struct item //Uma estrutura para armazenar itens não é obrigatoria nesse caso por se tratar de um unico valor 
{                   
    int cod;
}Item;

typedef struct nodeTree      //A estrutura da árvore onde passamos a struct item criada acima que vai servir como raiz da nossa árvore
{                            //E dois ponteiros da struct nodeTree um para representar a esquerda da árvore e outro para representar a direita             
    Item item;               
    struct nodeTree *left;   
    struct nodeTree *right;
}Node;

Node* initialize(){ //Função com objetivo de inicializar a árvore retornando o valor null 
    return NULL;    //É importante que a raiz tenha o valor null, vamos precisar fazer essa confirmação antes de inserir um valor para essa raiz
}

Item itemCreate(int x){ //Essa função é necessaria para passarmos como parametro para função de inserir um valor na árvore 
    Item item;          //Pois não vamos conseguir passar um inteiro diretamente 
    item.cod = x;       //O papel dessa função basicamente é fazer a conversão de inteiro para o tipo de dado item que criamos
    return item;
}

Node* insertNode(Item itemx, Node* root){                   //Nessa função vamos inserir itens na nossa árvore, para isso vamos criar uma função que
    if(root == NULL){                                       //recebe as nossas estruturas item e Node
        Node* aux = (Node*)malloc(sizeof(Node));            //O primeiro passo é varificar se o a nossa raiz é null, se sim significa que nossa arvore foiinicializada
        aux->item = itemx;                                  //então vamos criar um ponteiro do tipo Node e vamos alocar memoria para ele, em seguida vamos acessar
        aux->left = NULL;                                   //nosso item e passar o item que recebemos como parametro da função e os ponteiros que fazem referencia e
        aux->right = NULL;                                  //a esquerda e direita da nossa raiz vamos passar o valor null
    }else{                                                  //A proxima vez que a função for chamada a nossa raiz não sera mais nula então caimos no else
        if(itemx.cod < root->item.cod){                     //no else vamos fazer a comparação se o novo elemento que queremos inserir é menor que a nossa raiz
            root->left = insertNode(itemx, root->left);     //se sim vamos acessar o nó a esqueda que é null e chamar a função a nossa função recursivamente 
        }else if(itemx.cod > root->item.cod){               //passando como parametro o novo item e a estrutura que vamos inserir
            root->right = insertNode(itemx, root->right);   //Caso contrario fazemos o mesmo processo porem para a direita por se tratar de um valor maior que a raiz
        }
    }
}

void printTree(Node *root){              //Função para imprimir nossa árvore em ordem
    if(root != NULL){                    //A função recebe como parametro a estrutura que queremos imprimir
        printTree(root->left);           //O if é nescessario para que a função recurciva não seja executada pois seu valor é nulo
        printf("%d ", root->item.cod);   //Casa os nós da esquerda e direita sejam nulos e forem executados o programa vai travar
        printTree(root->right);          //Aqui tambem vamos usar a função recursivamente para imprimir os valores a esquerda e direita da raiz
    }
}

void treeFree(Node *root){     //função para desalocar a memoria alocana quando inserimos um nó
    if(root != NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

//Como pesquisar elementos na arvore
//A ideia dessa função é retornar o endereço do nó caso ele seja encontrado e caso ele não seja encontrado retornar null
Node *treeSearch(Node *root, int value){    //A função recebe como parametro a estrutura que vamos fazer a pesquisa e o valor que queremos pesquisar
    if(root != NULL){                       //Primeiro passo é varificar se a raiz é null se sim a árvore esta vazia
        if(root->item.cod == value){        //Caso contrario vamos ver se o valor que queremos é igual o valor da raiz
            return root;                    //caso não seja vamos verificar se o valor que queremos é menos que a raiz, se sim o valor esta a esquerda
        }else{                              //então chamamos a função recursivamente para ver se o valor dessa sub árvore é o valor que queremos
            if(value < root->item.cod){                 //caso não se o processo vai ser repidido fazendo comparações pra saber se o valor esta a direita ou a
                return treeSearch(root->left, value);   //esquerda das subarvores
            }else{
                return treeSearch(root->right, value);
            }
        }
    }
    return NULL;
}

int main(){
    

}