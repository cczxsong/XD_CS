package EchoThreadPool;

import java.net.*;

import java.io.IOException;
import java.net.ServerSocket;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Server {

    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(8888);
            // 构造一个线程池
            ThreadPoolExecutor threadPool = new ThreadPoolExecutor(3, 5, 3,TimeUnit.SECONDS,
                    new ArrayBlockingQueue<Runnable>(3));
            System.out.println("服务端已启动，等待客户端连接..");
            while (true) {
                Socket socket = server.accept();// 侦听并接受到此套接字的连接,返回一个Socket对象
                ServerPool socketThread = new ServerPool(socket);
                threadPool.execute(socketThread);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}



