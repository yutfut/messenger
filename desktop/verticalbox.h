#ifndef VERTICALBOX_H
#define VERTICALBOX_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>


class VerticalBox : public QWidget
{
public:
    VerticalBox(QWidget *parent = 0);
    void add_dialog();
    QVBoxLayout *vbox;
};

#endif // VERTICALBOX_H
