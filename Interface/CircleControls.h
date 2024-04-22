#ifndef CIRCLECONTROLS_H
#define CIRCLECONTROLS_H

#include <QWidget>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class CircleControls;
}
QT_END_NAMESPACE

enum class Parameter
{
	diameter,
	intensity,
};

class CircleControls : public QWidget
{
	Q_OBJECT
public:
	explicit CircleControls(QWidget *parent = nullptr);
	~CircleControls();

	int diameter() {return _diameter->value();}
	void setDiameter(int value) {_diameter->setValue(value);}

	int intensity() {return _intensity->value();}
	void setIntensity(int value) {_intensity->setValue(value);}

private:
	Ui::CircleControls* ui;

	QSpinBox* _diameter {nullptr};
	QSpinBox* _intensity {nullptr};

private slots:
	void on_diameter_valueChanged(int arg1);

	void on_intensity_valueChanged(int arg1);

signals:
	void diameterChanged(int value);
	void intensityChanged(int value);
};

#endif // CIRCLECONTROLS_H
