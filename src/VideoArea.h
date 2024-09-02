#ifndef VIEWER_VIDEOAREA_H
#define VIEWER_VIDEOAREA_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QThread>

#include "VideoPlayer.h"


class VideoArea : public QScrollArea
{
	Q_OBJECT

public:
	explicit VideoArea(QWidget *parent = nullptr);
	~VideoArea();
	
	void startPlay(int cam = 0);
	void stopPlay();
	void clear();

signals:
	void startPlaying(int cam);
	void stopPlaying();
	
private slots:
	
	void drawImage(const QImage& image);

private:
	QLabel* _label;
	QThread _videoPlayerThread;
	VideoPlayer _videoPlayer;
	
};


#endif // VIEWER_VIDEOAREA_H