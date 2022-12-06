package com.mypokegame;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.util.Pair;

import java.util.List;
import java.util.Objects;

public class Controller {
    /*�ȷ�չʾ*/
    public Label score1, score2;
    @FXML
    // ��������
    private GridPane robotPane;

    @FXML
    // �������
    private GridPane kkPane;
    @FXML
    //�����м�����
    private GridPane robotfiled;
    @FXML
    // ����м�����
    private GridPane playerfiled;
    // poke��������������
    private poke cards = new poke();
    @FXML
    // �м���չʾ��
    private TextField result;
    // ���ڴ��������ͼƬ������
    private ImageView[] botCards;
    // ���ڱ�������ͼƬ�±�
    private int botPos;
    // �Ʒ�
    private int count = 0, count1 = 0;
    // �ȴ�С���л�
    private int flag = 1;
    // ��ҵ��ƺͻ�������
    private List<Pair<String, Integer>> robotCards, playerCards;
    @FXML
    // �л���С�İ�ť
    private Button change;

    private void CardAction(Button btn, int index) {
        //        double x = playerfiled.getLayoutX();
        //        double y = playerfiled.getLayoutY();
        //        btn.setLayoutX(x+50);
        //        btn.setLayoutY(y+50);
        //        System.out.println(x + "" + y);
        //        System.out.println(btn.getLayoutX() + "" + btn.getLayoutY());
        System.out.println(playerCards.get(index).getKey() + playerCards.get(index).getValue());
        System.out.println(robotCards.get(botPos).getKey() + robotCards.get(botPos).getValue());
        compareValue(playerCards.get(index).getKey(), playerCards.get(index).getValue(), robotCards.get(botPos).getKey(), robotCards.get(botPos).getValue());
        whoWin();
        playerfiled.add(btn, 0, 0);
        robotfiled.add(botCards[botPos++], 0, 0);
    }

    public void robotInit() {
        robotPane.getChildren().clear();
        cards.makeRobotPoke();
        robotCards = cards.robot;
        botCards = new ImageView[13];
        int j = 0;
        for (var rcard : robotCards) {
            String rpath = "img/" + rcard.getKey() + rcard.getValue() + ".jpg";
//            String key = rcard.getKey();
//            int numbers = rcard.getValue();
            ImageView imgg = new ImageView(new Image(rpath));
            imgg.setFitHeight(130);
            imgg.setFitWidth(90);
            botCards[j] = imgg;
            robotPane.add(imgg, j++, 0);
            robotfiled.getChildren().clear();
        }
    }

    public void initialize() {
        Init();
    }

    public void Init() {
        count = 0;
        count1 = 0;
        score1.setText("score: ");
        score2.setText("score: ");
        result.clear();
        robotInit();
        botPos = 0;
        cards.makePokeName();
        kkPane.getChildren().clear();
        playerCards = cards.kk;
        int i = 0;
        for (var card : playerCards) {
            String path = "img/" + card.getKey() + card.getValue() + ".jpg";
//            System.out.println(playerKey);
//            System.out.println(playerValue);

            ImageView img = new ImageView(new Image(path));
            img.setFitWidth(90);
            img.setFitHeight(130);
            // Button (text,g)
            // ÿ��ѭ���½�һ����ť������ť����gridpane���ÿ��������
            Button btn = new Button("", img);
            //gridpane.add(new Button(), 2, 1)// �ڼ��еڼ���
            int finalI = i;
            btn.setOnAction(e -> CardAction(btn, finalI));
            kkPane.add(btn, i++, 0);

            playerfiled.getChildren().clear();
        }
    }

    public void compareValue(String poke1, int value1, String poke2, int value2) {

        score1.setText(score1.getText());
        score2.setText(score2.getText());
        int sum = 0, sum1 = 0;
        if (Objects.equals(poke1, "hei")) {
            sum = 40 + value1;
        } else if (Objects.equals(poke1, "hong")) {
            sum = 21 + value1;
        } else if (Objects.equals(poke1, "mei")) {
            sum = 10 + value1;
        } else if (Objects.equals(poke1, "fang")) {
            sum = value1;
        }
        if (Objects.equals(poke2, "hei")) {
            sum1 = 40 + value2;
        } else if (Objects.equals(poke2, "hong")) {
            sum1 = 21 + value2;
        } else if (Objects.equals(poke2, "mei")) {
            sum1 = 10 + value2;
        } else if (Objects.equals(poke2, "fang")) {
            sum1 = value2;
        }
        System.out.println(sum + " " + sum1);
        // �ȴ�
        if (flag == 1) {
            if (sum > sum1) {
                score1.setText("score: ");
                setResult("player�÷�Ϊ:  " + sum + "  robot�÷�Ϊ: " + sum1 + " player win !");
                count++;
                score1.setText(score1.getText() + count);
                System.out.println("player win");
            } else {
                score2.setText("score: ");
                setResult(" player�÷�Ϊ: " + sum + " robot�÷�Ϊ: " + sum1 + " robot win zzz");
                count1++;
                score2.setText(score2.getText() + count1);
                System.out.println("robot win!");
            }
        } else {
            if (sum > sum1) {
                score2.setText("score: ");
                setResult(" player�÷�Ϊ: " + sum + " robot�÷�Ϊ: " + sum1 + " robot win zzz");
                count1++;
                score2.setText(score2.getText() + count1);
                System.out.println("robot win!");
            } else {
                score1.setText("score: ");
                setResult("player�÷�Ϊ:  " + sum + "  robot�÷�Ϊ: " + sum1 + " player win !");
                count++;
                score1.setText(score1.getText() + count);
                System.out.println("player win");
            }
        }
    }

    public void setResult(String text) {
        result.setText(text);
    }

    public void setChange() {
        change.setText("");
        flag = -1 * flag;
        if (flag == 1) {
            change.setText("�ȴ�");
        } else {
            change.setText("��С");
        }
        System.out.println(flag);
    }

    public void whoWin() {
        if (count1 >= 5 || count >= 5) {
            result.setText("");
            if (count > count1) {
                result.setText("player finally win!!!!");
            } else result.setText("you lose��");
            playerCards.clear();
            robotCards.clear();

        }
    }
}
