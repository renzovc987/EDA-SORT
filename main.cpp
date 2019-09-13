#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector <int>& arr)
{
    int maximo = *max_element(arr.begin(), arr.end());
    int minimo = *min_element(arr.begin(), arr.end());
    int rango = maximo - minimo + 1;

    vector<int> count(rango), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i]-minimo]++;

    for(int i = 1; i < count.size(); i++)
           count[i] += count[i-1];

    for(int i = arr.size()-1; i >= 0; i--)
    {
         output[ count[arr[i]-minimo] -1 ] = arr[i];
              count[arr[i]-minimo]--;
    }

    for(int i=0; i < arr.size(); i++)
            arr[i] = output[i];
}
void merges(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merges(arr, l, m, r);
    }
}
void bubble(int *A, int n) {
  int x,y,tmp;
  for(x = 1; x < n; x++) {
    for(y = 0; y < n - x; y++) {
      if(A[y] > A[y + 1]) {
        tmp = A[y];
        A[y] = A[y + 1];
        A[y + 1] = tmp;
      }
    }
  }
}
void ssort(int *A, int n) {
  int x, y, min, tmp;
  for(x = 0; x < n; x++) {
    min = x;
    for(y = x + 1; y < n; y++) {
      if(A[min] > A[y]) {
        min = y;
      }
    }
    tmp = A[min];
    A[min] = A[x];
    A[x] = tmp;
  }
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void isort(int *A, int n) {
  int x,val,y;
  for(x = 1; x < n; x++) {
    val = A[x];
    y = x - 1;
    while (y >= 0 && A[y] > val) {
      A[y + 1] = A[y];
      y--;
    }
    A[y + 1] = val;
  }
}

void qsort(int *A, int inicio, int final) {
  int i = inicio, f = final, tmp;
  int x = A[(inicio + final) / 2];
  do {
    while(A[i] < x && f <= final) {
      i++;
    }
    while(x < A[f] && f > inicio) {
      f--;
    }
    if(i <= f) {
      tmp = A[i];
      A[i] = A[f];
      A[f] = tmp;
      i++; f--;
    }
  } while(i <= f);

  if(inicio < f) {
    qsort(A,inicio,f);
  }

  if(i < final){
    qsort(A,i,final);
  }

}

int main()
{
    int n;
    cout<<"Numero de elementos"<<endl;
    cin>>n;
    cout<<"Ingrese elementos"<<endl;
    int *B;
    B=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    isort(B,n);
    cout<<"INSERT SORT"<<endl;
    for(int k=0;k<n;k++)
    {
        cout<<B[k]<<" ";
    }
    cout<<endl;
    cout<<"Ingrese elementos"<<endl;
    int *C;
    C=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }
    qsort(C,0,n-1);
    cout<<"QUICK SORT"<<endl;
    for(int l=0;l<5;l++)
    {
        cout<<C[l]<<" ";
    }
    cout<<endl;
    cout<<"Ingrese elementos"<<endl;
    int *A;
    A=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    bubble(A,n);
    cout<<"BUBBLE SORT"<<endl;
    for(int w=0;w<n;w++)
    {
        cout<<A[w]<<" ";
    }
    cout<<endl;
    cout<<"Ingrese elementos"<<endl;
    int *D;
    D=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>D[i];
    }
    ssort(D,n);
    cout<<"SELECTION SORT"<<endl;
    for(int w=0;w<n;w++)
    {
        cout<<D[w]<<" ";
    }
    cout<<endl;

    cout<<"Ingrese elementos"<<endl;
    int *E;
    E=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>E[i];
    }
    heapSort(E,n);
    cout<<"HEAP SORT"<<endl;
    for(int w=0;w<n;w++)
    {
        cout<<E[w]<<" ";
    }
    cout<<endl;

    cout<<"Ingrese elementos"<<endl;
    int *F;
    F=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>F[i];
    }
    mergeSort(F,0,n-1);
    cout<<"MERGE SORT"<<endl;
    for(int w=0;w<n;w++)
    {
        cout<<F[w]<<" ";
    }
    cout<<endl;

    cout<<"Ingrese elementos"<<endl;
    vector<int>G;
    G.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>G[i];
    }
    countSort(G);
    cout<<"COUNTING SORT"<<endl;
    for(int w=0;w<n;w++)
    {
        cout<<G[w]<<" ";
    }
    cout<<endl;

}
