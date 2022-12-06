package com.t3;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        FXMLLoader fxml = new FXMLLoader(getClass().getResource("Main.fxml"));
        Scene scene = new Scene(fxml.load());
        stage.setResizable(false);
        stage.setTitle("blue");
        stage.setScene(scene);
        stage.show();
    }
}
