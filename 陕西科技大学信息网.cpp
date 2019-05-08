#include "stdio.h"
#include "malloc.h"
#include "string.h"
#include "stdlib.h"
#define LEN sizeof(struct student)
	

struct student   
{
 char name[20];
 double num;
 char sex[4];
 int yuwen;
 int shuxue;
 int yingyu;
 int kexue;
 int tiyu;
 int year;
 int month;
 int day;
 struct student *next;
};//����һ���ṹ�� 
int TOTAL_NUM = 0;//ѧ������
struct student *head = NULL;
void welcome (); //��ӭ����
void mainmenu (); //������
void create();//����ѧ����Ϣ 
void record (); //��¼����
void insert(struct student *stu); //��������
void display(struct student *stu); //��ʾһ��ѧ������Ϣ
void displayAll (); //��ʾ����ѧ������Ϣ
void chazhao();//����ѧ����Ϣ 
void alter(); //��ѧ�Ų�ѯѧ����Ϣ
void search();//����������ѯѧ����Ϣ 
void createData();//�����ļ��� 
void readData (); //��ȡ�ļ���ѧ������Ϣ
void writeData (); //���ļ�д��ѧ����Ϣ
void freeAll (); //�����������
void del (); //ɾ��ѧ����Ϣ
void change (); //����ѧ����Ϣ
void devise (struct student *p); //ѡ���������
int main (void)
{ 
    welcome ();		
 //��ʾ���˵� 
 readData ();

  mainmenu ();
     
 return 0;
}
//��ʾ��ӭ��Ϣ
void welcome ()
{
    printf ("------------------------------------------------------\n");
    printf ("------------------------------------------------------\n");
    printf ("| |                                                 ||\n");
    printf ("| |      ��ӭʹ�������Ƽ���ѧѧ����Ϣ����ϵͳ       ||\n");
    printf ("| |                                                 ||\n");
    printf ("------------------------------------------------------\n");
    printf ("------------------------------------------------------\n");
}
//ϵͳ���˵�
void mainmenu ()
{
    int choice;
    choice = -1;
    
 printf ("\n��ܰ��ʾ��Ϊ��֤���Ĳ����õ����棬�밴����˳���˳�ϵͳ^_^\n");
    do
    {            
  printf("=================ѧ����Ϣ����ϵͳ==================   ");
  printf(" \n����ѡ�\n  ");
  printf("   0---������Ϣ���˳�  \n   ");
  printf("  1---����ѧ����Ϣ     ");
  printf("   2---����ѧ����Ϣ   \n    ");
  printf(" 3---���ѧ����Ϣ     "); 
  printf("   4---�޸�ѧ����Ϣ    \n  "); 
  printf("   5---����ѧ����Ϣ        ");
  printf("6---ɾ��ѧ����Ϣ      \n  ");
  printf("\n=================================================== \n������ѡ�0--6��:   "); 
        scanf ("%d", &choice);
        switch (choice)
        {
    case 0:
   				writeData ();
    			freeAll ();
                exit (0);
    case 1:
    			create();
    			break;
    case 2:
                record ();
                break;
    case 3:
                displayAll ();
                break;
    case 4:
                change ();
                break; 	
	case 5:
                chazhao ();
                break;  
    case 6:
                del ();
                break; 
            default:
                printf ("\n��Чѡ��!");
                break;	
        }
    }
    while (choice != 0);
}
//����ѧ����Ϣ
void create() 
{   int xx;
	printf("-------------------------------------------------\n");
    printf("1---�Ӽ�������������Ϣ\n") ;
    printf("2---���ļ���ȡ������Ϣ\n");
	printf("--------------------------------------------------\n");
    scanf("%d",&xx);
	switch(xx)
{
	case 1: printf("��ѡ���˴Ӽ������룬�����......"); 
			printf("������ѧ������:");
			int rs,n;
			scanf("%d",&rs);
			for(n=0;n<rs;n++)
			record();
			break;
	case 2:	printf("��ѡ���˴��ļ��ж�ȡ�������......");
	        readData ();
			break;
	default: 
			printf ("\n��Чѡ��!");
            break;	
	  
}
}
//����ѧ����Ϣ
void chazhao() 
{   int xx;
	printf("-------------------------------------------------\n");
    printf("1---��ѧ�Ų�ѯѧ����Ϣ\n") ;
    printf("2---��������ѯѧ����Ϣ\n");
	printf("--------------------------------------------------\n");
    scanf("%d",&xx);
	switch(xx)
{
	case 1: printf("��ѡ���˰�ѧ�Ų��ң�"); 
			alter();
			break;
	case 2:	printf("��ѡ���˰��������ң�");
	       search(); 
	default: 
			printf ("\n��Чѡ��!");
            break;	
	  
}
}
//¼��ѧ����Ϣ
void record ()
{ 
 struct student *p0;   
 
 p0 = (struct student *)malloc(LEN);
 printf ("������ѧ����ѧ��:");
 scanf ("%lf",&p0->num);
 printf ("������ѧ��������:");
 scanf ("%s",p0->name);
 printf ("������ѧ���ĳ�������:");
 scanf ("%d-%d-%d",&p0->year,&p0->month,&p0->day);  
 printf ("������ѧ�����Ա�:");
 scanf ("%s",p0->sex);
 printf ("������ѧ�������ĳɼ�:");
 scanf ("%d",&p0->yuwen);
 printf ("������ѧ������ѧ�ɼ�:");
 scanf ("%d",&p0->shuxue);
  printf ("������ѧ����Ӣ��ɼ�:");
 scanf ("%d",&p0->yingyu);
 printf ("������ѧ���Ŀ�ѧ�ɼ�:");
 scanf ("%d",&p0->kexue);
 printf ("������ѧ���������ɼ�:");
 scanf ("%d",&p0->tiyu);
    
 insert (p0);
 printf ("��ѧ������ϢΪ:\n");
 printf ("-------------------------------------------------------------------------------\n");
 printf ("ѧ��  \t        ����\t��������\t�Ա�   \t����\t��ѧ\tӢ��\t��ѧ\t����\n");
 display(p0);
}
void insert (struct student *stu)
{
 struct student *p0, *p1, *p2;
 
 p1 = head;
 p0 = stu;
 
 if (head == NULL)
 {
  head = p0;
  p0->next = NULL;
 }
 else
 {
  while ((p0->num > p1->num)&&(p1->next != NULL))
  {
   p2 = p1;
   p1 = p1->next;
  }
  if (p0->num <= p1->num)
  {
   if (head == p1)
   head = p0;
   else
   p2->next = p0;
   p0->next = p1;
  }
  else
  {
   p1->next = p0;
   p0->next = NULL;
  }  
 } 
}
void display (struct student *p)
{
 printf ("%.0lf\t%s\t%d-%d-%d\t%s\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name,p->year,p->month,p->day, p->sex, p->yuwen, p->shuxue, p->yingyu,p->kexue,p->tiyu);
}
//���ѧ����Ϣ
void displayAll()
{
 struct student *p;
 p = head; 
 if (head != NULL)
 { 
  printf ("ѧ��  \t        ����\t��������\t�Ա�   \t����\t��ѧ\tӢ��\t��ѧ\t����\n");
  printf("-------------------------------------------------------------------------------\n");
  do
  {
   display(p);
   p = p->next;
  }
  while(p != NULL);
 } 
 printf ("\n");
}
//��ѧ�Ų�ѯѧ����Ϣ
void alter ()
{
 double num;
 struct student *p1;
 printf("������ѧ����ѧ�ţ�");
 scanf("%lf", &num);
 if(head==NULL)
 {
  printf("��ѧ����¼��\n");
  return ;
 } 
 p1 = head;
 while (num!=p1->num && p1->next!=NULL)
 p1 = p1->next; 
 if (num == p1->num)
 { 
  printf ("����  \tѧ�� \t�Ա�\t�༶   \t����\t��ѧ\tӢ��\t��ѧ\t����\n");
  printf ("-------------------------------------------------------------------------------\n");
  display (p1);
 } 
 else
 printf ("û�и�ѧ����¼����˶ԣ�");
}
//��������ѯѧ����Ϣ
void search ()
{
 char name;
 struct student *p1;
 printf("������ѧ����������");
 scanf("%s", &name);
 if(head==NULL)
 {
  printf("��ѧ����¼��\n");
  return ;
 } 
 p1 = head;
 while (name!=*(p1->name)&& p1->next!=NULL)
 p1 = p1->next; 
 if (name == *(p1->name))
 { 
  printf ("ѧ��  \t        ����\t��������\t�Ա�   \t����\t��ѧ\tӢ��\t��ѧ\t����\n");
  printf ("-------------------------------------------------------------------------------\n");
  display (p1);
 } 
 else
 printf ("û�и�ѧ����¼����˶ԣ�");
}
//д���ļ�
void writeData ()
{
 FILE*  fp;//�ļ�ָ�� 
 struct student *p;
    fp = fopen("1.txt", "w");
    if (!fp)
    {
  printf("�ļ��򿪴���");
  return ;
    } fprintf(fp,"%d\n", TOTAL_NUM);
    for(p = head; p!= NULL; p= p->next)
    {
        fprintf(fp,"%.0lf\t%s\t%d-%d-%d\t%s\t%d\t%d\t%d\t%d\t%d\n",  p->num,p->name,  p->year,p->month,p->day,p->sex, p->yuwen, p->shuxue, p->yingyu,p->kexue,p->tiyu);
    }
    fclose (fp); 
}

void freeAll ()
{
 struct student *p1, *p2;
 p1 = p2=head; 
 while(p1)
 {
  p2=p1->next;
  free (p1);
  p1 = p2;
 } 
}

//��ȡ�ļ�
void readData ()
{
 FILE*  fp;//�ļ�ָ�� 
 struct student *p1, *p2; 
    fp = fopen("1.txt", "r");
    if (!fp)
    {
  printf("�ļ��򿪴���");
        return;
    }
 
 fscanf(fp,"%d\n", &TOTAL_NUM);
 head = p1 = p2 = (struct student *)malloc(LEN);
   fscanf(fp,"%lf\t%s\t%d-%d-%d\t%s\t%d\t%d\t%d\t%d\t%d\n", &p1->num,p1->name, &p1->year,&p1->month,&p1->day, p1->sex,  &p1->yuwen, &p1->shuxue, &p1->yingyu, &p1->kexue,&p1->tiyu);
 while(!feof(fp))
 {
  p1 = (struct student *)malloc(LEN);
   fscanf(fp,"%lf\t%s\t%d-%d-%d\t%s\t%d\t%d\t%d\t%d\t%d\n", &p1->num,p1->name, &p1->year,&p1->month,&p1->day, p1->sex,  &p1->yuwen, &p1->shuxue, &p1->yingyu, &p1->kexue,&p1->tiyu);

  p2->next = p1;
  p2 = p1;
 }
 p2->next = NULL;
 fclose(fp);
}
//ɾ��ѧ����Ϣ
void del ()
{
 struct student *p1, *p2;
 long int num;
 
 if (head == NULL)
 {
  printf("��ѧ����¼��\n");
  return;
 }
 printf("��������Ҫɾ����ѧ����ѧ�ţ�");
 scanf("%ld", &num);
 p1 = head;
 
 while (num != p1->num && p1->next != NULL)
 {
  p2 = p1;
  p1 = p1->next;  
 }
 if(num == p1->num)
 {
  if(p1 == head)
  head = p1->next;
  else p2->next = p1->next;
  free(p1);
  TOTAL_NUM--;printf("delete\n");
 }
 else
 printf("û�и�ѧ����¼����˶ԣ�\n");
}
//�޸�ѧ����Ϣ
void change ()
{
 struct student *p1, *p2;
 double num;
 if (head == NULL)
 {
  printf ("��ѧ����¼��\n");
  return;
 }
 printf ("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
 scanf ("%lf", &num);
 p1 = head; 
 while (num != p1->num && p1->next != NULL)
 {
  p2 = p1;
  p1 = p1->next;  
 }
 if(num == p1->num)
 devise (p1); 
 else
 printf("û�и�ѧ����¼����˶ԣ�\n");
}
void devise (struct student *p)
{
 int choice;
    choice = -1;
    do
    {
        printf("��ѡ����Ҫ�޸ĵ�ѧ������Ϣ����:\n");
        printf("+----------------------+\n");        
        printf("| ѧ��          �밴 1 |\n");
        printf("| ����          �밴 2 |\n");
   printf("| ��������          �밴 3 |\n");
  printf("| �Ա�  �밴 4 |\n");
  printf("| ����          �밴 5 |\n");
  printf("| ��ѧ          �밴 6 |\n");
  printf("| Ӣ��  �밴 7 |\n");
  printf("| ��ѧ �밴 8 |\n");
  printf("| ����  �밴 9 |\n");

  printf("| ȡ��          �밴 0 |\n");
        printf("+----------------------+\n");
        printf("����������ѡ��:");
        scanf("%d", &choice);
       
        switch (choice)
        {
            case 0:
    return;
            case 1:
                printf("��������ѧ��:");
    scanf("%lf", p->num);break;
                
            case 2:
                printf("������������:");
    scanf("%s", &p->num); break; 
               
   case 3:
                printf("�������³�������:");
    scanf("%s-%s-%s", p->year,p->month,p->day); break;
               
   case 4:
                printf("���������Ա�:");
    scanf("%s", p->sex);break; 
                
   case 5:
                printf("�����������ĳɼ�:");
    scanf("%d", &p->yuwen);break;
                 
   case 6:
                printf("����������ѧ�ɼ�:");
    scanf("%d", &p->shuxue);break; 
                
   case 7:
                printf("��������Ӣ��ɼ�:");scanf("%d", &p->yingyu);break; 
   case 8:
                printf("�������¿�ѧ�ɼ�:");scanf("%d", &p->kexue);break; 
   case 9:
                printf("�������������ɼ�:");scanf("%d", &p->tiyu);break;  
	default:
    printf("\n��Чѡ��!");
    break;
        }
    }
    while(choice != 0);
}
