import java.util.*;
import java.io.*;
import java.net.MalformedURLException;
import java.rmi.AlreadyBoundException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
public class RMIServer {
    public static void main(String[] args)  {      
		try{
			BookMethod mserver = new BookMethodImpl();
			LocateRegistry.createRegistry(8989);
			Naming.bind("rmi://localhost:8989/BookMethod", mserver);
			System.out.println("Service is online.");
        }catch (Exception e) {
            e.printStackTrace();
        }
    }
}
