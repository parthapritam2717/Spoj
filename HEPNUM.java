/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/HEPNUM/
/* Name of the class has to be "Main" only if the class is public. */
class HEPNUM
{
    public static void main (String[] args) throws java.lang.Exception {
        Scanner s = new Scanner(System.in);
        while (true) {
            String s1 = s.next();

            String s2 = s.next();
//            System.out.println(s1);
//            System.out.println(s2);
            s.nextLine();

            if (s1.equals("*")) {
                break;
            } else {
                //process
                int len1=s1.length();
                int len2=s2.length();
//                System.out.println(len1);
//                System.out.println(len2);
                int index1=len1-1;
                int index2=len2-1;
                long result=0;
                int val1,val2;
                while(index1>=0 && index2>=0){
                    //System.out.println(s1.charAt(index1));
                    if(s1.charAt(index1)<=57){
                        val1=s1.charAt(index1)-48;
                    }
                    else{
                        val1=s1.charAt(index1)-55;
                    }
                    if(s2.charAt(index2)<=57){
                        val2=s2.charAt(index2)-48;
                    }
                    else{
                        val2=s2.charAt(index2)-55;
                    }
//                    System.out.println("s1="+val1);
//                    System.out.println("s2="+val2);
                    if(val1>val2){
                        result=1;
                    }
                    else if(val2> val1){
                        result=-1;
                    }
                    --index1;
                    --index2;
                }
                while(index1>=0){
                    if(s1.charAt(index1)<=57){
                        val1=s1.charAt(index1)-48;
                    }
                    else{
                        val1=s1.charAt(index1)-55;
                    }
                    //System.out.println("s1"+val1);
                    if(val1>0){
                        result=1;
                    }
                    --index1;
                }
                while(index2>=0){
                    if(s2.charAt(index2)<=57){
                        val2=s2.charAt(index2)-48;
                    }
                    else{
                        val2=s2.charAt(index2)-55;
                    }
                    //System.out.println("s2"+val2);
                   if(val2>0){
                       result=-1;
                   }
                    --index2;

                }
                if(result<0){
                    System.out.println("<");
                }
                else if(result>0){
                    System.out.println(">");
                }
                else{
                    System.out.println("=");
                }

            }

        }
    }
}