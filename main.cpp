#include "Interface/MainWindow.h"
#include "StimGenApp.h"

int main(int argc, char *argv[])
{
	StimGenApp stimgen(argc, argv);
	stimgen.setStyle("fusion");

	MainWindow w;
	w.show();
	return stimgen.exec();
}
