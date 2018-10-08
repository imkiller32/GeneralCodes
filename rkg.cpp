#include<bits/stdc++.h> 
#define d 256 

using namespace std;

void search(string pat, string txt, int q ) 
{ 
    int i, j; 
    int p = 0;
    int t = 0;
    int h = 1; 
  
    for(i=0;i<pat.length()-1;i++) 
        h=(h*d)%q; 
        
    for(i=0;i<pat.length();i++) 
    { 
        p=(d*p + pat[i])%q; 
        t=(d*t + txt[i])%q; 
    } 
    for(i=0;i<=txt.length()-pat.length();i++) 
    { 
        if(p==t) 
        { 
            for(j=0;j<pat.length();j++) 
            { 
                if(txt[i+j] != pat[j]) 
                    break; 
            } 
            if(j==pat.length()) 
                cout<<"Found at shift "<<i<<endl;
        } 
        if(i<txt.length()-pat.length()) 
        { 
            t=(d*(t-txt[i]*h) + txt[i+pat.length()])%q; 
            if(t<0) 
            t=(t+q); 
        } 
    } 
} 

int main() 
{ 
    string t,p; 
    cout<<"Enter Text String : ";
    cin>>t;
    cout<<"Enter Pattern To Find : ";
    cin>>p;
    int q = 101; 
    search(p, t, q); 
    return 0; 
}
