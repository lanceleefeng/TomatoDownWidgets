

#include <QtSql>
#include <QSqlTableModel>

#include "db.h"
#include "settingmodel.h"

QString SettingModel::tableName = "settings";
QMap<QString, int> SettingModel::tableFields;

SettingModel::SettingModel()
    //: tableName("settings222")
{

    //super::tableName = tableName; // need: typedef BaseModel super
    //super::tableFullName = tableFullName;
    //tableFields = setTableInfo(); // super::setTableInfo();
    if(tableFields.isEmpty()){
        tableFields = getTableFields();
    }
    qDebug() << __FUNCTION__;
    QMap<QString, int>::const_iterator i = tableFields.constBegin();
    while(i != tableFields.constEnd()){
        qDebug() << i.key() << ": " << i.value();
        ++i;
    }

    QString tableInfo = "PRAGMA table_info(" + this->tableName + ")";
    QStringList keys;
    keys << "cid" << "name";

    static DB& db = DB::instance();
    //db.query(tableInfo);
    QList<QMap<QString, QVariant>> tableInfoList = db.query(tableInfo, keys);

    //QMap<QString, QVariant> item;
    QVariantMap item;
    foreach(item, tableInfoList){
            qDebug() << item["name"].toString() << ": " << item["cid"].toInt();
        }


    //QList<QString, QVariant$data

    //QMap<QString, QVariant>  == QVariantMap
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");


    // 写入顺序不可靠：2017-6-28 23:25:02
    // QHash没有固定顺序；
    // QMap按键名排序，与写入顺序无关

    QVariantMap data;
    data["uid"] = 1;
    data["auto_start"] = 0;
    //data["countdown"] = 0;
    data["created_at"] = currentTime;
    data["updated_at"] = currentTime;

    // 有一些值可能没有提供，因此用键保存名字，用值保存数据表上对应的索引比较好
    // 遍历的时候不是遍历索引，而是遍历数据，没有的不设置，使用默认值

    // bool addRes = this->add(data);


}

SettingModel::~SettingModel()
{

}


QMap<QString, int> SettingModel::getTableFields()
{
    if(tableFields.isEmpty()){
        super::tableName = tableName;
        super::tableFullName = tableFullName;
        tableFields = super::getTableFields();
    }
    return tableFields;
}

bool SettingModel::add(QVariantMap data)
{

    qDebug() << "SettingModel::add";

    QMap<QString, int> index;
    index["id"] = 0;
    index["uid"] = 1;
    index["auto_start"] = 2;
    index["countdown"] = 3;
    index["created_at"] = 4;
    index["updated_at"] = 5;



    // 这是表字段顺序，能通过sql查询搞定吗？


    QSqlTableModel *model = new QSqlTableModel(Q_NULLPTR, DB::instance().conn);
    model->setTable("t_settings");

    int row = 0;
    bool res = model->insertRows(row, 1);

    /*QMap<QString, int>::const_iterator i = index.constBegin();
    while(i != index.constEnd()){
        int dataIndex = i.value();
        QString dataKey = i.key();

        ++i;
    }
    */

    QMap<QString, QVariant>::const_iterator i = data.constBegin();
    while(i != data.constEnd()){

        QString dataKey = i.key();
        QString dataVal = i.value().toString();
        int dataIndex = index[dataKey];
        QString dataIndex2 = dataKey;

        qDebug() << "index: " << dataIndex << "; " << dataKey << ": " << dataVal ;
        model->setData(model->index(row, dataIndex), dataVal);
        //model->setData(model->index(row, dataIndex2), dataVal);

        ++i;

    }

    model->submitAll();


    return true;
}


bool SettingModel::saveCountMode(int countDown)
{
    qDebug() << "in " << __FUNCTION__ << "保存到数据库";

    QVariantMap data;
    data["countdown"] = countDown > 0 ? 1 : 0;

    return saveSetting(data);
}

bool SettingModel::saveSetting(QVariantMap data)
{
    qDebug() << "in " << __FUNCTION__;

    static DB& db = DB::instance();

    //db.exec(table, data, fields);

    //if()
    //add(data);
    //add(data, table, fields);

    //update(data, condition);
    //update(data, condition, table, fields)



    return true;


}
