package UDPThread;

import java.net.*;

public class UDPServer{
    public static void main(String args[]){
        try{
            DatagramSocket aSocket = null;
            int serverPort = 8189;
            aSocket = new DatagramSocket(serverPort);
            System.out.println("服务端已启动，等待客户端连接..");
            while(true){
                UDPServerThread UDPst = new UDPServerThread(aSocket);
                UDPst.start();
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}