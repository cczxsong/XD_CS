package UDPThread;

import java.lang.management.ManagementFactory;
import java.net.*;
import static java.lang.Thread.sleep;

public class UDPClient{
    public static void main(String args[]){
// args give message contents and server hostname
        try {
            String name = ManagementFactory.getRuntimeMXBean().getName();
            String pid = name.split("@")[0];

            DatagramSocket aSocket = null;
            aSocket = new DatagramSocket();
            String text = "I am Sylveater. PID = ";
            text = text+pid;
            byte[] m = text.getBytes();

            InetAddress aHost = InetAddress.getByName("127.0.0.1");
            int serverPort = 8189;

            DatagramPacket request = new DatagramPacket(m, m.length, aHost, serverPort);
            aSocket.send(request);

            byte[] buffer = new byte[1000];
            DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
            aSocket.receive(reply);
            System.out.println("Reply: " + new String(reply.getData()));
            sleep(100000);
            //程序等待，以便运行多个线程，不同线程不同PID
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}