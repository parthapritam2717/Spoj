#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<stack>

using namespace std;

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define all(v) v.begin(),v.end()
#define Pi(x) printf("%d", x)
#define Pl(x) printf("%lld", x)
#define os() printf(" ")
#define nl() printf("\n");
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define forl(i,s,n) for(ll i=(s);i<(n);++i)
#define forir(i,s,n) for(int i=(n)-1;i>=(s);--i)
#define forlr(i,s,n) for(ll i=(n)-1;i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define debugl(i,st,arr) forl(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();++(i))
#define forcr(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();++(i))
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}
int main(){
    int t;
    fastRead_int(t);
    fori(i,0,t){
            int n;
            fastRead_int(n);
            multiset<int> list1;
            fori(j,0,n){
                    int tem;
                    fastRead_int(tem);
                    list1.insert(tem);
            }
                bool flag=true;
        		for(int i=0;i<=n-1;i++){
                    int t1=i;
                    int t2=n-1-i;
                    multiset<int>::iterator ii=list1.find(t1);
                    multiset<int>::iterator ij=list1.find(t2);
                    if(ii!=list1.end()){
                            list1.erase(ii);
                            flag=true;
                            continue;
                    }
                    else if(ij!=list1.end()){
                            list1.erase(ij);
                            flag=true;
                            continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==true && list1.size()==0){
                    cout<<"YES"<<endl;
                }
                else if(flag==true && list1.size()!=0){
                    cout<<"NO"<<endl;
                }
                else if(flag==false){
                     cout<<"NO"<<endl;
                }




    }
    return 0;

}



