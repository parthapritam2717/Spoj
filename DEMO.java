/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class DEMO
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        s.nextLine();
        for(int i=0;i<t;++i){
            String x=s.next();
            String n=s.next();
            BigInteger sum=new BigInteger("0");
            BigInteger bx=new BigInteger(x);
            BigInteger bn=new BigInteger(n);
            while(bx.compareTo(bn)>=0){
                if(bx.mod(bn)==BigInteger.ZERO){
                    sum=sum.add(bx.divide(bn));
                    bx=bx.divide(bn);
                }
                else{
                    sum=sum.add(bx.divide(bn));
                    BigInteger temp=bx.divide(bn);
                    bx=temp.add(bx.mod(bn));
                }
            }
            sum=sum.add(new BigInteger(x));
            System.out.println(sum.toString());
        }

    }
}