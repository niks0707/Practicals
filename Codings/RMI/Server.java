import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
 
public class Server {
 
    public static void main(String[] args) {
        try {
            RemoteInterface remoteObj = new RemoteImplementation();
 
            // Bind the remote object to the registry
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("CalculatorService", remoteObj);
 
            System.out.println("Server is running...");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
