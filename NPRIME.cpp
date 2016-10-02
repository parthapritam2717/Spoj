#include<iostream>
using namespace std;int p[100001],j=0,i=2,z=2,n,k;void s(){bool *a=new bool[1300001]();while(z*z<=1300000){if(a[z]==0){k=z*2;while(k<=1300000){a[k]=1;k+=z;}}++z;}while(i<=1300000){if(!a[i]){p[j]=i;j++;if(j==100000){break;}}++i;}}int main(){s();while(!cin.eof()){cin>>n;cout<<p[n-1]<<"\n";}return 0;}
