///Folosind un tabel de dispersie pentru multimea mai mare, implementati diferenta simetrica a doua multimi.
///Cealalta multime este un array de intregi,
///iar rezultatul este un array de intregi, continand elementele din diferenta simetrica.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct intrare{
    long long CNP;
    int numar;
};

struct nod{
    intrare info;
    nod* next;
};

struct lista{
    nod* primul_element;//pointer la primul element
    lista(){
        primul_element=NULL;//initializare
    }
    void insert_la_inceput(long long cheie, int valoare){
        nod* nou = new nod;
        nou->info.CNP = cheie;
        nou->info.numar = valoare;
        nou->next = primul_element;
        primul_element = nou;
    }
    intrare* cauta_dupa_cheie(long long cheie){
        nod* curent = primul_element;
        while (curent!=NULL && curent->info.CNP!= cheie)
            curent=curent->next;
        if (curent==NULL)
            return NULL;
        return &(curent->info);
    }
    void afisare(){
        nod* pointer;
        if (primul_element==NULL)
            cout<<"prim=NULL";
        else
            for (pointer = primul_element; pointer !=NULL;pointer = pointer->next)
                cout<<"["<<pointer->info.CNP<<", "<<pointer->info.numar<< "] -> ";
        cout<<endl;
    }
};

int hash_diviziune(long long cheie, int N){
    return cheie % 19;
}

struct hashtable_chaining{
    lista* T;//pointer la viitor array de liste
    int n;
    int (*hashfunc)(long long, int);
    hashtable_chaining(int N, int (*H)(long long, int)){
        n=N;
        hashfunc = H;
        T=new lista[n]; //alocam un array de n liste
    }
    void put(long long cheie, int valoare){
        int hash = hashfunc(cheie,n);
        int index = hash % n;
        intrare* gasit = T[index].cauta_dupa_cheie(cheie);
        if (gasit==NULL)
            T[index].insert_la_inceput(cheie,valoare);
        else
            gasit->numar=valoare;
    }
    int get (long long cheie){
        int hash = hashfunc(cheie,n);
        int index = hash % n;
        intrare* gasit = T[index].cauta_dupa_cheie(cheie);
        if (gasit==NULL)
            return -1;
        else
            return gasit->numar;
    }
    void afisare(){
        for (int i=0;i<n;i++)
            T[i].afisare();
    }
};

int main(){
    long long A[]={35,31,58,84,6,99,94,60,36,92,91,41,3,4,66,14,56,67,82,69};
    long long B[] = {94,46,85,60,28,1,76,67,9,21,29,25,39,33,15,13,12,79,96,84};

    int n = sizeof(A)/sizeof(long long);
    int m = sizeof(B)/sizeof(long long);

    hashtable_chaining H_A(16,hash_diviziune);
    hashtable_chaining H_B(16,hash_diviziune);

    for (int i=0;i<n;i++)
        H_A.put(A[i],i);
    for (int i=0;i<m;i++)
        H_B.put(B[i],i);

    vector <int> dif_A;
    vector <int> dif_B;
    vector <int> dif_A_B;

    cout << "A este format din: "<<endl;
    H_A.afisare();

    cout <<endl<< "B este format din: "<<endl;
    H_B.afisare();

    cout << endl;
    for(int i=0; i<n; i++){
        if (H_B.get(A[i])==-1){  /// folosim functia get ptr a verifica daca un numar face parte din tabel, daca nu l gaseste va returna -1,iar daca l gaseste afis nr
            dif_A.push_back(A[i]);
            dif_A_B.push_back(A[i]);
        }

    }
    cout << " Diferenta A - B este: " << endl;
    for(int i : dif_A)
        cout<<i<<" ";


    cout << endl;
    for(int i=0;i<m; i++){
        if(H_A.get(B[i])==-1){
            dif_B.push_back(B[i]);
            dif_A_B.push_back(B[i]);}
    }
    cout << "Diferenta B - A este: " << endl;
    for(int i : dif_B)
        cout<<i<<" ";

    cout << endl << "Diferenta simetrica dintre A si B este: " << endl; /// dif simetrica : a-b reunit cu b-a
    for(int i : dif_A_B)
        cout<<i<<" ";
    
    return 0;
}