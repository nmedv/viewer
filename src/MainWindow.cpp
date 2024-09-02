#include "MainWindow.h"


ViewerMainWindow::ViewerMainWindow(QWidget* parent)
	: QMainWindow(parent)
	, _centralWidget(new QWidget(this))
	, _newTabDialog(new ViewerNewTabDialog(this))
	, _menuBar(new QMenuBar(this))
	, _dockWidget(new QDockWidget(this))
{
	this->resize(640, 480);
	this->setCentralWidget(_centralWidget);

	// Vertical Layout
	_vbLayout = new QVBoxLayout(_centralWidget);
	_vbLayout->setContentsMargins(0, 0, 0, 0);
	_vbLayout->setSpacing(0);

	// Video area
	_videoArea = new VideoArea(_centralWidget);
	_vbLayout->addWidget(_videoArea);

	// Menu Bar
	_viewMenu = new QMenu(_menuBar);
	_viewMenu->setTitle("&View");

	_viewOpenStream = new QAction(_viewMenu);
	_viewOpenStream->setText("Open stream");
	connect(_viewOpenStream, &QAction::triggered, [this]() {
		//_videoArea->stopPlay();
		_newTabDialog->show();
		_videoArea->startPlay(0);
	});

	_viewClose = new QAction(_viewMenu);
	_viewClose->setText("Close");
	connect(_viewClose, &QAction::triggered, this, [this]() {
		_videoArea->stopPlay();
		_videoArea->clear();
	});

	_viewMenu->addAction(_viewOpenStream);
	_viewMenu->addAction(_viewClose);
	_menuBar->addAction(_viewMenu->menuAction());
	this->setMenuBar(_menuBar);

	// Dock Panel
	_dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
	_dockWidget->setWindowTitle("Parameters");
	_dockWidget->setMinimumWidth(170);
	this->addDockWidget(Qt::RightDockWidgetArea, _dockWidget);
}