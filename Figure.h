//
// Created by Timur Yakhshigulov on 18.09.2024.
//

#ifndef FIGURE_H
#define FIGURE_H
#include <array>

constexpr int SIZE = 7;

typedef std::array<std::array<bool, SIZE>, SIZE> FigureMap;

enum Type {
    Circle,
    Square,
    Triangle,
};

class Figure {
public:
    explicit Figure();

    explicit Figure(Type type);

    [[nodiscard]] std::string getType() const;

    [[nodiscard]] std::string getFigure() const;

    [[nodiscard]] std::string getAsCSVEntry() const;

private:
    Type type;
    FigureMap figure;
};

std::ostream &operator<<(std::ostream &os, const Figure &f);

#endif //FIGURE_H
