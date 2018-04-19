package com.company;

import static java.lang.Math.random;

public class RandomBotPlayer extends Player implements IPlayer {
    RandomBotPlayer() {
        enemyField = new byte[SIZE_OF_FIELD][SIZE_OF_FIELD];
        yourField = new byte[SIZE_OF_FIELD][SIZE_OF_FIELD];
    }

    public boolean[][] GetShips() {
        boolean[][] field = new boolean[SIZE_OF_FIELD][SIZE_OF_FIELD];
        for (int i = 0; i < SIZE_OF_FIELD; i++) {
            for (int j = 0; j < SIZE_OF_FIELD; j++) {
                field[i][j] = false;
            }
        }
        byte[] tailPosition, nosePosition, tmp;
        nosePosition = new byte[2];
        int tmp1;
        boolean flag, mistakeFlag;
        tailPosition = new byte[2];
        for (int j = MAX_SHIP_SIZE; j > 0; j--) {   //go throw all types of ships
            for (int k = MAX_SHIP_SIZE + 1 - j; k > 0; k--) { // read enough numbers of this type of ship
                mistakeFlag = true;
                while (mistakeFlag) {
                    mistakeFlag = false;
                    nosePosition[0] = (byte) (random() * SIZE_OF_FIELD);
                    nosePosition[1] = (byte) (random() * SIZE_OF_FIELD);
                    tmp1 = (int) (random() * 2);
                    if (tmp1 == 0) {
                        tailPosition[0] = nosePosition[0];
                        if (checkRange(nosePosition[1] + j - 1)) {
                            tailPosition[1] = (byte) (nosePosition[1] + j - 1);
                        } else {
                            tailPosition[1] = (byte) (nosePosition[1] - j + 1);
                        }
                        if (nosePosition[1] > tailPosition[1]) {
                            tmp = nosePosition;
                            nosePosition = tailPosition;
                            tailPosition = tmp;
                        }
                        for (byte i = nosePosition[1]; i <= tailPosition[1]; i++) {
                            flag = checkPoint(nosePosition[0], i, field); //check if other ship too close
                            if (!flag) {
                                mistakeFlag = true;
                                break;
                            }
                        }
                        if (!mistakeFlag) {
                            for (byte i = nosePosition[1]; i <= tailPosition[1]; i++) {
                                field[nosePosition[0]][i] = true;
                                yourField[nosePosition[0]][i] = 3;
                            }
                        }
                    } else {
                        tailPosition[1] = nosePosition[1];
                        if (checkRange(nosePosition[0] + j - 1)) {
                            tailPosition[0] = (byte) (nosePosition[0] + j - 1);
                        } else {
                            tailPosition[0] = (byte) (nosePosition[0] - j + 1);
                        }
                        if (nosePosition[0] > tailPosition[0]) {
                            tmp = nosePosition;
                            nosePosition = tailPosition;
                            tailPosition = tmp;
                        }
                        for (byte i = nosePosition[0]; i <= tailPosition[0]; i++) {
                            flag = checkPoint(i, nosePosition[1], field); //check if other ship too close
                            if (!flag) {
                                mistakeFlag = true;
                                break;
                            }
                        }
                        if (!mistakeFlag) {
                            for (byte i = nosePosition[0]; i <= tailPosition[0]; i++) {
                                field[i][nosePosition[1]] = true;
                                yourField[i][nosePosition[1]] = 3;
                            }
                        }
                    }
                }
            }
        }
        return field;
    }

    public byte[] Shoot() {
        byte[] position = {0, 0};
        boolean flag = false;
        while (!flag) {
            position[0] = (byte)(random() * SIZE_OF_FIELD);
            position[1] = (byte)(random() * SIZE_OF_FIELD);
            if (enemyField[position[0]][position[1]] == 0) {
                flag = true;
            }
        }
        return position;
    }
}
