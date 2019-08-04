#include "processa.h"

/* Processa uma palavra dado um autômato
* Entrada: Automato
* Retorno: Nenhum
* Pré-condição: O autômato deve existir e estar completo
* Pós-condição: A palavra é processada
*/
void process(Automato *a){
    Estado *e = new Estado(a->getEstados()[a->getInitial()]);
    int i,k,novoEstado,controle=0;
    char temp[1000],*palavra,*aux;
    char decisao;
    system("clear");
    cout << "Digite a palavra para ser processada\n:";
    scanf("%[^\n]%*c",temp);
    palavra = new char[strlen(temp)+1];
    strcpy(palavra,temp);
    aux = palavra;
    system("clear");
    cout << "\t\t\tProcessamento de: " << palavra << endl << endl;
    
     for(i=0;i<strlen(palavra);i++,aux++){
        for(k=0;k<e->getNumeroDeTransicoes();k++){
            if(palavra[i] == e->getTransicoes()[k]->getSimboloLido()){
                cout << "[" << e->getNome() << "]: " << aux << endl;
                novoEstado = e->getTransicoes()[k]->getEstadoPossivel();
                delete e;
                e = new Estado(a->getEstados()[novoEstado]);
                break;
            }else if(palavra[i] != e->getTransicoes()[k]->getSimboloLido() && k == e->getNumeroDeTransicoes()-1){
                controle=1;
                break;
            }
        }
        if(controle==1) {
            aux++;
            break;
        }
    }
    if(controle==0 && e->getFinal() == true){
        cout << "[" << e->getNome() << "]: " << endl;
        cout << "Palavra aceita\n";
    }else{
        cout << "[" << e->getNome() << "]: " << --aux << endl;
        cout << "[" << e->getNome() << "]: " << endl;
        cout << "Palavra rejeitada\n";
    }
    cout << "\nAperte r para digitar outra palavra ou q para voltar ao menu\n:";
    decisao = getchChar();
    if(decisao == 'r' || decisao == 'R'){
        process(a);
    }
}

