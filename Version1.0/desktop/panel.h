#include <QPlainTextEdit>

class Panel : public QPlainTextEdit
{
    Q_OBJECT

signals:
    void getData(const QByteArray &data);

public:
    explicit Panel(QWidget *parent = nullptr);

    void putData(const QByteArray &data);
    void setLocalEchoEnabled(bool set);

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;

private:
    bool m_localEchoEnabled = false;
};
