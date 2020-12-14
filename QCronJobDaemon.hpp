#pragma once

#include "libs/QJsonStruct/QJsonStruct.hpp"

#include <QObject>

namespace libcron
{
    class Locker;
    class LocalClock;
    template<typename T1, typename T2>
    class Cron;
} // namespace libcron

typedef std::function<void(int jobId, const QString &name, const QString &cron, const void *const userInfo)> QCronJobCallback;

class QCronJobDaemon : public QObject
{
    Q_OBJECT
  public:
    explicit QCronJobDaemon(int sleepTime = 500, QObject *parent = nullptr);
    ~QCronJobDaemon();

    int AddJob(const QString &name, const QString &cron, const QCronJobCallback &callback, void *userInfo = nullptr);
    void RemoveJob(int jobId);

  protected:
    void timerEvent(QTimerEvent *e) override;

  signals:
    void OnJobTriggered(int jobId, const QString &name, const QString &cron, const void *const userInfo);

  private:
    int timerId = -1;
    int jobCounter = 0;
    libcron::Cron<libcron::LocalClock, libcron::Locker> *cronEngine;
};
