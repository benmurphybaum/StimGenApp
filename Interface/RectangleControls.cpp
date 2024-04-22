#include "RectangleControls.h"
#include "Interface/ui_RectangleControls.h"

RectangleControls::RectangleControls(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::RectangleControls)
{
	ui->setupUi(this);

	_length = ui->length;
	_width = ui->width;
	_intensity = ui->intensity;
}

RectangleControls::~RectangleControls()
{
	delete ui;
}
