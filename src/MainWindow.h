#ifndef VIEWER_MAIN_WINDOW_H
#define VIEWER_MAIN_WINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QScrollArea>
#include <QThread>

#include "Dialog.h"
#include "VideoArea.h"


class ViewerMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit ViewerMainWindow(QWidget* parent = nullptr);

private:
	QMenuBar* _menuBar;
	QMenu* _viewMenu;
	QAction* _viewOpenStream;
	QAction* _viewClose;

	QDockWidget* _dockWidget;

	ViewerNewTabDialog* _newTabDialog;

	QWidget* _centralWidget;
	QVBoxLayout* _vbLayout;
	VideoArea* _videoArea;
};


#endif