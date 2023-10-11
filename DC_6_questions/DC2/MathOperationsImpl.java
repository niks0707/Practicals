import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class MathOperationsImpl extends UnicastRemoteObject implements MathOperations {
    public MathOperationsImpl() throws RemoteException {
        super();
    }

    @Override
    public double calculateSquareRoot(double number) throws RemoteException {
        return Math.sqrt(number);
    }

    @Override
    public double calculateSquare(double number) throws RemoteException {
        return number * number;
    }

    @Override
    public int calculateFactorial(int number) throws RemoteException {
        if (number == 0) {
            return 1;
        } else {
            return number * calculateFactorial(number - 1);
        }
    }
}
