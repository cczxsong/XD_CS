import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;

class MyListener_average implements MessageListener {
    int num = 0; //current num
    double sum = 0;
    @Override
    public void onMessage(Message message) {
        try {
            num++;
            String str = ((TextMessage)message).getText();
            sum += Double.valueOf(str);
            System.out.println("current num: "+num+" average: "+sum/num);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}


public class ASyncConsumer_average {

    public static void main(String[] args) throws JMSException {
        String brokerURL = "tcp://localhost:61616";
        ConnectionFactory factory = null;
        Connection connection = null;
        Session session = null;
        Topic topic = null;
        MessageConsumer messageConsumer = null;
        MyListener_average listener = null;
        try {
            factory = new ActiveMQConnectionFactory(brokerURL);
            connection = factory.createConnection();

            session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
            topic = session.createTopic("MYTOPIC");

            messageConsumer = session.createConsumer(topic);

            listener = new MyListener_average();

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
