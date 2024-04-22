#include "StimulusObjectList.h"

StimulusObjectList::StimulusObjectList(QWidget* parent)
	: QListWidget(parent)
{
	connect(this, &QListWidget::currentRowChanged, this, &StimulusObjectList::onCurrentRowChanged);
}
