#include "TextLabel.h"
#include "TextLabelDialog.h"
#include "XmlSerializer.h"
#include "NetworkMapDrawer.h"

TextLabel::TextLabel(QPoint position, bool quickConfig) : content("Text...")
{
    unselect();
    setPosition(position);
    if (quickConfig)
    {
        configure();
    }
}

QSize TextLabel::getSize() const
{
    QFontMetrics fontMetrics(QFont("Any", 11));
    return fontMetrics.size(Qt::TextExpandTabs, content);
}

void TextLabel::draw(NetworkMapDrawer *drawer)
{
    if (isSelected)
    {
        drawer->drawSelectedText(content, getPosition());
    }
    else
    {
        drawer->drawText(content, getPosition());
    }
}

void TextLabel::configure()
{
    TextLabelDialog dialog(this);
    dialog.exec();
}

void TextLabel::addDataIn(XmlSerializer *builder)
{
    builder->addTextLabelData(this);
}

