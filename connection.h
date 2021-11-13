

#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


class connection
{
public:
    connection();
    bool createConnect();
};

#endif // CONNECTION_H
