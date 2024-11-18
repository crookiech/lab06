#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "GraphicPrimitive.h"

int id_document = 1;

/// @brief класс, представляющий документ
class Document {
private:
    const int id; // id документа
    std::string nameDocument; // название документа
    std::string pathDocument; // путь до документа
    std::vector<std::shared_ptr<GraphicPrimitive>> graphicPrimitives; // набор графических примитивов в документе
public:
    /// @brief конструктор по умолчанию
    Document() : nameDocument(""), pathDocument(""), id(id_document++) {
        std::cout << "Создан пустой документ; ID: " << id << std::endl;
    }
    /// @brief конструктор с параметрами
    /// @param nameDocument название документа
    /// @param pathDocument путь до документа
    Document(const std::string nameDocument, const std::string pathDocument) : nameDocument(nameDocument), pathDocument(pathDocument), id(id_document++) {
        std::cout << "Создан документ: \"" << nameDocument << "\"; путь до документа: " << pathDocument << "; ID: " << id << std::endl;
    }
    /// @brief гетер названия документа
    /// @return название документа
    const std::string getNameDocument() {
        std::cout << "Название документа: \"" << nameDocument << "\" (ID: " << id << ")" << std::endl;
        return nameDocument;
    }
    /// @brief гетер id
    /// @return id
    const int getId() {
        std::cout << "ID документа: \"" << nameDocument << "\" "<< id << std::endl;
        return id;
    }
    /// @brief гетер пути документа
    /// @return путь документа
    const std::string getPathDocument() {
        std::cout << "Путь до документа \"" << nameDocument << "\": " << pathDocument << " (ID: " << id << ")" << std::endl;
        return pathDocument;
    }
    /// @brief сетер названия документа
    /// @param name название документа
    void setName(const std::string& name) {
        nameDocument = name;
        std::cout << "Установлено название документа: \"" << nameDocument << "\" (ID: " << id << ")" << std::endl;
    }
    /// @brief сетер пути документа
    /// @param path путь документа
    void setPath(const std::string& path) {
        pathDocument = path;
        std::cout << "Установлен путь до документа \"" << nameDocument << "\": " << pathDocument << " (ID: " << id << ")" << std::endl;
    }
    /// @brief импорт документа из файла
    /// @param path путь файла
    void importDocument(const std::string& path) {
        if (pathDocument == path) {
            std::cout << "Документ \"" << nameDocument << "\" импортирован из файла: " << path << " (ID: " << id << ")" << std::endl;
        } else {
            std::cout << "Документа \"" << nameDocument << "\" нет в файле: " << path << " (ID: " << id << ")" << std::endl;
        }
        
    }
    /// @brief экспорт документа в файл
    /// @param path путь файла
    void exportDocument(const std::string& path) {
        pathDocument = path;
        std::cout << "Документ \"" << nameDocument << "\" экспортирован в файл: " << path << " (ID: " << id << ")" << std::endl;
    }
    /// @brief добавление примитива
    /// @param figure примитив
    void addGraphicPrimitive(std::shared_ptr<GraphicPrimitive> figure) {
        graphicPrimitives.push_back(figure);
        std::cout << "В документ \"" << nameDocument << "\" (ID: " << id << ") добавлен графический примитив: " << figure->getFigureName() << " (ID: " << figure->getId() << ")" << std::endl;
    }
    /// @brief удаление примитива
    /// @param figure примитив
    void deleteGraphicPrimitive(std::shared_ptr<GraphicPrimitive> figure) {
        bool found = false; // нашелся ли примитив в документе
        for (auto it = graphicPrimitives.end(); it != graphicPrimitives.begin();) { // итерация по вектору
            --it;
            if ((*it)->getFigureName() == figure->getFigureName()) { // если имена совпадают примитивов
                found = true; // примитив нашелся
                graphicPrimitives.erase(it); // удаляем элемент
                std::cout << "Из документа \"" << nameDocument << "\" (ID: " << id << ") удален графический примитив: " << figure->getFigureName() << " (ID: " << figure->getId() << ")" << std::endl;
            }
        }
        if (!found) { // примитив не нашелся
            std::cout << "Графический примитив \"" << figure->getFigureName()  << "\" (ID: " << figure->getId() << ") не найден в документе \"" << nameDocument << "\" (ID: " << id << ")" << std::endl;
        }
    }
    /// @brief деструктор
    ~Document () {
        std::cout << "Удален документ \"" << nameDocument << "\" (ID: " << id << ")"<< std :: endl ;
    }
};