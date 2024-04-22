#include "CircleControls.h"
#include "Interface/ui_CircleControls.h"

CircleControls::CircleControls(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::CircleControls)
{
	ui->setupUi(this);

	_diameter = ui->diameter;
	_intensity = ui->intensity;
}

CircleControls::~CircleControls()
{
	delete ui;
}



void CircleControls::on_diameter_valueChanged(int arg1)
{
	emit diameterChanged(arg1);
}


void CircleControls::on_intensity_valueChanged(int arg1)
{
	emit intensityChanged(arg1);
}

