#include<bits/stdc++.h>
using namespace std;


bool compare( pair<pair<int,int>,int > &a,pair<pair<int,int>,int > &b)
{
 if(a.first.first!=b.first.first)
 return a.first.first<b.first.first;
 return a.second<b.second;
 }

bool allvisited(bool vis[],int n)
{
 for(int i=0;i<n;i++)
 {if(vis[i]==false)
  return false;}
  return true;
  }
 



int main()
{
   vector<pair<pair<int,int>,int> >v;
   
   int n;
   cout<<"Enter the no of process"<<endl;
   cin>>n;
   cout<<"Enter the burst time and arrival time of each process"<<endl;
   for(int i=0;i<n;i++)
   {
    int a,b;
    cin>>a>>b;
    v.push_back(make_pair(make_pair(a,b),i));
    }
    
    sort(v.begin(),v.end(),compare);
    
    int t=0;
    int ct[n];
    bool vis[n];
    memset(vis,false,sizeof(vis));
    
    
    while(allvisited(vis,n)==false)
    {
     for(int i=0;i<n;i++)
     {
       if(v[i].first.second<=t && vis[i]==false)
       {
        t+=v[i].first.first;
        vis[i]=true;
        ct[v[i].second]=t;
        }
        }}
        
        cout<<"Completion time"<<endl;
        for(int i=0;i<n;i++)
        cout<<ct[i]<<endl;
        return 0;
        }
      
   
 
