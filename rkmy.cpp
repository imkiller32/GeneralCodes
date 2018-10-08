#include<bits/stdc++.h>
using namespace std;

int hash(string p)
{
	int num=0;
	for(int i=0;i<p.length();i++)
	{
		num=num*10+p[i]-'a';
	}
	return num;
}
bool search(int val,string s,int L)
{
	int num=0;
	for(int i=0;i<L;i++)
	{
		num=num*10+s[i]-'a';
	}
	if(num==val) return 1;
	int j=0;
	for(int i=L;i<s.length();i++)
	{
		int temp=num-(s[j]-'a')*pow(10,L-1);
		num=temp;
		num=num*10+s[i]-'a';
		j++;
		if(num==val)
		return 1;
	}
	return 0;
}
int main()
{
	string s,p;
	cin>>s>>p;
	int val=hash(p);
	bool res=search(val,s,p.length());
	if(res)
	cout<<"YES\n";
	else
	cout<<"NO\n";
}
