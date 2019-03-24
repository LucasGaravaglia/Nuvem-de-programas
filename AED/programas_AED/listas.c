//Lista Encadeada Simples

#include <stdio.h>
#include <stdlib.h>

typedef int TipoItem;
typedef struct no{
    TipoItem info;
    struct no * prox;
}Lista;
//Verifica se a cabeça da lista é nula.
int VerificaLista(Lista* novo){
    return(novo == NULL);
}
//Insere um elemento na cabeça.
Lista* insere(Lista* l,TipoItem info){
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    aux->info = info;
    aux->prox = l;                          //encadeia com a cabeca da lista
    return aux;                             // retorna a nova cabeca
}
//Remove um elemento da lista, seja na cabeça ou no corpo.
Lista * retira1(Lista* l,TipoItem info){
    Lista * ant = l;                        // elemento anterior
    Lista * p = l;                          // usado para encontrar o elemento
                                            // a ser retirado
    while(p!= NULL && p->info != info) {    // localiza o elemento
    ant = p;
    p = p->prox;
    }
    if(p != NULL) {                         // elemento encontrado
        if(p == l)                          // remoc~ao na cabeca
            l = l->prox;                    // atualiza a cabeca
        else                                // remoc~ao no meio
            ant->prox = p->prox;
        free(p);
    }else
        printf("Elemento n~ao encontrado\n");
                                            // libera o no do elemento removido
    return l;
}
//Imprime a lista
void ShowLista(Lista *l){
    Lista *t;
    t=l;
    while(t != NULL){
        printf("%d\n",t->info);
        t = t->prox;
    }
}
//Recebe uma lista e um valor, conta e retorna quatas vezes aquele elemento apareceu.
int ContaOcorrencias(Lista *l, TipoItem n){
    Lista *aux = l;
    int cont=0;
    while(aux != NULL){
        if(aux->info == n) cont ++;
        aux = aux->prox;
    }
    return cont;
}
//Remove todas as ocorrencias de um valor da lista.
Lista * retiraall(Lista* l,TipoItem info){
    Lista * ant = l;                        // elemento anterior
    Lista * p = l;                          // usado para encontrar o elemento
                                            // a ser retirado
    int cont=0;
    int i;

    cont = ContaOcorrencias(p,info);
    if(cont != 0) {
        for(i=0;i<cont;i++){
        p = l;
        while(p->info!= info) {                       // conta quantas vezes o elemento aparece
            ant = p;
            p = p->prox;
        }
            if(p == l)                          // remoc~ao na cabeca
                l = l->prox;                    // atualiza a cabeca
            else                                // remoc~ao no meio
                ant->prox = p->prox;
            free(p);                            // libera o no do elemento removido
        }
    }else
        printf("Elemento não encontrado\n");

    return l;
}
//Se a lista estiver vazia ele mostra que esta vazia, se nao ele printa a lista.
void vazia(Lista *novo){
    if(VerificaLista(novo)) printf("Lista vazia\n");
    else ShowLista(novo);
}
Lista* InvertLista(Lista *novo){
    Lista *aux = novo;
    Lista *ant = NULL;
    //Lista *temp = NULL;
    //ant = temp;
    while(aux != NULL){
        novo = novo->prox;
        aux->prox = ant;
        ant = aux;
        aux = novo;
    }
    return ant;
}
//Concatena a l2 no final de l1, e retorna a cabeça de l1.
Lista* ConcatenaLista(Lista *l1,Lista *l2){
    Lista *p = l1->prox;
    Lista *ant = l1;
    while(p!=NULL){
        ant = p;
        p = p->prox;
    }
    ant->prox = l2;
    return l1;
}

//Intercala l1 com l2, e retorna a cabeça de l1.
Lista* MergeLista(Lista *l1,Lista *l2){
    Lista *ant;
    Lista *aux1 = l1;
    Lista *aux2 = l2;
    while(aux2 != NULL && aux1 != NULL){ //Intercala entre l1 e l2 ate que um dos dois chege em NULL
        ant = aux1;
        aux1 = aux1->prox;
        ant->prox = aux2;
        ant = aux2;
        aux2 = aux2->prox;
        ant->prox = aux1;
    }                                   //O ultimo elemento da lista é sempre o NULL de l1.
    if(aux2 != NULL){   //caso l2 for maior que l1 ele concatena o resto de l2 na lista.
        ant->prox = aux2;
    }
    return l1;
}
//Função que retira uma posição em especifico da lsita.
Lista* RetiraElemento(Lista *l,Lista *ant){//recebe a posição a ser tirada, e a posição anterior.
    Lista *temp = l;
    l = l->prox;
    ant->prox = l;
    free(temp);
    return l;
}
//Remove elementos repetidos da Lista
Lista* EliminaRepetidos(Lista *l){
    Lista *aux = l;
    Lista *fixo = l;
    Lista *ant;
    TipoItem  info;

    while(fixo != NULL){
        info = fixo->info;
        aux = fixo->prox;
        ant = fixo;
        while(aux != NULL){
            if(aux->info == info)
                aux = RetiraElemento(aux,ant);
            else{
                aux = aux->prox;
                ant = ant = ant->prox;
            }
        }
        fixo = fixo->prox;
    }
    return l;
}

int main(){
    Lista *novo1;
    Lista *novo2;
    TipoItem n=1;
    novo1=NULL;
    novo2=NULL;
    //vazia(novo);
    printf("Qual valor deseja colocar na lista ?\n");
    scanf("%d",&n);
    while(n!=-1){
        novo1 = insere(novo1,n);
        scanf("%d",&n);
    }
//    printf("Qual valor deseja colocar na lista ?\nCaso deseje parar, so digitar (-1)\n");
//    scanf("%d",&n);
//    while(n!=-1){
//        novo2 = insere(novo2,n);
//        scanf("%d",&n);
//    }
    system("cls");
    //ShowLista(MergeLista(novo1,novo2));
    //system("cls");
   // vazia(novo);
   // printf("\n\n");
    printf("Qual valor deseja contar?\n");
    scanf("%d",&n);
    system("cls");
    ShowLista(novo1);
    printf("\n\n%d\n\n",ContaOcorrencias(novo1,n));
    ShowLista(novo1);
    //novo1 = EliminaRepetidos(novo1);
  //  novo = InvertLista(novo);
   // vazia(novo);

    return 0;
}



//Lista duplamente encadeada
/*
#include <stdio.h>
#include <stdlib.h>

typedef int TipoItem;
typedef struct no{
    TipoItem info;
    struct no * prox;
    struct no * ant;
}Lista;

//Começa uma lista cujos dois lados apontam para nulo.
Lista* NovaLista(Lista* l,TipoItem info){
    l->info = info;
    l->ant = NULL;
    l->prox = NULL;
    return l;
}
//Insere um elemento na cabeça.
Lista* insere(Lista* l,TipoItem info){
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    l->ant = aux;
    aux->info = info;
    aux->prox = l; //encadeia com a cabeca da lista
    return aux;// retorna a nova cabeca
}

//Remove um elemento da lista, seja na cabeça ou no corpo.
Lista * retira(Lista* l,TipoItem info){
    Lista * ant = l;    // elemento anterior
    Lista * p = l;      // usado para encontrar o elemento
                        // a ser retirado
    while(p!= NULL && p->info != info) { // localiza o elemento
    ant = p;
    p = p->prox;
    }
    if(p != NULL){          // elemento encontrado
        if(p == l) {        // remoc~ao na cabeca
            l = l->prox;// atualiza a cabeca
            l->ant = NULL;
        }else{               // remocao no meio
            ant->prox = p->prox;
            p->prox->ant = ant;
        }
        free(p);            // libera o no do elemento removido
    }else
        printf("Elemento n~ao encontrado\n");
    return l;
}

void ShowLista(Lista *l){
    Lista *t;
    t=l;
    while(t != NULL){
        printf("%d\n",t->info);
        t = t->prox;
    }
}

int main(){
    Lista *novo;
    TipoItem n=1;
    printf("Qual o primeiro valor que deseja inserir?\n");
    scanf("%d",&n);
    novo = (Lista*) malloc(sizeof(Lista));
    novo = NovaLista(novo,n);
    printf("Qual valor deseja colocar na lsita ?\nCaso deseje parar, so digitar (-1)\n");
    scanf("%d",&n);
    while(n!=-1){
        novo = insere(novo,n);
        scanf("%d",&n);
    }
    system("cls");
    ShowLista(novo);
    printf("Qual valor deseja apagar?\n");
    scanf("%d",&n);
    system("cls");
    ShowLista(retira(novo,n));

    return 0;
}
*/
