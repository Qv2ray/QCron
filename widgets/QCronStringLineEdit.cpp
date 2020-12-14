#include "QCronStringLineEdit.hpp"

QCronStringLineEdit::QCronStringLineEdit(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void QCronStringLineEdit::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}
