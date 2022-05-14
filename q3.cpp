#include<bits/stdc++.h>
using namespace std;

struct states{
    int s;
    int p;
    char l;
};
struct Test {
    int id;
    char l;
   
};
  
// We compare Test objects by their ids.
bool operator<(const Test& t1, const Test& t2)
{
    return (t1.id < t2.id);
}

  
    
int main() {
    int cnt = 0;
    int cnt1 = 0;
 set<int> s;
int n,k,a;
cin >>n>>k>>a;
vector<int>v(a);
set <int> e;
int q[n][n] = {0};
for(int i=0;i<a;i++)
{
    
    cin >> v[i];
    s.insert(v[i]);
}
map<Test , int> mp;
struct states var[k];
struct Test var1[k];
for(int i=0;i<k;i++)
{
    cin>>var[i].s>>var[i].l>>var[i].p;
    var1[i].id = var[i].s;
    var1[i].l = var[i].l;
    
    mp[var1[i]] = var[i].p;
}
 map<Test, int>::iterator it1;
  map<Test, int>::iterator it2;
 
  
for(int i=0;i<n;i++)
{ 
  for(int j=i+1;j<n;j++)
  {
         
         if (s.find(i) != s.end() && s.find(j) == s.end() || s.find(i) == s.end() && s.find(j) != s.end() ) 
         {
            
            q[i][j] = 1;
         }
        
      
  }
   
}
for(int i=0;i<n;i++)
{ 
  for(int j=i+1;j<n+1;j++)
  {
         
         if (q[i][j] != 1) 
         {
            for(int m=0;m<k;m++)
            {    
                it1 = mp.find({i,var[m].l});
                it2 = mp.find({j,var[m].l});
                 if(it1== mp.end() || it2 == mp.end())
                 {
                     q[i][j] = 0;
                 }
                 else
                 {
                    if (s.find(it1->second) != s.end() && s.find(it2->second) == s.end() || s.find(it1->second) == s.end() && s.find(it2->second) != s.end() ) 
                    {
            
                             q[i][j] = 1;
                    }
                 }
                       
                 
            }
           
         }
        
      
  }
  
  
   
}


for(int i=0;i<n;i++)
{ 
  for(int j=i+1;j<n;j++)
  {
         
         if (q[i][j] != 1) 
         {
             
              cnt++;
              if (s.find(i) != s.end() ) 
              {
                   cnt1++;
                  s.erase(i);
              }
              if (s.find(j) != s.end() ) 
              {
                   cnt1++;
                  s.erase(j);
              }
              e.insert(j);
         }
        
         
        
      
  }
   
}

 cout << "MINIMIZED DFA IS :" << "\n";
 cout << n-cnt << " " << k-cnt << " " << a-cnt1 << "\n";
  std::set<int>::iterator itr;
 for (itr = s.begin(); itr != s.end(); itr++)
 {
        cout << *itr << " " ;
 }
 cout <<"\n";
 for(int i=0;i<k-cnt;i++)
 {  
              if (e.find(i) != e.end() ) 
              {
                  
                continue;
                
              }
              else
              {
                  cout << var[i].s << var[i].l << var[i].p << "\n";
              }
     
 }
 

 
 
}
