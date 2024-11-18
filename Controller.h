#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Document.h"

class Controller {
private:
    std::shared_ptr<Document> currentDocument; // текущий документ
public:
    /// @brief Конструктор по умолчанию
    Controller() : currentDocument(nullptr) {}
    /// @brief Создать новый документ
    void createDocument(const std::string& name, const std::string& path) {
        currentDocument = std::make_shared<Document>(name, path);
    }
    /// @brief Импортировать документ из файла
    void importDocument(const std::string& path) {
        if (currentDocument) {
            currentDocument->importDocument(path);
        } else {
            std::cout << "Нет текущего документа для импорта" << std::endl;
        }
    }
    /// @brief Экспортировать текущий документ в файл
    void exportDocument(const std::string& path) {
        if (currentDocument) {
            currentDocument->exportDocument(path);
        } else {
            std::cout << "Нет текущего документа для экспорта" << std::endl;
        }
    }
    /// @brief Установить текущий документ
    void setCurrentDocument(const std::shared_ptr<Document>& document) {
        currentDocument = document;
    }
    /// @brief Добавить графический примитив в документ
    void addGraphicPrimitive(const std::string& type, double param1 = 0, double param2 = 0) {
        if (!currentDocument) {
            std::cout << "Нет текущего документа. Сначала создайте или выберите документ." << std::endl;
            return;
        }
        std::shared_ptr<GraphicPrimitive> primitive;
        if (type == "круг") {
            primitive = std::make_shared<Circle>(param1);
        } else if (type == "прямоугольник") {
            primitive = std::make_shared<Rectangle>(param1, param2);
        } else if (type == "квадрат") {
            primitive = std::make_shared<Square>(param1);
        } else {
            std::cout << "Неизвестный тип графического примитива: " << type << std::endl;
            return;
        }
        currentDocument->addGraphicPrimitive(primitive);
    }
    /// @brief Удалить графический примитив из документа
    void deleteGraphicPrimitive(const std::string& type) {
        if (!currentDocument) {
            std::cout << "Нет текущего документа. Сначала создайте или выберите документ" << std::endl;
            return;
        }
        auto primitiveToDelete = std::make_shared<GraphicPrimitive>(type);
        currentDocument->deleteGraphicPrimitive(primitiveToDelete);
    }
    /// @brief Показать информацию о текущем документе
    void showCurrentDocumentInfo() const {
        if (currentDocument) {
            std::cout << "Информация о текущем документе:" << std::endl;
            currentDocument->getNameDocument();
            currentDocument->getId();
            currentDocument->getPathDocument();
        } else {
            std::cout << "Нет текущего документа" << std::endl;
        }
    }
};