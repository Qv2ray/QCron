#pragma once

#include <QObject>

class QCronJobObject : public QObject
{
    Q_OBJECT
public:
    explicit QCronJobObject(QObject *parent = nullptr);

signals:

};

