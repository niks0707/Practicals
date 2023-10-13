import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
 
public class RemoteImplementation extends UnicastRemoteObject implements RemoteInterface {
 
    protected RemoteImplementation() throws RemoteException {
        super();
    }
 
    @Override
    public int add(int a, int b) throws RemoteException {
        return a + b;
    }
 
    @Override
    public int subtract(int a, int b) throws RemoteException {
        return a - b;
    }
 
    @Override
    public int multiply(int a, int b) throws RemoteException {
        return a * b;
    }
 
    @Override
    public int divide(int a, int b) throws RemoteException {
        return a / b;
    }

    @Override
    public String info(String name) throws RemoteException {
    	StringBuilder sb = new StringBuilder();
        sb.append(name);
        return sb.reverse().toString();
    }

    @Override
    public Boolean StringComp(String s1, String s2){
        int a =  s1.compareTo(s2);
        if( a== 0 ) return true;
        else return false;
    }

    @Override
    public int stringCt(String s1) {
        return s1.length();  
    }

    @Override
    public int stringCt2(String s1) {
        String[] words = s1.split("\\s+");
        int wordCount = words.length;
        return wordCount; 
    }

    @Override
    public int simpleIntrest(int p, int i, int r){
        return (p*i*r);
    }

    @Override
    public int square(int num) {
        return num*num;
    }

    @Override
    public Double squareRoot(int num) {
        return Math.sqrt(num);
    }
}