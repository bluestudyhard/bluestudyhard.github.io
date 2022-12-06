package com.homework;

public class Student1 {
    private
    String name, number, subject;
    double totalscore, avgscore, Mscore, Escore;

    Student1(String name1, String number1, String subject1, double M, double E) {
        name = name1;
        number = number1;
        subject = subject1;
        Mscore = M;
        Escore = E;
    }

    public void display() {
        System.out.print("学号为 :");
        System.out.print(number);
        System.out.print("姓名为 :");
        System.out.print(name);

    }

    double getAvgscore() {
        avgscore = Mscore + Escore / 2;
        return avgscore;
    }

    double getTotalscore() {
        totalscore = Escore + Mscore;
        return totalscore;
    }
}
