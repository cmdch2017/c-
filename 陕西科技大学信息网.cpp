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
};//定义一个结构体 
int TOTAL_NUM = 0;//学生总数
struct student *head = NULL;
void welcome (); //欢迎界面
void mainmenu (); //主界面
void create();//创建学生信息 
void record (); //记录数据
void insert(struct student *stu); //插入数据
void display(struct student *stu); //显示一个学生的信息
void displayAll (); //显示所有学生的信息
void chazhao();//查找学生信息 
void alter(); //按学号查询学生信息
void search();//按照姓名查询学生信息 
void createData();//创立文件； 
void readData (); //读取文件里学生的信息
void writeData (); //向文件写入学生信息
void freeAll (); //清空链表内容
void del (); //删除学生信息
void change (); //更改学生信息
void devise (struct student *p); //选择更改内容
int main (void)
{ 
    welcome ();		
 //显示主菜单 
 readData ();

  mainmenu ();
     
 return 0;
}
//显示欢迎信息
void welcome ()
{
    printf ("------------------------------------------------------\n");
    printf ("------------------------------------------------------\n");
    printf ("| |                                                 ||\n");
    printf ("| |      欢迎使用陕西科技大学学生信息管理系统       ||\n");
    printf ("| |                                                 ||\n");
    printf ("------------------------------------------------------\n");
    printf ("------------------------------------------------------\n");
}
//系统主菜单
void mainmenu ()
{
    int choice;
    choice = -1;
    
 printf ("\n温馨提示：为保证您的操作得到保存，请按正常顺序退出系统^_^\n");
    do
    {            
  printf("=================学生信息管理系统==================   ");
  printf(" \n功能选项：\n  ");
  printf("   0---保存信息并退出  \n   ");
  printf("  1---创建学生信息     ");
  printf("   2---增加学生信息   \n    ");
  printf(" 3---浏览学生信息     "); 
  printf("   4---修改学生信息    \n  "); 
  printf("   5---查找学生信息        ");
  printf("6---删除学生信息      \n  ");
  printf("\n=================================================== \n请输入选项（0--6）:   "); 
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
                printf ("\n无效选项!");
                break;	
        }
    }
    while (choice != 0);
}
//创建学生信息
void create() 
{   int xx;
	printf("-------------------------------------------------\n");
    printf("1---从键盘输入数据信息\n") ;
    printf("2---从文件读取数据信息\n");
	printf("--------------------------------------------------\n");
    scanf("%d",&xx);
	switch(xx)
{
	case 1: printf("您选择了从键盘输入，请继续......"); 
			printf("请输入学生人数:");
			int rs,n;
			scanf("%d",&rs);
			for(n=0;n<rs;n++)
			record();
			break;
	case 2:	printf("您选择了从文件中读取，请继续......");
	        readData ();
			break;
	default: 
			printf ("\n无效选项!");
            break;	
	  
}
}
//查找学生信息
void chazhao() 
{   int xx;
	printf("-------------------------------------------------\n");
    printf("1---按学号查询学生信息\n") ;
    printf("2---按姓名查询学生信息\n");
	printf("--------------------------------------------------\n");
    scanf("%d",&xx);
	switch(xx)
{
	case 1: printf("您选择了按学号查找，"); 
			alter();
			break;
	case 2:	printf("您选择了按姓名查找，");
	       search(); 
	default: 
			printf ("\n无效选项!");
            break;	
	  
}
}
//录入学生信息
void record ()
{ 
 struct student *p0;   
 
 p0 = (struct student *)malloc(LEN);
 printf ("请输入学生的学号:");
 scanf ("%lf",&p0->num);
 printf ("请输入学生的姓名:");
 scanf ("%s",p0->name);
 printf ("请输入学生的出生日期:");
 scanf ("%d-%d-%d",&p0->year,&p0->month,&p0->day);  
 printf ("请输入学生的性别:");
 scanf ("%s",p0->sex);
 printf ("请输入学生的语文成绩:");
 scanf ("%d",&p0->yuwen);
 printf ("请输入学生的数学成绩:");
 scanf ("%d",&p0->shuxue);
  printf ("请输入学生的英语成绩:");
 scanf ("%d",&p0->yingyu);
 printf ("请输入学生的科学成绩:");
 scanf ("%d",&p0->kexue);
 printf ("请输入学生的体育成绩:");
 scanf ("%d",&p0->tiyu);
    
 insert (p0);
 printf ("该学生的信息为:\n");
 printf ("-------------------------------------------------------------------------------\n");
 printf ("学号  \t        姓名\t出生日期\t性别   \t语文\t数学\t英语\t科学\t体育\n");
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
//浏览学生信息
void displayAll()
{
 struct student *p;
 p = head; 
 if (head != NULL)
 { 
  printf ("学号  \t        姓名\t出生日期\t性别   \t语文\t数学\t英语\t科学\t体育\n");
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
//按学号查询学生信息
void alter ()
{
 double num;
 struct student *p1;
 printf("请输入学生的学号：");
 scanf("%lf", &num);
 if(head==NULL)
 {
  printf("无学生记录！\n");
  return ;
 } 
 p1 = head;
 while (num!=p1->num && p1->next!=NULL)
 p1 = p1->next; 
 if (num == p1->num)
 { 
  printf ("姓名  \t学号 \t性别\t班级   \t语文\t数学\t英语\t科学\t体育\n");
  printf ("-------------------------------------------------------------------------------\n");
  display (p1);
 } 
 else
 printf ("没有该学生记录，请核对！");
}
//按姓名查询学生信息
void search ()
{
 char name;
 struct student *p1;
 printf("请输入学生的姓名：");
 scanf("%s", &name);
 if(head==NULL)
 {
  printf("无学生记录！\n");
  return ;
 } 
 p1 = head;
 while (name!=*(p1->name)&& p1->next!=NULL)
 p1 = p1->next; 
 if (name == *(p1->name))
 { 
  printf ("学号  \t        姓名\t出生日期\t性别   \t语文\t数学\t英语\t科学\t体育\n");
  printf ("-------------------------------------------------------------------------------\n");
  display (p1);
 } 
 else
 printf ("没有该学生记录，请核对！");
}
//写入文件
void writeData ()
{
 FILE*  fp;//文件指针 
 struct student *p;
    fp = fopen("1.txt", "w");
    if (!fp)
    {
  printf("文件打开错误！");
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

//读取文件
void readData ()
{
 FILE*  fp;//文件指针 
 struct student *p1, *p2; 
    fp = fopen("1.txt", "r");
    if (!fp)
    {
  printf("文件打开错误！");
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
//删除学生信息
void del ()
{
 struct student *p1, *p2;
 long int num;
 
 if (head == NULL)
 {
  printf("无学生记录！\n");
  return;
 }
 printf("请输入您要删除的学生的学号：");
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
 printf("没有该学生记录，请核对！\n");
}
//修改学生信息
void change ()
{
 struct student *p1, *p2;
 double num;
 if (head == NULL)
 {
  printf ("无学生记录！\n");
  return;
 }
 printf ("请输入您要修改的学生的学号：");
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
 printf("没有该学生记录，请核对！\n");
}
void devise (struct student *p)
{
 int choice;
    choice = -1;
    do
    {
        printf("请选择您要修改的学生的信息内容:\n");
        printf("+----------------------+\n");        
        printf("| 学号          请按 1 |\n");
        printf("| 姓名          请按 2 |\n");
   printf("| 出生日期          请按 3 |\n");
  printf("| 性别  请按 4 |\n");
  printf("| 语文          请按 5 |\n");
  printf("| 数学          请按 6 |\n");
  printf("| 英语  请按 7 |\n");
  printf("| 科学 请按 8 |\n");
  printf("| 体育  请按 9 |\n");

  printf("| 取消          请按 0 |\n");
        printf("+----------------------+\n");
        printf("请输入您的选择:");
        scanf("%d", &choice);
       
        switch (choice)
        {
            case 0:
    return;
            case 1:
                printf("请输入新学号:");
    scanf("%lf", p->num);break;
                
            case 2:
                printf("请输入新姓名:");
    scanf("%s", &p->num); break; 
               
   case 3:
                printf("请输入新出生日期:");
    scanf("%s-%s-%s", p->year,p->month,p->day); break;
               
   case 4:
                printf("请输入新性别:");
    scanf("%s", p->sex);break; 
                
   case 5:
                printf("请输入新语文成绩:");
    scanf("%d", &p->yuwen);break;
                 
   case 6:
                printf("请输入新数学成绩:");
    scanf("%d", &p->shuxue);break; 
                
   case 7:
                printf("请输入新英语成绩:");scanf("%d", &p->yingyu);break; 
   case 8:
                printf("请输入新科学成绩:");scanf("%d", &p->kexue);break; 
   case 9:
                printf("请输入新体育成绩:");scanf("%d", &p->tiyu);break;  
	default:
    printf("\n无效选项!");
    break;
        }
    }
    while(choice != 0);
}
