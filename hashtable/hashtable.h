#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "item.h"
#include "screen.h"
using namespace std;

class hashtable
{       
public:

    void show(int ind = -1, item it = item(0, "")){
        screen &s = *scr;
        s.clear();
        int step = 6;
        const int lkey = 5;//linha da chave

        int delta = 5;
        s.write(lkey - 1, 0, 0,  "  ind");
        s.write(lkey    , 0, 0, "  key");
        s.write(lkey + 1, 0, 0, "value");
        for(int i = 0; i < _max; i++){
            s.write(lkey - 2, i * step + delta, step, string(step, '='));
            s.write(lkey - 1, i * step + delta, step, "|__" + to_string(i) + "__");
            s.write(lkey    , i * step + delta, step, "|" + to_string(_vet[i].key));
            s.write(lkey + 1, i * step + delta, step, "|" + _vet[i].data);
            s.write(lkey + 2, i * step + delta, step, string(step, '='));
        }

        int lfkey = lkey - 4;//linha da chave em foco
        if(ind != -1){
            s.write(lfkey    , ind * step + delta, step, "|" + to_string(it.key));
            s.write(lfkey + 1, ind * step + delta, step, "|" + it.data);
        }
        s.show();
        s.wait();
    }

private:
    item * _vet;
    int _qtd;
    int _max;
    screen * scr;

    //realoca a tabela numa tabela com este novo tamanho
    void rebuild(int new_max_size){
        (void) new_max_size;
    }

    //retorna o indice da chave ou da primeira posição vazia após colisao
    int find_pos(int key, string value = ""){
        return -1;
    }

public:

    hashtable(int size, screen * scr)
    {
        this->scr = scr;
        _vet = new item[size];
        _max = size;
        _qtd = 0;
    }

    ~hashtable(){
        delete[] _vet;
    }

    int size(){
        return _qtd;
    }

    //se a chave ja existir, retorne false.
    //se não existe faça a inserção na tabela
    //se a ocupação passar de 80%, duplique o tamanho da tabela e
    //realoque todos os elementos
    bool insert(int key, string data){
        return false;
    }

    //se a chave existir retorne true
    bool exists(int key){
        return false;
    }

    //se a chave existir, retorne o dado. Se não existir, retorne ""
    string get(int key){
        return "";
    }

    //se a chave existir, remova da tabela e retorne true
    //realoque todos os elementos seguintes
    //se a chave não existir, retorne false
    bool remove(int key){
        return false;
    }
};

#endif // HASHTABLE_H
