#include<bits/stdc++.h>
using namespace std;

int Search_Pattern(string s,string p,vector<int> F)
{
	int i,j;
	i=0;
	j=-1;
	while(j+1!=p.length() && i<s.length())
	{
		if(s[i]==p[j+1])
		{
			i++;
			j++;
		}
		else
		{
			if(j==-1)
			i++;
			else
			j=F[j]-1;
		}
	}
	if(j+1==p.length())
	return (i-p.length());
	else
	return -1;
}

vector<int> CreatePrefix(string s)
{
	int n = (int) s.length() ;
	vector<int> F(n);
	F[0]=0;
	for(int i=1;i<n;i++)
	{
		int j = F[i-1];
		while(j>0 && s[i]!=s[j])
		j=F[j-1];
		if(s[i]==s[j])
		j++;
		F[i]=j;
	}
	return F;
}

int main()
{
	string s,p;
	vector<int> v;
	cout<<"Enter Major String : ";
	cin>>s;
	cout<<"Enter The Pattern : ";
	cin>>p;
	v=CreatePrefix(p);
	int res=Search_Pattern(s,p,v);
	if(res!=-1)
	{
		cout<<"Matched at index "<<res<<endl;
		for(int i=res;i<res+p.length();i++)
		cout<<s[i];
		cout<<endl;
	}
	else
	cout<<"Not Matched\n";
}
