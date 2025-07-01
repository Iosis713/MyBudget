#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

    QLabel label("Hello in the MyBudget app!");
    label.show();
    
    return app.exec();
}