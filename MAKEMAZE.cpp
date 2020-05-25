#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<set>

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
//to read strings with whitespace string s,getline(cin,s);


void BFS(string graph[],  bool visited[21][21], queue<char> q,queue<pair<int,int> > cordinate,pair<int,int> exit,bool &flag,int n,int m){
    while(!q.empty()){
        //cout<<q.size()<<endl;
        char s=q.front();
        q.pop();
        int i=cordinate.front().first;
        int j=cordinate.front().second;
        cordinate.pop();
        //cout<<"item=="<<s<<" i "<<i<<" j"<<j<<endl;
        if(s=='.' && exit.first==i && exit.second==j ){
            flag=true;
            return;
        }
            if(i+1<n && j<m && i+1>=0 && j>=0 && graph[i+1][j]!='#' && visited[i+1][j]==false ){
                visited[i+1][j]=true;
                q.push(graph[i+1][j]);
                cordinate.push(make_pair(i+1,j));
                //bfs(vis,graph,q,i+1,j,n,m,sheep,wolf,flag);

            }
            //cout<<visited[i][j-1]<<endl;
             if(i<n && j-1<m && i>=0 && j-1>=0 && graph[i][j-1]!='#' && visited[i][j-1]==false ){
                visited[i][j-1]=true;
                q.push(graph[i][j-1]);
                 cordinate.push(make_pair(i,j-1));
                //bfs(vis,graph,q,i,j-1,n,m,sheep,wolf,flag);
                
               
            }
            //cout<<visited[i-1][j]<<" "<<i-1<<" "<<j<<endl;
             if(i-1<n && j<m && i-1>=0 && j>=0 &&  graph[i-1][j]!='#' && visited[i-1][j]==false ){
                visited[i-1][j]=true;
                q.push(graph[i-1][j]);
                 cordinate.push(make_pair(i-1,j));
                //bfs(vis,graph,q,i-1,j,n,m,sheep,wolf,flag);

               
            }
            //cout<<visited[i][j+1]<<endl;
            if(i<n && j+1<m && i>=0 && j+1>=0 &&  graph[i][j+1]!='#' && visited[i][j+1]==false ){
                visited[i][j+1]=true;
                q.push(graph[i][j+1]);
                 cordinate.push(make_pair(i,j+1));
                //bfs(vis,graph,q,i,j+1,n,m,sheep,wolf,flag);
            }   
    }
}

int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int t;
    cin>>t;
   for(int i=0;i<t;++i){
       int n,m;
       cin>>n>>m;
       //cout<<n<<m<<endl;
       string graph[21];
       bool visited[21][21];
       for(int ii=0;ii<21;++ii){
            for(int j=0;j<21;++j){
                visited[ii][j]=0;
            }
        }
        for(int j=0;j<n;++j){
            cin>>graph[j];
            //cout<<graph[j];
        }
        int entry=0;
        set<pair<int,int>> hm;
        for(int j=0;j<n;++j){
            if(graph[j][0]=='.'){
                hm.insert(make_pair(j,0));
            }
            if(graph[j][m-1]=='.'){
               hm.insert(make_pair(j,m-1));
            }
        }
        for(int j=0;j<m;++j){
            if(graph[0][j]=='.'){
               hm.insert(make_pair(0,j));
            }
            if(graph[n-1][j]=='.'){
               hm.insert(make_pair(n-1,j));
            }
        }
        if(hm.size()!=2){
            cout<<"invalid"<<endl;
        }
        else{
            //will find if its a valid maze using bfs
            bool flag=0;
            queue<char> q;
            queue<pair<int,int> > cordinate;
            set<pair<int,int>>::iterator itr=hm.begin();
            pair<int,int> start=*itr;
            ++itr;
            pair<int,int> end=*itr;
            visited[start.first][start.second]=1;
            q.push(graph[start.first][start.second]);
            cordinate.push(make_pair(start.first,start.second));
            // cout<<"Traveres start"<<" i"<<start.first<<" j"<<start.second<<endl;
            // cout<<"Expecting exit at"<<" i"<<end.first<<" j"<<end.second<<endl;
            BFS(graph,visited,q,cordinate,end,flag,n,m);
            if(flag){
                cout<<"valid"<<endl;
            }
            else{
                cout<<"invalid"<<endl;
            }
        }

       
   }
    return 0;

}



