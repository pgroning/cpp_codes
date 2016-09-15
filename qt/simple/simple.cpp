#include <QTextStream>
#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QIcon>
#include <QPushButton>


class myButton : public QWidget {

public:
  myButton(QWidget *parent = 0);

};


myButton::myButton(QWidget *parent) : QWidget(parent) {

  QPushButton *quitBtn = new QPushButton("Quit", this);
  quitBtn->setGeometry(50, 40, 75, 30);

  connect(quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));
  
}

int main(int argc, char *argv[])
{
  
  QTextStream qout(stdout);

  QApplication app(argc, argv);

  //QWidget window;
  myButton window;

  // Resize and move window
  const int win_width = 500;
  const int win_height = 300;
  window.resize(win_width, win_height);

  QDesktopWidget *desktop = QApplication::desktop();
  int screenwidth = desktop->width();
  int screenheight = desktop->height();
  qout << screenwidth << endl;
  qout << screenheight << endl;

  int x = (screenwidth - win_width)/2;
  int y = (screenheight - win_height)/2;
  window.move(x-500, y);

  // Set title
  window.setWindowTitle("Simple Qt window");
  window.show();

  // Show tool tip
  window.setToolTip("This is a Qwidget");

  // Add an application icon
  window.setWindowIcon(QIcon("bird-icon_32x32.png"));

  return app.exec();

}
