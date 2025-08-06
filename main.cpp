// #include <QApplication>
// #include <QLabel>
#include <iostream>
import Category;

// int main(int argc, char* argv[])
int main()
{
    // QApplication app(argc, argv);

    // QLabel label("Hello in the MyBudget app!");
    // label.show();

    // std::cout << "someting\n";
    Categories cat;
    cat.AddCategory(1, "SomeCategory");

    // return app.exec();
    return 0;
}