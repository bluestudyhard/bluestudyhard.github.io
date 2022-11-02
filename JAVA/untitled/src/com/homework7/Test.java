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
        System.out.println("ѧ��ȥʳ�óԷ�");
    }

    @Override
    public void sleep() {
        System.out.println("ѧ��������˯��");
    }
}

class Teacher implements Test.Person {

    @Override
    public void eat() {
        System.out.println("��ʦʦȥ��ʦʳ�óԷ�");
    }

    @Override
    public void sleep() {
        System.out.println("��ʦ��ѧУ��Ԣ˯��");
    }
}

class Guest implements Test.Person {

    @Override
    public void eat() {
        System.out.println("ѧ���ҳ�/���/�ϼ��쵼ȥ�д����Է�");
    }

    @Override
    public void sleep() {
        System.out.println("ѧ���ҳ�/���/�ϼ��쵼���Ǽ��Ƶ�˯��");
    }
}