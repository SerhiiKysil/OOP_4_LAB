#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlError>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    connectDatabase();
    loadData();
}

MainWindow::~MainWindow()
{
    db.close();
}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    carListWidget = new QListWidget(this);
    layout->addWidget(carListWidget);

    carInput = new QLineEdit(this);
    carInput->setPlaceholderText("Введіть дані про автомобіль");
    layout->addWidget(carInput);

    searchInput = new QLineEdit(this);
    searchInput->setPlaceholderText("Пошук автомобіля");
    layout->addWidget(searchInput);

    addButton = new QPushButton("Додати автомобіль", this);
    layout->addWidget(addButton);

    editButton = new QPushButton("Редагувати автомобіль", this);
    layout->addWidget(editButton);

    removeButton = new QPushButton("Видалити автомобіль", this);
    layout->addWidget(removeButton);

    searchButton = new QPushButton("Пошук", this);
    layout->addWidget(searchButton);

    filterButton = new QPushButton("Фільтрувати", this);
    layout->addWidget(filterButton);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addCar);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::editCar);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeCar);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::searchCar);
    connect(filterButton, &QPushButton::clicked, this, &MainWindow::filterCars);

    setCentralWidget(centralWidget);
    setWindowTitle("Автосервіс");
    resize(400, 400);
}

void MainWindow::connectDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("autoshop.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося відкрити базу даних");
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS cars (id INTEGER PRIMARY KEY AUTOINCREMENT, details TEXT)");
    }
}

void MainWindow::loadData()
{
    loadFromDatabase();
}

void MainWindow::loadFromDatabase()
{
    QSqlQuery query("SELECT * FROM cars");
    carListWidget->clear();
    while (query.next()) {
        int id = query.value(0).toInt();
        QString details = query.value(1).toString();
        QListWidgetItem *item = new QListWidgetItem(details, carListWidget);
        item->setData(Qt::UserRole, id);
    }
}

void MainWindow::saveToDatabase(const QString &carDetails)
{
    QSqlQuery query;
    query.prepare("INSERT INTO cars (details) VALUES (:details)");
    query.bindValue(":details", carDetails);
    query.exec();
}

void MainWindow::updateDatabase(int id, const QString &carDetails)
{
    QSqlQuery query;
    query.prepare("UPDATE cars SET details = :details WHERE id = :id");
    query.bindValue(":details", carDetails);
    query.bindValue(":id", id);
    query.exec();
}

void MainWindow::removeFromDatabase(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM cars WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
}

void MainWindow::addCar()
{
    QString carDetails = carInput->text();
    if (!carDetails.isEmpty()) {
        saveToDatabase(carDetails);
        loadFromDatabase();
        carInput->clear();
    }
}

void MainWindow::editCar()
{
    QListWidgetItem *currentItem = carListWidget->currentItem();
    if (currentItem) {
        bool ok;
        QString text = QInputDialog::getText(this, tr("Редагувати автомобіль"),
                                             tr("Дані автомобіля:"), QLineEdit::Normal,
                                             currentItem->text(), &ok);
        if (ok && !text.isEmpty()) {
            int id = currentItem->data(Qt::UserRole).toInt();
            updateDatabase(id, text);
            currentItem->setText(text);
        }
    } else {
        QMessageBox::warning(this, tr("Увага"), tr("Виберіть автомобіль для редагування"));
    }
}

void MainWindow::removeCar()
{
    QListWidgetItem *currentItem = carListWidget->currentItem();
    if (currentItem) {
        int id = currentItem->data(Qt::UserRole).toInt();
        removeFromDatabase(id);
        delete currentItem;
    } else {
        QMessageBox::warning(this, tr("Увага"), tr("Виберіть автомобіль для видалення"));
    }
}

void MainWindow::searchCar()
{
    QString searchText = searchInput->text();
    if (!searchText.isEmpty()) {
        for (int i = 0; i < carListWidget->count(); ++i) {
            QListWidgetItem *item = carListWidget->item(i);
            if (item->text().contains(searchText, Qt::CaseInsensitive)) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    }
}

void MainWindow::filterCars()
{
    QString filterText = carInput->text();
    if (!filterText.isEmpty()) {
        for (int i = 0; i < carListWidget->count(); ++i) {
            QListWidgetItem *item = carListWidget->item(i);
            if (item->text().contains(filterText, Qt::CaseInsensitive)) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    } else {
        for (int i = 0; i < carListWidget->count(); ++i) {
            carListWidget->item(i)->setHidden(false);
        }
    }
}
