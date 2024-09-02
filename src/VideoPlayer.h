#ifndef VIEWER_VIDEOPLAYER_H
#define VIEWER_VIDEOPLAYER_H

#include <iostream>

#include <QObject>
#include <QScopedPointer>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QImage>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


class VideoPlayer : public QObject
{
	Q_OBJECT

	QBasicTimer _timer;
	cv::Mat _frame;
	QScopedPointer<cv::VideoCapture> _videoCapture;
	QImage _image;

public:
	VideoPlayer(QObject* parent = {}) : QObject(parent) {}
	
	void start(int cam = 0)
	{
		_videoCapture.reset(new cv::VideoCapture(cam));
		_frame = cv::Mat();

		if (_videoCapture->isOpened())
		{
			_timer.start(std::chrono::milliseconds(0), this);
			emit started();
		}
	}

	void pause() {
		_timer.stop();
		emit paused();
	}

	void resume() { _timer.start(std::chrono::milliseconds(0), this); }

signals:
	void started();
	void paused();
	void frameReady(const QImage&);

private:

	void timerEvent(QTimerEvent* ev)
	{
		if (ev->timerId() != _timer.timerId())
			return;

		if (!_videoCapture->read(_frame))
		{
			_timer.stop();
			return;
		}

		_image = QImage(_frame.data, _frame.cols, _frame.rows, _frame.step, QImage::Format_BGR888);
		// _frame.release();

		emit frameReady(_image);
	}

};


#endif // VIEWER_VIDEOPLAYER_H