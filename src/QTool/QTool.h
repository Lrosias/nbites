/**
 * @class QTool
 * main QTool class
 * inherits from qmainwindow
 *
 * @author Octavian Neamtu
 */

#pragma once

#include <qmainwindow.h>
#include <qtabwidget.h>

#include "ColorCreator/colorcreator.h"

namespace QTool {

class QTool : public QMainWindow {

    Q_OBJECT

public:
    QTool();
    ~QTool();

private:
    QTabWidget* toolTabs;

    ColorCreator* colorCreator;

};

}
