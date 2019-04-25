import java.util.*;
import java.io.*;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.io.Serializable;
public class RMIClient {
	
    public static void main(String[] args) throws RemoteException, NotBoundException, MalformedURLException, FileNotFoundException {     
        BookMethod method = (BookMethod)Naming.lookup("rmi://localhost:8989/BookMethod");
		method.initData();
		Scanner input = new Scanner(System.in);
		System.out.println(menu());
		int choose = input.nextInt();
		while (choose != 0) {
			switch(choose) {
				case 1: System.out.println("please input book_id and book_name to add it\n");
						int newBookID = input.nextInt();
						String newName = input.next();
						Book newBook = new Book(newBookID, newName);
						if (method.add(newBook)) {
							System.out.println("add sucessful\n");
						} else {
							System.out.println("ID:" + newBookID + " pre_existing, add book failed\n");
						}
						break;
				case 2: System.out.println("please input book_id to query it\n");
						int queryBookID = input.nextInt();
						Book queryid = method.queryByID(queryBookID);
						if (queryid != null) {
							System.out.println("*******book list *********\n");
							queryid.showInfo();
						} else {
							System.out.println("this book isnot existing");
						}
						break;
				case 3: System.out.println("please input book_name to query it\n");
						String queryBookKeyword = input.next();
						BookList list = method.queryByName(queryBookKeyword);
						if (list != null) {
							System.out.println("*******book list *********\n");
							list.showInfo();
						} else {
							System.out.println("this book isnot existing");
						}
						break;
				case 4: System.out.println("please input book_id to delete it\n");
						int deleteID = input.nextInt();
						if (method.delete(deleteID)) {
							System.out.println("del sucessful\n");
						} else {
							System.out.println("del failed\n");
						}
						break;
				case 5: System.out.println(method.booksInfo());
						break;
				default: System.out.println("please input again!\n");
						break;
			}
			System.out.println(menu());
			choose = input.nextInt();
		}
	}
	public static String menu() {
		return "**********menu**********\n"
			+ "1.add book\n" 
			+ "2.query Book by ID\n"
			+ "3.query Book By Name\n"
			+ "4.delete Book by ID\n"
			+ "5.show All Books\n"
			+ "0.quit\n"
			+ "************************\n";
	}
}
