import java.util.*;
public class Whirl{
    public static void main(String[] args){
        System.out.print("Enter n: ");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.close();
        int i=1;
        System.out.println("\t\tTable of "+n);
        System.out.println("-----------------------------------------------");
        while(i<=10){
            System.out.println("\t"+n+"\t"+"*"+"\t"+i+"\t"+"="+" "+n*i);
            i++;
        }
        System.out.println("-----------------------------------------------");
}
}

