import java.util.*;
import java.io.*;
import java.rmi.RemoteException;
public interface BookMethod extends java.rmi.Remote {
	void initData() throws RemoteException, FileNotFoundException;
	void update() throws RemoteException, FileNotFoundException;
	boolean add(Book b) throws RemoteException, FileNotFoundException;
	Book queryByID(int bookID) throws RemoteException;
	BookList queryByName(String name) throws RemoteException;
	boolean delete(int bookID) throws RemoteException, FileNotFoundException;
	String booksInfo() throws RemoteException;
	void showAllTheBooks() throws RemoteException;
}