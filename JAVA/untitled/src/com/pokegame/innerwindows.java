package com.pokegame;


import com.mypokegame.Controller;
import javafx.scene.layout.BorderPane;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class innerwindows {
    public static void main(String[] args) {
//
    }

    void addInner1() {

    }
    void addInner2()
    {

    }
    void makePoke() {
        JFrame jf = new JFrame();
        jf.setSize(600, 500);
        JButton btn1 = new JButton("第一个按钮");
        JButton btn2 = new JButton("第二个按钮");
        JDesktopPane dp = new JDesktopPane();
        int w = (int) Toolkit.getDefaultToolkit().getScreenSize().getWidth();
        int h = (int) Toolkit.getDefaultToolkit().getScreenSize().getHeight();
        JInternalFrame in1 = new JInternalFrame("1", true, true, true, true);
        dp.add(in1);
        in1.setBounds(0, 0, w, h);
        in1.setVisible(true);
        jf.setVisible(true);
    }
}

//   JFrame jf = new JFrame();
//        jf.setSize(600, 500);
//        JLayeredPane jp = new JLayeredPane();
//        jp.setBounds(100, 100, 200, 200);
//        jp.setLayer(jp, 2, 100);
//        JButton jj = new JButton("hhh");
//        jj.addActionListener(addInner);
//        jj.setBounds(0, 0, 100, 100);
//        jp.add(jj);
//        jf.setLocationRelativeTo(null);
//        jf.setDefaultCloseOperation(jf.EXIT_ON_CLOSE);
//        Container c = jf.getContentPane();
//        JDesktopPane dp = new JDesktopPane();
//        c.add(dp);
//       // c.add(jp);
//        int w = (int) Toolkit.getDefaultToolkit().getScreenSize().getWidth();
//        int h = (int) Toolkit.getDefaultToolkit().getScreenSize().getHeight();
//        JInternalFrame in1 = new JInternalFrame("1", true, true, true, true);
//        dp.add(in1);
//        in1.setBounds(0, 0, w, h);
//        in1.setVisible(true);
//        jf.setVisible(true);