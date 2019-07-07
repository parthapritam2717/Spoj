import java.util.*;


import java.lang.*;
//https://www.spoj.com/problems/TOANDFRO/

class TOANDFRO {
    public static  void main(String[] args){
        Scanner s=new Scanner(System.in);
        while(s.hasNextInt()){
            int c=s.nextInt();
            if(c==0){
                break;
            }
            else{
                s.nextLine();
                String msg=s.nextLine();
                System.out.println(getMessage(msg,c));
            }
        }
    }
    public static  String getMessage(String ss,int c){
        StringBuilder res=new StringBuilder();
        int rev=1;
        for(int i=0;i<ss.length();i+=c){
            int limit=Math.min(i+c,ss.length());
            if(rev%2==1){

                for(int j=i;j<limit;++j){
                    res.append(ss.charAt(j));
                }
                rev=0;
            }
            else{
                StringBuilder temp=new StringBuilder();
                for(int j=i;j<limit;++j){
                    temp.append(ss.charAt(j));

                }
                temp.reverse();
                res.append(temp);
                rev=1;

            }

        }
        //StringBuilder result=new StringBuilder();
        ArrayList<StringBuilder> result= new ArrayList<StringBuilder>();
        for(int i=0;i<c;++i){
            result.add(new StringBuilder());
        }
       // System.out.println(res);
        for(int i=0;i<res.length();++i){
            result.get(i%c).append(res.charAt(i));
        }
        res=new StringBuilder("");
        for(int i=0;i<result.size();++i){
            res.append(result.get(i));
        }
        return res.toString();

    }

}
