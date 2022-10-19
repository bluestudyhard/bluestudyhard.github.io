package com.homework;

public class Rectangle {
    private double len, width;

    public Rectangle(double l, double w) {
        len = l;
        width = w;
    }

    double getLen() {
        return len;
    }

    double getWidth() {
        return width;
    }

    double getArea() {
        return len * width;
    }

    public static void main(String[] args) {
        Square s = new Square(12.2, 3.3);
        s.setside();
        System.out.println(s.getArea());
    }
}

class Square extends Rectangle {
    private double r;

    public Square(double l, double w) {
        super(l, l);
    }

    void setside() {
        r = getLen();
    }
}

