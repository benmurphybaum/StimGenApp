#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "StimulusObject.h"

namespace StimGen
{
	class Rectangle : public StimulusObject
	{
		Q_OBJECT
	public:
		Rectangle();
		int width() const {return _width;}
		int length() const {return _length;}
		int angle() const {return _angle;}

		virtual void updateControls() override {};
		virtual QVector<float> recalculate(RenderWidget* renderer) override {return QVector<float>();}

	private:
		int _width {0};
		int _length {0};
		int _angle {0}; // degrees
	};
}

#endif // RECTANGLE_H
