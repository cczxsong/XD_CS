package com.company;

import org.apache.activemq.ActiveMQConnectionFactory;
import javax.jms.*;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;

class MyListener_err implements MessageListener {
    int num = 0; //current var
    int errnum = 0;
    ArrayList arrayList = new ArrayList();

    BigDecimal va = new BigDecimal("0");
    BigDecimal avg = new BigDecimal("0");
    public BigDecimal sqrt_(BigDecimal a){
        BigDecimal _2=BigDecimal.valueOf(2.0);
        int precision=100;
        MathContext mc = new MathContext(precision, RoundingMode.HALF_UP);
        if(a.compareTo(BigDecimal.ZERO)==0) {
            return new BigDecimal("0");
        }
        else{
            BigDecimal x=a;
            int cnt=0;
            while(cnt<100){
                x=(x.add(a.divide(x,mc))).divide(_2,mc);
                cnt++;
            }
            return x;
        }
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
            if(num>1){
                for (int i = 0; i < arrayList.size(); i++ ){
                    BigDecimal d1 = (BigDecimal)arrayList.get(i);
                    sum = sum.add(d1);
                }
                avg = sum.divide(BigDecimal.valueOf(arrayList.size()),20,BigDecimal.ROUND_UP);
                for (int i = 0; i < arrayList.size(); i++ ){
                    BigDecimal d2 = (BigDecimal)arrayList.get(i);
                    sum_var = sum_var.add((d2.subtract(avg)).multiply(d2.subtract(avg)));
                }

                va = sum_var.divide(BigDecimal.valueOf(arrayList.size()),20,BigDecimal.ROUND_UP);//setha^2
                va = sqrt_(va);
                BigDecimal xx = avg.subtract(va.multiply(new BigDecimal("3")));  //      avg-3*seata
                BigDecimal yy = avg.add(va.multiply(new BigDecimal("3"))); //            avg+3*seata
                if(temp.compareTo(xx) < 0 || temp.compareTo(yy) > 0) {
                    errnum++;
                }
                System.out.println("current_num: "+num+" err_num: " + errnum );
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
public class ASyncConsumer_err {
    public static void main(String[] args) throws JMSException {
        String brokerURL = "tcp://localhost:61616";
        ConnectionFactory factory = null;
        Connection connection = null;
        Session session = null;
        Topic topic = null;
        MessageConsumer messageConsumer = null;
        MyListener_err listener = null;
        try {
            factory = new ActiveMQConnectionFactory(brokerURL);
            connection = factory.createConnection();

            session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
            topic = session.createTopic("MYTOPIC");

            messageConsumer = session.createConsumer(topic);

            listener = new MyListener_err();

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

