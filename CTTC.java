/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/CTTC/
/* Name of the class has to be "Main" only if the class is public. */
class CTTC
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
            int n=s.nextInt();
            Stack<Integer> stack=new Stack<>();
            int array[]=new int[102];
            for(int k=0;k<102;++k){
                array[k]=0;
            }
            stack.push(s.nextInt());
            for(int j=1;j<2*n;++j){
                int item=s.nextInt();
                if(item==stack.peek()){
                    stack.pop();
                }
                else{
                    int parent=stack.peek();
                    array[parent]++;
                    stack.push(item);
                }

            }
            System.out.println("Case "+i+1+":");
            for(int j=1;j<=n;++j){
                System.out.println(j+" -> "+array[j]);
            }
            System.out.println();
        }
    }
}