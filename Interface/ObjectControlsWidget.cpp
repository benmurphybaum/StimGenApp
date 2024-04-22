#include "ObjectControlsWidget.h"
#include "CircleControls.h"
#include <QLayout>
#include "Rectangle.h"
#include "RectangleControls.h"

#include "Circle.h"


ObjectControlsWidget::ObjectControlsWidget(QWidget* parent)
	: QWidget(parent)
{

}

void ObjectControlsWidget::updateControls(StimulusObject* object)
{
	if (!_controlList.isEmpty())
	{
		for (const auto& control : _controlList)
		{
			control->deleteLater();
		}
		_controlList.clear();
	}

	QWidget* baseWidget;
	switch (object->type())
	{
		case StimulusType::Circle:
		{
			CircleControls* controlWidget = new CircleControls(this);

			StimGen::Circle* circleObject = static_cast<StimGen::Circle*>(object);
			controlWidget->setDiameter(circleObject->diameter());
			controlWidget->setIntensity(circleObject->intensity());
			baseWidget = static_cast<QWidget*>(controlWidget);

			connect(controlWidget, &CircleControls::diameterChanged, circleObject, &StimGen::Circle::onDiameterChanged);
			connect(controlWidget, &CircleControls::intensityChanged, circleObject, &StimGen::Circle::onIntensityChanged);
			break;
		}
		case StimulusType::Rectangle:
		{
			RectangleControls* controlWidget = new RectangleControls(this);

			StimGen::Rectangle* rectangleObject = static_cast<StimGen::Rectangle*>(object);
			controlWidget->setLength(rectangleObject->length());
			controlWidget->setWidth(rectangleObject->width());
			controlWidget->setIntensity(rectangleObject->intensity());
			baseWidget = static_cast<QWidget*>(controlWidget);
			break;
		}
	}

	QLayout* layout = this->layout();
	layout->addWidget(baseWidget);
	_controlList.push_back(baseWidget);
	baseWidget->show();
}
