///Folosind (heapsort), implementati diferenta a doua multimi.
///Fiecare multime este un array de intregi, iar rezultatul este un array de intregi, continand elementele din diferenta.
///Hint: modificati o interclasare.

#include <iostream>

using namespace std;

/// facem heapsort la cele 2 array uri

int largest(const int arr[], int n, int i) {
    int auxLargest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[auxLargest]) ///daca exista fiu stang si e mai mic
        auxLargest = left; ///minimul de pana acum este fiu stang

    if (right < n && arr[right] > arr[auxLargest]) ///daca exista fiu drept si e mai mic
        auxLargest = right; /// minimul de pana acum este fiu drept
    return auxLargest;
}

void heapify(int arr[], int n, int i) {
    int aux = largest(arr, n, i);
    if (aux == i) return;
    swap(arr[i], arr[aux]); ///daca parintele nu e cel mai mic interschimbam
    heapify(arr, n, aux);
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


///folosim o interclasare modificata pentru a afla lungimea diferentei si ce valori are array ul diferentei

int getDifferenceLength(const int arr1[], const int arr2[], int n1,
                        int n2) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])  {i++;k++; }
        else if (arr2[j] < arr1[i]) j++;
        else {
            i++;
            j++;
        }

    }

    while (i < n1){
        k++;
        i++;
    }

    return k;
}

///ne folosim de hint si modificam interclasarea
void difference(const int arr1[], const int arr2[], int n1,
                int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else if (arr2[j] < arr1[i]) j++;
        else {
            i++;
            j++;
        }

    }

    while (i < n1)
        arr3[k++] = arr1[i++];
}



///sortam diferenta care va intoarce un array
int* heapSortDifference(int arr[], int arr1[],int n,int n1) {
    heapSort(arr, n);
    heapSort(arr1, n1);
    int k= getDifferenceLength(arr, arr1, n, n1);
    int* c=new int[k];
    difference(arr,arr1,n,n1,c);
    return c;
}




int main() {
    int arr[] = {};
    int n=sizeof(arr)/sizeof (arr[0]);
    int arr1[] = {};
    int m=sizeof(arr1)/sizeof(arr1[0]);
    int* c= heapSortDifference(arr,arr1,n,m);
    for(int i=0;i<sizeof(c)/sizeof(c[0]);i++){
        cout<<c[i]<<" ";
    }
}










