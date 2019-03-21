#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void add();
void update();
void del();
int ch,i,e=0,r,u,v,we,you;
char k,lk;
char h[500],a[20],c[20],word[10],meaning[10],search[200],s[200],j[200],y[200];
FILE *b,*w;
main()
{
while(1)
{
system("cls");
printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t     *****************welcome in dictionary*****************\n");
printf("\t\t\t\t\t\t\t\t\t        enter your name\n");
printf("\t\t\t\t\t\t\t\t\t\t    ");
scanf("%s",a);
printf("\n\t\t\t\t\t\t\t\t\t          ***welcome %s***\n\n",a);
printf("\t\t\t\t\t\t\t\t\t\tplease press 1 to continue\n\n");
printf("\t\t\t\t\t\t\t\t\t\t    press 0 to exit\n\n");
printf("\t\t\t\t\t\t\t\t\t\t     your choice=");
scanf("%d",&u);
if(u==0)
{goto exit;
}
start:system("cls");
printf("\t\t\t\t\t\t\t\t\twhat would you like to choose %s\n\n",a);
printf("\t\t\t\t\t\t\t\t\t     *****1.Search a word*****\n\n");
printf("\t\t\t\t\t\t\t\t\t       *****2.Add a word*****\n\n");
printf("\t\t\t\t\t\t\t\t\t    *****3.display dictionary*****\n\n");
printf("\t\t\t\t\t\t\t\t\t    *******4.update dictionary*******\n\n");
printf("\t\t\t\t\t\t\t\t\t     *******5.delete a word*******\n\n");
printf("\t\t\t\t\t\t\t\t\t         *****6.Exit*****\n\n");
printf("\t\t\t\t\t\t\t\t\t\t  ");
getch();
scanf("%d",&ch);
switch(ch)
{
case 1:system("cls");
printf("\n\n\n\n\n\t\t\t\t\t\t\t\tenter word that you want to search\n");
printf("\t\t\t\t\t\t\t\t\t");
scanf("%s",s);
b=fopen("dictionary.txt","r");
while(1)
{if(feof(b))
{
goto suggestion;
break;
}
else 
{fscanf(b,"%s",word);
fgets(meaning,200,b);
if(!strcmp(word,s))
{printf("\n\t\t\t\t\t\t\t\tword=%s       meaning=%s",word,meaning);
goto forward;
break;
}
}
}
getch();
fclose(b);
suggestion:
{printf("\n\n\t\t\t\t\t\t\t\t\tword is not found\n");
printf("\t\t\t\t\t\t\t\t\tsuggested words are:\n");
printf("word\n\n");
b=fopen("recordofword.txt","r");
while(!feof(b))
{fscanf(b,"%s",ch);
if(ch==s[0])
{printf("%s\n",ch);
}
}
forward:printf("\n\t\t\t\t\t\t\t\t   press '1' for main menu\n\n");
printf("\t\t\t\t\t\t\t\t    press '2' for add a word\n\n");
printf("\t\t\t\t\t\t\t\t        press '3' to exit\n\n");
scanf("\t\t\t\t\t\t\t\t        your choice=%d",&we);
getch();
switch(we)
{case 1:goto start;
break;
case 2:add();
break;
case 3:goto exit;
break;
default:goto start;
}
getch();
break;
case 2:system("cls");
b=fopen("dictionary.txt","a");
printf("\n\n\n\t\t\t\t\t\t\t\tenter a word with its meaning\n");
scanf("%s",word);
printf("meaning of this word %s",word);
gets(meaning);
fprintf(b,"%s %s",word,meaning);
fclose(b);
printf("\t\t\t\t\tpress '1' for main menu\n\n");
printf("\t\t\t\t\tpress '2' To add another word\n\n");
printf("\t\t\t\t\tpress '3' To exit\n\n");
scanf("your choice=%d",&we);
switch(we)
{case 1:goto start;
break;
case 2:add();
break;
case 3:goto exit;
break;
default:goto start;
}
getch();
break;
case 3:
system("cls");
printf("\n\n\n\t\t\t\t\t\t\t\t\t******DICTIONARY******\n");
printf("word meaning\n");
b=fopen("dictionary.txt","r");
lk=getc(b);
while(lk!=EOF)
{lk=getc(b);
printf("%c",lk);
}
getch();
printf("\n\t\t\t\t\tpress '1' for main menu\n\n");
printf("\t\t\t\t\tpress '2' for adding a new word\n\n");
printf("\t\t\t\t\tpress '3' to exit\n\n");
scanf("%d",&v);
switch(v)
{case 1:goto start;
break;
case 2:add() ;
break;
case 3:goto exit;
break;
default:goto start; 
}
fclose(b);
break;
case 4:
update();
break;
case 5:del();
printf("\t\t\t\t\t\t\t\t\t\t\tentered word is deleted\n\n");
printf("\t\t\t\t\t\t\t\t\tpress '1' for main menu\n\n");
printf("\t\t\t\t\t\t\t\t\tpress '2' To add another word\n\n");
printf("\t\t\t\t\t\t\t\t\tpress '3' To exit\n\n");
printf("\t\t\t\t\t\t\t\t\tpress '4' To delete another word\n\n");
scanf("your choice=%d",&you);
getch();
switch(you)
{case 1:goto start;
break;
case 2:add();
break;
case 3:goto exit;
break;
case 4:del();
break;
default:goto start;
}
break;
case 6:goto exit;
break;
default:printf("invalid input");
}}
exit:printf("\n\t\t\t\t\t\t\t\t\t thank you for using dictionary");
}}
void add()
{ 
system("cls");
b=fopen("dictionary.txt","a");
printf("\n\n\n\t\t\t\t\t\t\t\tenter a word with its meaning\n\n");
scanf("%s",word);
printf("\t\t\t\t\t\t\t\t\t\t\tenter its meaning\n\n");
gets(meaning);
fprintf(b,"\n%s %s\n",word,meaning);
fclose(b);
}
void update()
{system("cls");
FILE *p;
char word2[200],quiz[200];
printf("\n\n\n\t\t\t\t\t\t\t\t\t\tenter word whose meaning you want to change\n\n\n");
scanf("%s",word2);
p=fopen("dictionary.txt","a+");
while(1)
{if(feof(b))
{
break;
}
else 
{fscanf(b,"%s",word);
fgets(meaning,200,b);
if(!strcmp(word,word2))
{printf("old meaning=%s",meaning);
word[0]='\0';
printf("enter new meaning");
scanf("%s",quiz);
fprintf(p,"%s",quiz);
}}}}
void del()
{system("cls");
FILE *p,*b;
char word2[200],quiz[200];
printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tenter word that you want to delete\n\n");
printf("\t\t\t\t\t\t\t\t\t\t");
scanf("%s",word2);
p=fopen("recordofword.txt","r");
fscanf(p,"%s",quiz);
if(strcmp(quiz,word2)==0)
{b=fopen("dictionary.txt","a+");
while(1)
{if(feof(b))
{
break;
}
else 
{fscanf(b,"%s",word);
fgets(meaning,200,b);
if(!strcmp(word,s))
{word[0]='/0';
break;
}
}}
}
getch();
}
