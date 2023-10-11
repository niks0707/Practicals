import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class MathServer {
    public static void main(String[] args) {
        try {
            MathOperations mathOperations = new MathOperationsImpl();
            LocateRegistry.createRegistry(2000);
            Naming.rebind("MathOperations", mathOperations);
            System.out.println("Math Server is ready.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
