/********************************************************************************
** Form generated from reading UI file 'newpass.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPASS_H
#define UI_NEWPASS_H

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

class Ui_Newpass
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *pass;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *control_pass;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Newpass)
    {
        if (Newpass->objectName().isEmpty())
            Newpass->setObjectName(QString::fromUtf8("Newpass"));
        Newpass->resize(800, 600);
        centralwidget = new QWidget(Newpass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 60, 251, 41));
        label_3->setStyleSheet(QString::fromUtf8("font-size:20px"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 130, 283, 62));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pass = new QLineEdit(layoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(pass);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        control_pass = new QLineEdit(layoutWidget);
        control_pass->setObjectName(QString::fromUtf8("control_pass"));
        control_pass->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(control_pass);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 230, 151, 51));
        Newpass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Newpass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Newpass->setMenuBar(menubar);
        statusbar = new QStatusBar(Newpass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);"));
        Newpass->setStatusBar(statusbar);

        retranslateUi(Newpass);

        QMetaObject::connectSlotsByName(Newpass);
    } // setupUi

    void retranslateUi(QMainWindow *Newpass)
    {
        Newpass->setWindowTitle(QCoreApplication::translate("Newpass", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("Newpass", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("Newpass", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("Newpass", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("Newpass", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Newpass: public Ui_Newpass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPASS_H
