/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
//
/* Name of the class has to be "Main" only if the class is public. */
class UFPR14D
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
        FastReader s=new FastReader();
        int n=s.nextInt();
        long list[]=new long[100006];
        long sum=0;
        for(int i=0;i<n;++i){
            int p=s.nextInt();
            sum+=p;
            list[i]=sum;

        }
        int q=s.nextInt();
        for(int i=0;i<q;++i){
            int a=s.nextInt()-1;
            int b=s.nextInt()-1;
            if((a)<=0){
                System.out.println(list[b]);
            }
            else{
                System.out.println(list[b]-list[a-1]);
            }
        }

    }
}