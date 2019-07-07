    /* package whatever; // don't place package name! */

    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.ArrayList;
    import java.util.StringTokenizer;
    //https://www.spoj.com/problems/HAPPYTL/
    /* Name of the class has to be "Main" only if the class is public. */

    class INTERVAL{
        long start;
        long end;

        public INTERVAL(long start, long end) {
            this.start = start;
            this.end = end;
        }

    }

    class HAPPYTL
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
            while(true) {
                long n, m;
                n = s.nextLong();
                m = s.nextLong();
                if (n == 0 && m == 0) {
                    break;
                }
                long src,dest,start,duration,end;
                ArrayList<INTERVAL> list=new ArrayList<>();
                for(int i=0;i<n;++i){
                    src=s.nextLong();
                    dest=s.nextLong();
                    start=s.nextLong();
                    duration=s.nextLong();
                    end=start+duration;
                    list.add(new INTERVAL(start,end));
                }
                //System.out.println(list.get(0).end);
                for(int i=0;i<m;++i){
                    long operator_req=0;
                    start=s.nextLong();
                    duration=s.nextLong();
                    end=start+duration;

                    // System.out.println(start+" "+end);
                    long len=list.size();
                    for(int j=0;j<len;++j) {

                        INTERVAL node=list.get(j);
                        if(!((start<=node.start && end<=node.start) ||(start>=node.end && end>=node.end))){

                            //System.out.println(list.get(j).start+" "+list.get(j).end);
                            operator_req++;
                        }

                    }
                    System.out.println(operator_req);

                }
            }


        }
    }