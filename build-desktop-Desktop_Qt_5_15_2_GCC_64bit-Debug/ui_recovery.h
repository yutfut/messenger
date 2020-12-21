/********************************************************************************
** Form generated from reading UI file 'recovery.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOVERY_H
#define UI_RECOVERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Recovery
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *login;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *check_code;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Recovery)
    {
        if (Recovery->objectName().isEmpty())
            Recovery->setObjectName(QString::fromUtf8("Recovery"));
        Recovery->resize(800, 600);
        Recovery->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Recovery);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 521, 17));
        label_2->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 220, 191, 25));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 90, 194, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_3);

        login = new QLineEdit(layoutWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(login);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 370, 161, 25));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 290, 344, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label);

        check_code = new QLineEdit(layoutWidget1);
        check_code->setObjectName(QString::fromUtf8("check_code"));
        check_code->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(check_code);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 30, 271, 41));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        Recovery->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Recovery);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Recovery->setMenuBar(menubar);
        statusbar = new QStatusBar(Recovery);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));
        Recovery->setStatusBar(statusbar);

        retranslateUi(Recovery);

        QMetaObject::connectSlotsByName(Recovery);
    } // setupUi

    void retranslateUi(QMainWindow *Recovery)
    {
        Recovery->setWindowTitle(QCoreApplication::translate("Recovery", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("Recovery", "\320\235\320\260 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\321\203\321\216 \320\277\320\276\321\207\321\202\321\203 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\276 \320\277\320\270\321\201\321\214\320\274\320\276. \320\235\320\270\320\272\320\276\320\274\321\203 \320\275\320\265 \321\201\320\276\320\276\320\261\321\211\320\260\320\271\321\202\320\265 \320\272\320\276\320\264", nullptr));
        pushButton->setText(QCoreApplication::translate("Recovery", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("Recovery", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Recovery", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("Recovery", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\321\200\320\276\320\262\320\265\321\200\320\276\321\207\320\275\321\213\320\271 \320\272\320\276\320\264:", nullptr));
        label_4->setText(QCoreApplication::translate("Recovery", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Recovery: public Ui_Recovery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOVERY_H
