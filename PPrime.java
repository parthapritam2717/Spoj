import java.util.*;
import java.lang.*;
//Incomplete //will have to perform segmented sieve
class PPrime {
    public static void main(String[] args){
       Boolean [] list=new Boolean[10000000];
       for(int i=0;i<10000000;++i){
           list[i]=true;
       }
       ArrayList<Integer> result=new ArrayList<>();
       for(int p=2;p*p<=10000000;++p){
           if(list[p]==true){
               result.add(p);
               for(int start=p*p;start<10000000;start+=p){
                   list[start]=false;
               }
           }

       }
       for(int i=0;i<result.size();++i){
           System.out.println(result.get(i));

       }
    }
}

