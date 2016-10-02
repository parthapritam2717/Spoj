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
    map<ll,ll> sample;
    pll t1(0,0);
    sample.insert(t1);
    pll t2(1,1);
    sample.insert(t2);

    /*for(map<ll,ll>::iterator ii=sample.begin();ii!=sample.end();++ii){
        cout<<ii->first<<" "<<ii->second<<endl;
    }*/

    fori(i,0,t){
            int n,m;
            int a,b,c;
            si(n);
            si(m);
            m=m+2;
            n=n+1;
            ll tempm,tempn;
            bool fn=false;
            for(map<ll,ll>::iterator ii=sample.begin();ii!=sample.end();++ii){
                if(ii->first<n){
                    continue;
                }
                else if(ii->first==n){
                    // we have found an exact match
                    tempn=ii->second;
                    fn=true;
                    break;
                }
                else{
                    // means our index has exceeded our value n
                    map<ll,ll>::iterator f2=ii;
                    --f2;
                    // this will be our value b
                    b=f2->second;
                    ll lastindex=f2->first+1;
                    --f2;
                    // this will be our value a
                    a=f2->second;
                    for(ll t1=lastindex;t1<=n;++t1){
                        c=(a+b)%MOD;
                        a=b;
                        b=c;
                         pll t10(t1,c);
                    //cout<<"Inserting="<<n<<" "<<c<<endl;
                        sample.insert(t10);
                    }
                    // now we have our fact in the value c and we should also save one less index value when we need
                    pll t3(n,c);
                    //cout<<"Inserting="<<n<<" "<<c<<endl;
                    sample.insert(t3);
                    tempn=c;
                    pll t4(n-1,a);
                   // cout<<"Inserting="<<n-1<<" "<<a<<endl;
                    sample.insert(t4);
                    fn=true;
                    break;

                }
            }
            if(fn==false){
                // we didn't find any index which is greater than n nothing to worry we will just have to begin our calculation from the ending element of the set
                map<ll,ll>::iterator f3=sample.end();
                --f3;
                b=f3->second;
                ll lastindex=f3->first+1;
                --f3;
                a=f3->second;
                for(ll t1=lastindex;t1<=n;++t1){
                   c=(a+b)%MOD;
                    a=b;
                    b=c;
                    pll t10(t1,c);
                    //cout<<"Inserting="<<n<<" "<<c<<endl;
                    sample.insert(t10);

                }
                pll t4(n,c);
                sample.insert(t4);
                tempn=c;
                pll t5(n-1,a);
                sample.insert(t5);

            }
           /* for(map<ll,ll>::iterator ii=sample.begin();ii!=sample.end();++ii){
                cout<<ii->first<<" "<<ii->second<<endl;
            }*/
            // now the operation for finding fm repeat the procedure we did for finding fn
              bool fm=false;
              for(map<ll,ll>::iterator ii=sample.begin();ii!=sample.end();++ii){
                if(ii->first<m){
                    continue;
                }
                else if(ii->first==m){
                    // we have found an exact match
                    tempm=ii->second;
                    fm=true;
                    break;
                }
                else{
                    // means our index has exceeded our value n
                    map<ll,ll>::iterator f2=ii;
                    --f2;
                    // this will be our value b
                    b=f2->second;
                    ll lastindex=f2->first+1;
                    --f2;
                    // this will be our value a
                    a=f2->second;
                    for(ll t1=lastindex;t1<=m;++t1){
                       c=(a+b)%MOD;
                        a=b;
                        b=c;
                        pll t10(t1,c);
                    //cout<<"Inserting="<<n<<" "<<c<<endl;
                        sample.insert(t10);
                    }
                    // now we have our fact in the value c and we should also save one less index value when we need
                    pll t3(m,c);
                    // cout<<"Inserting="<<m<<" "<<c<<endl;
                    sample.insert(t3);
                    tempm=c;
                    pll t4(m-1,a);
                   //   cout<<"Inserting="<<m-1<<" "<<a<<endl;
                    sample.insert(t4);
                    fm=true;
                    break;
                }
            }
            if(fm==false){
                // we didn't find any index which is greater than n nothing to worry we will just have to begin our calculation from the ending element of the set
                map<ll,ll>::iterator f4=sample.end();
                --f4;
                b=f4->second;
                ll lastindex=f4->first+1;
                --f4;
                a=f4->second;
                for(ll t1=lastindex;t1<=m;++t1){
                  c=(a+b)%MOD;
                    a=b;
                    b=c;
                    pll t10(t1,c);
                    //cout<<"Inserting="<<n<<" "<<c<<endl;
                        sample.insert(t10);

                }
                pll t6(m,c);
               //   cout<<"Inserting="<<m<<" "<<c<<endl;
                sample.insert(t6);
                tempm=c;
                pll t7(m-1,a);
               //  cout<<"Inserting="<<m-1<<" "<<a<<endl;
                sample.insert(t7);

            }
           /* for(map<ll,ll>::iterator ii=sample.begin();ii!=sample.end();++ii){
                cout<<"index="<<ii->first<<" "<<ii->second<<endl;
            }*/
            cout<<(tempm-tempn)%MOD<<endl;
    }
    return 0;

}



