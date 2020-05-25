#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
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
int n,m;
void BFS(int graph[251][251],bool visited[251][251],queue<int> &q,queue<pair<int,int>> &cordinate,map<int,int> &ans,int sum,int &slick){
    while(!q.empty()){
        int s=q.front();
        q.pop();
         int i=cordinate.front().first;
        int j=cordinate.front().second;
        cordinate.pop();
        //cout<<"item=="<<s<<" i "<<i<<" j"<<j<<endl;
        if(s==1){
            sum++;
        }
        //cout<<n<<" "<<m<<endl;
         if(i+1<n && j<m && i+1>=0 && j>=0 && graph[i+1][j]!=0 && visited[i+1][j]==false ){
                visited[i+1][j]=true;
                q.push(graph[i+1][j]);
                cordinate.push(make_pair(i+1,j));
                //bfs(vis,graph,q,i+1,j,n,m,sheep,wolf,flag);

            }
            //cout<<visited[i][j-1]<<endl;
             if(i<n && j-1<m && i>=0 && j-1>=0 && graph[i][j-1]!=0 && visited[i][j-1]==false ){
                visited[i][j-1]=true;
                q.push(graph[i][j-1]);
                 cordinate.push(make_pair(i,j-1));
                //bfs(vis,graph,q,i,j-1,n,m,sheep,wolf,flag);
                
               
            }
            //cout<<visited[i-1][j]<<" "<<i-1<<" "<<j<<endl;
             if(i-1<n && j<m && i-1>=0 && j>=0 &&  graph[i-1][j]!=0 && visited[i-1][j]==false ){
                visited[i-1][j]=true;
                q.push(graph[i-1][j]);
                 cordinate.push(make_pair(i-1,j));
                //bfs(vis,graph,q,i-1,j,n,m,sheep,wolf,flag);

               
            }
            //cout<<visited[i][j+1]<<endl;
            if(i<n && j+1<m && i>=0 && j+1>=0 &&  graph[i][j+1]!=0 && visited[i][j+1]==false ){
                visited[i][j+1]=true;
                q.push(graph[i][j+1]);
                 cordinate.push(make_pair(i,j+1));
                //bfs(vis,graph,q,i,j+1,n,m,sheep,wolf,flag);
            }   
        
    }

    ans[sum]++;
    slick++;
//     //cout<<"sum"<<sum<<endl;
//    if(ans.find(sum)!=ans.end()){
       
//        ans.find(sum)->second++;
//        //cout<<ans.find(sum)->second<<endl;
//    }
//    else{
//        ans.insert(make_pair(sum,1));
//    }

}


int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    while(true){
        fastRead_int(n);
        fastRead_int(m);
        if(m==0 && n==0){
            break;
        }
        int graph[251][251];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                fastRead_int(graph[i][j]);
            }
        }
        //cout<<n<<" "<<m<<endl;
        bool vis[251][251]={{false}};
        //cout<<vis[1][0]<<endl;
        map<int,int> ans;
        int slickNum=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==false  && graph[i][j]==1){
                    queue<int> q;
                    queue<pair<int,int>> cord;
                    int sum=0;
                    q.push(graph[i][j]);
                    vis[i][j]=true;
                    cord.push(make_pair(i,j));
                    //cout<<"Traverse start"<<i<<" "<<j<<endl;
                    BFS(graph,vis,q,cord,ans,sum,slickNum);
                }

            }
        }
        cout<<slickNum<<endl;
        for(map<int,int>::iterator itr=ans.begin();itr!=ans.end();++itr){
            cout<<itr->first<<" "<<itr->second<<endl;
        }

    }
    return 0;

}



