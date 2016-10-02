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
            ll n,m;
            sl(n);
            sl(m);
            int flag=0;
            multiset<pair<ll,ll>> sample;
            fori(j,0,n){
                ll pi,mi;
                sl(pi);sl(mi);
                pair<ll,ll> t(pi,mi);
                sample.insert(t);
            }

            //for(multiset<pair<ll,ll>>::iterator i=sample.begin();i!=sample.end();i++){
           //     cout<<i->first<<"->"<<i->second<<endl;
           // }
           // nl();
            // now lets do the processing
           /* multiset<pair<ll,ll>>::iterator ii=sample.upper_bound(pair<ll,ll>(3,2));
            if(ii!=sample.end()){
                cout<<ii->first<<endl;
            }
            else{
                cout<<"end"<<endl;
            }*/
            while(m>0){
                    multiset<pair<ll,ll>>::iterator i=sample.begin();
                    ll f=i->first;
                    ll c1=i->second;
                    i=sample.upper_bound(pair<ll,ll>(f,c1));
                    if(i!=sample.end()){
                        //cout<<"Upb="<<i->first<<"->"<<i->second<<endl;
                        ll sec=i->first;
                        ll c2=i->second;
                        if(f+(c1*1)>m){
                            break;
                        }
                        else{
                            ll temp=f+c1;
                           // cout<<"T="<<temp<<endl;
                            multiset<pair<ll,ll>>::iterator j=i;
                            --j;
                            sample.erase(j);
                           //// for(multiset<pair<ll,ll>>::iterator i=sample.begin();i!=sample.end();i++){
                            //    cout<<i->first<<"->"<<i->second<<endl;
                            ////}
                            //nl();
                            sample.insert(pair<ll,ll>(temp,c1));
                            m=m-c1;
                           // cout<<"Am here1"<<endl;
                           // for(multiset<pair<ll,ll>>::iterator i=sample.begin();i!=sample.end();i++){
                               // cout<<i->first<<"->"<<i->second<<endl;
                           // }
                            //nl();


                        }
                    }
                    else{
                            // means all value are equa;l now now we just need to distribute the vlues among all the robots
                            ll s=sample.size();
                            ll inc=(m/s);
                            multiset<pair<ll,ll>>::iterator i=sample.begin();
                            ll f=i->first+inc;
                            cout<<f<<endl;
                            flag=1;
                            /*for(multiset<pair<ll,ll>>::iterator i=sample.begin();i!=sample.end();i++){
                                    //cout<<i->first<<"->"<<i->second<<endl;
                                    ll f=i->first;
                                    ll s=i->second;
                                    sample.erase(i);
                                    sample.insert(pair<ll,ll> (f+inc,s));
                                     // cout<<"Am here2"<<endl;
                                //for(multiset<pair<ll,ll>>::iterator i=sample.begin();i!=sample.end();i++){
                               //     cout<<i->first<<"->"<<i->second<<endl;
                               // }
                              //  nl();
                                }*/
                                break;


                    }

                //cout<<"Hello"<<endl;
            }
            if(flag!=1)cout<<(sample.begin()->first)<<endl;
    }

    return 0;

}



