#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

int id_graphic = 1;
int id_document = 1;

class GraphicPrimitive {
private:
    const int id;
    std::string figureName;
public:
    GraphicPrimitive() : id(id_graphic++) {}
    GraphicPrimitive(const std::string name) : figureName(name), id(id_graphic++) {}
    const int getId() const {
        return id;
    }
    const std::string getFigureName() const {
        return figureName;
    }
    ~GraphicPrimitive() {
        std::cout << "Удален графический примитив \"" << figureName << "\" (ID: " << id << ")"<< std :: endl ;
    }
};

class Document {
private:
    const int id;
    std::string nameDocument;
    std::string pathDocument;
    std::vector<std::shared_ptr<GraphicPrimitive>> graphicPrimitives;
public:
    Document() : nameDocument(""), pathDocument(""), id(id_document++) {
        std::cout << "Создан пустой документ; ID: " << id << std::endl;
    }
    Document(const std::string nameDocument, const std::string pathDocument) : nameDocument(nameDocument), pathDocument(pathDocument), id(id_document++) {
        std::cout << "Создан документ: \"" << nameDocument << "\"; путь до документа: " << pathDocument << "; ID: " << id << std::endl;
    }
    const std::string getNameDocument() {
        std::cout << "Название документа: \"" << nameDocument << "\" (ID: " << id << ")" << std::endl;
        return nameDocument;
    }
    const std::string getPathDocument() {
        std::cout << "Путь до документа \"" << nameDocument << "\": " << pathDocument << " (ID: " << id << ")" << std::endl;
        return pathDocument;
    }
    void setName(const std::string& name) {
        nameDocument = name;
        std::cout << "Установлено название документа: \"" << nameDocument << "\" (ID: " << id << ")" << std::endl;
    }
    void setPath(const std::string& path) {
        pathDocument = path;
        std::cout << "Установлен путь до документа \"" << nameDocument << "\": " << pathDocument << " (ID: " << id << ")" << std::endl;
    }
    void importDoc(const std::string& path) {
        std::cout << "Документ \"" << nameDocument << "\" импортирован из файла: " << path << " (ID: " << id << ")" << std::endl;
    }
    void exportDoc(const std::string& path) {
        std::cout << "Документ \"" << nameDocument << "\" экспортирован в файл: " << path << " (ID: " << id << ")" << std::endl;
    }
    void addGraphicPrimitive(std::shared_ptr<GraphicPrimitive> figure) {
        graphicPrimitives.push_back(figure);
        std::cout << "В документ \"" << nameDocument << "\" (ID: " << id << ") добавлен графический примитив: " << figure->getFigureName() << " (ID: " << figure->getId() << ")" << std::endl;
    }
    void deleteGraphicPrimitive(std::shared_ptr<GraphicPrimitive> figure) {
        bool found = false;
        for (auto it = graphicPrimitives.end(); it != graphicPrimitives.begin();) {
            --it; // Двигаемся к предыдущему элементу
            if ((*it)->getFigureName() == figure->getFigureName()) {
                graphicPrimitives.erase(it); // Удаляем элемент
                found = true; // Устанавливаем флаг, что элемент найден
                std::cout << "Из документа \"" << nameDocument << "\" (ID: " << id << ") удален графический примитив: " << figure->getFigureName() << " (ID: " << figure->getId() << ")" << std::endl;
            }
        }
        if (!found) {
            std::cout << "Графический примитив \"" << figure->getFigureName()  << "\" (ID: " << figure->getId() << ") не найден в документе \"" << nameDocument << "\" (ID: " << id << ")" << std::endl;
        }
    }
    ~Document () {
        std::cout << "Удален документ \"" << nameDocument << "\" (ID: " << id << ")"<< std :: endl ;
    }
};

class Circle : public GraphicPrimitive {
private:
    double radius;
public:
    Circle() {
        std::cout << "Создан графический примитив \"круг\"" << "; ID: " << getId() << std :: endl ;
    }
    Circle(const double& radius) : GraphicPrimitive("круг"), radius(radius) {
        std::cout << "Создан графический примитив \"круг\" с радиусом " << radius <<"; ID: " << getId() << std :: endl ;
    }
    void setRadius(const double& r) {
        radius = r;
        std::cout << "Установлен радиус круга: " << radius << " (ID: " << getId() << ")"<< std :: endl ;
    }
    const double getRadius() {
        std::cout << "Радиус круга: " << radius << " (ID: " << getId() << ")"<< std :: endl ;
        return radius;
    }
};

class Rectangle : public GraphicPrimitive {
private:
    double length;
    double width;
public:
    Rectangle() {
        std::cout << "Создан графический примитив \"прямоугольник\"" << " ; ID: " << getId() << std :: endl ;
    }
    Rectangle(const double& length, const double& width) : GraphicPrimitive("прямоугольник"), length(length), width(width) {
        std::cout << "Создан графический примитив \"прямоугольник\" с длиной " << length << " и шириной " << width << "; ID: " << getId() << std :: endl ;
    }
    const double getLength() {
        std::cout << "Длина прямоугольника: " << length << " (ID: " << getId() << ")"<< std :: endl ;
        return length;
    }
    const double getWidth() {
        std::cout << "Ширина прямоугольника: " << width << " (ID: " << getId() << ")"<< std :: endl ;
        return width;
    }
    void setLength(const double& l) {
        length = l;
        std::cout << "Установлена длина прямоугольника: " << length << " (ID: " << getId() << ")"<< std :: endl ;
    }
    void setWidth(const double& w) {
        width = w;
        std::cout << "Установлена ширина прямоугольника: " << width << " (ID: " << getId() << ")"<< std :: endl ;
    }
};

class Square : public Rectangle {
private:
    double length;
public:
    Square() : Rectangle() {}
    Square(const double& length) : Rectangle(length, length) {}
    const double getLength() {
        return Rectangle::getLength();
    }
};