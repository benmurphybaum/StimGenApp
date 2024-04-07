#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RenderWidget.h"
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

public slots:
	void onFrameRateUpdate(float rate) {_fpsCounter->setText(QString::number(1e9f/rate, 'f', 2) % QLatin1String(" Hz"));}

private slots:
	void on_addObject_Button_clicked();
	void on_previewStimulus_Button_clicked();

	void onStimulusObjectRequested(StimulusType type);
	void on_diameter_Setting_valueChanged(int arg1);

private:
	Ui::MainWindow *ui;

	StimulusObjectList* _stimulusObjectList {nullptr};
	StimulusBank* _stimulusBank {nullptr};
	RenderWidget* _stimulusPreview {nullptr};

	QLabel* _fpsCounter {nullptr};
signals:
	void stopRendering();
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
