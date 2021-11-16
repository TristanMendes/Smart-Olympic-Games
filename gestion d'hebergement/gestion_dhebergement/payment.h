#ifndef PAYMENT_H
#define PAYMENT_H
#include <QSqlQueryModel>

  class payment
{
    public:
      payment();
      payment(int,int,int);
          int getchambre_reserve();
          int getprix();
          int getperiode();
          void setchambre_reserve(int);
          void setprix(int);
          void setperiode(int);

          bool ajouter();
        QSqlQueryModel* afficher();
 int gain()  ;
      private:
          int chambre_reserve,periode,prix;

};

#endif // PAYMENT_H
