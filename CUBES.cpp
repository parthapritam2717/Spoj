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
    for(int i=6;i<=100;++i){
        ll sum=pow(i,3);
        // need to create some containers to store all the equal values set
        map<int,vi> data;
        for(int j=2;j<i;++j){
            ll sum1=sum-pow(j,3);
             for(int k=2;k<j;++k){
                    ll sum2=sum1-pow(k,3);
                     for(int l=2;l<k;++l){
                            ll sum3=sum2-pow(l,3);
                            if(sum3==0){
                                //cout<<"Cube = "<<i<<", Triple = ("<<l<<","<<k<<","<<j<<")"<<endl;
                                vi temp={k,j};
                                data.insert(pair<int,vi> (l,temp));
                            }
                     }
             }
        }
        for(map<int,vi>::iterator ii=data.begin();ii!=data.end();++ii){
            vi temp=ii->second;
            cout<<"Cube = "<<i<<", Triple = ("<<ii->first<<","<<temp[0]<<","<<temp[1]<<")"<<endl;


        }


        }


    return 0;

}



