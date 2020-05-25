#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
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
int shipCount=0;
int wolfCount=0;
bool visited[251][251];
string graph[251];
void BFS(queue<char> q, queue<pair<int,int>> cd,int n, int m,int sheep,int wolf,bool flag){
    // cout<<"queue size"<<q.size()<<endl;
    // cout<<q.front()<<endl;
    // cout<<cd.front().first<<" "<<cd.front().second<<endl;
    while(!q.empty()){
        char s=q.front();
        q.pop();
        pair<int,int> cds=cd.front();
        cd.pop();
        int i=cds.first;
        int j=cds.second;
        //cout<<"item1=="<<s<<i <<"  "<<j<<endl;
        if((s=='.' || s=='k' || s=='v') && (i==0 || j==0 || i==n || j==m)){
            //cout<<s<<" true"<<i<<" "<<j<<endl;
            flag=true;
        }
        if(s=='.' || s=='k' || s=='v'){
            // cout<<vis[i][j]<<endl;
            if(s=='k')
                sheep++;
            else if(s=='v')
                wolf++;
            //cout<<visited[i+1][j]<<endl;
            if(i+1<n && j<m && i+1>=0 && j>=0 && visited[i+1][j]==false ){
                visited[i+1][j]=true;
                q.push(graph[i+1][j]);
                cd.push(make_pair(i+1,j));
                //bfs(vis,graph,q,i+1,j,n,m,sheep,wolf,flag);

            }
            //cout<<visited[i][j-1]<<endl;
             if(i<n && j-1<m && i>=0 && j-1>=0 && visited[i][j-1]==false ){
                visited[i][j-1]=true;
                q.push(graph[i][j-1]);
                 cd.push(make_pair(i,j-1));
                //bfs(vis,graph,q,i,j-1,n,m,sheep,wolf,flag);
                
               
            }
            //cout<<visited[i-1][j]<<" "<<i-1<<" "<<j<<endl;
             if(i-1<n && j<m && i-1>=0 && j>=0 &&  visited[i-1][j]==false ){
                visited[i-1][j]=true;
                q.push(graph[i-1][j]);
                 cd.push(make_pair(i-1,j));
                //bfs(vis,graph,q,i-1,j,n,m,sheep,wolf,flag);

               
            }
            //cout<<visited[i][j+1]<<endl;
            if(i<n && j+1<m && i>=0 && j+1>=0 &&  visited[i][j+1]==false ){
                visited[i][j+1]=true;
                q.push(graph[i][j+1]);
                 cd.push(make_pair(i,j+1));
                //bfs(vis,graph,q,i,j+1,n,m,sheep,wolf,flag);
            }
        }
    }
    //cout<<"sheep=="<<sheep<<" "<<"wolf=="<<wolf<<endl;
    if(!flag && sheep>wolf){
        shipCount+=sheep;
    }
    else if(!flag && sheep<=wolf){
        wolfCount+=wolf;
    }
    else if(flag){
        shipCount+=sheep;
        wolfCount+=wolf;
    }
    //cout<<shipCount<<" "<<wolfCount<<endl;
}

int main(){  
    int n,m;
    fastRead_int(n);
    fastRead_int(m);
   
    for(int i=0;i<n;++i){
        // for(int j=0;j<=m;++j){
          cin>>graph[i];
        //}
    }
    //bool visited[251][251]={false,false};
    // for(int i=0;i<10;++i){
    //     cout<<visited[i][5]<<endl;
    // }
    // queue<char> q;
    // queue<pair<int,int>> cd;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            visited[i][j]=false;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(visited[i][j]==false && graph[i][j]!='#'){
                 queue<char> q;
                 queue<pair<int,int>> cd;
                bool flag=false;
                string s=graph[i];
                //cout<<s[j];
                //cout<<"traverese start "<<i<<" "<<j<<" "<<graph[i][j]<<endl;
                visited[i][j]=true;
                //cout<<visited[i][j]<<endl;
                q.push(graph[i][j]);
                cd.push(make_pair(i,j));
                BFS(q,cd,n,m,0,0,flag);
            }
        }
    }
    cout<<shipCount<<" "<<wolfCount;

}



