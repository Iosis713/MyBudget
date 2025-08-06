#include <QApplication>
#include <QLabel>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label("Hello in the MyBudget app!");
    label.show();

    std::cout << "someting\n";

    return app.exec();
}