package Wservice;

import wsTransproxy .*;

import java.util.Scanner;

public class TransClient {

    public static void main(String[] args) {

        EnglishChinese englishChinese = new EnglishChinese();
        EnglishChineseSoap englishChineseSoap = englishChinese.getEnglishChineseSoap();
        System.out.println("please the word:");
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        System.out.println(englishChineseSoap.translatorString(str).getString());

        System.out.println(englishChineseSoap.translatorSentenceString(str).getString());
    }

}
