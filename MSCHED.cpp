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


ll calc_profit( vector<pair<long long,long long>> sample,ll n){
    int *list1 =new int[n](); ll counti=0;
    for(int i=0;i<n;i++){
        for(int j=min(n,sample[i].second)-1;j>=0;--j){
                if(list1[j]==0){
                    counti+=sample[i].first;
                    list1[j]=1;
                    break;
                }

        }
    }
    return counti;

}
int main(){
            int n;
            si(n);
            vector<pair<long long,long long>> sample;
            fori(j,0,n){
                    ll pro;ll dead;
                    sl(pro);sl(dead);
                    pair<ll,ll> t(pro,dead);
                    sample.pb(t);
            }
            // now process
            sort(sample.rbegin(),sample.rend());
            ll profit=0;
            ll tt=0;
            ll price=0;
           // for( vector<pair<long long,long long>>::iterator i=sample.begin();i!=sample.end();++i){
             //   cout<<i->first<<" "<<i->second<<endl;
                         //   }
            cout<<calc_profit(sample,n)<<endl;

    return 0;

}



