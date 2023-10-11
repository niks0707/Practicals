
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class StringOperationsImpl extends UnicastRemoteObject implements StringOperations {

    public StringOperationsImpl() throws RemoteException {
        super();
    }

    @Override
    public boolean compareStrings(String str1, String str2) throws RemoteException {
        return str1.equals(str2);
    }

    @Override
    public int countCharacters(String str) throws RemoteException {
        return str.length();
    }
}
