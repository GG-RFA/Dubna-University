package com.company;
//import java.lang.*;
import java.util.regex.Matcher; //Импортируем библиотеки для работы с регулярными выражениями
import java.util.regex.Pattern;

public class Main {
    static String [] phrases = { //Прописываем разные строки
            "I have a weekend I have a weekend",
            "He can relax in my spare time",
            "She wants to play She wants to play"
    };
    public static void main(String[] args) {
        String duplicatePattern = "\\b([\\w\\s']+) \\1\\b"; // Убираем дублирующиеся слова в строке при помощи шаблона \b([\w\s']+) \1\b
        Pattern word = Pattern.compile(duplicatePattern);
        for (String phrase : phrases) {
            Matcher match = word.matcher(phrase); // Определяем, содержит ли соответствие текущая строка
            if (match.matches()) {
                System.out.println(match.group(1)); // Если в строке найдено соответствие, отображаем текст строки для подходящей группы
            } else {
                System.out.println(phrase);
            }
        }
    }
}

