#ifndef CONNECTIONBD_H
#define CONNECTIONBD_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>

/*class connectionBD
{
public:
    connectionBD();
    void fermerConnSQL();
    int conn(QString LOGIN, QString PASSWORD);
};*/
#include <QSqlDatabase>
class connectionBD
{
private:
    QSqlDatabase db;
public:
    connectionBD();
    bool OuvrirConnexion();
    void closeConnexion();
};
#endif // CONNECTIONBD_H
