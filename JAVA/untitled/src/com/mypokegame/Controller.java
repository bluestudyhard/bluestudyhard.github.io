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
    /*比分展示*/
    public Label score1, score2;
    @FXML
    // 机器牌区
    private GridPane robotPane;

    @FXML
    // 玩家牌区
    private GridPane kkPane;
    @FXML
    //机器中间牌区
    private GridPane robotfiled;
    @FXML
    // 玩家中间牌区
    private GridPane playerfiled;
    // poke对象用于生成牌
    private poke cards = new poke();
    @FXML
    // 中间结果展示区
    private TextField result;
    // 用于存机器手牌图片的数组
    private ImageView[] botCards;
    // 用于遍历手牌图片下标
    private int botPos;
    // 计分
    private int count = 0, count1 = 0;
    // 比大小的切换
    private int flag = 1;
    // 玩家的牌和机器的牌
    private List<Pair<String, Integer>> robotCards, playerCards;
    @FXML
    // 切换大小的按钮
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
            // 每次循环新建一个按钮，将按钮绑定在gridpane里的每个格子里
            Button btn = new Button("", img);
            //gridpane.add(new Button(), 2, 1)// 第几行第几列
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
        // 比大
        if (flag == 1) {
            if (sum > sum1) {
                score1.setText("score: ");
                setResult("player得分为:  " + sum + "  robot得分为: " + sum1 + " player win !");
                count++;
                score1.setText(score1.getText() + count);
                System.out.println("player win");
            } else {
                score2.setText("score: ");
                setResult(" player得分为: " + sum + " robot得分为: " + sum1 + " robot win zzz");
                count1++;
                score2.setText(score2.getText() + count1);
                System.out.println("robot win!");
            }
        } else {
            if (sum > sum1) {
                score2.setText("score: ");
                setResult(" player得分为: " + sum + " robot得分为: " + sum1 + " robot win zzz");
                count1++;
                score2.setText(score2.getText() + count1);
                System.out.println("robot win!");
            } else {
                score1.setText("score: ");
                setResult("player得分为:  " + sum + "  robot得分为: " + sum1 + " player win !");
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
            change.setText("比大");
        } else {
            change.setText("比小");
        }
        System.out.println(flag);
    }

    public void whoWin() {
        if (count1 >= 5 || count >= 5) {
            result.setText("");
            if (count > count1) {
                result.setText("player finally win!!!!");
            } else result.setText("you lose！");
            playerCards.clear();
            robotCards.clear();

        }
    }
}
