package UDPThread;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDPServerThread extends Thread{
    DatagramSocket aSocket = null;
    public UDPServerThread(DatagramSocket socket) {
        this.aSocket = socket;
    }
    @Override
    public void run(){
        try {
            byte[] buffer = new byte[1000];
            while(true){
                DatagramPacket request = new DatagramPacket(buffer, buffer.length);
                aSocket.receive(request);

                byte[] data = request.getData();
                String msg = new String(data, 0, request.getLength());
                System.out.println(msg);

                DatagramPacket reply = new DatagramPacket(request.getData(),
                        request.getLength(), request.getAddress(), request.getPort());
                aSocket.send(reply);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
