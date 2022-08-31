#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QObject>
#include <QQmlEngine>
#include <QUrl>

class MyImage : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
public:
    explicit MyImage(QObject* parent = nullptr);

    const QUrl& url() const;
    void setUrl(const QUrl& newUrl);

signals:
    void urlChanged();

private:
    QUrl m_url{"qrc:/icons/home"};
};

#endif  // MYIMAGE_H
