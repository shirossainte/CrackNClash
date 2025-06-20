/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *startScreen;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QPushButton *exitButton;
    QWidget *difficultyScreen;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *easyButton;
    QPushButton *mediumButton;
    QPushButton *hardButton;
    QWidget *gameScreen;
    QTextEdit *outputTextEdit;
    QProgressBar *timeBar;
    QLineEdit *inputLineEdit;
    QPushButton *submitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(807, 661);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 811, 701));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("    QStackedWidget {\n"
"        background-color: lightblue; /* Replace 'lightblue' with your desired color */\n"
"    }"));
        startScreen = new QWidget();
        startScreen->setObjectName("startScreen");
        label = new QLabel(startScreen);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 80, 251, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #6A0DAD; /* Purple */\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    font-family: \"Arial Black\";\n"
"    background-color: transparent;\n"
"    padding: 10px;\n"
"    border: 2px solid #BA55D3; /* Orchid border */\n"
"    border-radius: 10px;\n"
"}\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(startScreen);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(240, 190, 311, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName("startButton");
        startButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ff6f61;\n"
"    color: #fff5e1;\n"
"}\n"
""));

        verticalLayout->addWidget(startButton);

        exitButton = new QPushButton(verticalLayoutWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ff6f61;\n"
"    color: #fff5e1;\n"
"}\n"
""));

        verticalLayout->addWidget(exitButton);

        stackedWidget->addWidget(startScreen);
        difficultyScreen = new QWidget();
        difficultyScreen->setObjectName("difficultyScreen");
        label_2 = new QLabel(difficultyScreen);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 90, 281, 71));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #0077b6;\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    font-family: \"Arial Black\";\n"
"    background-color: transparent;\n"
"    padding: 10px;\n"
"    border: 2px solid #00b4d8;\n"
"    border-radius: 10px;\n"
"}\n"
""));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(difficultyScreen);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(310, 190, 181, 281));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        easyButton = new QPushButton(verticalLayoutWidget_2);
        easyButton->setObjectName("easyButton");
        easyButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ff6f61;\n"
"    color: #fff5e1;\n"
"}\n"
""));

        verticalLayout_2->addWidget(easyButton);

        mediumButton = new QPushButton(verticalLayoutWidget_2);
        mediumButton->setObjectName("mediumButton");
        mediumButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ff6f61;\n"
"    color: #fff5e1;\n"
"}\n"
""));

        verticalLayout_2->addWidget(mediumButton);

        hardButton = new QPushButton(verticalLayoutWidget_2);
        hardButton->setObjectName("hardButton");
        hardButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ff6f61;\n"
"    color: #fff5e1;\n"
"}\n"
""));

        verticalLayout_2->addWidget(hardButton);

        stackedWidget->addWidget(difficultyScreen);
        gameScreen = new QWidget();
        gameScreen->setObjectName("gameScreen");
        outputTextEdit = new QTextEdit(gameScreen);
        outputTextEdit->setObjectName("outputTextEdit");
        outputTextEdit->setGeometry(QRect(180, 60, 491, 301));
        timeBar = new QProgressBar(gameScreen);
        timeBar->setObjectName("timeBar");
        timeBar->setGeometry(QRect(360, 460, 141, 31));
        timeBar->setValue(24);
        inputLineEdit = new QLineEdit(gameScreen);
        inputLineEdit->setObjectName("inputLineEdit");
        inputLineEdit->setGeometry(QRect(360, 380, 131, 31));
        submitButton = new QPushButton(gameScreen);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(390, 420, 75, 24));
        stackedWidget->addWidget(gameScreen);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 807, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Crack N Clash", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select Difficulty", nullptr));
        easyButton->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        mediumButton->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        hardButton->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
