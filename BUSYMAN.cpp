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
int main(){
    int t;
    si(t);
    fori(i,0,t){
            int n;
            si(n);
            multimap<ll,ll> sample;
            for(int j=0;j<n;++j){
                ll t1,t2;
                sl(t1);
                sl(t2);
                pair<ll,ll> te(t2,t1);
                sample.insert(te);
            }
            ll counti=0;
            ll maxi=0;
            for( multimap<ll,ll>::iterator ii=sample.begin();ii!=sample.end();++ii){
                //cout<<ii->first<<" "<<ii->second<<endl;
                if(ii->second>=maxi){
                    maxi=ii->first;
                    counti++;
                }

            }
            cout<<counti<<endl;
    }
    return 0;

}



