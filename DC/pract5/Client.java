import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.*;

public class Client {
 
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 2000);
            RemoteInterface remoteObj = (RemoteInterface) registry.lookup("CalculatorService");
            // System.out.println("Enter Three Numbers(P, I, R) : ");
            // int p = sc.nextInt();
            // int i = sc.nextInt();
            // int r = sc.nextInt();
            // System.out.println("Enter the Number : ");
            // int num = sc.nextInt();
            System.out.println("Enter String : ");
 	        String s1 = sc.nextLine();
            //String s2 = sc.next();

            // System.out.println("Sum: " + remoteObj.add(a, b));
            // System.out.println("Difference: " + remoteObj.subtract(a, b));
            // System.out.println("Product: " + remoteObj.multiply(a, b));
            // System.out.println("Quotient: " + remoteObj.divide(a, b));
            // System.out.println("reverse string is\n" + remoteObj.info(s1));
            // System.out.println("String Compare\n" + remoteObj.StringComp(s1,s2));
            // System.out.println("Simple Intrest is : \n" + remoteObj.simpleIntrest(p,i,r));
            System.out.println("String Word Count : \n" + remoteObj.stringCt2(s1));
            // System.out.println("Square of Number is : \n" + remoteObj.square(num));
            // System.out.println("Square Root of Number is : \n" + remoteObj.squareRoot(num));

        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }

}