import java.util.*;


import java.lang.*;

/*Always change the class name to Main before uploading
file to SPOJ as SPOJ always expects a Main class*/

public class COIN {
    public static HashMap<Long,Long> h=new HashMap<Long,Long> ();
    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner s=new Scanner(System.in);
        while(s.hasNext()) {
            long num=s.nextLong();
            long maxValue=Long.MIN_VALUE;
            System.out.println(Math.max(maxValue,calculate( num)));
        }
        s.close();
    }

    public static long calculate(long valueCoin) {
        if(valueCoin<=3) {
            return valueCoin;
        }
        if(h.containsKey(valueCoin)) {
            return h.get(valueCoin);
        }
        else {
            h.put(valueCoin,Math.max(valueCoin, calculate(valueCoin/4)+calculate(valueCoin/3)+calculate(valueCoin/2)));
            return h.get(valueCoin);
        }

    }

}
