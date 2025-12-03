#include<iostream>
using namespace std;

void getArr(const int *arr , const int& n){
    for(int i=0;i<n;i++) cout<<arr[i]<<"\n";
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void merge(int *arr, int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1]{0},R[n2]{0};
    for(int i=0;i<n1;i++)L[i]=arr[l+i];
    for(int i=0;i<n2;i++)R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j])arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}
int partition(int *arr, int l, int r){
    int k=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<=k){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quickSort(int *arr, int l , int r){
    if(l<r){    
        int pi=partition(arr,l, r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);

    }
}
int main()
{
    int n = 7 ;
    int *arr = new int[n]{2,1,7,5,4,3,6};
    // int *arr = new int[n]{1,2,3,4,5,6,7};

    cout<<"Before \n";
    getArr(arr, n);
    
    quickSort(arr, 0,n-1);

    cout<<"After \n";
    getArr(arr, n);

    delete[] arr;
    arr = nullptr;
    return 0;
}