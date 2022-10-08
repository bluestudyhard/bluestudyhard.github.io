package com.homework;

public class CPU {
    private
    int speed;

    public void setSpeed(int speed) {
        this.speed = speed;
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
        p.setCPU(c);
        p.setHd(hd);
        p.Show();
    }
}

class HardDisk {
    private
    int amount;

    public void setAmount(int amount) {
        this.amount = amount;
    }

    int getAmount() {
        return amount;
    }
}

class PC {
    private
    CPU cpu;
    HardDisk hd;

    public void setCPU(CPU cpu) {
        this.cpu = cpu;
    }

    public void setHd(HardDisk hd) {
        this.hd = hd;
    }

    void Show() {
        System.out.println("CPU速度" + cpu.getSpeed() + "ms");
        System.out.println("硬盘容量" + hd.getAmount() + "GB");
    }
}
