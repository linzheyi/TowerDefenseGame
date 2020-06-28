#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
class QMediaPlayer;

//实现背景音乐播放

class AudioPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AudioPlayer(QObject *parent = nullptr);

    void startBGM();

private:
    QMediaPlayer *m_backgroundMusic;

signals:

};

#endif // AUDIOPLAYER_H
