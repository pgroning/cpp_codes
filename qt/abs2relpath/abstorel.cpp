// Converting absolute file path to relative path using Qt library

#include <QDir>
#include <QTextStream>


int main() {

  QTextStream qout(stdout); // direct stream to stdout (terminal)
  qout << "Converting file paths" << endl;

  qout << "--- abs to rel file path ---" << endl;
  QDir abs_dir("/home/prog/dvlp/PERG/tmp");
  QString s;
  s = abs_dir.relativeFilePath("/home/prog/dvlp/PERG/test");
  qout << s << endl;

  qout << "--- rel to abs file path ---" << endl;
  QDir rel_dir(".");
  QString s_abs = rel_dir.absoluteFilePath("tmp");
  qout << s_abs << endl;

  qout << "--- dir name ---" << endl;
  QDir my_dir("/home/prog/dvlp/PERG");
  QString s_dirname = my_dir.dirName();
  qout << s_dirname << endl;

  

  return 0;
}
