package EchoThread;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    /**
     * Socket服务端
     */
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(8888);
            System.out.println("服务端已启动，等待客户端连接..");

            while (true) {
                Socket socket = serverSocket.accept();// 侦听并接受到此套接字的连接,返回一个Socket对象
                ServerThread socketThread = new ServerThread(socket);
                socketThread.start();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}

