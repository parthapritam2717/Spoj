/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
//https://www.spoj.com/problems/GIRLSNBS/
/* Name of the class has to be "Main" only if the class is public. */
class GIRLSNBS
{
    public static void main (String[] args) throws java.lang.Exception {
        double g, b;
        Scanner s = new Scanner(System.in);
        while(true) {
            g = s.nextDouble();
            b = s.nextDouble();
            if (g >= 0 && b >= 0) {
                if (b == 0 && g > 0) {
                    System.out.println((int)g);
                } else if (g == 0 && b > 0) {
                    System.out.println((int)b);
                } else if (g > b)
                    System.out.println((int)Math.ceil(g / (b+1)));
                else
                    System.out.println((int)Math.ceil(b / (g+1)));
            }
            else{
                break;
            }
        }


    }
}