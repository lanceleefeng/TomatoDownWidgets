//
// Created by Administrator on 2017-8-2.
//

#ifndef DATETIME_H
#define DATETIME_H


#include <QString>

class DateTime {

public:

    static QString defaultFormat;

    static QString getTime();
    static QString getTime(QString format);

};


#endif //DATETIME_H
