package com.pokegame;
import java.util.Objects;
import java.util.Random;
public class Poke {
	String[] a = new String[53];
	String[] b = new String[53];
	String[] c = new String[14];
	String[] d = new String[14];
	String[] e = new String[53];
	String temp;
	public static void main(String[] args) {
        Poke user = new Poke();//通过new关键字配合构建新方法Pack2(),完成实例化并取名为User
        user.makePokeName();
        user.rondomPoke();
        user.realcombinepoke();
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
        System.out.println("打印数组a");
        for (int i = 1; i <= a.length - 1; i++) {
            System.out.printf("%s", a[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
    }

    void printPokeName() {
    	System.out.println("打印数组c");
        for (int i = 1; i <= c.length - 1; i++) {
            System.out.printf("%s", c[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("打印数组d");

        for (int i = 1; i <= d.length - 1; i++) {
            System.out.printf("%s", d[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("打印数组e");
        for (int i = 1; i <= e.length - 1; i++) {
            System.out.printf("%s", e[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
    }

    String[] rondomPoke() {
        System.arraycopy(a, 1, b, 1, 52);//将数组a从下标1  复制到数组b从下标1开始拿52个数值
        for (int i = 0; i < 100; i++) {
            Random r = new Random();
            // 为什么这里要+1呢 因为random(52) 是[0,52]区间的值,有可能出现0，然后这样交换的话就会换到null，因为我们的数组是从1开始的。所以+1可以让区间变成[1,52];
            int m = r.nextInt(52) + 1;
            int n = r.nextInt(52) + 1;
            //System.out.println(m+n);//交换以m,n 为下标的数组
            temp = b[m];
            b[m] = b[n];
            b[n] = temp;
            //System.out.println(m+n);
        }
        System.out.println("\n");
    	System.out.println("打印数组b");
        for (int i = 1; i <= b.length - 1; i++) {
            System.out.printf("%s", b[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
		return b;
    }
    
    String[] realcombinepoke() {
        int a = 1;//用i 和 j来表示下标，这里可以用到双指针法
        int j = 13;
        while (j <= 52) {
            //13 26 39 52
            System.arraycopy(b, a, c, 1, 13);
            sortPoke();
            System.arraycopy(d, 1, e, a, 13);// 1  14 27 40 52
            a = j + 1;//为什么要+1呢是因为，你下一次要进行复制的元素，是不是原来的数组的下一个。所以＋1不然会导致e数组的最后一个为null。
            j += 13;
        }
		return e;
    }

    String[] sortPoke() {
        int k = 1;
        for (int i = 1; i <= a.length - 1; i++) {
            for (int j = 1; j <= c.length - 1; j++) {
                if (Objects.equals(a[i], c[j])) {
                    d[k++] = c[j];
                }
            }
        }
		return c;
    }
    
}
