#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Геттери для доступу до приватних членів
    QLineEdit* getCarInput() const { return carInput; }
    QPushButton* getAddButton() const { return addButton; }
    QPushButton* getEditButton() const { return editButton; }
    QPushButton* getRemoveButton() const { return removeButton; }
    QListWidget* getCarListWidget() const { return carListWidget; }
    QLineEdit* getSearchInput() const { return searchInput; }
    QPushButton* getSearchButton() const { return searchButton; }
    QPushButton* getFilterButton() const { return filterButton; }

    // Геттери для методів
    void callAddCar() { addCar(); }
    void callEditCar() { editCar(); }
    void callRemoveCar() { removeCar(); }
    void callSearchCar() { searchCar(); }
    void callFilterCars() { filterCars(); }

private slots:
    void addCar();
    void editCar();
    void removeCar();
    void searchCar();
    void filterCars();
    void loadData();

private:
    void setupUI();
    void connectDatabase();
    void loadFromDatabase();
    void saveToDatabase(const QString &carDetails);
    void updateDatabase(int id, const QString &carDetails);
    void removeFromDatabase(int id);

    QListWidget *carListWidget;
    QLineEdit *carInput;
    QLineEdit *searchInput;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *searchButton;
    QPushButton *filterButton;

    QSqlDatabase db;
};

#endif // MAINWINDOW_H
