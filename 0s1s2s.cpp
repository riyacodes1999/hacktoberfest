#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void sort(int a[],int n){
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        switch(a[i]){
            case 0:
            c0++;
            break;
            case 1:
            c1++;
            break;
            case 2:
            c2++;
            break; 
        }
    }
    int i=0;
    while(c0>0){
        a[i++]=0;
        c0--;
    }
    while(c1>0){
        a[i++]=1;
        c1--;
    }
    while(c2>0){
        a[i++]=2;
        c2--;
    }
     print(a,n);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,n);
    return 0;
}