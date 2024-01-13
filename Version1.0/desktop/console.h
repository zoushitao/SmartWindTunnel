

#ifndef CONSOLE_H
#define CONSOLE_H

#include <QPlainTextEdit>
#include <QVector>
#include <QListView>
#include <QStringListModel>
#include <QEventLoop>
class Console : public QPlainTextEdit
{
    Q_OBJECT

signals:
    void getData(const QByteArray &data);

public:
    explicit Console(QWidget *parent = nullptr);

    void putData(const QByteArray &data);
    void setLocalEchoEnabled(bool set);

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;

private:
    bool m_localEchoEnabled = false;
    QVector<unsigned int> m_sheer_mode_list;
    //model for sheer mode
    QStringListModel m_model;
    QStringList m_dataList;
};

#endif // CONSOLE_H
