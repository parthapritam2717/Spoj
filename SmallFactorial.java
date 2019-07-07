
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
//https://www.spoj.com/problems/FCTRL2/
class SmallFactorial {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        HashMap<Integer,BigInteger> f=new HashMap<>();
        BigInteger fact =BigInteger.ONE;
        for(int i=1;i<=100;++i){
            fact=fact.multiply(BigInteger.valueOf(i));
            f.put(i,fact);
        }
        int t=s.nextInt();
        for(int i=0;i<t;++i){
            int n=s.nextInt();
            System.out.println(f.get(n));
        }
    }
}

