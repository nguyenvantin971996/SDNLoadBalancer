#include "MetricDecoder.h"
#include <QStringList>

QVector<float> MetricDecoder::decode(QString data)
{
    QVector<float> decodedData;
    foreach (QString item, data.split(","))
    {
        decodedData.append(item.toDouble());
    }
    return decodedData;
}
