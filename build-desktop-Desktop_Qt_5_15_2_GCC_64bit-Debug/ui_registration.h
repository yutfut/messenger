/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_8;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *code_from_letter;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *user_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *pass;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *pass_control;
    QLabel *label_9;
    QPushButton *send_code;
    QPushButton *end_reg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(800, 600);
        centralwidget = new QWidget(Registration);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 221, 61));
        label->setStyleSheet(QString::fromUtf8("font-size:20px"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 410, 531, 17));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 260, 231, 17));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 350, 295, 27));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        code_from_letter = new QLineEdit(layoutWidget);
        code_from_letter->setObjectName(QString::fromUtf8("code_from_letter"));
        code_from_letter->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout_5->addWidget(code_from_letter);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 70, 311, 171));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        user_name = new QLineEdit(layoutWidget1);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        user_name->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(user_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        login = new QLineEdit(layoutWidget1);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(login);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        pass = new QLineEdit(layoutWidget1);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(pass);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        pass_control = new QLineEdit(layoutWidget1);
        pass_control->setObjectName(QString::fromUtf8("pass_control"));
        pass_control->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout_4->addWidget(pass_control);


        verticalLayout->addLayout(horizontalLayout_4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 450, 481, 17));
        send_code = new QPushButton(centralwidget);
        send_code->setObjectName(QString::fromUtf8("send_code"));
        send_code->setGeometry(QRect(180, 300, 161, 25));
        end_reg = new QPushButton(centralwidget);
        end_reg->setObjectName(QString::fromUtf8("end_reg"));
        end_reg->setGeometry(QRect(240, 480, 241, 25));
        Registration->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Registration);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Registration->setMenuBar(menubar);
        statusbar = new QStatusBar(Registration);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));
        Registration->setStatusBar(statusbar);

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QMainWindow *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("Registration", "\320\222\320\260\320\274 \320\275\320\260  \320\277\320\276\321\207\321\202\321\203 \320\261\321\213\320\273\320\276 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\276 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265. \320\235\320\270\320\272\320\276\320\274\321\203 \320\275\320\265 \321\201\320\276\320\276\320\261\321\211\320\260\320\271\321\202\320\265 \320\272\320\276\320\264!", nullptr));
        label_8->setText(QCoreApplication::translate("Registration", "\320\237\320\265\321\200\320\265\320\264\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\275\320\260 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\321\203?", nullptr));
        label_7->setText(QCoreApplication::translate("Registration", "\320\232\320\276\320\264 \320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "\320\230\320\274\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_4->setText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("Registration", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_9->setText(QCoreApplication::translate("Registration", "\320\224\320\273\321\217 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\270\321\217 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \"\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\216\"", nullptr));
        send_code->setText(QCoreApplication::translate("Registration", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\264", nullptr));
        end_reg->setText(QCoreApplication::translate("Registration", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
