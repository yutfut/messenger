#include "verticalbox.h"

VerticalBox::VerticalBox(QWidget * parent): QWidget(parent)
{
      QVBoxLayout *vbox = new QVBoxLayout(this);
      vbox->setSpacing(1);
}

void VerticalBox::add_dialog() {
      QLabel *label = new QLabel("*Andrey  dretry...", this);
      /*settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      vbox->addWidget(settings);
      vbox->addWidget(accounts);
      vbox->addWidget(loans);
      vbox->addWidget(cash);
      vbox->addWidget(debts);

      setLayout(vbox);*/
}
