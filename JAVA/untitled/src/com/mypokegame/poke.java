package com.mypokegame;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class poke {
    List<Pair<String, Integer>> robot = new ArrayList<>();
    List<Pair<String, Integer>> kk = new ArrayList<>();
    String[] cardType = {"fang", "hong", "mei", "hei"};

    void makePokeName() {

        kk.clear();
        Random r = new Random();
        /*玩家的牌*/
        for (int i = 1; i <= 13; i++) {
            int numbers = r.nextInt(13) + 1;
            kk.add(new Pair<String, Integer>(cardType[r.nextInt(4)], numbers));
        }
    }

    void makeRobotPoke() {
        robot.clear();
        Random r = new Random();
        for (int i = 1; i <= 13; i++) {
            int numbers = r.nextInt(13) + 1;
            robot.add(new Pair<>(cardType[r.nextInt(4)], numbers));
        }
    }

    void printPoke() {
        int i = 0;
        for (Pair<String, Integer> stringIntegerPair : kk) {
            System.out.println(stringIntegerPair.getKey() + stringIntegerPair.getValue());
            System.out.println(i);
            i++;
        }
        System.out.println();
        for (Pair<String, Integer> stringIntegerPair : robot) {
            System.out.println(stringIntegerPair.getKey() + stringIntegerPair.getValue());
        }
    }

    public static void main(String[] args) {
        poke p = new poke();
        p.makePokeName();
        p.printPoke();

    }
}