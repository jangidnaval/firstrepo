#include<bits/stdc++.h>
using namespace std;


bool compare(pair<pair<int,int>,pair<int,int> > &a,pair<pair<int,int>,pair<int,int> > &b)
{
 if(a.first.first!=b.first.first)
   return a.first.first>b.first.first;
   return a.first.second<b.first.second;
   }
   
   
   bool allvis(bool vis[],int n)
{
 for(int i=0;i<n;i++)
 {if(vis[i]==false)
  return false;}
  return true;
  }
 

int main()
{
 int n;
 cin>>n;
 vector<pair<pair<int,int>,pair<int,int> > >v;
 
 cout<<"Enter the burst time,arrival time and priority for each one "<<endl;
 for(int i=0;i<n;i++)
 {
  int br,ar,pr;
  cin>>br>>ar>>pr;
  v.push_back(make_pair(make_pair(pr,i),make_pair(br,ar)));
  }
  
  sort(v.begin(),v.end(),compare);
  
  for(int i=0;i<n;i++)
   cout<<v[i].second.first<<endl;
   
  
  bool vis[n];
  int t=0;
  int ct[n];
  memset(vis,false,sizeof(vis));
  
  while(allvis(vis,n)==false)
  {
  for(int i=0;i<n;i++)
  {
    if(v[i].second.second<=t && vis[i]==false)
    {
     t+=v[i].second.first;
     ct[v[i].first.second]=t;
     vis[i]=true;
     break;
     }
     }}
     cout<<"Completion time"<<endl;
        for(int i=0;i<n;i++)
        cout<<ct[i]<<endl;
        return 0;
        }
      
        
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

