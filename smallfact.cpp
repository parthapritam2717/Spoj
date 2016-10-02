#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
#define si(x) scanf("%d", &x)
#define fori(i,s,n) for(int i=(s);i<(n);++i)
string multiplication(string s11,string s22){
int len1=s11.length();
int len2=s22.length();
int ss=max(len1,len2);
int *s1=new (nothrow) int[ss];
int *s2=new (nothrow) int [ss];
int *s3=new (nothrow) int [ss];
string result;
int index=ss-1;
int c1=0,c2=0;
for(int tt=len1-1;tt>=0;--tt){
s1[index]=s11[tt]-48;
if(s1[index]==0){
c1++;
}
--index;
}
if(c1==len1){
return "0";
}
index=ss-1;
for(int tt=len2-1;tt>=0;--tt){
s2[index]=s22[tt]-48;
if(s2[index]==0){
c2++;
}
--index;
}
if(c2==len2){
return "0";
}int loop=0;
int temp=ss;
for(int i=temp-1;i>=0;--i){
int carry=0;index=ss-1-loop;int sum=0;
for(int j=temp-1;j>=0;--j){
sum=s2[i]*s1[j]+carry;
if (index<0){
size_t sz=ss+1;
int *newarr=new int [sz];
memcpy(newarr+1,s3,ss*sizeof(int));
ss=sz;
delete[] s3;
s3=newarr;
index=0;
}
if(sum>9){
while(sum!=0){
int temp=sum%10;
sum=sum/10;
s3[index]+=temp;
carry=sum;
--index;
break;
}      }
else{
s3[index]+=sum;
--index;
carry=0;
}    }
if(carry!=0){
size_t sz=ss+1;
int *newarr=new int [sz];
memcpy(newarr+1,s3,ss*sizeof(int));
ss=sz;
delete[] s3;
newarr[0]=carry;
s3=newarr;
}
++loop;
}
bool flag=0;
fori(i,0,ss){
result=result+(char)(s3[i]+48);   }
return result;}
vector<string> data(100);
int counti=1;
int main(){
for(int i=0;i<100;++i){
data[i]="0";    }
int t;si(t);
fori(i,0,t){
string s;
cin>>s;
int nn=stoi(s);
if(data[nn-1]=="0"){
string f=data[counti-1];
if(f=="0"){
    f="1";
}
for(int i=counti;i<=nn;++i){
f=multiplication(f,to_string(i));
data[i-1]=f;
}
cout<<f<<endl;
for(int i=0;i<nn;++i){
    cout<<data[i]<<endl;
}
counti=nn+1;
cout<<counti<<endl;
}
else{
string f;
f=data[nn-1];
cout<<f<<endl;}}
return 0;
}
