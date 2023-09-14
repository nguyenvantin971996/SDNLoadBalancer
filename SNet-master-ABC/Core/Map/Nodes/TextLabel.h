#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "Node.h"
#include "Devicetype.h"

class TextLabel : public Node
{
public:
    TextLabel(QPoint position, bool quickConfig = false);
    inline DeviceType getDeviceType();
    virtual QSize getSize() const;
    void draw(NetworkMapDrawer *drawer);
    inline QString getContent() const;
    inline void setContent(QString text);
    virtual void configure();
    virtual void addDataIn(XmlSerializer *builder);

private:
    QString content;
};

inline DeviceType TextLabel::getDeviceType()
{
    return TEXTLABEL;
}

inline QString TextLabel::getContent() const
{
    return content;
}

inline void TextLabel::setContent(QString text)
{
    content = text;
}

#endif // TEXTLABEL_H
