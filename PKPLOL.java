/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/PKPLOL/
/* Name of the class has to be "Main" only if the class is public. */
class PKPLOL
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
        String list[]=new String[10];
        list[0]="abcdef";
        list[1]="bc";
        list[2]="abdeg";
        list[3]="a"+list[1]+"dg";
        list[4]="bcfg";
        list[5]="acdfg";
        list[6]="acdefg";
        list[7]="a"+list[1];
        list[8]="abcdefg";
        list[9]="abcdfg";
        for(int i=0;i<t;++i){
            int n=s.nextInt();
            System.out.println("Case "+(i+1)+": "+list[n]);
        }
    }
}