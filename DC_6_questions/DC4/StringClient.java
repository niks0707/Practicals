import java.rmi.Naming;
import java.util.Scanner;

public class StringClient {

    public static void main(String[] args) {
        try {
            // Look up the remote object
            StringOperations stringOperations = (StringOperations) Naming.lookup("rmi://localhost/StringOperations");

            Scanner scanner = new Scanner(System.in);
            
            // Ask the user which action to perform
            System.out.println("Choose an action:");
            System.out.println("1. String Comparison");
            System.out.println("2. String Character Count");
            System.out.print("Enter your choice (1 or 2): ");
            
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            
            switch (choice) {
                case 1:
                    // Perform string comparison
                    System.out.print("Enter the first string: ");
                    String str1 = scanner.nextLine();
                    
                    System.out.print("Enter the second string: ");
                    String str2 = scanner.nextLine();
                    
                    boolean areEqual = stringOperations.compareStrings(str1, str2);
                    System.out.println("Strings are equal: " + areEqual);
                    break;
                
                case 2:
                    // Perform string character count
                    System.out.print("Enter the string: ");
                    String str = scanner.nextLine();
                    
                    int charCount = stringOperations.countCharacters(str);
                    System.out.println("Character count in string: " + charCount);
                    break;
                
                default:
                    System.out.println("Invalid choice. Please choose 1 or 2.");
            }
            
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
