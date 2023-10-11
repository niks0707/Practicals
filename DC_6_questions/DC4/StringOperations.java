import java.rmi.Remote;
import java.rmi.RemoteException;

public interface StringOperations extends Remote {
    boolean compareStrings(String str1, String str2) throws RemoteException;
    int countCharacters(String str) throws RemoteException;
}
