#include <QSizePolicy>
#include "VideoArea.h"


VideoArea::VideoArea(QWidget *parent)
	: QScrollArea(parent)
	, _label(new QLabel(this))
{
	this->setWidgetResizable(true);
	this->setWidget(_label);
	_label->setAlignment(Qt::AlignCenter);
	
	_videoPlayer.moveToThread(&_videoPlayerThread);
	connect(this, &startPlaying, &_videoPlayer, &VideoPlayer::start);
	connect(this, &stopPlaying, &_videoPlayer, &VideoPlayer::pause);
	connect(&_videoPlayer, &VideoPlayer::frameReady, this, &drawImage);
	_videoPlayerThread.start();
}


VideoArea::~VideoArea()
{
	_videoPlayerThread.quit();
	_videoPlayerThread.wait();
}


void VideoArea::startPlay(int cam)
{
	emit startPlaying(cam);
}


void VideoArea::stopPlay()
{
	emit stopPlaying();
}


void VideoArea::clear()
{
	_label->clear();
}


void VideoArea::drawImage(const QImage& image)
{
	_label->setPixmap(QPixmap::fromImage(image));
}