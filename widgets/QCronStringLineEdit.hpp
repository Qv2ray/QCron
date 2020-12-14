#pragma once

#include "ui_QCronStringLineEdit.h"

class QCronStringLineEdit : public QWidget, private Ui::QCronStringLineEdit
{
    Q_OBJECT

public:
    explicit QCronStringLineEdit(QWidget *parent = nullptr);

protected:
    void changeEvent(QEvent *e);
};

