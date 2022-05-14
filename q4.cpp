#include <bits/stdc++.h>
using namespace std;
stack<char>st;
vector<string>v(100);
    int a = 0;
    int vc = 0;
void func1(char c, char b);
void func2(char c,char b);
void func3(char c);
int func(int i,string s)
{    int hik = 0;
    for(int j=i+1;j<s.length();j++)
    {   
        
        if(s[j] == '+')
        {   
           
           func1(s[j-1],s[j+1]);
           
        }
        if(s[j] == '*')
        {
            func2(s[j-1],s[j+1]);
        }
        hik++;
        if((s[j]!= '*' && s[j] != '+' && s[j]!= ')' && s[j]!= '('))
        {
            func3(s[j]);
        }
        if(s[j] == ')')
        {
            break;
        }
       
       
    }
     
    return hik;
}

void func1(char c, char b)
{
            v[vc++]  = std::to_string(a)+'E'+std::to_string(a+1);
            v[vc++] = std::to_string(a)+'E'+std::to_string(a+2);
            v[vc++]  = std::to_string(a+1)+c+std::to_string(a+3);
            v[vc++] = std::to_string(a+2)+b+std::to_string(a+3);
            
            //v[vc++] = std::to_string(a+3)+'E'+std::to_string(a+4);
            a = a+3;
}
void func2(char c,char b)
{
            v[vc++]  = std::to_string(a)+'E'+std::to_string(a+1);
            v[vc++] = std::to_string(a)+'E'+std::to_string(a+3);
            v[vc++] = std::to_string(a+1)+c+std::to_string(a+2);
            v[vc++]  = std::to_string(a+2)+'E'+std::to_string(a+1);
            v[vc++] = std::to_string(a+2)+'E'+std::to_string(a+3);
            v[vc++] = std::to_string(a+3)+b+std::to_string(a+4);
            a = a+6;
}
void func3(char c)
{
            v[vc++]  = std::to_string(a)+c+std::to_string(a+1);
            
            
            a = a+1;
}

void func4(char c,string s)
{
            v[vc++]  = std::to_string(a)+'E'+std::to_string(a+1);
            v[vc++] = std::to_string(a)+'E'+std::to_string(a+2);
            
            //int k = func(a+2,s);
             v[vc++]  = std::to_string(a+1)+c+std::to_string(a+3);
             v[vc++]  = std::to_string(a+2)+'E'+std::to_string(a+3);
             v[vc++]  = std::to_string(a+2)+'E'+std::to_string(a+3);
            
            //v[vc++] = std::to_string(a+3)+'E'+std::to_string(a+4);
            a = a+3;
}
int main(int argc, char** argv)
{  
   ofstream outdata; 
   

   outdata.open(argv[2]);
    string s;
  ifstream myfile (argv[1]);
  if (myfile.is_open())
  {
    while ( getline (myfile,s) )
    {
       for(int i=0;i<s.length();i++)
       {   
           if(s[i] == '(')
           {   
               int hik = func(i,s);
               i = i+hik+1;
           }
           if(s[i] == '+')
           {   
                 if(s[i+1]!= '(')
                 {
                    func1(s[i-1],s[i+1]);
                 }
                 else
                 {
                     v[vc++]  = std::to_string(a)+'E'+std::to_string(a+1);
                     v[vc++] = std::to_string(a)+'E'+std::to_string(a+2);
            
                     int lk = func(i+1,s);
                     v[vc++]  = std::to_string(a+1)+s[i-1]+std::to_string(lk+3);
                     v[vc++]  = std::to_string(a+2)+'E'+std::to_string(a+3);
                     v[vc++]  = std::to_string(a+2)+'E'+std::to_string(a+3);
                 }
            }
             
            
       
       
            if(s[i] == '*')
            {   
                if(s[i+1]!= '(')
                {  
                 func2(s[i-1],s[i+1]);
                
                }
                else
                {
                  func4(s[i-1],s);
                }
           
            }
        
          if((s[i]!= '*' && s[i] != '+' && s[i]!= '(')&& (s[i-1]!= '*' && s[i-1] != '+' && s[i-1]!= '(') && (s[i+1]!= '*' && s[i+1] != '+' && s[i+1]!= '('))
          {
            func3(s[i]);
          }
        
           
           
       }
            for(int i=0;i<vc;i++)
           {
                outdata << v[i] <<"\n";
           }
           
           outdata << "\n";
    }
    
   
    
    
    
  }
   
   
    
    myfile.close();
    outdata.close();
    
}