//
// Created by Timur Iakhshigulov on 18.09.2024.
//

#include "Figure.h"
#include <iostream>

namespace Generators {
    [[nodiscard]] int rrand() {
        return static_cast<int>(random() % INT_MAX);
    }

    FigureMap generateCircle() {
        FigureMap result;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; ++j) {
                result[i][j] = false;
            }
        }

        const int oX = rrand() % 3 + 2; // value from 2 to 4
        const int oY = rrand() % 3 + 2; // value from 2 to 4
        int radius;
        if (oX == 3 && oY == 3) {
            radius = rrand() % 2 + 2;
        } else {
            radius = 2;
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                double value = sqrt(pow(oX - i, 2) + pow(oY - j, 2));
                if (radius - 0.5 < value && value <= radius + 0.5) {
                    result[i][j] = true;
                }
            }
        }

        return result;
    };

    FigureMap generateSquare() {
        FigureMap result;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; ++j) {
                result[i][j] = false;
            }
        }

        // left up angle coordinates
        const int luX = rrand() % 5; // value from 0 to 4
        const int luY = rrand() % 5; // value from 0 to 4
        int maxSideLength;

        maxSideLength = std::min(SIZE - luX, SIZE - luY); // from 3 to 7
        int sideLength = rrand() % (maxSideLength - 2) + 2; // from 3 to 7

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if ((i == luX || i - sideLength == luX) && luY <= j && j <= luY + sideLength) {
                    result[i][j] = true;
                }

                if ((j == luY || j - sideLength == luY) && luX <= i && i <= luX + sideLength) {
                    result[i][j] = true;
                }
            }
        }

        return result;
    };
}
