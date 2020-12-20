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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *add_layout;
    QStackedWidget *chat_windows;
    QWidget *page;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QWidget *contact_frame;
    QVBoxLayout *verticalLayout_21;
    QVBoxLayout *verticalLayout_13;
    QLabel *contact_label;
    QLabel *contact_status;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *output;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_18;
    QVBoxLayout *verticalLayout_20;
    QWidget *contact_frame_2;
    QVBoxLayout *verticalLayout_29;
    QVBoxLayout *verticalLayout_28;
    QLabel *contact_label_2;
    QLabel *contact_status_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_6;
    QVBoxLayout *verticalLayout_25;
    QVBoxLayout *output_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_22;
    QVBoxLayout *verticalLayout_23;
    QWidget *contact_frame_3;
    QVBoxLayout *verticalLayout_33;
    QVBoxLayout *verticalLayout_32;
    QLabel *contact_label_4;
    QLabel *contact_status_4;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_7;
    QVBoxLayout *verticalLayout_26;
    QVBoxLayout *output_3;
    QWidget *page_3;
    QWidget *blank;
    QVBoxLayout *verticalLayout_27;
    QLineEdit *add_line;
    QFrame *top_frame;
    QFrame *image_frame;
    QLabel *username_label;
    QLabel *status_label;
    QLabel *status_text_label;
    QWidget *layoutWidget_2;
    QVBoxLayout *add_layout_2;
    QPushButton *profile;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        centralwidget = new QWidget(Dialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 280, 2, 2));
        add_layout = new QVBoxLayout(layoutWidget);
        add_layout->setSpacing(6);
        add_layout->setObjectName(QString::fromUtf8("add_layout"));
        add_layout->setContentsMargins(0, 0, 0, 0);
        chat_windows = new QStackedWidget(centralwidget);
        chat_windows->setObjectName(QString::fromUtf8("chat_windows"));
        chat_windows->setGeometry(QRect(204, 197, 471, 251));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_8 = new QVBoxLayout(page);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        contact_frame = new QWidget(page);
        contact_frame->setObjectName(QString::fromUtf8("contact_frame"));
        contact_frame->setMinimumSize(QSize(0, 50));
        contact_frame->setMaximumSize(QSize(16777215, 50));
        contact_frame->setStyleSheet(QString::fromUtf8("background: #1c1c37;"));
        verticalLayout_21 = new QVBoxLayout(contact_frame);
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        contact_label = new QLabel(contact_frame);
        contact_label->setObjectName(QString::fromUtf8("contact_label"));
        contact_label->setStyleSheet(QString::fromUtf8("font: 12pt; color: white;"));
        contact_label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_13->addWidget(contact_label);

        contact_status = new QLabel(contact_frame);
        contact_status->setObjectName(QString::fromUtf8("contact_status"));
        contact_status->setStyleSheet(QString::fromUtf8("color: white; \n"
"font: 8pt;"));
        contact_status->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_13->addWidget(contact_status);


        verticalLayout_21->addLayout(verticalLayout_13);


        verticalLayout_7->addWidget(contact_frame);

        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("background: #E1E1E8;"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 98, 40));
        scrollAreaWidgetContents_4->setMaximumSize(QSize(600, 16777215));
        verticalLayout_16 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        output = new QVBoxLayout();
        output->setSpacing(10);
        output->setObjectName(QString::fromUtf8("output"));
        output->setContentsMargins(10, 20, 10, 20);

        verticalLayout_16->addLayout(output);

        scrollArea->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_7->addWidget(scrollArea);


        verticalLayout_8->addLayout(verticalLayout_7);

        chat_windows->addWidget(page);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        verticalLayout_18 = new QVBoxLayout(page_1);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        contact_frame_2 = new QWidget(page_1);
        contact_frame_2->setObjectName(QString::fromUtf8("contact_frame_2"));
        contact_frame_2->setMinimumSize(QSize(0, 50));
        contact_frame_2->setMaximumSize(QSize(16777215, 50));
        contact_frame_2->setStyleSheet(QString::fromUtf8("background: #1c1c37;"));
        verticalLayout_29 = new QVBoxLayout(contact_frame_2);
        verticalLayout_29->setSpacing(0);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        verticalLayout_29->setContentsMargins(0, 0, 0, 0);
        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setSpacing(0);
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        contact_label_2 = new QLabel(contact_frame_2);
        contact_label_2->setObjectName(QString::fromUtf8("contact_label_2"));
        contact_label_2->setStyleSheet(QString::fromUtf8("font: 12pt;\n"
"color: white;"));
        contact_label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_28->addWidget(contact_label_2);

        contact_status_2 = new QLabel(contact_frame_2);
        contact_status_2->setObjectName(QString::fromUtf8("contact_status_2"));
        contact_status_2->setStyleSheet(QString::fromUtf8("color: white; font: 8pt"));
        contact_status_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_28->addWidget(contact_status_2);


        verticalLayout_29->addLayout(verticalLayout_28);


        verticalLayout_20->addWidget(contact_frame_2);

        scrollArea_2 = new QScrollArea(page_1);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setStyleSheet(QString::fromUtf8("background: #E1E1E8;"));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollArea_2->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 98, 40));
        scrollAreaWidgetContents_6->setMaximumSize(QSize(600, 16777215));
        verticalLayout_25 = new QVBoxLayout(scrollAreaWidgetContents_6);
        verticalLayout_25->setSpacing(0);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        verticalLayout_25->setContentsMargins(0, 0, 0, 0);
        output_2 = new QVBoxLayout();
        output_2->setSpacing(10);
        output_2->setObjectName(QString::fromUtf8("output_2"));
        output_2->setContentsMargins(10, 20, 10, 20);

        verticalLayout_25->addLayout(output_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_6);

        verticalLayout_20->addWidget(scrollArea_2);


        verticalLayout_18->addLayout(verticalLayout_20);

        chat_windows->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_22 = new QVBoxLayout(page_2);
        verticalLayout_22->setSpacing(0);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(0, 0, 0, 0);
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(0);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        contact_frame_3 = new QWidget(page_2);
        contact_frame_3->setObjectName(QString::fromUtf8("contact_frame_3"));
        contact_frame_3->setMinimumSize(QSize(0, 50));
        contact_frame_3->setMaximumSize(QSize(16777215, 50));
        contact_frame_3->setStyleSheet(QString::fromUtf8("background: #1c1c37;"));
        verticalLayout_33 = new QVBoxLayout(contact_frame_3);
        verticalLayout_33->setSpacing(0);
        verticalLayout_33->setObjectName(QString::fromUtf8("verticalLayout_33"));
        verticalLayout_33->setContentsMargins(0, 0, 0, 0);
        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setSpacing(0);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        contact_label_4 = new QLabel(contact_frame_3);
        contact_label_4->setObjectName(QString::fromUtf8("contact_label_4"));
        contact_label_4->setStyleSheet(QString::fromUtf8("font: 12pt;\n"
"color: white;"));
        contact_label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_32->addWidget(contact_label_4);

        contact_status_4 = new QLabel(contact_frame_3);
        contact_status_4->setObjectName(QString::fromUtf8("contact_status_4"));
        contact_status_4->setStyleSheet(QString::fromUtf8("color: white; font: 8pt"));
        contact_status_4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_32->addWidget(contact_status_4);


        verticalLayout_33->addLayout(verticalLayout_32);


        verticalLayout_23->addWidget(contact_frame_3);

        scrollArea_4 = new QScrollArea(page_2);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setStyleSheet(QString::fromUtf8("background: #E1E1E8;"));
        scrollArea_4->setFrameShape(QFrame::NoFrame);
        scrollArea_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_4->setWidgetResizable(true);
        scrollArea_4->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 98, 40));
        scrollAreaWidgetContents_7->setMaximumSize(QSize(600, 16777215));
        verticalLayout_26 = new QVBoxLayout(scrollAreaWidgetContents_7);
        verticalLayout_26->setSpacing(0);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        verticalLayout_26->setContentsMargins(0, 0, 0, 0);
        output_3 = new QVBoxLayout();
        output_3->setSpacing(10);
        output_3->setObjectName(QString::fromUtf8("output_3"));
        output_3->setContentsMargins(10, 20, 10, 20);

        verticalLayout_26->addLayout(output_3);

        scrollArea_4->setWidget(scrollAreaWidgetContents_7);

        verticalLayout_23->addWidget(scrollArea_4);


        verticalLayout_22->addLayout(verticalLayout_23);

        chat_windows->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        chat_windows->addWidget(page_3);
        blank = new QWidget();
        blank->setObjectName(QString::fromUtf8("blank"));
        blank->setStyleSheet(QString::fromUtf8("background: #3f3f60;"));
        verticalLayout_27 = new QVBoxLayout(blank);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        chat_windows->addWidget(blank);
        add_line = new QLineEdit(centralwidget);
        add_line->setObjectName(QString::fromUtf8("add_line"));
        add_line->setGeometry(QRect(30, 260, 150, 20));
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
        top_frame->setGeometry(QRect(170, 90, 561, 81));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy);
        top_frame->setMinimumSize(QSize(0, 81));
        top_frame->setStyleSheet(QString::fromUtf8("background: #0b0b20;"));
        image_frame = new QFrame(top_frame);
        image_frame->setObjectName(QString::fromUtf8("image_frame"));
        image_frame->setGeometry(QRect(10, 10, 61, 61));
        image_frame->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/profile.png);"));
        image_frame->setFrameShape(QFrame::StyledPanel);
        image_frame->setFrameShadow(QFrame::Raised);
        username_label = new QLabel(top_frame);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setGeometry(QRect(80, 20, 111, 41));
        username_label->setStyleSheet(QString::fromUtf8("font: 13pt \"Open Sans Light\";\n"
"color: white;"));
        status_label = new QLabel(top_frame);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(480, 0, 81, 81));
        status_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        status_text_label = new QLabel(top_frame);
        status_text_label->setObjectName(QString::fromUtf8("status_text_label"));
        status_text_label->setGeometry(QRect(350, 0, 141, 81));
        status_text_label->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 10pt Open Sans Light;"));
        status_text_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        username_label->raise();
        image_frame->raise();
        status_label->raise();
        status_text_label->raise();
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(40, 290, 101, 91));
        add_layout_2 = new QVBoxLayout(layoutWidget_2);
        add_layout_2->setSpacing(6);
        add_layout_2->setObjectName(QString::fromUtf8("add_layout_2"));
        add_layout_2->setContentsMargins(0, 0, 0, 0);
        profile = new QPushButton(centralwidget);
        profile->setObjectName(QString::fromUtf8("profile"));
        profile->setGeometry(QRect(50, 100, 74, 71));
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
        input_frame = new QWidget(centralwidget);
        input_frame->setObjectName(QString::fromUtf8("input_frame"));
        input_frame->setGeometry(QRect(204, 450, 471, 75));
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

        Dialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Dialog->setMenuBar(menubar);
        statusbar = new QStatusBar(Dialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Dialog->setStatusBar(statusbar);
        toolBar = new QToolBar(Dialog);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Dialog->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(Dialog);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        Dialog->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(Dialog);

        chat_windows->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "MainWindow", nullptr));
        contact_label->setText(QString());
        contact_status->setText(QString());
        contact_label_2->setText(QString());
        contact_status_2->setText(QString());
        contact_label_4->setText(QString());
        contact_status_4->setText(QString());
        add_line->setPlaceholderText(QCoreApplication::translate("Dialog", "Search...", nullptr));
        username_label->setText(QString());
        status_label->setText(QString());
        status_text_label->setText(QCoreApplication::translate("Dialog", "Connection lost...", nullptr));
        profile->setText(QString());
        input->setPlaceholderText(QCoreApplication::translate("Dialog", "Type a message...", nullptr));
        file_button->setText(QString());
        smile_button->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("Dialog", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("Dialog", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
