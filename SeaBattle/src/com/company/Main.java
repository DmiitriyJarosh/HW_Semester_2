package com.company;

public class Main {
    public static void main(String[] args) {
        GameServer server = new GameServer();
        RandomBotPlayer firstPlayer = new RandomBotPlayer();
        CleverBotPlayer secondPlayer = new CleverBotPlayer();
        server.Game(firstPlayer, secondPlayer, 0);  //type of output means whose field will not be shown
    }
}
