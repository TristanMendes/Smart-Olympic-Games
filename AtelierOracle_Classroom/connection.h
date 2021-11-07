#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class connection
{
public:
    connection();
    bool createConnect();
};

#endif // CONNECTION_H
