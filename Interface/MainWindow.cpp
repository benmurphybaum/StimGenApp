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

	ui->objectType_Setting->insertItems(0, QStringList({"Circle", "Rectangle"}));
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
	_stimulusPreview->render(_stimulusObjectList->stimulus());
}

