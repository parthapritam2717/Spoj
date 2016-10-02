/*segment tree to find the sum of a given range */
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

typedef struct segmentNode{
    int data;
    int sq;
}segmentNode;


int *lazyTree;
int getMidIndex(int s1,int s2){
    return s1+(s2-s1)/2;
}

segmentNode constructSTUtil(int arr[], int starts, int ends, segmentNode *st, int scurrent){
    /*If there is only one element in the segment store it in current node of the segment tree and return */

    if(starts==ends){
            (st)[scurrent].sq=pow(arr[starts],2);
            (st)[scurrent].data=arr[starts];
            return (st)[scurrent];
    }
    // if more than one node present then recurse for left subtree and right subtree  and store the sum of values in this node
    int mid=getMidIndex(starts,ends);
    segmentNode temp1=constructSTUtil(arr,starts,mid,st,2*scurrent+1);
    segmentNode temp2=constructSTUtil(arr,mid+1,ends,st,scurrent*2+2);
    return (st)[scurrent];
}



segmentNode *constructSegmentTree(int list1[],int n){
    // calc the height of the tree
    int height=(int)ceil(log2(n));
    // now lets calc the amount of space needed for the tree
    int maxSize=2*(int)pow(2,height)-1;
    segmentNode *sTree= new  segmentNode[maxSize] ();
    lazyTree = new int[maxSize]();
    // now the actual utility function which will construct the segmented tree
    constructSTUtil(list1,0,n-1,sTree,0);
    for(int i=0;i<maxSize;++i){
        segmentNode n=sTree[i];
    cout<<n.data<<" "<<n.sq<<" ";}
    nl();
    return sTree;
}


/*parameters for the sum utility function*/
/*st->pointer for segment tree
si->index of current node in the segment tree initially 0 is passed as root index is always 0 which is implemented in the array
ss and se->starting and ending index of the segment
qs and qe->starting and ending index of query range*/

int getSumUtil(int *st,int ss,int se,int qs,int qe,int si){
    // if lazy flag is set the we have to update the lazy values then only go forward with the
    // operation
    if(lazyTree[si]!=0){
        st[si]+=(se-ss+1)*lazyTree[si];
        if(ss!=se){
            // update the childeren about the lazy value
            lazyTree[si*2+1]=lazyTree[si];
            lazyTree[si*2+2]=lazyTree[si];

        }
        // reset current node lazy value
        lazyTree[si]=0;
    }

    // if no overlap
    if(se<qs || ss>qe || ss>se ){
        return 0;
    }

    // all pending lazy updates done now return the sum
    if(qs<=ss && qe>=se){
        return st[si];
    }
    // now the case of partial overlap we will recusiveley find the sum
    int mid=getMidIndex(ss,se);
    return getSumUtil(st,ss,mid,qs,qe,si*2+1)+getSumUtil(st,mid+1,se,qs,qe,si*2+2);
}

int getSum(int *sTree,int sizeOfTree,int r1,int r2){
    // we will have to make use of an utility functions which will help us find the sum recursively
    if(r1<0 || r2>sizeOfTree-1|| r1>r2){
        cout<<"Invalid Input!!\n";
        return -1;
    }
    return getSumUtil(sTree,0,sizeOfTree-1,r1,r2,0);
}



void updateValueUtil(int *st,int ss,int se,int us,int ue,int diff,int si){
    // if some pending updates are there we will have to remove them first
    if(lazyTree[si]!=0){
        st[si]+=(se-ss+1)*lazyTree[si];
        // check if leaf node because if leaf node we cannot go any further
        if(ss!=se){
            lazyTree[si*2+1]+=lazyTree[si];
            lazyTree[si*2+2]+=lazyTree[si];

        }
        // current node lazy vale is set to zero
        lazyTree[si]=0;

    }
    // if out of range
    if(ss>se || ss>ue || se<us){
        return ;
    }
    // if current segment if fully in range
    if(ss>=us && se<=ue){
        // add the diff to the current node

        st[si]+=(se-ss+1)*diff;
        //  checking if leaf or not
        if(ss!=se){
            lazyTree[si*2+1]+=diff;
            lazyTree[si*2+2]+=diff;
        }
        return;
    }
    // if not completely in range but partially overlap
        int mid=getMidIndex(ss,se);
        updateValueUtil(st,ss,mid,us,ue,diff,2*si+1);
        updateValueUtil(st,mid+1,se,us,ue,diff,2*si+2);
        st[si]=st[si*2+1]+st[si*2+2];
}

void updateValue(int list1[],int *st,int sizeOfTree,int s,int e,int newValue){

   // int diff=newValue-(list1)[index];

    updateValueUtil(st,0,sizeOfTree-1,s,e,newValue,0);

}


//void setValue(int list1[],int *st,int sizeOfTree,int s,int e,int newValue){
//   setValueUtil(st,0,sizeOfTree-1,s,e,newValue,0);
//}


int main(){
        int t;
        si(t);
        for(int i=0;i<t;++i){
            int n,m;
            si(n);si(m);
            int *list1=new int[n]();
            fori(j,0,n){
                    int tem;
                    si(list1[j]);

            }
            // now lets construct the segment tree
            segmentNode *segmentTree=constructSegmentTree(list1,n);
            // now lets do some queries to see if our result are good
            for(int k=0;k<m;++k){
                int a,b,c;
                si(a);si(b);si(c);
                if(a==2){
                    Pi(getSum(segmentTree,n,b-1,c-1));
                    nl();
                }
                else if(a==1){
                    int data;
                    si(data);
                     updateValue(list1,segmentTree,n,b-1,c-1,data);
                }
                else if(a==0){
                  int data;
                    si(data);
                }
            }
             delete [] segmentTree;

             }
    return 0;

}





