#include "architecture.cpp"

int main() {
    // Создание документа
    Document doc("Мой документ", "/path/to/document");

    // Создание графических примитивов
    Circle circle1(5.0);
    Rectangle rectangle1(10.0, 5.0);
    Square square1(4.0);

    // // Добавление графических примитивов в документ
    // doc.addGraphicPrimitive(circle1);
    // doc.addGraphicPrimitive(rectangle1);
    // doc.addGraphicPrimitive(square1);

    // Проверка свойств графических примитивов
    circle1.getRadius();
    rectangle1.getLength();
    rectangle1.getWidth();
    square1.getLength();

    // Изменение свойств графических примитивов
    circle1.setRadius(7.0);
    rectangle1.setLength(12.0);
    rectangle1.setWidth(6.0);
    square1.setLength(5.0);

    // // Удаление графического примитива
    // doc.deleteGraphicPrimitive(circle1);
    
    // Попытка удалить несуществующий примитив
    auto circle2 = std::make_shared<Circle>(3.0); // Новый круг с другим ID
    doc.deleteGraphicPrimitive(circle2);

    // Экспорт и импорт документа
    doc.exportDoc("/path/to/exported/document");
    doc.importDoc("/path/to/imported/document");

    return 0;
}