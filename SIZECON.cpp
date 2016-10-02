#include<iostream>
using namespace std;
int sum=0;
int main(){
int t;
scanf("%d",&t);
int n;
while(t>0){
scanf("%d",&n);
if(n>0){
sum+=n;
}
--t;
}printf("%lld",sum);
return 0;
}
