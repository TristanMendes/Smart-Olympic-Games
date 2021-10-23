#ifndef ATHLETES_H
#define ATHLETES_H

#include <QString>
class Athletes
{
public:
    Athletes();
    Athletes(int, QString);

    int ID,age;
    QString Nom, Prenom,nationalite,sexe,specialité;
};

#endif // ATHLETES_H
