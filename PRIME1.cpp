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
#include<time.h>
#include<math.h>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<stack>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<string> vs;
typedef unordered_map<int,int> umap;
typedef map<long long,long long> omap;
typedef multimap<long long,long long> mmap;

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


bool isprime(ll n){
    if(n==3){
        return true;
    }
    else if(n%3==0){
        return false;
    }
    else{
        //check for prime
        ll sq=sqrt(n)+1;
        bool flag=false;
        for(ll j=2;j<=sq;j+=1){
            if(n%j==0){
                return false;
            }
            else{
                continue;
            }
        }
      if(flag==false){
        return true;
      }

    }

}

int main(){
    int t;
    si(t);
    fori(i,0,t){
            ll n,m;
            sl(n);
            sl(m);
            // now check for prime
            ll start;
            if(n<=2){
                Pl(2);nl();
                start=3;

            }
            else if(n%2==0){
                    start=n+1;
            }
            else{
                start=n;
            }
            ll c=0;
            for(ll j=start;j<=m;j+=2){
                   if(isprime(j)){
                    Pl(j);nl();
                   }
                   c++;
            }

    }

    return 0;

}



