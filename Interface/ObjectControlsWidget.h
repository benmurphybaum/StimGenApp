#ifndef OBJECTCONTROLSWIDGET_H
#define OBJECTCONTROLSWIDGET_H

#include "StimulusObject.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ObjectControlsWidget : public QWidget
{
	Q_OBJECT
public:
	ObjectControlsWidget(QWidget* parent = nullptr);

	void updateControls(StimulusObject* object);
private:
	Ui::MainWindow *ui;

	QList<QWidget*> _controlList;
};

#endif // OBJECTCONTROLSWIDGET_H
