#include <iostream>

using namespace std;

struct Nod {
    int info;
    Nod *prev;
    Nod *next;
};

void Afisare(Nod *elem) {

    while (elem != nullptr) {
        cout << elem->info << " ";
        elem = elem->next;
    }
    cout << endl;
}

void Insert(Nod *&cap, int valoare) {
    //cap este primul element din lista
    Nod *elem_final = new Nod;
    elem_final->info = valoare;
    elem_final->next = nullptr;
    elem_final->prev = nullptr;

    if (cap == nullptr) // In cazul in care lista noastra este vida, punem elementul in lista
        cap = elem_final;
    else {
        //Parcurgem lista pana la final
        Nod *nod_curent = cap;
        while (nod_curent->next != nullptr)
            nod_curent = nod_curent->next;

        //Mutam sageata ultimului element catre elementul creat anterior
        nod_curent->next = elem_final;
        elem_final->prev = nod_curent;
    }


    Nod *elem = new Nod();
    elem->info = -valoare;

    elem->next = cap;
    elem->prev = nullptr;

    cap = elem;
}

void Extract(Nod *&cap) {
    Nod *prima_victima = cap;
    cap = cap->next;
    cap->prev = nullptr;
    delete prima_victima;

    Nod *ultima_victima = cap;
    while (ultima_victima->next != nullptr)
        ultima_victima = ultima_victima->next;

    ultima_victima->prev->next = nullptr;
    delete ultima_victima;
}

int main() {
    Nod *nod = nullptr;
    Insert(nod, 1);
    Insert(nod, 2);
    Insert(nod, 3);
    Afisare(nod);
    Extract(nod);
    Afisare(nod);
    Extract(nod);
    Afisare(nod);
    Extract(nod);
    Afisare(nod);
    return 0;
}