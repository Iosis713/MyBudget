#include <QApplication>
#include <QLabel>
#include <iostream>

class Foo
{
  public:
    void bar() { std::cout << "Unformatted!"; }
};

int main()
{
    Foo f;
    f.bar();
    return 0;
}

/*
int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

    QLabel label("Hello in the MyBudget app!");
    label.show();

        std::cout <<   "someting\n";

    return app.exec();
}*/