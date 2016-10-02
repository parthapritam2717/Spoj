#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
long long int t;
scanf("%lld",&t);
while(t>0)
{
long long int n,sum=0;
scanf("%lld",&n);
long long int a[n];
for(long long int i=0;i<n;i++)
{
scanf("%lld",&a[i]);
sum=((sum%n)+(a[i]%n))%n;
}
if(sum==0) printf("YES\n");
else printf("NO\n");
t--;
}
}
