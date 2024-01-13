
#include "Panel.h"

#include <QScrollBar>

Panel::Panel(QWidget *parent) :
    QPlainTextEdit(parent)
{
    document()->setMaximumBlockCount(100);
    QPalette p = palette();
    //p.setColor(QPalette::Base, Qt::black);
    //p.setColor(QPalette::Text, Qt::green);
    setPalette(p);
}

void Panel::putData(const QByteArray &data)
{
    insertPlainText(data);

    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Panel::setLocalEchoEnabled(bool set)
{
    m_localEchoEnabled = set;
}

void Panel::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
        break;
    default:
        if (m_localEchoEnabled)
            QPlainTextEdit::keyPressEvent(e);
        emit getData(e->text().toLocal8Bit());
    }
}

void Panel::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    setFocus();
}

void Panel::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
}

void Panel::contextMenuEvent(QContextMenuEvent *e)
{
    Q_UNUSED(e);
}
