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
 int maxi=0;
int calcMax(int num1,int num2,int num3,int num4,int num5,int num6,int num7,int num8,int num9){
    int maxi=-1;
    maxi=max(maxi,num1);
    maxi=max(maxi,num2);maxi=max(maxi,num3);maxi=max(maxi,num4);maxi=max(maxi,num5);maxi=max(maxi,num6);
    maxi=max(maxi,num7);maxi=max(maxi,num8);maxi=max(maxi,num9);
    return maxi;
}

int getMax(int dp[1001][21][21],int cost[21][21],int opening[21],int rating[21][21],int capacity,int flag[21],int i,int j,int sum,int n,int m){
    //cout<<"i "<<"j "<<i<<" "<<j<<"capold= "<<capacity<<endl;
    if(i<0 || j<0 || i>=n || j>=m ){
        return 0;// recursion ends here with these limit condition
    }
   int newCapacity=(capacity-(cost[i][j]+opening[i]*flag[i]));
   if(newCapacity<0){
       return 0;
   }
    int newsum=sum+rating[i][j];
    //cout<<"sum=="<<newsum<<"i "<<"j "<<i<<" "<<j<<endl;
    //int newCapacity=(capacity-(cost[i][j]+opening[i]*flag[i]));
     if(flag[i]==1){
        flag[i]=0;// To mark that this batch has been opened and its opening cost has been accounted for
    }
    //cout<<"capnew"<<newCapacity<<endl;
    if(dp[newCapacity][i][j]!=-1){
        //cout<<dp[newCapacity][i][j]<<" returning"<<endl;
        return dp[newCapacity][i][j];
    }
    
    int max6=calcMax(getMax(dp,cost,opening,rating,newCapacity,flag,i,j,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i-1,j,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i-1,j+1,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i,j+1,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i+1,j,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i+1,j+1,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i+1,j-1,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i,j-1,newsum,n,m),
    getMax(dp,cost,opening,rating,newCapacity,flag,i-1,j-1,newsum,n,m));
    int newData=newsum+max6;
    dp[newCapacity][i][j]=newData-sum;
    // cout<<"newData"<<newData<<endl;
    // cout<<"sum"<<newsum<<endl;
    // cout<<"oldsum"<<sum<<endl;
    // cout<<"rating"<<rating[i][j]<<endl;
    // cout<<"max6--"<<max6<<endl;
    //dp[newCapacity][i][j]-=rating[i][j;
    //cout<<newCapacity<<" "<<i<<" "<<j<<" "<<" "<<dp[newCapacity][i][j]<<endl;
    maxi=max(maxi,newData);
    //cout<<"maxi"<<maxi<<endl;
    //cout <<"capacity"<<newCapacity<<" "<<dp[newCapacity][i][j]<<endl;
    flag[i]=1;
    return dp[newCapacity][i][j];
}



int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int t;
    si(t);
    fori(i,0,t){
        int n,m,k;
        maxi=0;
        int opening [21];
        si(n);si(m);si(k);
        fori(j,0,n){
            si(opening[j]);
        }
        int cost[21][21];
        int rating[21][21];
        int flag[21]={1};
        fori(a,0,n){
            fori(b,0,m){
                si(cost[a][b]);
            }
        }
         fori(a,0,n){
            fori(b,0,m){
                si(rating[a][b]);
            }
        }
        int dp[1001][21][21];
         fori(a,0,1001){
            fori(b,0,21){
                fori(c,0,21){
                    dp[a][b][c]=-1;
                }
            }
         }
        int sum=0;
        dp[k][0][0]=sum+calcMax(getMax(dp,cost,opening,rating,k,flag,0,0,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,-1,0,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,-1,1,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,0,1,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,1,0,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,1,1,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,1,-1,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,0,-1,sum,n,m),
        getMax(dp,cost,opening,rating,k,flag,-1,-1,sum,n,m));
        maxi=max(maxi,dp[k][0][0]);
        Pi(maxi);
        nl();
    }
    

    return 0;

}



