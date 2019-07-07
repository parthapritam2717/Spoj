/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class NGM
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner s=new Scanner(System.in);
        long num=s.nextLong();
        if(num%10!=0){
            System.out.println(1);
            System.out.println(num%10);


        }
        else{
            System.out.println(2);
        }
    }
}