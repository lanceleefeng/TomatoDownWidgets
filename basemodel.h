//
// Created by Administrator on 2017-7-4.
//

#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "db.h"


class BaseModel
{
public:

    //QString tableName = "settings";
    static QString tableName;
    static QString tableFullName;
    static QString tablePrefix;

    static QMap<QString, int> tableFields;
    static QMap<QString, int> getTableFields();
    static QString getTableName();

    BaseModel();

};




#endif //BASEMODEL_H
