package com.homework;

public class CPU {
    private
    int speed;

    public int setSpeed(int speed) {
        speed = speed;
        return speed;
    }

    int getSpeed() {
        return speed;
    }

    public static void main(String[] args) {
        CPU c = new CPU();
        c.setSpeed(100);
        HardDisk hd = new HardDisk();
        hd.setAmount(512);
        PC p = new PC();
        p.Show();
    }
}

class HardDisk {
    private
    int amount;

    public int setAmount(int amount) {
        amount = amount;
        return amount;
    }

    int getAmount() {
        return amount;
    }
}

class PC {
    private
    CPU c1;
    HardDisk hd;

    void Show() {
        System.out.print(c1.getSpeed());
        System.out.print("ms ");
        System.out.print(hd.getAmount());
        System.out.print("GB ");
    }
}
