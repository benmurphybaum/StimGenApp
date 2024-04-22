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

		// Select that item in the list
		setCurrentRow(_objectList.size()-1);
	}

	QList<StimulusObject*> stimulus() const {return _objectList;}

private:
	QList<StimulusObject*> _objectList;

private slots:

	/**
	 * @brief Relay the currentRowChanged signal onto the MainWindow with the stimulus data
	 * @param currentRow
	 */
	void onCurrentRowChanged(int currentRow)
	{
		emit selectedStimulusChanged(_objectList.at(currentRow));
	}

signals:
	void selectedStimulusChanged(StimulusObject* currentStimulusObject);

};

#endif // STIMULUSOBJECTLIST_H
