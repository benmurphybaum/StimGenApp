#ifndef CIRCLE_H
#define CIRCLE_H

#include "StimulusObject.h"

class Circle : public StimulusObject
{
	Q_OBJECT
public:
	Circle();
	int diameter() {return _diameter;}

private:
	int _diameter {0};
};

#endif // CIRCLE_H
