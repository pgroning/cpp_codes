#include "skeleton.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>

Skeleton::Skeleton(QWidget *parent)
  : QMainWindow(parent) {
  
  QPixmap newpix("icons/diagram-icon_32x32.png");
  //QPixmap openpix("open.png");
  QPixmap openpix("icons/open-file-icon_32x32.png");
  //QPixmap quitpix("quit.png");
  QPixmap quitpix("icons/exit-icon_32x32.png");

  QAction *quit = new QAction("&Quit", this);
  
  QMenu *file;
  file = menuBar()->addMenu("&File");
  file->addAction(quit);
  
  connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
  
  QToolBar *toolbar = addToolBar("main toolbar");
  toolbar->addAction(QIcon(newpix), "New File");
  toolbar->addAction(QIcon(openpix), "Open File");
  toolbar->addSeparator();
  
  QAction *quit2 = toolbar->addAction(QIcon(quitpix), 
                                      "Quit Application");
  connect(quit2, SIGNAL(triggered()), qApp, SLOT(quit()));
  
  QTextEdit *edit = new QTextEdit(this);  
  
  setCentralWidget(edit);
  
  statusBar()->showMessage("Ready");
}
