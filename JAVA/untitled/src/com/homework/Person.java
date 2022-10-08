package com.homework;

import java.util.Scanner;


public class Person {
    private
    String name;
    int age;

    Person() {
        name = "blue";
        age = 19;
    }

    public void display() {
        System.out.println(name);
        System.out.println(age);
    }

    public static void main(String[] args) {
        Person p = new Person();
        p.display();
    }
}
