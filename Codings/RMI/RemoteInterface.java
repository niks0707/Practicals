import java.rmi.Remote;
import java.rmi.RemoteException;
 
public interface RemoteInterface extends Remote {
    int add(int a, int b) throws RemoteException;
    int subtract(int a, int b) throws RemoteException;
    int multiply(int a, int b) throws RemoteException;
    int divide(int a, int b) throws RemoteException;
    String info(String name) throws RemoteException;
    Boolean StringComp(String s1, String s2) throws RemoteException;
    int stringCt(String s1) throws RemoteException;
    int stringCt2(String s1) throws RemoteException;
    int simpleIntrest(int p, int i, int r) throws RemoteException;
    int square(int num) throws RemoteException;
    Double squareRoot(int num) throws RemoteException;
}