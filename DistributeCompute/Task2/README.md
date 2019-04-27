# 舔着脸，求关注(*❦ω❦) 
## 题目：
利用RPC/RMI技术实现一个书籍信息管理系统，具体要求：
客户端实现用户交互，服务器端实现书籍信息存储和管理。客户端与服务器端利用RPC/RMI机制进行协作。中间件任选。
服务器端至少暴露如下RPC/RMI接口：
  bool add(Book b)   添加一个书籍对象。
  Book queryByID(int bookID) 查询指定ID号的书籍对象。
  BookList queryByName(String name) 按书名查询符合条件的书籍对象列表，支持模糊查询。
  bool delete((int bookID) 删除指定ID号的书籍对象。
