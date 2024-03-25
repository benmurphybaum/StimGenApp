#ifndef STIMULUSOBJECTLIST_H
#define STIMULUSOBJECTLIST_H

#include "StimulusObject.h"
#include <QListWidget>

class StimulusObjectList : public QListWidget
{
	Q_OBJECT
public:
	StimulusObjectList(QWidget* parent = nullptr);

	void add(StimulusObject* obj)
	{
		_objectList.append(obj);
		switch(obj->type())
		{
			case StimulusType::Circle:
				addItem("Circle");
				break;
			case StimulusType::Rectangle:
				addItem("Rectangle");
				break;
		}
	}

	QList<StimulusObject*> stimulus() const {return _objectList;}

private:
	QList<StimulusObject*> _objectList;
};

#endif // STIMULUSOBJECTLIST_H
