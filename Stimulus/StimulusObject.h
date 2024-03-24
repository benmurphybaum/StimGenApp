#ifndef STIMULUSOBJECT_H
#define STIMULUSOBJECT_H

#include <QObject>
#include <QPoint>

enum class StimulusType
{
	Circle,
	Rectangle,
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

	float intensity() {return _intensity;}

private:
	QString _name;
	StimulusType _type;

	QPoint _offset {0,0};
	QPoint _position {0,0};

	float _intensity {0.0};
};

#endif // STIMULUSOBJECT_H
