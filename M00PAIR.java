
import java.util.*;
// import java.lang.*;
import java.math.BigInteger;
import java.io.*;
class M00PAIR {
    private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c)) {
				if (c == -1)
					return -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					return -1;
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res;
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	}
    public static void main (String[] args) throws java.lang.Exception{
        // // fori(i,0,1005){
        // //     dp[i]=0;
        // // }
        // // dp[2]=1;
        // // dp[3]=1;
        // // dp[4]=3;
        // // dp[5]=5;
        // ArrayList<String> dp=new ArrayList<>(1001);
        // dp.add(0, "0");
        // dp.add(1,"0");
        // dp.add(2, "1");
        // dp.add(3, "1");
        // dp.add(4, "3");
        // dp.add(5, "5");
        // BigInteger sum=new BigInteger("5");
        // for(int i=6;i<=1000;++i){
        //     BigInteger temp=new BigInteger(dp.get(i-1));
        //     temp=temp.add(sum);
        // //dp.add(i, dp.get(i-1).add(sum));
        // if(i%2==0){
        //     //dp.set(i, dp.get(i).add(BigInteger.ONE));
        //     temp=temp.add(BigInteger.ONE);
        // }
        // dp.add(i,temp.toString());
        // sum=sum.add(new BigInteger(dp.get(i-1)));
        // }
        BigInteger[] a = new BigInteger[999 + 1];
		String[] b = new String[a.length];
		a[1] = BigInteger.ZERO;
		for (int i = 2; i < a.length; i++) {
			if (i % 2 == 0)
				a[i] = a[i - 1].multiply(BigInteger.valueOf(2)).add(BigInteger.ONE);
			else
				a[i] = a[i - 1].multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
		}
		for (int i = 1; i < a.length; i++) {
			b[i] = a[i].toString();
		}
        //Scanner sc=new Scanner(System.in); 
		
        InputReader ir = new InputReader(System.in);
		while (true) {
			int x = ir.nextInt();
			//int x=sc.nextInt();
			if (x == -1)
				break;
			System.out.println(b[x]);
		}

    }
}
