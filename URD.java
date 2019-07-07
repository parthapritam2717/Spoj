/* package whatever; // don't place package name! */

import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/URD/
/* Name of the class has to be "Main" only if the class is public. */
class URD
{
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        FastReader s=new FastReader();
        int t=s.nextInt();
        for(int i=0;i<t;++i){
            String n1=s.next();
            String n2=s.next();
            BigInteger b1=new BigInteger(n1);
            BigInteger b2=new BigInteger(n2);
            System.out.println(b1.multiply(b2));
        }


    }
}