// 
//#include <iostream>
#include <QDir>
#include <QTextStream>
//#include <QCoreApplication>
//#include <iostream>

void help();

int main(int argc, char* argv[]) {
  //QCoreApplication a(argc, argv);

  QTextStream qout(stdout); // direct stream to stdout (console)

  if (argc == 1) { // no input argument is given
    qout << "No argument is given.\nType -h for help.\n";
    return 0;    
  }

  /* Get input parameters */
  int i = 1;
  if (!strcmp(argv[i], "-h")) {
    help(); // call help function
    return 0;
  }

  QString f_rel = argv[i];
  QFileInfo fi(f_rel);
  if (!fi.exists()) { // return if file does not exist.
    qout << "File does not exists.\n";
    return 0;
  }

  //QDir dir(".");
  //QString s = dir.absoluteFilePath(f_rel);
  //qout << s << endl;

  QDir rel_dir(".");
  QString f_abs = rel_dir.absoluteFilePath(argv[i]);

  // remove any "." and ".." elements from path
  QDir abs_dir(f_abs);
  QString f_canonical = abs_dir.canonicalPath();

  qout << f_canonical << endl;

  //QDir rel_dir(current());
  //QDir wdir = QDir::current();
  //qout << wdir.currentPath() << endl;
  //qout << argv[i] << endl;

  return 0;
}


void help() {
  QTextStream qout(stdout);

  qout << "qlsp:\n";
  qout << "Converting relative to absolute file paths using the Qt \
library.\n\n";
  

}

