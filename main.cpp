#include "QCronJobDaemon.hpp"

#include <QApplication>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void cb(int jobId, const QString &name, const QString &cron, const void *const userInfo)
{
    std::cout << "Done" << std::endl;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCronJobDaemon d;
    d.AddJob("test", "* * * * * ?", cb);
    return a.exec();
}
