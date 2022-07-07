#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<int>u,vector<int>v)
{
    unordered_map<int,unordered_set<int> >adj;
    
    for(int i=0;i<m;i++){
        adj[u[i]].insert(v[i]);
        adj[v[i]].insert(u[i]);
    }
    
    
    int thcycle=0;
    for(int i=1;i<=n;i++){
        int node=i;
        
        for(int p=1;p<n;p++){
            for(int q=p+1;q<=n;q++){
                
                if(adj[node].count(p)==0)
                    break;
                if(adj[node].count(q)==0)
                    continue;
                
                if(adj[node].count(p) && adj[node].count(q)){
                    if(adj[p].count(q))
                        thcycle++;
                }
            }
        }
    }
    return thcycle/3;
    
}


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}