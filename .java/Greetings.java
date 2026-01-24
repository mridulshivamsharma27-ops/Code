import java.util.*;

        public class Greetings{
                public static void main(String[] args){
                        System.out.print("Enter Your Greetings(1/2/3): ");
                        Scanner sc=new Scanner(System.in);
                        int num=sc.nextInt();
                        sc.close();
                        switch (num) {
                                case 1:System.out.println("\t Hello \t");        
                                        break;
                                case 2:System.out.println("\t Namaste \t");                                        
                                        break;
                                case 3:System.out.println("\t Bonjour \t");                                        
                                        break;
                                default:System.out.println("\t\t Invalid!Try Again.\t\t");
                                        break;
                        }               
                }
        }