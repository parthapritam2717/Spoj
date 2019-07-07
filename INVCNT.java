import java.util.*;


import java.lang.*;
//https://www.spoj.com/problems/INVCNT/
class INVCNT {
    public static  void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        s.nextLine();
        for(int i=0;i<t;++i){
            int n=s.nextInt();
            ArrayList<Integer> list=new ArrayList<>();
            for(int j=0;j<n;++j){
                list.add(s.nextInt());
            }
            s.nextLine();
            System.out.println(mergeSort(list,0,n-1));
        }




    }
    public static long mergeSort(ArrayList<Integer> list,int l,int r){
        long inversion_count=0;
        if(l<r){
            int mid=(l+r)/2;
            inversion_count+=mergeSort(list,l,mid);
            inversion_count+=mergeSort(list,mid+1,r);
            inversion_count+=merge(list,l,mid+1,r);

        }
        //System.out.println(list);
        return inversion_count;

    }
    public static long merge(ArrayList<Integer> list,int l,int mid,int r){
        long inv=0;
        ArrayList<Integer> left=new ArrayList<>();
        ArrayList<Integer> right= new ArrayList<>();
        for(int i=0;i<=mid-l-1;++i){
            left.add(list.get(l+i));
        }
        for(int i=mid;i<=r;++i){
            right.add(list.get(i));
        }
        // System.out.println("ll=="+left);
        // System.out.println("rr=="+right);
        int k=l;
        int i=0,j=0;
        while(i<left.size() && j<right.size()){

            //System.out.println(i+" "+j );
            if(left.get(i)<=right.get(j)){
                list.set(k++,left.get(i++));
            }
            else{
//                System.out.println(left);
//                System.out.println(right);
                list.set(k++,right.get(j++));
                //System.out.println(mid+" "+l+i);
                inv+=mid-(l+i);

            }

        }
        while(i<left.size()){
            list.set(k++,left.get(i++));
        }
        while(j<right.size()){
            list.set(k++,right.get(j++));
        }

        return inv;
    }
}

