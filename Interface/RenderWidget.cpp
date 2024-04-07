#include "RenderWidget.h"
#include "Circle.h"

#include <QOpenGLFunctions>
#include <QElapsedTimer>

#include <QMatrix4x4>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

RenderWidget::RenderWidget(QWidget* parent)
	: QOpenGLWidget(parent)
{
	QSizePolicy policy = sizePolicy();
	policy.setHeightForWidth(true);
	setSizePolicy(policy);

	QSurfaceFormat format = this->format();
	format.setSwapInterval(1);
	format.setVersion(4,6);
	format.setSwapBehavior(QSurfaceFormat::TripleBuffer);
	setFormat(format);
	connect(this, &QOpenGLWidget::frameSwapped, this, &RenderWidget::onFrameSwapped);
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

void RenderWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (_rendering)
	{
		StimGen::Circle* circleObject {nullptr};
		switch(_stimulus.at(0)->type())
		{
			case StimulusType::Circle:
				circleObject = static_cast<StimGen::Circle*>(_stimulus.at(0));
				break;
			case StimulusType::Rectangle:
				break;
		}

		QMatrix4x4 projection;
		projection.setToIdentity();
		projection.ortho(0, width(), 0, height(), -1, -1);

		QOpenGLShaderProgram program;
		program.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
		program.addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
		program.link();
		program.bind();

		program.setUniformValue("projection", projection);

		QOpenGLVertexArrayObject vao;
		vao.create();
		vao.bind();

		QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
		vbo.create();
		vbo.bind();

		float radius = 0;
		if (circleObject->diameter() > 0)
		{
			radius = (float)circleObject->diameter()/(float)width();
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

		vbo.allocate(vertices.data(), vertices.size() * sizeof(float));
		program.enableAttributeArray(0);
		program.setAttributeBuffer(0, GL_FLOAT, 0, 2);

		glDrawArrays(GL_LINE_LOOP, 0, segments + 1);

		program.disableAttributeArray(0);
		vao.release();
		vbo.release();
		program.release();

		update();
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}

void RenderWidget::render(QList<StimulusObject*> stimulus)
{
	_frameCount = 0;
	_rendering = true;
	_stimulus = stimulus;
	start();
}

void RenderWidget::start()
{
	timer.restart();
	update();
}


/// Slots
void RenderWidget::onFrameSwapped()
{
	_frameCount++;
	if (_rendering)
	{
		emit frameRateUpdate((float)timer.nsecsElapsed());
	}
	timer.restart();
}
