#include "RenderWidget.h"
#include <QOpenGLFunctions>
#include <QElapsedTimer>

RenderWidget::RenderWidget(QWidget* parent)
	: QOpenGLWidget(parent)
{
	QSizePolicy policy = sizePolicy();
	policy.setHeightForWidth(true);
	setSizePolicy(policy);

	QSurfaceFormat format = this->format();
	format.setSwapInterval(1);
	setFormat(format);
	connect(this, &QOpenGLWidget::frameSwapped, this, &RenderWidget::onFrameSwapped);
}

void RenderWidget::resizeEvent(QResizeEvent* event)
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

void RenderWidget::initializeGL()
{
	// Set up the rendering context, load shaders and other resources, etc.:
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // background
}

void RenderWidget::resizeGL(int w, int h)
{
	// update projection matrix and other settings to account for new size
}

void RenderWidget::paintGL()
{
	// Draw the scene
	glClearColor(0.0f, 0.1f, 0.8f, 1.0f);
	update();
}

void RenderWidget::render(QList<StimulusObject*> stimulus)
{
	_frameCount = 0;
	start();
}

void RenderWidget::start()
{
	timer.restart();
	update();
}
