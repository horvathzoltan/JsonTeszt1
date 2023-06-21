#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>

/// "{"resultCode":101,"device":{"deviceId":"macaddress","deviceName":"Teszt gép PI","active":false,"lastDeviceLoginDate":null,"comments":"","applications":null}}"
/// https://thecodeprogram.com/how-to-use-json-data-with-qt-c--

#include "webapi/deviceresponse.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray jsonData = QStringLiteral(R"({"resultCode":101,"device":{"deviceId":"macaddress","deviceName":"Teszt gép PI","active":false,"lastDeviceLoginDate":null,"comments":"","applications":null}})").toUtf8();

    qDebug()<<"dsonData:"<<jsonData;

    if(jsonData.isEmpty() == true) qDebug() << "Need to fill JSON data";

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    if(jsonDocument.isObject() == false) qDebug() << "It is not a JSON object";
    QJsonObject object = jsonDocument.object();

    DeviceResponse deviceResponse = DeviceResponse::JsonParse(object);

    qDebug()<<"deviceResponse:"<<deviceResponse.resultCode;
    qDebug()<<"deviceName:"<<deviceResponse.device.deviceName;
    return a.exec();
}
