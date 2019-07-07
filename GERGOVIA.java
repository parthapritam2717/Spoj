/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/GERGOVIA/
/* Name of the class has to be "Main" only if the class is public. */



class GERGOVIA
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Scanner s=new Scanner(System.in);
        while(true) {
            int n=s.nextInt();
            if(n==0){
                break;

            }
            else{
                long res=0;
                long a0=s.nextInt();
                //res=res+Math.abs(a0);
                for(int i=1;i<n;++i){
                    //a0=s.nextInt();
                    res=res+Math.abs(a0);
                    a0=a0+s.nextInt();
                }
                System.out.println(res);
            }

        }

    }
}