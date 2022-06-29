package com.company;
import java.util.Scanner;

class Math_Series{
    public static double Arcth(double x, double eps)
    {
        double sum = 0;
        double num = 1.0;
        int n=0;
        while (Math.abs(num) >= eps)
        {
            sum += num;
            n++;
            num = Math.pow(x,2.0*n) / (2.0 * n+1.0);
        }
        return x * sum;
    }
}
public class Main {

    public static void main(String[] args)
    {
        final double eps = 1.0e-16;
        Scanner in = new Scanner(System.in);
        System.out.print("Введите значение x:");
        double x = in.nextDouble();
        double result = Math_Series.Arcth(x, eps);
        if ((x<-1) || (x>1))
        {
            System.out.print("Некорректные данные! Введите значение x в диапазоне от -1 до 1!\n");
        }
        System.out.format("Результат вычисления функции F(x) равен %2.16f\n", result);
        System.out.format("Результат вычисления функции f(x) равен %2.16f\n", 0.5*Math.log((1+x)/(1-x))); //Используем вычисление для сравнения результатов
    }
}



