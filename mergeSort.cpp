#include<bits/stdc++.h>
#define inf 100000
using namespace std;

void merge(int arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	int i=0,j=0,k=l;
	
	for (i=0;i<n1;i++)
        L[i]=arr[l+i];
    for (j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    
    i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=R[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int mid=l+(r-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
int main()
{
	int n,i,a[inf];
	cout<<"Enter No. of elements: ";
	cin>>n;
	cout<<"Enter "<<n<<" Elements:\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	mergeSort(a,0,n-1);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
