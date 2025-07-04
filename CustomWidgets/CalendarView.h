#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QWidget>
#include <QVector>
#include <QDate>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>
#include "../publicheader.h"

class DayCell : public QFrame {
    Q_OBJECT
public:
    explicit DayCell(const QDate& date, QWidget *parent = nullptr);
    void setTasks(const QVector<Task>& tasks);  // 可用于添加任务信息

private:
    QLabel *dateLabel;
    QVBoxLayout *cellLayout;
};

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    explicit CalendarView(QVector<Task> &tasks, QWidget *parent = nullptr);

private:
    QVector<Task> &task_list;
    QGridLayout *calendarGrid;
    QVBoxLayout *mainLayout;

    void buildCalendar(const QDate& month);
    QVector<Task> tasksForDate(const QDate& date); // 获取某天的任务
    void refreshCalendar(const QDate& month);

signals:
    void taskChanged();
};

#endif // CALENDARVIEW_H
