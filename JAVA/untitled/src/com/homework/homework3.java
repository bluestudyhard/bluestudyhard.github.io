package com.homework;

import java.util.Scanner;

public class homework3 {

    static class Cat {
        void Speak() {
            System.out.println("喵喵");
        }
    }


    static class Cicle {
        double h, r, v;
        double PI = 3.1415;

        void scanf() {
            Scanner input = new Scanner(System.in);
            h = input.nextDouble();
            r = input.nextDouble();

        }

        double get_V() {
            return h * PI * r * r;
        }
    }

    static class Test {
        public static void main(String[] args) {
            Cat c1 = new Cat();
            c1.Speak();
            Cicle c = new Cicle();
            c.scanf();
            System.out.println(c.get_V());
        }
    }
}
