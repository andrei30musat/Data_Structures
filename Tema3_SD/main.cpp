#include <iostream>
#include <unordered_map>

using namespace std;
struct nod_arbore {
    int info;
    nod_arbore *fiu_stang;
    nod_arbore *fiu_drept;
};

struct arbore {
    nod_arbore *radacina;

    arbore() {
        radacina = nullptr;
    }

    void insert_element(int x) {
        nod_arbore *nou = new nod_arbore;
        nou->info = x;
        nou->fiu_stang = nullptr;
        nou->fiu_drept = nullptr;

        if (radacina == nullptr) {
            radacina = nou;
            return;
        }

        nod_arbore *pointer_prev = nullptr;
        nod_arbore *pointer = radacina;
        int directie = 0;

        while (pointer != nullptr) {
            pointer_prev = pointer;
            if (x <= pointer->info) {
                pointer = pointer->fiu_stang;
                directie = -1;
            } else {
                pointer = pointer->fiu_drept;
                directie = 1;
            }
        }

        if (directie < 0)
            pointer_prev->fiu_stang = nou;
        else
            pointer_prev->fiu_drept = nou;
    }

    void SRD() {
        cout << "SRD: ";
        SRD(radacina);
        cout << endl;
    }

    void SRD(nod_arbore *pointer) {
        if (pointer != nullptr) {
            SRD(pointer->fiu_stang);
            cout << pointer->info << " ";
            SRD(pointer->fiu_drept);
        }
    }
};


int main() {
    unordered_map<int, int> map;
    arbore arb1, arb2, arb3;
    int v1[] = {6, 9, 2, 1, 11, 5, 3, 7, 8};
    int v2[] = {3, 7, 6, 10, 5, 4, 13};

    for (const auto& i: v1) {
        arb1.insert_element(i);
        map[i]++;
    }
    for (const auto& i: v2) {
        arb2.insert_element(i);
        map[i]++;
    }
    for(const auto& [i, contor] : map){
        if(contor==2)
            arb3.insert_element(i);
    }

    cout << "Arborele 1 ";
    arb1.SRD();
    cout << "Arborele 2 ";
    arb2.SRD();
    cout << "Arborele 3 ";
    arb3.SRD();


    return 0;
}
