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
#include<queue>
#include<algorithm>

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
//Usefull for codeforces and spoj for faster integer input reading
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
//to read strings with whitespace string s,getline(cin,s);

struct comp { 
    bool operator()(pair<string,int> const& p1, pair<string,int> const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.second < p2.second; 
    } 
}; 
void getMaxLength(map<int,set<string> ,greater<int>> &maxString){
   
    int maxi;
    string maxiString;
    maxi=maxString.begin()->first;
    set<string> tt;
    tt=maxString.begin()->second;
    set<string>::iterator itr=tt.begin();
    maxiString=*itr;
    cout<< maxiString<<" "<<maxi<<"\n";
    // Pi(maxi);
    // nl();

    // for(map<int,set<string> ,greater<int>> ::iterator i=maxString.begin();i!=maxString.end();++i){
    //     cout<<i->first<<" "<<endl;
    //     for(set<string> ::iterator j=i->second.begin();j!=i->second.end();++j){
    //         cout<<*j<<" ";
    //     }
    //     cout<<endl;

    // }
}
int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int t;
    cin>>t;
    fori(i,0,t){
        int k,n;
        cin>>n>>k;
        cin.ignore();
        queue<string> q;
        map<string,int> keep_count;
        map<int,set<string> ,greater<int>> getMax;
       
       vector<string> list;
       for(int a=0;a<n;++a){
           string ss;
           cin>>ss;
           //cout<<ss<<endl;
           list.push_back(ss);
       }
       //printf("Case %d:\n",(i+1));
        cout << "Case " <<(i+1)<<":"<<"\n";
        fori(j,0,k){
            string s=list[j];
            //cout<<"s=="<<s<<endl;
            q.push(s);
             map<string,int>::iterator i1=keep_count.find(s);
             if(i1!=keep_count.end()){
                 i1->second=i1->second+1;
             }
             else{
                 keep_count.insert(make_pair(s,1));
             }
             int countofString=keep_count.find(s)->second;
             //insertion done will have to isert the darta into the getMax map
             map<int,set<string> ,greater<int>>::iterator i2=getMax.find(countofString);
             if(i2!=getMax.end()){
                 i2->second.insert(s);
             }
             else{
                 set<string> ss;
                 ss.insert(s);
                 getMax.insert({countofString,ss});
             }

            //Need to remove the old value from getMax
             if(countofString>=2){
                 i2=getMax.find(countofString-1);
                  if(i2!=getMax.end()){
                        i2->second.erase(s);
                        if(i2->second.size()==0){
                            getMax.erase(countofString-1);
                        }
                  }
             }
             getMaxLength(getMax);
        }

        fori(j,k,n){
            string s=list[j];
            //cout<<"s1=="<<s<<endl;
            //cin >> s;
            //  cout<<"in second loop "<<s<<endl;
            q.push(s);
            map<string,int>::iterator i1=keep_count.find(s);
            if(i1!=keep_count.end()){
                i1->second=i1->second+1;
            }
            else{
                keep_count.insert({s,1});
            }
            int countofString=keep_count.find(s)->second;
             map<int,set<string> ,greater<int>>::iterator i2=getMax.find(countofString);
                if(i2!=getMax.end()){
                    i2->second.insert(s);
                }
                else{
                    set<string> ss;
                    ss.insert(s);
                    getMax.insert({countofString,ss});
                }
             //Need to remove the old value from getMax
             if(countofString>=2){
                 i2=getMax.find(countofString-1);
                  if(i2!=getMax.end()){
                        i2->second.erase(s);
                        if(i2->second.size()==0){
                            getMax.erase(countofString-1);
                        }
                  }
             }
            //cout<<keep_count.find(s)->first<<"----"<<keep_count.find(s)->second<<endl;
            string del=q.front();
            q.pop();
            map<string,int> ::iterator itr=keep_count.find(del);
            itr->second=itr->second-1;
             //cout<<del<<"----"<<itr->second<<endl;
              //getMaxLength(getMax);
            if(itr->second==0){
                keep_count.erase(del);
                getMax.find(1)->second.erase(del);
                if(getMax.find(1)->second.size()==0){
                    getMax.erase(1);
                }
            }
            else{
                int cc=itr->second+1;
                getMax.find(cc)->second.erase(del);
                if(getMax.find(cc)->second.size()==0){
                    getMax.erase(cc);
                }
                cc=itr->second;
                map<int,set<string> ,greater<int>>::iterator i2=getMax.find(cc);
                if(i2!=getMax.end()){
                    i2->second.insert(del);
                }
                else{
                    set<string> ss;
                    ss.insert(del);
                    getMax.insert({cc,ss});
                }


            }
             getMaxLength(getMax);
            
        }

            

    }
    return 0;

}



