import java.rmi.Remote;
import java.rmi.RemoteException;

public interface MathOperations extends Remote {
    double calculateSquareRoot(double number) throws RemoteException;
    double calculateSquare(double number) throws RemoteException;
    int calculateFactorial(int number) throws RemoteException;
}
