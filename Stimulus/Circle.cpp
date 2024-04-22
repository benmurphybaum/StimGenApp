#include "Circle.h"
#include "RenderWidget.h"

using namespace StimGen;

Circle::Circle()
	: StimulusObject(StimulusType::Circle)
{
}

void Circle::updateControls()
{

}


QVector<float> Circle::recalculate(RenderWidget* renderer)
{
	float radius = 0;
	if (diameter() > 0)
	{
		radius = (float)diameter()/(float)renderer->width();
	}
	int segments = 100;

	QVector<float> vertices;
	for (int i = 0; i <= segments; ++i)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(segments);
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);

		vertices.append(x);
		vertices.append(y);
	}

	return vertices;
}
