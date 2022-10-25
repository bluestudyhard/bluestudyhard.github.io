package com.homework;

public class Test4 {
    public static void main(String[] args) {
        Animal an = new Dog();
        Animal an1 = new Cat();
        an.cry();
        an1.cry();
        Square s1 = new Square(2, 2);
        System.out.println(s1.getArea());
        Circle c1 = new Circle();
        c1.setR(2);
        System.out.println(c1.getArea_());
        Grogebra g = new Grogebra();
        g.setL(3);
        g.setH(3);
        System.out.println(g.getV());
    }
}

class Animal {
    public void cry() {
        System.out.println("animal cry");
    }

}

class Dog extends Animal {
    public void cry() {
        System.out.println("汪呜呜呜，汪呜，汪呜，呜~唔");
    }
}

class Cat extends Animal {
    public void cry() {
        System.out.println("喵呜呜呜，喵呜");
    }
}

abstract class Geometry {

    abstract public double getArea_();

}


class Rectangle_ extends Geometry {
    double len, wid, area;

    Rectangle_(double l, double w) {
        len = l;
        wid = w;
    }

    public double getLen() {
        return len;
    }

    public double getWid() {
        return wid;
    }

    public double getArea_() {
        area = len * wid;
        return area;
    }
}

class Square_ extends Rectangle {
    double a;

    public Square_(double l, double w) {
        super(l, w);
        a = l;
    }

}

class Circle extends Geometry {
    double r;

    public void setR(double r1) {
        r = r1;
    }

    public double getR() {
        return r;
    }

    public double getArea_() {
        return r * r * 3.14;
    }
}

class Grogebra {

    double l;
    double h;

    public void setH(double h1) {
        h = h1;
    }

    public void setL(double l1) {
        l = l1;
    }

    public double getV() {
        return l * l * h / 3.0;
    }
}