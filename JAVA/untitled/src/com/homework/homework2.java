package com.homework;

import java.util.Arrays;
import java.util.Scanner;
import java.math.*;

public class homework2 {

    public static boolean isshui(int n) {
        double sum = 0;
        double n1 = n;
        while (n != 0) {
            double m = n % 10;
            sum += Math.pow(m, 3.);
            n /= 10;
        }

        return sum == n1;
    }

    public static long fib(int n) {
        long sum = 0;

        for (int i = 1; i <= n; i++) {
            long sum1 = 1;
            for (int j = 1; j <= i; j++) {
                sum1 *= j;
            }
            sum += sum1;
        }

        return sum;

    }

    public static void main(String[] args) {
        /* 一 */
//        for (int i = 100; i <= 999; i++) {
//            if (isshui(i)) {
//                System.out.print(i);
//                System.out.print(' ');
//            }
//
//        }
        /* 二 */
//        long sum = fib(10);
//        System.out.println(sum);

        /* 三*/

//        int[] arr = new int[]{
//                23, 24, 25, 6, 5, 10, 7, 89, 700, 90
//        };
//        Arrays.sort(arr);
//        for (int i = 0; i < arr.length; i++) {
//            System.out.print(arr[i]);
//            System.out.print(" ");
//        }
        /*四*/
        int maxlen = 0;
        int minlen = (int) 1e9;
        String[] str = new String[5];
        for (int i = 0; i < 5; i++) {
            Scanner input = new Scanner(System.in);
            str[i] = input.nextLine();
            if (str[i].length() > maxlen)
                maxlen = str[i].length();
        }
        for (int i = 0; i < 5; i++) {
            if (str[i].length() < minlen)
                minlen = str[i].length();
        }
        System.out.println(maxlen);
        System.out.println(minlen);
    }
}
