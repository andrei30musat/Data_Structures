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

void Insert(Nod *&head, int valoare) {
    //head este primul element din lista
    Nod *ultimul_element = new Nod;
    ultimul_element->info = valoare;
    ultimul_element->next = nullptr;
    ultimul_element->prev = nullptr;

    if (head == nullptr) // In cazul in care lista noastra este vida, punem elementul in lista
        head = ultimul_element;
    else {
        //Parcurgem lista pana la final
        Nod *nod_curent = head;
        while (nod_curent->next != nullptr)
            nod_curent = nod_curent->next;

        //Mutam sageata ultimului element catre elementul creat anterior
        nod_curent->next = ultimul_element;
        ultimul_element->prev = nod_curent;
    }


    Nod *primul_element = new Nod();
    primul_element->info = -valoare;

    primul_element->next = head;
    primul_element->prev = nullptr;

    head = primul_element;
}

void Extract(Nod *&head) {
    Nod *prima_victima = head;
    head = head->next;
    head->prev = nullptr;
    delete prima_victima;

    Nod *ultima_victima = head;
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