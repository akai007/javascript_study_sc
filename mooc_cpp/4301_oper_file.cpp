#include <fstream> // 使用文件流
#include <iomanip>

using namespace std; // 文件流定义在std命名空间

int main(int argc, char const *argv[])
{
  char s1[500];
  int cnt = 0;

  ifstream inf("./3801_a_binding.cpp"); // 打开源文件读

  if (!inf.fail())
  {
    ofstream outf("./4031_copy_from_3801.cpp");
    while (!inf.eof())
    {
      inf.getline(s1, sizeof(s1)-1); // 读取一行 且不超过 最大字符
      outf << setfill('0') << setw(4) << ++cnt << " " << s1 << endl;
    }
    
    outf.close();
    inf.close();
  }

  return 0;
}

