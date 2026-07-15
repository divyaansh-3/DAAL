#include<iostream>
using namespace std;
void quicksort(int a[],int low, int high){
    if(low<high){
        int pivot = a[low];
        int i = low + 1;
        int j = high;
        int temp;
        while (i <=j){
            while(i <= high && a[i] <= pivot)
                i++;        
        
        while(a[j] > pivot)
                j--;
            if(i<j){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[low];
        a[low] = a[j];  
        a[j] = temp;
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);

    }
}

int main() {
        int n;
        cout<<"Enter number of elements: ";
        cin>>n;
        int a[n];
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<"Enter element at index "<<i+1<<":";
            cin>>a[i];
        }
        quicksort(a,0,n-1);
        cout<<endl<<"Sorted elements: ";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        return 0;
    }
