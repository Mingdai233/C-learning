typedef struct
{
	int *head;//内存位置
	int length;//元素个数
	int size;//表大小
}Table;

//创建顺序表（大小，地址）
Table* CreatTable(int size, Table* t);
//打印顺序表
void DisplayTable(Table t);
//设置初值（地址）
Table* SetTable(Table*p);
//插入一个值（地址，下标，值）
Table* AddTable(Table*p);
//删除一个元素（地址，下标）
Table* DelTable(Table*p, int pos);
//查找一个元素(地址，数值)
int  FindoutNum(Table*p, int num);
//更改顺序表元素(地址，下标，数值)
void ChangeNum(Table*p, int pos, int num);