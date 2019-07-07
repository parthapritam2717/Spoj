

import java.util.*;


import java.lang.*;


//https://www.spoj.com/problems/RPLD/
class RPLD {
    public static  void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i=0;i<t;++i) {
            int n = s.nextInt();
            int r = s.nextInt();
            HashMap<Integer,HashSet<Integer>> hm=new HashMap<>();
            boolean flag=true;
            for(int j=0;j<r;++j) {
                int id=s.nextInt();
                // sc.add(id);
                int c=s.nextInt();
                //System.out.println(id+" "+c);
                if(flag){
                    if (hm.containsKey(c)) {
                        if(hm.get(c).contains(id)) {
                            System.out.println("Scenario #" + (i + 1) + ": impossible");
                            flag = false;
                            //break;
                        }
                        else{
                            hm.get(c).add(id);
                        }

                    }
                    else {
                        HashSet<Integer> h=new HashSet<>();
                        h.add(id);
                        hm.put(c,h);
                    }
                }
            }
            //s.nextLine();
            if(flag){
                System.out.println("Scenario #" + (i + 1) + ": possible");
            }
//            else if(sc.size()!=n && flag){
//                System.out.println("Scenario #" + (i + 1) + ": impossible");
//            }


        }


        s.close();
    }
}
