#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int l=0,m=0,h=n-1;
    for(int i=0;i<n;i++){
        if(arr[m]==0){
            swap(arr[m],arr[l]);
            l++;
            m++;
        }
        else if(arr[m]==1) m++;
        else{
            swap(arr[m],arr[h]);
            h--;
        }
    }
}