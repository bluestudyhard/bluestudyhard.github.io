package com.pokegame;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class MyFrame implements ActionListener {
    String[] e = new String[53];
    JButton[] jb = new JButton[13];
    boolean point = false;
    boolean pos = false;
    JButton 已选牌;

    public MyFrame() {
        com.pokegame.Poke p = new com.pokegame.Poke();
        JFrame jf = new JFrame("我的窗体");
        jf.setExtendedState(JFrame.MAXIMIZED_BOTH);
        int w = (int) Toolkit.getDefaultToolkit().getScreenSize().getWidth();
        int h = (int) Toolkit.getDefaultToolkit().getScreenSize().getHeight();
        ImageIcon img = new ImageIcon("img/bj.jpg");
        JLabel jl = new JLabel(img);
        jl.setBounds(0, 0, w, h);
        jf.add(jl);
        JLayeredPane jp = jf.getLayeredPane();
        jp.setBounds(300, 600, 1000, 1000);
        for (int i = 0; i <= 12; i++) {
            ImageIcon imag1 = new ImageIcon("img/fang" + (i + 1) + ".jpg");
            jb[i] = new JButton(imag1);
            jb[i].setBounds(i * 100, 600, 134, 201);
            jb[i].setVisible(true);
            //jb[i].addActionListener(this);
            jp.add(jb[i], new Integer(i));
            jf.setVisible(true);
            jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        }
    }

    public static void main(String[] args) {
        MyFrame p = new MyFrame();

    }

    public void actionPerformed(ActionEvent e) {
        int x, y;

        // System.out.println(e.getSource()); 相当于是一个图片的信息
        for (int i = 0; i <= 12; i++) {
            if (e.getSource() == jb[i]) {
                x = jb[i].getX();
                y = jb[i].getY();

                for (int j = 0; j <= 12; j++) {
                    jb[j].setBounds(j * 120, 600, 134, 201);
                }
                jb[i].setBounds(x, y - 50, 134, 201);
                // 第一次点

//                } else {
//                    jb[i].setBounds(x, y - 50, 134, 201);
//                    point = false;
//                }

            }
        }
    }
}

