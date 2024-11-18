#include "GraphicPrimitive.h"
#include "Document.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Создание документа: " << std::endl;
    Document document;
    document.setName("мой документ");
    document.setPath("C:\\programming");
    std::cout << std::endl;

    std::cout << "Создание графических примитивов: " << std::endl;
    auto circle = std::make_shared<Circle>(3);
    auto rectangle = std::make_shared<Rectangle>(4, 5);
    auto square = std::make_shared<Square>(6);
    std::cout << std::endl;

    std::cout << "Проверка параметров графических примитивов: " << std::endl;
    circle->getFigureName();
    circle->getRadius();
    rectangle->getLength();
    rectangle->getWidth();
    square->getLength();
    square->getWidth();
    square->setLength(1);
    std::cout << std::endl;

    std::cout << "Добавление и удаление графических примитивов в документе: " << std::endl;
    document.addGraphicPrimitive(circle);
    document.addGraphicPrimitive(rectangle);
    document.deleteGraphicPrimitive(rectangle);
    document.deleteGraphicPrimitive(square);
    std::cout << std::endl;

    std::cout << "Импортирование и экспортирование документа: " << std::endl;
    document.importDocument("C:\\programming");
    document.exportDocument("C:");
    document.importDocument("C:\\programming");
    std::cout << std::endl;

    std::cout << "Вызов деструкторов:" << std::endl;
    return 0;
}