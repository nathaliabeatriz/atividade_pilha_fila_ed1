#include<bits/stdc++.h>
using namespace std;

struct No{
    int valor;
    No* prox;

    No(int _valor){
        valor = _valor;
        prox = NULL;
    }

    No(){
        prox = NULL;
    }

};

struct Pilha{
    No* topo;
    int tam;

    Pilha(){
        topo = NULL;
        tam = 0;
    }

    void inserir(int valor){
        No* novo = new No(valor);
        if(topo == NULL){
            topo = novo;
        } else{
            novo->prox = topo;
            topo = novo;
        }
        tam++;
    }

    void remover(){
        if(tam==0) return;
        if(tam==1){
            delete(topo);
            topo = NULL;
            tam = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        tam--;
    }

    int topoPilha(){
        if(topo == NULL) return -1;
        return topo->valor;
    }
};

struct Fila{
    No* inicio;
    No* fim;
    int tam;

    Fila(){
        inicio = NULL;
        fim = NULL;
        tam = 0;
    }

    void enfileirar(int valor){
        No* novo = new No(valor);
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        tam++;
    }

    void desenfileirar(){
        if(tam == 0) return;
        if(tam == 1){
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            tam = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        tam--;
    }

    int frente(){
        if(tam==0) return -1;
        return inicio->valor;
    }
};

Fila inverterFila(Fila f, Pilha p){
    while(f.tam > 0){
        p.inserir(f.frente());
        f.desenfileirar();
    }

    while(p.tam > 0){
        f.enfileirar(p.topoPilha());
        p.remover();
    }

    return f;
}

int main(){
    Fila f;
    f.enfileirar(2);
    f.enfileirar(5);
    f.enfileirar(9);
    f.enfileirar(3);
    f.enfileirar(7);

    Pilha p;
    f = inverterFila(f, p);

    while(f.tam > 0){
        cout << f.frente() << "\n";
        f.desenfileirar();
    }
    
}
