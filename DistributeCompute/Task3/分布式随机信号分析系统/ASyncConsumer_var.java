import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Scanner;

class MyListener_var implements MessageListener {
    int N = 0;
    int num = 0; //current var
    ArrayList arrayList = new ArrayList();


    BigDecimal va = new BigDecimal("0");
    BigDecimal avg = new BigDecimal("0");

    MyListener_var(int Nu){
        this.N = Nu;
    }
    @Override
    public void onMessage(Message message) {
        try {
            num++;
            String str = ((TextMessage)message).getText();
            BigDecimal temp = new BigDecimal(str);
            arrayList.add(temp);
            BigDecimal sum = new BigDecimal("0");
            BigDecimal sum_var = new BigDecimal("0");
            if(num>N){
                for (int i = arrayList.size()-1; i >= arrayList.size()-N; i-- ){
                    BigDecimal d1 = (BigDecimal)arrayList.get(i);
                    sum = sum.add(d1);
                }
                avg = sum.divide(BigDecimal.valueOf(N),20,BigDecimal.ROUND_UP);
                for (int i = arrayList.size()-1; i >= arrayList.size()-N; i--){
                    BigDecimal d2 = (BigDecimal)arrayList.get(i);
                    sum_var = sum_var.add((d2.subtract(avg)).multiply(d2.subtract(avg)));
                }

                va = sum_var.divide(BigDecimal.valueOf(N),20,BigDecimal.ROUND_UP);
                System.out.println("current var: "+va.toString());

            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
public class ASyncConsumer_var {
    public static void main(String[] args) throws JMSException {
        String brokerURL = "tcp://localhost:61616";
        ConnectionFactory factory = null;
        Connection connection = null;
        Session session = null;
        Topic topic = null;
        MessageConsumer messageConsumer = null;
        MyListener_var listener = null;
        try {
            factory = new ActiveMQConnectionFactory(brokerURL);
            connection = factory.createConnection();

            session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
            topic = session.createTopic("MYTOPIC");

            messageConsumer = session.createConsumer(topic);

            System.out.println("Press the N :");
            Scanner scanner = new Scanner(System.in);
            int N = scanner.nextInt();
            listener = new MyListener_var(N);

            messageConsumer.setMessageListener(listener);

            connection.start();

            System.out.println("Press any key to exit.");
            System.in.read();   // Pause
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            connection.close();
        }
    }
}
