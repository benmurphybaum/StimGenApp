#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StimulusObjectList.h"
#include "StimulusBank.h"
#include "qmenu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_addObject_Button_clicked();
	void onStimulusObjectRequested(StimulusType type);
private:
	Ui::MainWindow *ui;

	StimulusObjectList* _stimulusObjectList {nullptr};
	StimulusBank* _stimulusBank {nullptr};
};


class StimulusTypeMenu : public QMenu
{
	Q_OBJECT
public:
	StimulusTypeMenu(QWidget* parent = nullptr)
		: QMenu(parent)
	{
		QAction* circleAction = addAction("Circle");
		QAction* rectangleAction = addAction("Rectangle");

		connect(circleAction, &QAction::triggered, this, [=]{emit stimulusObjectRequested(StimulusType::Circle);});
		connect(rectangleAction, &QAction::triggered, this, [=]{emit stimulusObjectRequested(StimulusType::Rectangle);});
	}

signals:
	void stimulusObjectRequested(StimulusType type);
};

#endif // MAINWINDOW_H
