/* package whatever; // don't place package name! */

import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/IGARB/
/* Name of the class has to be "Main" only if the class is public. */
class IGARB
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        int newNUmberSystem[]=new int[]{0,1,2,5,9,8,6};
        s.nextLine();
        BigInteger base=new BigInteger("7");
        for(int i=0;i<t;++i) {
            StringBuilder output=new StringBuilder();
            String input = s.nextLine();
            BigInteger n = new BigInteger(input);
            while (n!=BigInteger.ZERO){
                BigInteger d = n.mod(base);
                output.append(newNUmberSystem[d.intValue()]);
                n = n.divide(base);
            }
            System.out.println(output);
        }

    }


}