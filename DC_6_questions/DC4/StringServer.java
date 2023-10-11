import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class StringServer {

    public static void main(String[] args) {
        try {
            // Create and export the remote object
            StringOperations stringOperations = new StringOperationsImpl();

            // Start the RMI registry on port 1099
            LocateRegistry.createRegistry(2001);

            // Bind the remote object to the registry
            Naming.rebind("StringOperations", stringOperations);

            System.out.println("StringOperations server is running...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
