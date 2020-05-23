import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;
import java.awt.*;
import java.math.*;
import java.util.*;

public class Publisher {

    private static String brokerURL = "tcp://localhost:61616";
    private static ConnectionFactory factory;
    private Connection connection;
    private Session session;
    private MessageProducer producer;
    private Topic topic;
    private Random random = new Random();

    public Publisher(String topicName) throws JMSException {

        factory = new ActiveMQConnectionFactory(brokerURL);
        connection = factory.createConnection();

        session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
        topic = session.createTopic(topicName);
        producer = session.createProducer(topic);

        connection.start();
    }

    public void close() throws JMSException {
        if (connection != null) {
            connection.close();
        }
    }

    public void sendMessage(int a ,int b) throws JMSException {
        double drand = Math.sqrt(b)*random.nextGaussian()+a;
        BigDecimal bigDecimal = BigDecimal.valueOf(drand);
        Message message = session.createTextMessage(bigDecimal.toString());
        producer.send(message);
    }

    public static void main(String[] args) throws JMSException,AWTException {

        Publisher publisher = new Publisher("MYTOPIC");
        Scanner scanner = new Scanner(System.in);
        long t1 = System.currentTimeMillis();
        System.out.println("please input a, b " +
                "as parameters of the Gaussian ");
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        Robot robot = new Robot();
        while(true){
            long t2 = System.currentTimeMillis();   //10s
            if (t2 - t1 >300000){
                break;
            }
            publisher.sendMessage(a,b);
            robot.delay(10);
        }
        publisher.close();

    }
}
