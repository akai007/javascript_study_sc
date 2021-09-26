#include <iostream>
#include <fstream>

using namespace std; // 文件流定义在 std 命名空间中

int main() {
  char src[260], dest[260], buff[16 * 1024]; // 读写缓冲达到16k
  ifstream inf("./3801_a_binding.cpp", ios_base::in | ios_base::binary); // 二进制读

  if (!inf.fail())
  {
    ofstream outf("./4302_copy_from_3801_a_binding.cpp", ios_base::out | ios_base::binary); // 二进制写

    while (!inf.eof())
    {
      inf.read(buff, sizeof(buff));
      outf.write(buff, inf.gcount());

      cout << buff << endl;
    }
    outf.close();
    inf.close();
    
  }
  

}