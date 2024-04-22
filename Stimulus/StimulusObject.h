#ifndef STIMULUSOBJECT_H
#define STIMULUSOBJECT_H

#include <QObject>
#include <QPoint>

class RenderWidget;

enum class StimulusType
{
	Circle,
	Rectangle,
};

enum class ModulationType
{
	Square,
	Sine,
};

struct Velocity
{
	int speed {0};
	int direction {0}; // angle in degrees
};

struct Modulation
{
	ModulationType type {ModulationType::Sine};
	int frequency {0};
};

class StimulusObject : public QObject
{
	Q_OBJECT

public:
	explicit StimulusObject(StimulusType type);

	QString name() {return _name;}
	StimulusType type() {return _type;}

	QPoint offset() {return _offset;}
	QPoint position() {return _position;}
	Velocity velocity() {return _velocity;}

	float intensity() {return _intensity;}
	Modulation modulation() {return _modulation;}

	virtual void updateControls() = 0;

	virtual QVector<float> recalculate(RenderWidget* renderer) = 0;

protected:
	QString _name;
	StimulusType _type;

	QPoint _offset {0,0};
	QPoint _position {0,0};
	Velocity _velocity {0,0};

	float _intensity {0.0};
	Modulation _modulation;
};

#endif // STIMULUSOBJECT_H
