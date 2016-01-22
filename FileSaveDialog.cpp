#include "FileSaveDialog.h"
#include <QApplication>
#include <QFileDialog>

FileSaveDialog::FileSaveDialog(QWindow *parent) :
    QQuickWindow(parent),
    m_fileDialog(new QFileDialog)
{
    setModality(Qt::ApplicationModal);

    m_fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    m_fileDialog->setFileMode(QFileDialog::AnyFile);
    m_fileDialog->setModal(true);

    connect(m_fileDialog, &QFileDialog::accepted, this, &FileSaveDialog::accept);
    connect(m_fileDialog, &QFileDialog::rejected, this, &FileSaveDialog::reject);

    connect(this, &FileSaveDialog::titleChanged, m_fileDialog, &QFileDialog::setWindowTitle);
    connect(this, &FileSaveDialog::nameFiltersChanged, m_fileDialog, &QFileDialog::setNameFilters);
    connect(this, &FileSaveDialog::fileNameChanged, m_fileDialog, &QFileDialog::selectFile);
}

FileSaveDialog::~FileSaveDialog()
{
    delete m_fileDialog;
}

QUrl FileSaveDialog::fileUrl() const
{
    return m_fileUrl;
}

void FileSaveDialog::setFileUrl(QUrl fileUrl)
{
    if (m_fileUrl == fileUrl)
        return;

    m_fileUrl = fileUrl;
    emit fileUrlChanged(fileUrl);
}

QString FileSaveDialog::fileName() const
{
    return m_fileName;
}

void FileSaveDialog::setFileName(QString filename)
{
    if (m_fileName == filename)
        return;

    m_fileName = filename;
    emit fileNameChanged(filename);
}

QString FileSaveDialog::title() const
{
    return m_title;
}

void FileSaveDialog::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(title);
}

QStringList FileSaveDialog::nameFilters() const
{
    return m_nameFilters;
}

void FileSaveDialog::setNameFilters(QStringList nameFilters)
{
    if (m_nameFilters == nameFilters)
        return;

    m_nameFilters = nameFilters;
    emit nameFiltersChanged(nameFilters);
}

QWindow *FileSaveDialog::windowForActivateRequesting() const
{
    return m_windowForActivateRequesting;
}

void FileSaveDialog::open()
{
    m_fileDialog->show();
}

void FileSaveDialog::close()
{
    m_fileDialog->close();
    windowForActivateRequesting()->requestActivate();
}

void FileSaveDialog::setWindowForActivateRequesting(QWindow *windowForActivateRequesting)
{
    if (m_windowForActivateRequesting == windowForActivateRequesting)
        return;

    m_windowForActivateRequesting = windowForActivateRequesting;
    emit windowForActivateRequestingChanged(windowForActivateRequesting);
}

void FileSaveDialog::accept()
{
    QStringList selectedUrls = m_fileDialog->selectedFiles();
    if (!selectedUrls.empty())
        setFileUrl(selectedUrls.at(0));
    close();
    emit accepted();
}

void FileSaveDialog::reject()
{
    close();
    emit rejected();
}
