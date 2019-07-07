
import java.util.*;


import java.lang.*;
//https://www.spoj.com/problems/AP2/
class AP2 {
    public static  void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t=s.nextInt();
        for(int i=0;i<t;++i) {
            long a3 = s.nextLong();
            long an2 = s.nextLong();
            long sum = s.nextLong();
            calculate(a3,an2,sum);
        }



    }
    public static void printAP(long d,long n,long a1){
        System.out.println(n);
        System.out.print(a1+" ");
        for(int i=1;i<n;++i){
            a1=a1+d;
            System.out.print(a1+" ");
        }
        System.out.println();

    }
    public static void calculate(long a3,long an2,long sum){
        long n=(sum*2)/(a3+an2);
        long d=(an2-a3)/(n-3-2);
        long a1=a3-2*d;
        printAP(d,n,a1);
    }

}
