#include "QCronJobDaemon.hpp"

#include "libcron/Cron.h"

#include <QTimerEvent>

QCronJobDaemon::QCronJobDaemon(int sleepTime, QObject *parent) : QObject(parent)
{
    cronEngine = new libcron::Cron<libcron::LocalClock, libcron::Locker>;
    timerId = startTimer(sleepTime);
}

int QCronJobDaemon::AddJob(const QString &name, const QString &cron, const QCronJobCallback &callback, void *userInfo)
{
    const int jobId = ++jobCounter;
    cronEngine->add_schedule(std::to_string(jobId), cron.toStdString(), [=](const libcron::TaskInformation &t) {
        callback(jobId, name, cron, userInfo);
        emit OnJobTriggered(jobId, name, cron, userInfo);
    });
    return jobId;
}

void QCronJobDaemon::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == timerId)
        cronEngine->tick();
}

QCronJobDaemon::~QCronJobDaemon()
{
    killTimer(timerId);
    cronEngine->clear_schedules();
    delete cronEngine;
}
