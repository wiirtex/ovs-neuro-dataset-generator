//
// Created by Timur Yakhshigulov on 18.09.2024.
//
#include "Figure.h"

#include <map>
#include <string>
#include <iostream>

#include "generators.h"

std::map<Type, std::string> FigureTypeToStr = {
    std::pair{Circle, "circle"},
    std::pair{Square, "square"},
    std::pair{Triangle, "triangle"},
};

Figure::Figure() {
    Type type;
    if (random() % 2) {
        type =Square;
    } else {
        type = Circle;
    }
    *this = Figure(type);
};

Figure::Figure(Type type)
    : type(type) {
    switch (type) {
        case Circle:
            this->figure = Generators::generateCircle();
            break;
        case Square:
            this->figure = Generators::generateSquare();
            break;
        default:
            throw std::invalid_argument("type is not expected");
    }
}

[[nodiscard]] std::string Figure::getType() const {
    return FigureTypeToStr[type];
}

[[nodiscard]] std::string Figure::getFigure() const {
    std::string res;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; ++j) {
            if (this->figure[i][j]) {
                res += "x";
            } else {
                res += "-";
            }
        }
        res += "\n";
    }

    return res;
}

[[nodiscard]] std::string Figure::getAsCSVEntry() const {
    std::string res = this->getType() + ",";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; ++j) {
            if (this->figure[i][j]) {
                res += "1";
            } else {
                res += "0";
            }
        }
    }

    return res + ";";
}


std::ostream &operator<< (std::ostream &os, const Figure &f) {
    os << f.getType() << std::string("\n") << f.getFigure();
    return os;
}
