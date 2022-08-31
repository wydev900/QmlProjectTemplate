#include "MyImage.h"

MyImage::MyImage(QObject *parent)
    : QObject{parent}
{

}

const QUrl& MyImage::url() const
{
    return m_url;
}

void MyImage::setUrl(const QUrl& newUrl)
{
    if (m_url == newUrl)
        return;
    m_url = newUrl;
    emit urlChanged();
}
