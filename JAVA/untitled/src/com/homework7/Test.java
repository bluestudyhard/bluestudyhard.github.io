package com.homework7;

public class Test {
    interface IMath {
        int add(int a, int b);

        int maxNum(int a, int b);
    }

    interface Person {
        void eat();

        void sleep();
    }

    public static void main(String[] args) {
        MathClass m = new MathClass();
        System.out.println(m.add(1, 2));
        System.out.println(m.maxNum(2, 3));
        Student s = new Student();
        Teacher t = new Teacher();
        Guest g = new Guest();
        s.eat();
        s.sleep();
        t.eat();
        t.sleep();
        g.eat();
        g.sleep();
    }
}

class MathClass implements Test.IMath {

    @Override
    public int add(int a, int b) {
        int sum = a + b;
        return sum;
    }

    @Override
    public int maxNum(int a, int b) {
        return Math.max(a, b);
    }
}

class Student implements Test.Person {

    @Override
    public void eat() {
        System.out.println("学生去食堂吃饭");
    }

    @Override
    public void sleep() {
        System.out.println("学生回寝室睡觉");
    }
}

class Teacher implements Test.Person {

    @Override
    public void eat() {
        System.out.println("教师师去教师食堂吃饭");
    }

    @Override
    public void sleep() {
        System.out.println("教师回学校公寓睡觉");
    }
}

class Guest implements Test.Person {

    @Override
    public void eat() {
        System.out.println("学生家长/外宾/上级领导去招待所吃饭");
    }

    @Override
    public void sleep() {
        System.out.println("学生家长/外宾/上级领导五星级酒店睡觉");
    }
}