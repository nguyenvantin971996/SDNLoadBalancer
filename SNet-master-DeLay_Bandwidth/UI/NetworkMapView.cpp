#include "NetworkMapView.h"

NetworkMapView::NetworkMapView(QWidget *parent) : QLabel(parent)
{
    initialize();
}

void NetworkMapView::initialize()
{
    setText("");
    setMinimumSize(QSize(2000, 768));
    setStyleSheet("QLabel { background-color: white; }");
}

void NetworkMapView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        emit signalMouseLeftButtonReleased(event->pos());
    }
}

void NetworkMapView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        emit signalMouseLeftButtonPressed(event->pos());
    }
}

void NetworkMapView::mouseMoveEvent(QMouseEvent *event)
{
    emit signalMouseMoved(event->pos());
}

void NetworkMapView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        emit signalMouseDoubleClicked(event->pos());
    }
}

void NetworkMapView::refresh(QPixmap image)
{
    setPixmap(image);
}


