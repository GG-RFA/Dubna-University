package com.company;

   //Обьявление необходимых переменных типа double
public class Main {
    protected double x;
    protected double y;
    protected double z;
    protected double m;
    protected double n;
    protected double p;
    //Создание конструктора для переменных
    public Main (double x, double y, double z, double m, double n, double p) {
       this.x=x;
       this.y=y;
       this.z=z;
       this.m=m;
       this.n=n;
       this.p=p;
    }
    //Создание функции для нахождения расстояния от прямой до начала координат
    public double distance(){
        double d1 = y * p - n * z;
        double d2 = z * m - x * p;
        double d3 = x * n - y * m;
        return Math.sqrt(d1 * d1 + d2 * d2 + d3 * d3) / Math.sqrt(m * m + n * n + p * p);
    }

    public double[] corner() {//угол между прямой и осями координат
        //Реализация формулы
        double S = Math.sqrt(m * m + n * n + p * p);
        double[] v = new double[3];
        v[0] = m / S;
        v[1] = n / S;
        v[2] = p / S;
        return v;
    }
       double distance_between(Main  A) {//Расстояние между 2 прямыми
           //Реализация формулы
           double d1 = n * A.p - p * A.n;
           double d2 = m * A.p - p * A.m;
           double d3 = m * A.n - A.m * n;
           double K = Math.sqrt(d1 * d1 + d2 * d2 + d3 * d3);
           d1 = d1 / K;
           d2 = d2 / K;
           d3 = d3 / K;
           double p = d1 * A.x + d2 * A.y + d3 * A.z;
           return Math.abs(d1 * x + d2 * y + d3 * z - p);
       }

       public static void main(String[]args){
           Main M1=new Main(-2,1,4,0,2,-3);
           Main M2=new Main(0,1,-4,1,-2,6);
           System.out.println("Расстояние от прямой до начала координат:"+M1.distance()); //Вывод результата
           double[]z=M1.corner();
           System.out.println("\n Угол между прямыми:"+z[0]+"\t"+z[1]+"\t"+z[2]+"\n"); //Вывод результата
           System.out.println("\n Расстояние между прямыми:"+M1.distance_between(M2)+'\n'); //Вывод результата
       }
   };




