#ifndef STIMULUSDISPLAYWIDGET_H
#define STIMULUSDISPLAYWIDGET_H

#include "qopenglwidget.h"

class StimulusDisplayWidget : public QOpenGLWidget
{
public:
	StimulusDisplayWidget(QWidget* parent = nullptr);

protected:
	virtual void resizeEvent(QResizeEvent* event) override;

private:
	bool _blockResize {false};
};

#endif // STIMULUSDISPLAYWIDGET_H
