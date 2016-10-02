
#include<iostream>
using namespace std;
int main(){
            long long  n=1;
           do{
            cin>>n;
            if(n!=0){
            long long  sum=((n+1)*(n)*(2*n+1))/6;
            cout<<sum<<endl;
            }
            else{
                break;
            }
           }while(n!=0);
    return 0;

}



