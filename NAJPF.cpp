#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

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

void createLps(vector<int> &lps,string pat){
    int i=0,len=0;
    lps[i]=0;
    i++;
    while(i<pat.length()){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }

    }

}

void findPattern(vector<int> &lps,string pat,string text){
    int sum=0;
    vector<int> ans;
    int N=text.length();
    int M=pat.length();
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == text[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
           // printf("Found pattern at index %d ", i - j); 
            ans.push_back(i-j+1);
            sum++;
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != text[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    if(sum>0){
        cout<<sum<<endl;
        for(vector<int>::iterator i=ans.begin();i!=ans.end();++i){
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false); //makes cin cout faster
    cin.tie(NULL);    
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        string text,pat;
        cin>>text;
        cin>>pat;
        vector<int> lps(pat.length());
        createLps(lps,pat);
        findPattern(lps,pat,text);

    }
    return 0;

}



