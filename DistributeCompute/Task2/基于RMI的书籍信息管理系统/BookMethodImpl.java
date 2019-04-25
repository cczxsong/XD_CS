import java.util.*;
import java.io.*;
import java.io.Serializable;
import java.rmi.RemoteException;
class Book implements Serializable {
	private int book_id;
	private String book_name;
    public Book(int ID, String name){
		this.book_id = ID;
		this.book_name = name;
    }
	public int getID() {
		return book_id;
	}
	public String getName() {
		return book_name;
	}
	public String getInfo() {
		return  "ID: " + book_id 
			+ " name:" + book_name + "\n";
	}
	public void showInfo() {
		System.out.println(getInfo());
	}
}
class BookList implements Serializable {
	ArrayList<Book> booklist = new ArrayList<Book>();
	public String getInfo() {
		String info ="";
		for (int i = 0; i < booklist.size(); i++) {
			info += ("ID: " + booklist.get(i).getID()
			+ " name:" + booklist.get(i).getName() + "\n");
		}
		return info;
	}
	public void showInfo() {
		System.out.println(getInfo());
	}
}
class BookMethodImpl extends java.rmi.server.UnicastRemoteObject implements BookMethod{
	BookMethodImpl() throws RemoteException  {
		super();
	}
	ArrayList<Book> books = new ArrayList<Book>();
	BookList query = new BookList();	
	@Override
	public void initData() throws RemoteException, FileNotFoundException {
		File file = new File("content.txt");
		Scanner input = new Scanner(file);	
		while (input.hasNext()) {
			int id = input.nextInt();
			String name = input.next();
			books.add(new Book(id, name));
		}
		input.close();
	}
	@Override
	public void update() throws RemoteException, FileNotFoundException {
		File file = new File("content.txt");
		PrintWriter output = new PrintWriter(file);
		for (int i = 0; i < books.size(); i++) {
			output.print(books.get(i).getID() + " ");
			output.println(books.get(i).getName());
		}
		output.close();
	}
	@Override
	public boolean add(Book b) throws RemoteException, FileNotFoundException{
		for (int i = 0; i < books.size(); i++) {
			if (books.get(i).getID() == b.getID()) {
				return false;
			}
		}
		books.add(b);
		update();
		return true;
	}
	@Override
	public Book queryByID(int bookID) throws RemoteException{
		Book b = null;
		for (int i = 0; i < books.size(); i++) {
			if (books.get(i).getID() == bookID) {
				b = books.get(i);
				return b;
			}
		}
		return null;
	}
	@Override
	public BookList queryByName(String name) throws RemoteException{
		for (int i = 0; i < books.size(); i++) {
			if(books.get(i).getName().indexOf(name)!=-1){
                query.booklist.add(books.get(i));
            }			
		}
		return query;
	}
	@Override
	public boolean delete(int bookID) throws RemoteException, FileNotFoundException {
		for (int i = 0; i < books.size(); i++) {
			if (books.get(i).getID() == bookID) {
				books.remove(books.get(i));  
				update();
				return true;
			}
		}
		return false;
	}
	@Override
	public String booksInfo() throws RemoteException {
		String info = "********current books**********\n";
		for (int i = 0; i < books.size(); i++) {
			info += ("ID: " + books.get(i).getID() 
			+ " name:" + books.get(i).getName() + "\n");
		}
		return info;
	}
	@Override
	public void showAllTheBooks() throws RemoteException {
		System.out.println(booksInfo());
	}
}
