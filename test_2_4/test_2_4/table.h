typedef struct
{
	int *head;//�ڴ�λ��
	int length;//Ԫ�ظ���
	int size;//���С
}Table;

//����˳�����С����ַ��
Table* CreatTable(int size, Table* t);
//��ӡ˳���
void DisplayTable(Table t);
//���ó�ֵ����ַ��
Table* SetTable(Table*p);
//����һ��ֵ����ַ���±ֵ꣬��
Table* AddTable(Table*p);
//ɾ��һ��Ԫ�أ���ַ���±꣩
Table* DelTable(Table*p, int pos);
//����һ��Ԫ��(��ַ����ֵ)
int  FindoutNum(Table*p, int num);
//����˳���Ԫ��(��ַ���±꣬��ֵ)
void ChangeNum(Table*p, int pos, int num);