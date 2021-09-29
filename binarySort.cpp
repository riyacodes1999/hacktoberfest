#include<bits/stdc++.h>
using namespace std;

void seg(int a[],int n){
    int c=0;
    for(int i=0;i<n;i++)
        if(a[i]==0)
        c++;
    
    for(int i=0;i<c;i++)
        a[i]=0;
    
    for(int i=c;i<n;i++)
        a[i]=1;
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    seg(a,n);
    return 0;
}
