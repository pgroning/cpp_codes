#include <QTextStream>
#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QIcon>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>


class myWindow : public QWidget {
  
  Q_OBJECT
  
public:
  myWindow(QWidget *parent = 0);
                               
  //private slots:
  //void onOK();
  
private:
  QLabel *lbl;

};


/*void myWindow::onOK() {
  

  }*/

myWindow::myWindow(QWidget *parent) : QWidget(parent) {
  
  QGridLayout *grid = new QGridLayout(this); // Defining the layout grid

  QPushButton *quitBtn = new QPushButton("Quit", this);
  //quitBtn->setGeometry(50, 40, 75, 30); // set manual position and size
  connect(quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));

  grid->addWidget(quitBtn,0,0); //adding quitBtn to the grid

  QPushButton *okBtn = new QPushButton("OK", this);
  grid->addWidget(okBtn,0,1); // Adding okBtn to the grid

  //connect(okBtn, SIGNAL(clicked()), this, SLOT(onOK()));

  setLayout(grid);


}

int main(int argc, char *argv[])
{
  
  QTextStream cout(stdout);

  QApplication app(argc, argv);

  //QWidget window;
  myWindow window;

  // Resize and move window
  const int win_width = 500;
  const int win_height = 300;
  window.resize(win_width, win_height);

  QDesktopWidget *desktop = QApplication::desktop();
  int screenwidth = desktop->width();
  int screenheight = desktop->height();
  cout << screenwidth << endl;
  cout << screenheight << endl;

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
