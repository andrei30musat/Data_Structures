#include <iostream>
using namespace std;

int fr[100];
struct nod_arbore{
    int info;
    nod_arbore* fiu_stang;
    nod_arbore* fiu_drept;
};

struct arbore{
    nod_arbore* radacina;
    arbore(){
        radacina=nullptr;
    }
    void insert_element(int x){
        nod_arbore* nou = new nod_arbore;
        nou->info = x;
        nou->fiu_stang=nullptr;
        nou->fiu_drept=nullptr;

        if (radacina==nullptr){
            radacina=nou;
            return;
        }

        nod_arbore* pointer_prev = nullptr;
        nod_arbore* pointer = radacina;
        int directie = 0;

        while(pointer!=nullptr){
            pointer_prev=pointer;
            if (x<=pointer->info){
                pointer=pointer->fiu_stang;
                directie = -1;
            }else{
                pointer=pointer->fiu_drept;
                directie = 1;
            }
        }

        if (directie <0)
            pointer_prev->fiu_stang=nou;
        else
            pointer_prev->fiu_drept=nou;
    }
    void SRD(){ /// afisam in preordine de la cel mai mic la cel mai mare
        cout<<"SRD: ";
        SRD(radacina);
        cout<<endl;
    }
    void SRD(nod_arbore* pointer){
        if (pointer!=nullptr){
            SRD(pointer->fiu_stang);
            cout<<pointer->info<<" ";
            SRD(pointer->fiu_drept);
        }
    }
};

bool apare(int x, nod_arbore* pointer) ///verificam daca nodul din arborele 1 e si in arborele 2
{if(pointer!=nullptr)
    {if(pointer->info==x)
            return true;
        if(pointer->info>x)
            return apare(x, pointer->fiu_stang);
        return apare(x, pointer->fiu_drept);
    }
    return false;
}
void parcurgere_intersectie(nod_arbore* pointer, arbore arb2, arbore &arb3){ ///parcurgem arborele 1
    if (pointer!=nullptr){
        parcurgere_intersectie(pointer->fiu_stang, arb2, arb3);
        if(apare(pointer->info, arb2.radacina)) ///ne ajutam de functia apare in if daca sunt noduri comune
            arb3.insert_element(pointer->info);
        parcurgere_intersectie(pointer->fiu_drept, arb2, arb3);
    }
}


arbore intersectie(arbore arb1, arbore arb2) ///creeam  un arbore nou unde pune nodurile din intersectie
{arbore arb3;
    parcurgere_intersectie(arb1.radacina, arb2, arb3);
    return arb3;
}

int main()
{   arbore arb1, arb2;
    
    arb1.SRD();
    arb2.SRD();

    intersectie(arb1, arb2).SRD();
    return 0;
}
