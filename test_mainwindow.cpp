#include <QtTest/QtTest>
#include <QInputDialog>
#include "mainwindow.h"

class TestMainWindow : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testAddCar();
    void testEditCar();
    void testRemoveCar();

private:
    MainWindow *window;
};

void TestMainWindow::initTestCase()
{
    window = new MainWindow();
}

void TestMainWindow::cleanupTestCase()
{
    delete window;
}

void TestMainWindow::testAddCar()
{
    // Arrange
    QString carDetails = "Test Car";
    window->getCarInput()->setText(carDetails);

    // Act
    QTest::mouseClick(window->getAddButton(), Qt::LeftButton);

    // Assert
    QList<QListWidgetItem *> items = window->getCarListWidget()->findItems(carDetails, Qt::MatchExactly);
    QCOMPARE(items.size(), 1);
    QCOMPARE(items[0]->text(), carDetails);
}

void TestMainWindow::testEditCar()
{
    // Arrange
    QString initialDetails = "Initial Car";
    window->getCarInput()->setText(initialDetails);
    window->callAddCar();

    QListWidgetItem *item = window->getCarListWidget()->item(0);
    window->getCarListWidget()->setCurrentItem(item);
    QString editedDetails = "Edited Car";

    // Act
    QSignalSpy spy(window->getEditButton(), &QPushButton::clicked);
    QTest::mouseClick(window->getEditButton(), Qt::LeftButton);

    // Assert
    QCOMPARE(spy.count(), 1);
    QCOMPARE(item->text(), editedDetails);
}

void TestMainWindow::testRemoveCar()
{
    // Arrange
    QString carDetails = "Remove Car";
    window->getCarInput()->setText(carDetails);
    window->callAddCar();

    QListWidgetItem *item = window->getCarListWidget()->item(0);
    window->getCarListWidget()->setCurrentItem(item);

    // Act
    QSignalSpy spy(window->getRemoveButton(), &QPushButton::clicked);
    QTest::mouseClick(window->getRemoveButton(), Qt::LeftButton);

    // Assert
    QCOMPARE(spy.count(), 1);
    QList<QListWidgetItem *> items = window->getCarListWidget()->findItems(carDetails, Qt::MatchExactly);
    QCOMPARE(items.size(), 0);
}

QTEST_MAIN(TestMainWindow)
#include "test_mainwindow.moc"
