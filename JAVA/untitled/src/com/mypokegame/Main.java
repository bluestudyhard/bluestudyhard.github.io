package com.mypokegame;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

import java.awt.*;


public class Main extends Application {
    //psvm
    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("blue'spokegame");
        Label label = new Label("Blue!");
        stage.getIcons().add(new Image("img/mimi.jpg"));
        FXMLLoader fx = new FXMLLoader(getClass().getResource("main.fxml"));
        /*场景们*/
        Scene fxmlscene = new Scene(fx.load());
        stage.setScene(fxmlscene);
        stage.getScene();
        stage.show();
    }
}
//    @Override
//    public void init() throws Exception {
//        super.init();
//        System.out.println("begin");
//
//    }
//    public void stop() throws Exception {
//        super.stop();
//        System.out.println("end");
//
//    }