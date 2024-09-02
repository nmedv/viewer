#ifndef VIEWER_DIALOG_H
#define VIEWER_DIALOG_H

#include <QDialog>
#include <QPushButton>


class ViewerNewTabDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ViewerNewTabDialog(QWidget *parent = nullptr)
		: QDialog(parent, Qt::Dialog)
	{
		setWindowTitle("Select input data");

		_okButton = new QPushButton(this);
		_okButton->setText("OK");
	}
	
private:
	QPushButton* _okButton;
	
};


#endif