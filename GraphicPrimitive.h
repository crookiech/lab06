#pragma once
#include <iostream>
#include <string>

int id_graphic = 1;

/// @brief класс, представляющий графический примитив
class GraphicPrimitive {
private:
    const int id; // id графического примитива
    std::string figureName; // название примитива
public:
    /// @brief конструктор по умолчанию
    GraphicPrimitive() : id(id_graphic++) {}
    /// @brief конструктор с параметрами
    /// @param name название примитива
    GraphicPrimitive(const std::string name) : figureName(name), id(id_graphic++) {}
    /// @brief гетер id
    /// @return id
    const int getId() const {
        return id;
    }
    /// @brief гетер названия примитива
    /// @return название примитива
    const std::string getFigureName() const {
        return figureName;
    }
    /// @brief деструктор
    ~GraphicPrimitive() {
        std::cout << "Удален графический примитив \"" << figureName << "\" (ID: " << id << ")"<< std :: endl ;
    }
};

/// @brief класс графического примитива "круг"
class Circle : public GraphicPrimitive {
private:
    double radius; // радиус круга
public:
    /// @brief конструктор по умолчанию
    Circle() {
        std::cout << "Создан графический примитив \"круг\"" << "; ID: " << getId() << std :: endl ;
    }
    /// @brief конструктор с параметрами
    /// @param radius радиус
    Circle(const double& radius) : GraphicPrimitive("круг"), radius(radius) {
        std::cout << "Создан графический примитив \"круг\" с радиусом " << radius <<"; ID: " << getId() << std :: endl ;
    }
    /// @brief сетер радиуса
    /// @param r радиус
    void setRadius(const double& r) {
        radius = r;
        std::cout << "Установлен радиус круга: " << radius << " (ID: " << getId() << ")"<< std :: endl ;
    }
    /// @brief гетер радиуса
    /// @return радиус
    const double getRadius() {
        std::cout << "Радиус круга: " << radius << " (ID: " << getId() << ")"<< std :: endl ;
        return radius;
    }
};

/// @brief класс графического примитива "прямоугольник"
class Rectangle : public GraphicPrimitive {
private:
    double length; // длина прямоугольника
    double width; // ширина прямоугольника
public:
    /// @brief конструктор по умолчанию
    Rectangle() {
        std::cout << "Создан графический примитив \"прямоугольник\"" << " ; ID: " << getId() << std :: endl ;
    }
    /// @brief конструктор с параметрами
    /// @param length длина
    /// @param width ширина
    Rectangle(const double& length, const double& width) : GraphicPrimitive("прямоугольник"), length(length), width(width) {
        std::cout << "Создан графический примитив \"прямоугольник\" с длиной " << length << " и шириной " << width << "; ID: " << getId() << std :: endl ;
    }
    /// @brief гетер длины
    /// @return длина
    const double getLength() {
        std::cout << "Длина прямоугольника: " << length << " (ID: " << getId() << ")"<< std :: endl ;
        return length;
    }
    /// @brief гетер ширины
    /// @return ширина
    const double getWidth() {
        std::cout << "Ширина прямоугольника: " << width << " (ID: " << getId() << ")"<< std :: endl ;
        return width;
    }
    /// @brief сетер длины
    /// @param l длина
    void setLength(const double& l) {
        length = l;
        std::cout << "Установлена длина прямоугольника: " << length << " (ID: " << getId() << ")"<< std :: endl ;
    }
    /// @brief сетер ширины
    /// @param w ширина
    void setWidth(const double& w) {
        width = w;
        std::cout << "Установлена ширина прямоугольника: " << width << " (ID: " << getId() << ")"<< std :: endl ;
    }
};

/// @brief класс прямоугольника с равными сторонами (квадрат)
class Square : public Rectangle {
private:
    double length; // сторона квадрата
public:
    /// @brief конструктор по умолчанию
    Square() : Rectangle() {}
    /// @brief конструктор с параметрами
    /// @param length сторона квадрата
    Square(const double& length) : Rectangle(length, length) {}
    /// @brief гетер стороны квадрата
    /// @return сторона квадрата
    const double getLength() {
        return Rectangle::getLength();
    }
    /// @brief сетер стороны квадрата
    /// @param l сторона квадрата
    void setLength(const double& l) {
        Rectangle::setLength(l);
        Rectangle::setWidth(l);
    }
};