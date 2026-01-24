import java.util.*;
public class Bow {

    public static int power(int x,int n){
        if(n==0) return 1;
        return x*power(x, n-1);
    }

    public static void main(String[] args){
        int x,n,value;
        Scanner sc=new Scanner(System.in);
        x=sc.nextInt();
        n=sc.nextInt();
        sc.close();
        value=power(x, n);
        System.out.println("The Value is: "+value);
        return ;
    }
}
