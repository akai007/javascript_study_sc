#include <iostream>
#include <fstream> // 使用文件流

using namespace std; // 文件流定义在 std 命名空间

struct Book {
  char id[5]; // 产品代码
  char name[11]; // 产品名称
  int price; // 产品名称
  int quantity; // 产品数量
};

int main(int argc, char const *argv[])
{
  Book book; // 书籍销售记录数组
  ifstream inf("./4303_book.dat"); // 打开文件读

  ios_base::open_mode mode = ios_base::in | ios_base::out; // 可读可写
  fstream iof("./4303_out.dat", mode | ios_base::trunc | ios_base::binary);// 新建二进制文件

  if (inf.fail() || iof.fail()) return -1; // 文件打开失败 退出运行
  
  while (!inf.eof())
  {
    inf >> book.id
        >> book.name
        >> book.price
        >> book.quantity;
    iof.write((char *)&book, sizeof(Book));
  }
  inf.close(); // 关闭book.dat 文件读

  iof.seekg(1 * sizeof(Book), ios_base::beg); // 定位第一个结构体
  iof.read((char*)&book, sizeof(Book));
  cout << book.id << "\t"
       << book.name << "\t"
       << book.price << "\t"
       << book.quantity << endl;
  
  iof.close();
  
  return 0;
}

