#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,vector< pair<int,int> >>m;
    int adge,starting_node,vertices;
    cout<<"adge=";cin>>adge;
    cout<<endl<<"vertices=";cin>>vertices;
    cout<<endl<<"starting_node=";cin>>starting_node;
    int a,b,w;
    for(int i=0;i<adge;i++)
    {
        cin>>a>>b>>w;
        m[a].push_back({b,w});
        m[b].push_back({a,w});
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->first<<" ";
        for(int j=0;j<(i->second).size();j++)
        {
            cout<<"["<<(i->second)[j].first<<","<<(i->second)[j].second<<"]"<<" ";
        }
        cout<<endl;
    }
    // -------------------------------------------------------------------------------------------------
    set<pair<int,int>>s;
    s.insert({0,starting_node});
    vector<int>v(vertices,INT_MAX);
    v[0]=0; 
    while(!s.empty())
    {
        auto top = s.begin();  
        int distace=top->first;
        int node=top->second;
        s.erase(top);
        for(auto i=m[node].begin();i!=m[node].end();i++)
        {
            if(i->second + distace < v[i->first])
            {
                auto find_node=s.find({v[i->first],i->first});
                if(find_node != s.end())
                {
                    s.erase(find_node);
                }
                v[i->first]=(i->second + distace);
                s.insert({v[i->first],i->first});
            }
        }
        cout<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }
    return 0;
}
