#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f(int a,int b,vector<int>v)
{
    if(v[b]!=-1)
    {
        return v[b];
    }
    else if(b==1 || b==0)
    {
        v[b]=1;
    }
    else 
    {
        int c=INT_MIN;
        for(int i=1;i<b;i++)
        {
            c= max(c,a*f(i,b-i,v));
        }
        v[b]=max(c,a*b);
    }
    return v[b];
}
int main()
{   
    int l;
    cout<<"length=";
    cin>>l;
    vector<int>v(l+1,-1);
    cout<<f(1,l,v)<<endl;
    return 0;
}