#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include "StimulusObject.h"

#include <QLabel>
#include <QElapsedTimer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	RenderWidget(QWidget* parent = nullptr);
	void render(QList<StimulusObject*> stimulus);
	void start();

	bool isRendering() {return _rendering;}

protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

private:
	bool _blockResize {false};

	QOpenGLFunctions* f {nullptr};

	QElapsedTimer timer;
	int _frameCount {0};

	bool _rendering {false};
	bool _editing {false};

	QLabel* _fpsCounter {nullptr};

	QList<StimulusObject*> _stimulus;

	const char* vertexShaderSource =
		"#version 460 core\n"
		"uniform mat4 projection;\n"
		"layout (location = 0) in vec2 position;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = projection * vec4(position, 0.0, 1.0);\n"
		"}\n";

	const char *fragmentShaderSource =
		"#version 460 core\n"
		"layout (location = 0) out vec4 color;"
		"void main()\n"
		"{\n"
		"   color = vec4(0.5, 0.5, 1.0, 1.0);\n"
		"}\n\0";

public slots:
	void onStopRendering() {_rendering = false; _stimulus.clear(); repaint();}

private slots:
	void onFrameSwapped();

signals:
	void frameRateUpdate(float rate);
};

#endif // RENDERWIDGET_H
