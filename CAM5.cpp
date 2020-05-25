#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<list>
#include <vector>

using namespace std;



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

void dfs(bool visited[],list<int> graph[],int v){
    for(list<int>::iterator j=graph[v].begin();j!=graph[v].end();++j){
        if(!visited[*j]){
            visited[*j]=1;
            dfs(visited,graph,*j);
        }
    }
}
//to read strings with whitespace string s,getline(cin,s);
int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int t;
    fastRead_int(t);
    for(int i=0;i<t;++i){
        int n;
        fastRead_int(n);
        list<int> graph[n];
        int e;
        fastRead_int(e);
        for(int j=0;j<e;++j){
            int a,b;
            fastRead_int(a);
            fastRead_int(b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool visited[100001]={0};
        int count=0;
        for(int j=0;j<n;++j){
            if(!visited[j]){
                count++;
                visited[j]=1;
                dfs(visited,graph,j);
            }

        }
        cout<<count<<endl;
        
    }

    return 0;

}



