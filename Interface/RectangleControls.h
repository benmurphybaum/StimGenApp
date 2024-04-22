#ifndef RECTANGLECONTROLS_H
#define RECTANGLECONTROLS_H

#include "qspinbox.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class RectangleControls;
}
QT_END_NAMESPACE

class RectangleControls : public QWidget
{
	Q_OBJECT
public:
	explicit RectangleControls(QWidget *parent = nullptr);
	~RectangleControls();

	int length() {return _length->value();}
	void setLength(int value) {_length->setValue(value);}

	int width() {return _width->value();}
	void setWidth(int value) {_width->setValue(value);}

	int intensity() {return _intensity->value();}
	void setIntensity(int value) {_intensity->setValue(value);}

private:
	Ui::RectangleControls* ui;

	QSpinBox* _length {nullptr};
	QSpinBox* _width {nullptr};
	QSpinBox* _intensity {nullptr};
};

#endif // RECTANGLECONTROLS_H
