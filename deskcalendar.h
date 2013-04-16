#ifndef DESKCALENDAR_H
#define DESKCALENDAR_H

#include <QMainWindow>
#include <QtSql/QtSql>

namespace Ui {
class DeskCalendar;
}

class DeskCalendar : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DeskCalendar(QString _path, int h, int w, QWidget *parent = 0);
    ~DeskCalendar();

    QSqlDatabase db;
    int id;
    int cDay; // день текущей
    int cMonth;
    int cYear;
    QDate cDate; // рабочая дата
    QString appPath; //папка с программой
private:
    Ui::DeskCalendar *ui;

private slots:
    // время
    void dc_time();
    void setCurrentTime();
    ////////////
    //дата
    void dc_date();
    void setCurrentDate();
    void prevMonth();
    void nextMonth();
    ////////////
    //db
    void connectDB();
    ///////////
    //заметки
    void addNotes();
    void editNotes();
    void cancelNotes();
    void saveNotes();
    void readNotes();
    void checkNotes();
    void updateNotes();
    /////////////
    //календарь
    void makeCalendar(QDate ddate);
    void updateCalendar();
    /////////////
    //diagramm
    void toDia();
    void toInfo();
    void loadIcons();
    ////////
    //test
    void testDB();

};

#endif // DESKCALENDAR_H
