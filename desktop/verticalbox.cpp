#include "verticalbox.h"

VerticalBox::VerticalBox(QWidget * parent): QWidget(parent)
{
      QVBoxLayout *vbox = new QVBoxLayout(this);
      vbox->setSpacing(1);
}

void VerticalBox::add_dialog() {
      QLabel *label = new QLabel("settings", this);
      label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      vbox->addWidget(label);
      setLayout(vbox);
}
