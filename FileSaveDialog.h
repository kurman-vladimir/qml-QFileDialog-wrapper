#ifndef FILESAVEDIALOG_H
#define FILESAVEDIALOG_H

#include <QQuickWindow>
#include <QUrl>

class QFileDialog;

class FileSaveDialog : public QQuickWindow
{
    Q_OBJECT

    Q_PROPERTY(QUrl fileUrl READ fileUrl NOTIFY fileUrlChanged)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QStringList nameFilters READ nameFilters WRITE setNameFilters NOTIFY nameFiltersChanged)
    Q_PROPERTY(QWindow* windowForActivateRequesting READ windowForActivateRequesting WRITE setWindowForActivateRequesting NOTIFY windowForActivateRequestingChanged)

public:
    explicit FileSaveDialog(QWindow *parent = nullptr);
    ~FileSaveDialog();

    bool valid() const;

    QUrl fileUrl() const;

    QString fileName() const;
    void setFileName(QString fileName);

    QString title() const;
    void setTitle(QString title);

    QStringList nameFilters() const;
    void setNameFilters(QStringList nameFilters);

    QWindow *windowForActivateRequesting() const;

    Q_INVOKABLE void open();
    Q_INVOKABLE void close();

public slots:
    void setWindowForActivateRequesting(QWindow* windowForActivateRequesting);

signals:
    void fileUrlChanged(QUrl fileUrl);
    void fileNameChanged(QString filename);
    void titleChanged(QString title);
    void nameFiltersChanged(QStringList filters);
    void accepted();
    void rejected();
    void windowForActivateRequestingChanged(QWindow* windowForActivateRequesting);

protected slots:
    virtual void accept();
    virtual void reject();

private:
    void setFileUrl(QUrl fileUrl);

    QUrl m_fileUrl;
    QString m_fileName;
    QString m_title;
    QStringList m_nameFilters;

    QFileDialog* m_fileDialog;
    QWindow* m_windowForActivateRequesting;
};

#endif // FILESAVEDIALOG_H
