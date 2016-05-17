#include <iostream>
#include "hashtable.h"
#include <unordered_map>
#include <cstdio>
#include <time.h>
#include "screen.h"

using namespace std;

int main()
{

    screen scr(20, 70);//para ajudar a escrever na tela
    hashtable ht(10, &scr);//constroi hash para 10 elementos

    string in;
    while(true){
        cout << "q quit, i insert, e exist, g get, r remove" << endl;
        cout << "ex: i key value; e key; g key; r key" << endl;
        cin >> in;
        if(in == "i"){
            int key;
            string value;
            cin >> key >> value;
            ht.insert(key, value);
            ht.show();
        }
        if(in == "e"){
            int key;
            cin >> key;
            cout << (ht.exists(key) ? "Existe" : "Nao existe") << endl;
        }
        if(in == "g"){
            int key;
            cin >> key;
            cout << "Valor " << ht.get(key) << endl;
        }
        if(in == "r"){
            int key;
            cin >> key;
            ht.remove(key);
            ht.show();
        }
        if(in == "q")
            break;
    }
    cout << endl;
    return 0;
}

