
#include "db.h"
#include "basemodel.h"

QString BaseModel::tableName;
QString BaseModel::tableFullName;
QString BaseModel::tablePrefix = "ts_";

QMap<QString, int> BaseModel::tableFields;

BaseModel::BaseModel()
{
    //setTableInfo();
}

//void BaseModel::setTableInfo()
//QMap<QString, int> BaseModel::setTableInfo()
QMap<QString, int> BaseModel::getTableFields()
{
    QString table = getTableName();
    qDebug() << "table got in BaseModel: " << table;

    QString sql = "PRAGMA table_info("+table+")";
    QStringList keys;
    keys << "cid" << "name";

    static DB& db = DB::instance();
    QList<QVariantMap> tableInfoList = db.query(sql, keys); // QList<QMap<QString, QVariant>>

    QMap<QString, int> tableInfo;
    QVariantMap field;
    foreach(field, tableInfoList){
            tableInfo[field["name"].toString()] = field["cid"].toInt();
        }
    return tableInfo;
}

QString BaseModel::getTableName()
{
    if(!tableFullName.isEmpty()){
        return tableFullName;
    }
    return tablePrefix + tableName;
}
