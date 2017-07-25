
#ifndef SETTINGMODEL_H
#define SETTINGMODEL_H

#include "db.h"
#include "basemodel.h"


class SettingModel : public BaseModel
{

public:
    typedef BaseModel super;
    SettingModel();
    ~SettingModel();


    //QString tableName = "settings";
    static QString tableName;
    static QMap<QString, int> tableFields;

    static QMap<QString, int> getTableFields();


    bool timestamp = true;
    QMap<QString, QString> timestampFields;


    bool softDelete = true;


    bool add(QVariantMap data);

    bool saveCountMode(int countDown);

    bool saveSetting(QVariantMap data);
};



#endif //SETTINGMODEL_H
