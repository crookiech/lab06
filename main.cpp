#include "GraphicPrimitive.h"
#include "Controller.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Controller controller;

    std::cout << "Создание нового документа: " << std::endl;
    controller.createDocument("Мой документ", "/path/to/document");
    std::cout << std::endl;

    std::cout << "Добавление графических примитивов: " << std::endl;
    controller.addGraphicPrimitive("круг", 5.0); // добавляем круг с радиусом 5.0
    controller.addGraphicPrimitive("прямоугольник", 10.0, 20.0); // добавляем прямоугольник 10x20
    controller.addGraphicPrimitive("квадрат", 15.0); // добавляем квадрат со стороной 15.0
    std::cout << std::endl;

    std::cout << "Показать информацию о текущем документе: " << std::endl;
    controller.showCurrentDocumentInfo();
    std::cout << std::endl;

    std::cout << "Экспорт документа в файл: " << std::endl;
    controller.exportDocument("/path/to/exported_document");
    std::cout << std::endl;

    std::cout << "Импорт документа из файла: " << std::endl;
    controller.importDocument("/path/to/document");
    std::cout << std::endl;

    std::cout << "Удаление графического примитива: " << std::endl;
    controller.deleteGraphicPrimitive("круг");
    std::cout << std::endl;

    std::cout << "Вызов деструкторов после завершения программы: " << std::endl;
    return 0;
}