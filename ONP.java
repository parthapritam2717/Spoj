import java.util.*;
import java.lang.*;
class ONP {
     //https://www.spoj.com/problems/ONP/
     static HashMap<Character,Integer> precedence=new HashMap<>();
     public static void main(String[] args) {
         Scanner s = new Scanner(System.in);
         precedence.put('+',0);
         precedence.put('-',1);
         precedence.put('/',3);
         precedence.put('*',2);
         precedence.put('^',4);
         precedence.put('(',5);
         precedence.put(')',5);
         int t = s.nextInt();
         s.nextLine();
         for (int i = 0; i < t; ++i) {

                 String ip = s.nextLine();
                 System.out.println(convert(ip));

         }
     }
     public static  String convert(String ss){
         Stack<Character> stack=new Stack<>();
         StringBuilder op=new StringBuilder();
         for(int i=0;i<ss.length();++i){
//             System.out.println(ss.charAt(i));
             if(precedence.get(ss.charAt(i))==null){
                 //System.out.println(ss.charAt(i));
                 op.append(ss.charAt(i));
             }
             else if(ss.charAt(i)=='('){
                 stack.push(ss.charAt(i));
             }
             else if(ss.charAt(i)==')'){
                 while(!stack.isEmpty()){
                     char temp=stack.pop();
                     if(temp=='(') {
                         break;
                     }
                     op.append(temp);
                     //System.out.println("op="+ op.toString());
                 }
             }
             else{
                 if(stack.isEmpty() || stack.peek()=='(' || precedence.get(ss.charAt(i))>precedence.get(stack.peek())){
                     stack.push(ss.charAt(i));
                 }
                 else{
                     while(!stack.isEmpty() &&( precedence.get(ss.charAt(i))<=precedence.get(stack.peek()))){
                         if(stack.peek()!='(' ) {
                             op.append(stack.pop());
                         }
                         else if(stack.peek()=='('){
                             //stack.pop();
                             break;
                         }
                     }
                     stack.push(ss.charAt(i));
                 }
             }

         }
        while(!stack.isEmpty()){
            op.append(stack.pop());
        }
        return op.toString();
     }


}
