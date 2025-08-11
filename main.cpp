#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include <iostream>

import Category;
import Transaction;

QPointer<QWidget> CreateTransactionWidget(const Transaction& transaction,
                                          QWidget* parent);

int main(int argc, char* argv[])
{
    using namespace std::chrono_literals;
    QApplication app(argc, argv);

    std::vector<Transaction> transactions = {
        Transaction(
            std::chrono::year_month_day{2025y, std::chrono::August, 11d},
            100.0f, "Groceries", 1),
        Transaction(50.0f, "Transport", 2)};

    QWidget mainWindow;
    QVBoxLayout* mainLayout = new QVBoxLayout(&mainWindow);

    for (const auto& transaction : transactions)
    {
        QPointer<QWidget> widget =
            CreateTransactionWidget(transaction, &mainWindow);
        mainLayout->addWidget(widget);
    }

    mainWindow.show();
    return app.exec();
}

QPointer<QWidget> CreateTransactionWidget(const Transaction& transaction,
                                          QWidget* parent)
{
    QPointer<QWidget> widget = new QWidget(parent);
    QHBoxLayout* layout = new QHBoxLayout(widget);

    const auto& date = transaction.GetDate();
    QString dateStr = QString::fromStdString(
        std::format("{}-{:02}-{:02}", static_cast<int>(date.year()),
                    static_cast<unsigned>(date.month()),
                    static_cast<unsigned>(date.day())));

    layout->addWidget(new QLabel("Date: " + dateStr));
    layout->addWidget(new QLabel(
        "Value: " + QString::number(transaction.GetValue(), 'f', 2)));
    layout->addWidget(new QLabel(
        "Description" + QString::fromStdString(transaction.GetDescription())));
    layout->addWidget(new QLabel("Category ID: " +
                                 QString::number(transaction.GetCategoryID())));

    return widget;
}