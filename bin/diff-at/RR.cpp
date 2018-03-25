#include<bits/stdc++.h>
using namespace std;

bool all(int exec[],int n,int bt[])
{
for(int i=0;i<n;i++)
{
if(exec[i]<bt[i])
return false;
}
return true;
}




int main()
{ 
  int n;
  cout<<"Enter the no of process"<<endl;
  cin>>n;
  vector<pair<int,int> >v;
  int bt[n];
  cout<<"arrival time and burst time "<<endl;
  for(int i=0;i<n;i++)
   {
    int a,b;
    cin>>a>>b;
    v.push_back(make_pair(a,b));
    bt[i]=b;
    }
     cout<<"Enter time quantum"<<endl;
     int tq;
     cin>>tq;
     
    
    int exec[n]={0};
    int t=0;
    int ct[n];
    
    while(all(exec,n,bt)==false)
    {
     for(int i=0;i<n;i++)
       {
         if(v[i].first<=t && exec[i]<bt[i])
         {
          exec[i]+=tq;
          if(exec[i]==bt[i])
          {
            t+=tq;
            ct[i]=t;}
          else if(exec[i]>bt[i])
          {
           int d=exec[i]-bt[i];
           exec[i]-=d;
           t+=tq-d;
           ct[i]=t;
           }
           else
           t+=tq;
           }}}
            cout<<"Completion time"<<endl;
        for(int i=0;i<n;i++)
        cout<<ct[i]<<endl;
        return 0;
        }
      
     
            
         
         
         
         
         
         
         
         
         
