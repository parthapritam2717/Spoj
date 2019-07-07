/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/JC15A/
/* Name of the class has to be "Main" only if the class is public. */
class JC15A
{    static class FastReader
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
        double p1=s.nextDouble();
        double p2=s.nextDouble();
        double ballSpeed=s.nextDouble();
        double windSpeed=s.nextDouble();
        String windDirection=s.next();
        if((windDirection.equals("R") && p2>=p1)|| (windDirection.equals("L") && p2<=p1)){
            ballSpeed=ballSpeed+windSpeed;
        }
        else {
            ballSpeed=ballSpeed-windSpeed;
        }
        if(ballSpeed>0){
            double time=(Math.abs(p2-p1))/ballSpeed;
            System.out.format("%.6f", time);
        }
        else{
            System.out.println("Impossible");
        }

    }
}