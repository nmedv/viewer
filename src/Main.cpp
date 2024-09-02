#include <QApplication>
#include <QFile>

#include "MainWindow.h"


int main(int argc, char* argv[])
{
	QApplication app (argc, argv);
	ViewerMainWindow window;

	QFile file ("styles/Style.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet { file.readAll() };
	app.setStyleSheet(styleSheet);

	window.show();

	return app.exec();
}
