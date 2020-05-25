#include<stdlib.h>
#include<stdio.h>


using namespace std;



#define Pi(x) printf("%d", x)

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
int main(){
    // ios_base::sync_with_stdio(false); //makes cin cout faster
    // cin.tie(NULL);    
    int n,k;
    fastRead_int(n);
    fastRead_int(k);
    int sum=0;
    while(n--){
        int num;
        fastRead_int(num);
        if(num%k==0){sum++;}
    }
    Pi(sum);
    return 0;

}



