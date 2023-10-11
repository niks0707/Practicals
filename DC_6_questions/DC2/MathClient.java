import java.rmi.Naming;
import java.util.Scanner;

public class MathClient {
    public static void main(String[] args) {
        try {
            MathOperations mathOperations = (MathOperations) Naming.lookup("MathOperations");
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("Choose an operation:");
                System.out.println("1. Calculate Square");
                System.out.println("2. Calculate Square Root");
                System.out.println("3. Calculate Factorial");
                System.out.println("4. Exit");
                System.out.print("Enter your choice (1/2/3/4): ");

                int choice = scanner.nextInt();

                switch (choice) {
                    case 1:
                        System.out.print("Enter a number to calculate its square: ");
                        double numberToSquare = scanner.nextDouble();
                        double square = mathOperations.calculateSquare(numberToSquare);
                        System.out.println("Square: " + square);
                        break;
                    case 2:
                        System.out.print("Enter a number to calculate its square root: ");
                        double numberToSqrt = scanner.nextDouble();
                        double sqrt = mathOperations.calculateSquareRoot(numberToSqrt);
                        System.out.println("Square Root: " + sqrt);
                        break;
                    case 3:
                        System.out.print("Enter a number to calculate its factorial: ");
                        int numberToFactorial = scanner.nextInt();
                        int factorial = mathOperations.calculateFactorial(numberToFactorial);
                        System.out.println("Factorial: " + factorial);
                        break;
                    case 4:
                        System.out.println("Exiting the program.");
                        System.exit(0);
                    default:
                        System.out.println("Invalid choice. Please enter 1, 2, 3, or 4.");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
