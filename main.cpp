#include "Interface/MainWindow.h"
#include "StimGenApp.h"

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

	StimGenApp stimgen(argc, argv);
	stimgen.setStyle("fusion");

	MainWindow w;
	w.show();
	return stimgen.exec();
}
