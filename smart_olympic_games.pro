QT       += core gui sql
QT       += core gui charts
QR       += printsupport
QT       += widgets
QT       += network
QT       += serialport
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QT += widgets quickwidgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affectation.cpp \
    agent.cpp \
    athletesop.cpp \
    calendrier.cpp \
    connexion.cpp \
    examen_medical.cpp \
    factures.cpp \
    fan.cpp \
    gestion_athletes.cpp \
    gestion_des_moyens_de_transport.cpp \
    gestion_examens_medicaux.cpp \
    gestion_hebergements.cpp \
    gestion_service_financier.cpp \
    gestion_stades.cpp \
    hebergement.cpp \
    main.cpp \
    mainwindow.cpp \
    moyensdetransport.cpp \
    payment.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    stade.cpp

HEADERS += \
    affectation.h \
    agent.h \
    athletesop.h \
    calendrier.h \
    connexion.h \
    examen_medical.h \
    factures.h \
    fan.h \
    gestion_athletes.h \
    gestion_des_moyens_de_transport.h \
    gestion_examens_medicaux.h \
    gestion_hebergements.h \
    gestion_service_financier.h \
    gestion_stades.h \
    hebergement.h \
    mainwindow.h \
    moyensdetransport.h \
    payment.h \
    qcustomplot.h \
    smtp.h \
    stade.h

FORMS += \
    gestion_athletes.ui \
    gestion_des_moyens_de_transport.ui \
    gestion_examens_medicaux.ui \
    gestion_hebergements.ui \
    gestion_service_financier.ui \
    gestion_stades.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icone_app.qrc \
    image_fond.qrc
