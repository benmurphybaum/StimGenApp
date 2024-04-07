#include "MainWindow.h"
#include "Interface/ui_MainWindow.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RenderWidget.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	_stimulusObjectList = ui->objectList_ListWidget;
	_stimulusBank = ui->stimulusBank_ListWidget;
	_stimulusPreview = ui->previewWidget;
	_fpsCounter = ui->FPS_Label;

	ui->objectType_Setting->insertItems(0, QStringList({"Circle", "Rectangle"}));
	connect(this, &MainWindow::stopRendering, _stimulusPreview, &RenderWidget::onStopRendering);
	connect(_stimulusPreview, &RenderWidget::frameRateUpdate, this, &MainWindow::onFrameRateUpdate);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_addObject_Button_clicked()
{
	StimulusTypeMenu* clickMenu = new StimulusTypeMenu(this);
	connect(clickMenu, &StimulusTypeMenu::stimulusObjectRequested, this, &MainWindow::onStimulusObjectRequested);

	QPoint menuOrigin = ui->addObject_Button->rect().bottomRight();
	clickMenu->popup(ui->addObject_Button->mapToGlobal(menuOrigin));
}

void MainWindow::onStimulusObjectRequested(StimulusType type)
{
	// Make new stimulus object
	switch(type)
	{
		case StimulusType::Circle:
			_stimulusObjectList->add(new StimGen::Circle());
			break;
		case StimulusType::Rectangle:
			_stimulusObjectList->add(new StimGen::Rectangle());
			break;
	}
}

void MainWindow::on_previewStimulus_Button_clicked()
{
	// Render the stimulus on the indicated OpenGLWidget
	if (_stimulusPreview->isRendering())
	{
		emit stopRendering();
	}
	else
	{
		_stimulusPreview->render(_stimulusObjectList->stimulus());
	}
}


void MainWindow::on_diameter_Setting_valueChanged(int arg1)
{
	if (!_stimulusObjectList->stimulus().isEmpty())
	{
		int selectedRow = _stimulusObjectList->currentRow();
		if (selectedRow != -1)
		{
			StimGen::Circle* object = static_cast<StimGen::Circle*>(_stimulusObjectList->stimulus().at(selectedRow));
			object->setDiameter(arg1);
		}
	}
}

