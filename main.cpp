#include <iostream>

#include "Figure.h"

int main() {
    srandom(time(nullptr));

    for (int i = 0; i < 10; i++) {
        Figure figure;

        std::cout << figure.getAsCSVEntry() << std::endl;
    }


    return 0;
}
