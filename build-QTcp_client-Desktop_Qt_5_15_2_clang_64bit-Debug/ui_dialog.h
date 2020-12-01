/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QTextBrowser *lwLog;
    QGridLayout *gridLayout;
    QPushButton *pbConnect;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pbt_Send;
    QPushButton *pbDisconnect;
    QLineEdit *message_Edit;
    QLineEdit *leHost;
    QLineEdit *sbPort;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(663, 458);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        verticalLayout->addLayout(gridLayout_2);

        lwLog = new QTextBrowser(Dialog);
        lwLog->setObjectName(QString::fromUtf8("lwLog"));

        verticalLayout->addWidget(lwLog);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pbConnect = new QPushButton(Dialog);
        pbConnect->setObjectName(QString::fromUtf8("pbConnect"));

        gridLayout->addWidget(pbConnect, 3, 0, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pbt_Send = new QPushButton(Dialog);
        pbt_Send->setObjectName(QString::fromUtf8("pbt_Send"));
        pbt_Send->setAutoDefault(false);
        pbt_Send->setFlat(false);

        gridLayout->addWidget(pbt_Send, 3, 2, 1, 1);

        pbDisconnect = new QPushButton(Dialog);
        pbDisconnect->setObjectName(QString::fromUtf8("pbDisconnect"));
        pbDisconnect->setEnabled(false);

        gridLayout->addWidget(pbDisconnect, 3, 1, 1, 1);

        message_Edit = new QLineEdit(Dialog);
        message_Edit->setObjectName(QString::fromUtf8("message_Edit"));

        gridLayout->addWidget(message_Edit, 2, 1, 1, 1);

        leHost = new QLineEdit(Dialog);
        leHost->setObjectName(QString::fromUtf8("leHost"));

        gridLayout->addWidget(leHost, 0, 1, 1, 1);

        sbPort = new QLineEdit(Dialog);
        sbPort->setObjectName(QString::fromUtf8("sbPort"));

        gridLayout->addWidget(sbPort, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Dialog);

        pbt_Send->setDefault(false);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "client", nullptr));
        pbConnect->setText(QCoreApplication::translate("Dialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\220\320\264\321\200\320\265\321\201 \321\205\320\276\321\201\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\320\237\320\276\321\200\321\202 \321\205\320\276\321\201\321\202\320\260", nullptr));
        pbt_Send->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        leHost->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
