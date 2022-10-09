package com.homework;

import java.util.Objects;
import java.util.Random;

public class Pack3 {
    String[] a = new String[53];
    String[] b = new String[53];
    String[] c = new String[14];
    String[] d = new String[14];
    String[] e = new String[53];
    String temp;

    public static void main(String[] args) {
        Pack3 user = new Pack3();//通过new关键字配合构建新方法Pack2(),完成实例化并取名为User
        user.makePokeName();
        user.rondomPoke();
        user.extractPoke();
        user.sortPoke();
        user.printPokeName();

    }

    void makePokeName() {
        String[] cardType = {"fang", "hong", "mei", "hei"};
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 13; j++) {
                a[cnt] = cardType[i] + j + ".jpg" + "     ";
                cnt++;
            }
        }
    }

    void printPokeName() {
        System.out.println("打印数组a");
        for (int i = 1; i <= 52; i++) {
            System.out.printf("%s", a[i]);
            if (i % 6 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("打印数组b");
        for (int i = 1; i <= 52; i++) {
            System.out.printf("%s", b[i]);
            if (i % 6 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("打印数组c");
        for (int i = 1; i <= 13; i++) {
            System.out.printf("%s", c[i]);
            if (i % 6 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("打印数组d");
        for (int i = 1; i <= 13; i++) {
            System.out.printf("%s", d[i]);
            if (i % 3 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("打印数组e");
        for (int i = 1; i <= 52; i++) {
            System.out.printf("%s", e[i]);
            if (i % 6 == 0) {
                System.out.println(" ");
            }
        }
    }

    void rondomPoke() {
        System.arraycopy(a, 0, b, 0, 53);//将数组a从下标0  复制到数组b从下标0开始拿52个数值
        for (int i = 0; i < 100; i++) {
            Random r = new Random();//生成0-51之间的随机数
            int m = r.nextInt(52);
            int n = r.nextInt(52);
            //System.out.println(m+n);//交换以m,n 为下标的数组
            temp = b[m];
            b[m] = b[n];
            b[n] = temp;
            //System.out.println(m+n);
        }

    }

    void sortPoke() {
        int k = 1;
        // 以后用长度最好用.length喔，然后这里为什么-1呢，因为你开了53的空间
        for (int i = 1; i <= a.length - 1; i++) {
            for (int j = 1; j <= c.length - 1; j++) {
                if (Objects.equals(a[i], c[j])) { //然后这里也要注意用这个方法，以前说过啦==不好
                    d[k++] = c[j];
                }

            }
        }
    }

    void extractPoke() {
        System.arraycopy(b, 1, c, 1, 13);//这里也要注意，因为你b是从1开始插入的，所以拷贝的时候这里也要从1开始
    }
}
