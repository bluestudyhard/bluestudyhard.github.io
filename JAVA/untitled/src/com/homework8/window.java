package com.homework8;

import javax.swing.*;
import java.awt.*;

public class window {
    public static void main(String args[]) {
        JFrame w1 = new JFrame("������ҵ�");
        Container con1 = w1.getContentPane();// ��ȡһ������
        con1.setBounds(20, 20, 200, 200);
        w1.setBounds(100, 100, 480, 400);
        w1.setVisible(true);
        con1.setBackground(Color.green);
        w1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //con1.setLayout(new BorderLayout(10, 5));
        con1.setLayout(new FlowLayout(FlowLayout.CENTER, 10, 20));
        // con1.setLayout(new CardLayout());
        JLabel jl = new JLabel("��һ����ǩ");
        jl.setBounds(100, 100, 150, 100);
        con1.add(jl);
        JButton jb = new JButton("��һ����ť");
        jb.setBounds(100, 100, 100, 100);
        con1.add(jb);

        /**
         * if(!�ѵ�)
         * {
         *      for(int i = 0;i<12;i++)
         *      {
         *          jb[i] =
         *      }
         * }
         */

    }
}
