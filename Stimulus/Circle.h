#ifndef CIRCLE_H
#define CIRCLE_H

#include "StimulusObject.h"

namespace StimGen
{
	class Circle : public StimulusObject
	{
		Q_OBJECT
	public:
		Circle();
		int diameter() const {return _diameter;}
		void setDiameter(int value) {_diameter = value;}
	private:
		int _diameter {0};
	};

}

#endif // CIRCLE_H
