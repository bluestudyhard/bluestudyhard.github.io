package com.homework;

public class person {
    private
    String name;
    int sex;

    public person(String n, int s) {
        name = n;
        sex = s;
    }


    String getName() {
        return name;
    }

    int getSex() {
        return sex;
    }

}

class test {
    public static void main(String[] args) {
        Student s = new Student("blue", 19, "2114100314");
        System.out.println(s.getName());
        System.out.println(s.getSex());
        System.out.println(s.getNumber());

    }
}


class Student extends person {
    private
    String number;

    public Student(String name, int sex, String n) {
        super(name, sex);
        number = n;

    }

    String getNumber() {
        return number;
    }
}

