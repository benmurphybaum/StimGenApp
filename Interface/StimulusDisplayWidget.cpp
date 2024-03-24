#include "StimulusDisplayWidget.h"

StimulusDisplayWidget::StimulusDisplayWidget(QWidget* parent)
	: QOpenGLWidget(parent)
{
	QSizePolicy policy = sizePolicy();
	policy.setHeightForWidth(true);
	setSizePolicy(policy);
}

void StimulusDisplayWidget::resizeEvent(QResizeEvent* event)
{
	if (_blockResize)
	{
		_blockResize = false;
		return;
	}

	QRect size = geometry();
	if (size.height() > size.width())
	{
		_blockResize = true;
		setGeometry(size.x(), size.y(), size.width(), size.width());
	}
	else
	{
		_blockResize = true;
		setGeometry(size.x(), size.y(), size.height(), size.height());
	}
}
