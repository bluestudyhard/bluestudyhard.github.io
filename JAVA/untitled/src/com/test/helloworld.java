package com.test;

import java.util.Objects;
import java.util.Scanner;
import java.math.*;

public class helloworld {
//    public boolean isshui(double n) {
//        int sum = 0;
//
//    }

    public static void main(String[] args) {
        // for (int i = 1; i <= 3; i++) {
        // for (int i = 1; i <= 3; i++) {
        // System.out.print(i);
        // System.out.print('\n');
        // }
        // int[] a = {1, 2, 3, 4};
        // String[] ss = {"one", "two", "three"};
        // ss[1] = "fuck";//可以更改
        // System.out.println(ss[1]);
        //System.out.println(max(1,2,3));
        System.out.println(" I am a student. I love java.");
        Scanner input = new Scanner(System.in);
        int cnt = 1;
        int maxx = 0;
        while (cnt <= 3) {
            int text = input.nextInt();
            maxx = Math.max(text, maxx);
            cnt++;
        }
        System.out.println(maxx);
        int shui[];
        for (int i = 100; i <= 1000; i++) {

        }


//    public static void main(String[] args) {
//        int cnt = 3;
//        while (cnt!=0) {
//            Scanner scan = new Scanner(System.in);
//            String str1 = scan.nextLine();
//            // 从键盘接收数据
//            if (Objects.equals(str1, "d") || Objects.equals(str1, "x")) {
//                int number = 0;
//                String str2;
//                for (int i = 0; i < 3; i++) {
//
//                    int x = (int) (Math.random() * 6 + 1);// 随机数的生成
//                    System.out.println("number:" + x);// 随机数的输出
//                    number += x;// 求和
//                  //  System.out.println(number);
//                }
//                System.out.println("总和：" + number);
//                if (number >= 13) {
//                    System.out.println("大");
//                    str2 = "d";
//                    System.out.println(str2);
//                } else {
//                    System.out.println("小");
//                    str2 = "x";
//                }
//                if (str1.equals(str2)) {
//                    System.out.println("猜对了");
//                } else {
//                    System.out.println("猜错了");
//                }
//            } else {
//                System.out.println("输入错误请重新输入");
//            }
//        cnt--;
//        }
//
//    }
    }
}
