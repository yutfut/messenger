/********************************************************************************
** Form generated from reading UI file 'dialogs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGS_H
#define UI_DIALOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *add_layout;
    QLineEdit *add_line;
    QFrame *top_frame;
    QLabel *status_label;
    QWidget *layoutWidget_2;
    QVBoxLayout *add_layout_2;
    QPushButton *profile;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QWidget *input_frame;
    QHBoxLayout *horizontalLayout_4;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_12;
    QWidget *input_frame_box;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *input;
    QPushButton *send_button;
    QPushButton *file_button;
    QPushButton *smile_button;
    QPushButton *pushButton;
    QPushButton *add_group_dlg;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(809, 611);
        Dialog->setStyleSheet(QString::fromUtf8("background: rgb(117, 80, 123);"));
        centralwidget = new QWidget(Dialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 280, 2, 2));
        add_layout = new QVBoxLayout(layoutWidget);
        add_layout->setSpacing(6);
        add_layout->setObjectName(QString::fromUtf8("add_layout"));
        add_layout->setContentsMargins(0, 0, 0, 0);
        add_line = new QLineEdit(centralwidget);
        add_line->setObjectName(QString::fromUtf8("add_line"));
        add_line->setGeometry(QRect(0, 150, 181, 31));
        add_line->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"        min-height: 20px;\n"
"        background: white;\n"
"        font: 10pt \"Open Sans\";\n"
"        border: 0px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"        border:0px;\n"
"}\n"
""));
        add_line->setMaxLength(20);
        top_frame = new QFrame(centralwidget);
        top_frame->setObjectName(QString::fromUtf8("top_frame"));
        top_frame->setGeometry(QRect(80, 0, 731, 81));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy);
        top_frame->setMinimumSize(QSize(0, 81));
        top_frame->setStyleSheet(QString::fromUtf8("background: #1c1c37;"));
        status_label = new QLabel(top_frame);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(480, 0, 81, 81));
        status_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 190, 181, 371));
        add_layout_2 = new QVBoxLayout(layoutWidget_2);
        add_layout_2->setSpacing(6);
        add_layout_2->setObjectName(QString::fromUtf8("add_layout_2"));
        add_layout_2->setContentsMargins(0, 0, 0, 0);
        profile = new QPushButton(centralwidget);
        profile->setObjectName(QString::fromUtf8("profile"));
        profile->setGeometry(QRect(0, 0, 81, 81));
        profile->setStyleSheet(QString::fromUtf8(" QPushButton:enabled\n"
"{\n"
"border-image: url(:/chat/img/profile.png);                \n"
"background: #1c1c37;\n"
"                min-width: 40px;\n"
"                min-height:40px;\n"
"                border-radius: 0px;\n"
"                padding: 5px;\n"
"                outline: 0px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"                background: #3D3D5A;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"           background: #585879;\n"
"}"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(180, 150, 631, 411));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget1);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8("background: rgb(238, 238, 236);\n"
"font-size:25px"));

        verticalLayout->addWidget(textBrowser);

        input_frame = new QWidget(layoutWidget1);
        input_frame->setObjectName(QString::fromUtf8("input_frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(input_frame->sizePolicy().hasHeightForWidth());
        input_frame->setSizePolicy(sizePolicy1);
        input_frame->setMinimumSize(QSize(0, 75));
        input_frame->setMaximumSize(QSize(16777215, 75));
        input_frame->setStyleSheet(QString::fromUtf8("background: #3f3f60;"));
        horizontalLayout_4 = new QHBoxLayout(input_frame);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(20, 10, 20, 10);
        horizontalWidget = new QWidget(input_frame);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(700, 16777215));
        horizontalLayout_12 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_12->setSpacing(10);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        input_frame_box = new QWidget(horizontalWidget);
        input_frame_box->setObjectName(QString::fromUtf8("input_frame_box"));
        input_frame_box->setMinimumSize(QSize(0, 48));
        input_frame_box->setMaximumSize(QSize(16777215, 48));
        input_frame_box->setStyleSheet(QString::fromUtf8("background: white;"));
        input_frame_box->setInputMethodHints(Qt::ImhMultiLine);
        horizontalLayout_3 = new QHBoxLayout(input_frame_box);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 11, 0, 0);
        input = new QPlainTextEdit(input_frame_box);
        input->setObjectName(QString::fromUtf8("input"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(input->sizePolicy().hasHeightForWidth());
        input->setSizePolicy(sizePolicy2);
        input->setMinimumSize(QSize(0, 48));
        input->setMaximumSize(QSize(16777215, 48));
        input->setStyleSheet(QString::fromUtf8("font: 10pt \"Open Sans\";"));
        input->setFrameShape(QFrame::NoFrame);
        input->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(input);


        horizontalLayout_12->addWidget(input_frame_box);

        send_button = new QPushButton(horizontalWidget);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        send_button->setEnabled(true);
        send_button->setMaximumSize(QSize(50, 35));
        send_button->setStyleSheet(QString::fromUtf8("QPushButton:enabled\n"
"{\n"
"                border-image: url(:/chat/img/send.png);\n"
"                background:   #73739b;\n"
"                border-radius: 3px;\n"
"                min-width: 40px;\n"
"                min-height:25px;\n"
"                padding: 5px;\n"
"                outline: 0px;\n"
"}\n"
"\n"
" QPushButton:disabled\n"
"{\n"
"                border-image: url(:/Resources/send_disabled.png);\n"
"                background:  #73739b;\n"
"                border-radius: 3px;\n"
"                min-width: 40px;\n"
"                min-height:25px;\n"
"                padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"                background: #7a7aa1;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"        background: #8f8fb3;\n"
"}"));

        horizontalLayout_12->addWidget(send_button);

        file_button = new QPushButton(horizontalWidget);
        file_button->setObjectName(QString::fromUtf8("file_button"));
        file_button->setMinimumSize(QSize(50, 35));
        file_button->setMaximumSize(QSize(50, 35));
        file_button->setStyleSheet(QString::fromUtf8(" QPushButton:enabled\n"
"{\n"
"                border-image: url(:/chat/img/files.png);\n"
"                background:  #73739b;\n"
"                border-radius: 3px;\n"
"                min-height:25px;\n"
"                padding: 5px;\n"
"                outline: 0px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"                background: #7a7aa1;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"        background: #8f8fb3;\n"
"}"));

        horizontalLayout_12->addWidget(file_button);


        horizontalLayout_4->addWidget(horizontalWidget);

        smile_button = new QPushButton(input_frame);
        smile_button->setObjectName(QString::fromUtf8("smile_button"));
        smile_button->setMinimumSize(QSize(50, 35));
        smile_button->setMaximumSize(QSize(50, 35));
        smile_button->setStyleSheet(QString::fromUtf8(" QPushButton:enabled\n"
"{\n"
"                border-image: url(:/chat/img/smile.png);\n"
"                background:  #73739b;\n"
"                border-radius: 3px;\n"
"                min-height:25px;\n"
"                padding: 5px;\n"
"                outline: 0px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"                background: #7a7aa1;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"        background: #8f8fb3;\n"
"}"));

        horizontalLayout_4->addWidget(smile_button);


        verticalLayout->addWidget(input_frame);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 80, 91, 71));
        pushButton->setStyleSheet(QString::fromUtf8(" QPushButton:enabled\n"
"{\n"
"                border-image: url(:/chat/img/chat.png);\n"
"                background: #3f3f60;\n"
"                border-radius: 3px;\n"
"                min-height:25px;\n"
"                padding: 5px;\n"
"                outline: 0px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"                background: #7a7aa1;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"        background: #8f8fb3;\n"
"}"));
        add_group_dlg = new QPushButton(centralwidget);
        add_group_dlg->setObjectName(QString::fromUtf8("add_group_dlg"));
        add_group_dlg->setGeometry(QRect(90, 80, 91, 71));
        add_group_dlg->setStyleSheet(QString::fromUtf8(" QPushButton:enabled\n"
"{\n"
"                border-image: url(:/chat/img/create_dlg.png);\n"
"                background: #3f3f60;\n"
"                border-radius: 3px;\n"
"                min-height:25px;\n"
"                padding: 5px;\n"
"                outline: 0px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"                background: #7a7aa1;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"        background: #8f8fb3;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 80, 631, 71));
        label->setStyleSheet(QString::fromUtf8("background: #3f3f60;"));
        Dialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 809, 22));
        Dialog->setMenuBar(menubar);
        statusbar = new QStatusBar(Dialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Dialog->setStatusBar(statusbar);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "MainWindow", nullptr));
        add_line->setPlaceholderText(QCoreApplication::translate("Dialog", "Search...", nullptr));
        status_label->setText(QString());
        profile->setText(QString());
        input->setPlaceholderText(QCoreApplication::translate("Dialog", "Type a message...", nullptr));
        file_button->setText(QString());
        smile_button->setText(QString());
        pushButton->setText(QString());
        add_group_dlg->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGS_H
