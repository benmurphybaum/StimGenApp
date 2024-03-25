#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include "StimulusObject.h"
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

protected:
	virtual void resizeEvent(QResizeEvent* event) override;

	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;
private:
	bool _blockResize {false};

	QOpenGLFunctions* f {nullptr};

	QElapsedTimer timer;
	int _frameCount {0};

private slots:
	void onFrameSwapped() {_frameCount++; qDebug() << _frameCount << timer.restart();}
};

#endif // RENDERWIDGET_H
