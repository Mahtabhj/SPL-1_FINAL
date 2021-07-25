#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
 char method_name[100];
 char variables_name[100][100];
 char return_type[100];
 char call_function[100][100];
}funtion_ast[100];

      char *intf="int";
      char *voidf="void";
      char *charf = "char";
      char *doublef = "double";
      char *floatf = "float";
      char *semicolon=";";
      char *bracket1 ="(";
      char *bracket2 = ")";
int line = 0,fi=0;
int countf[100];
int menu[100];
char filestring[100][100];
char function_name[100][100];
int findfunction();
void findvariable();
int findstart();
int findend();
void find_returntype();
void function_parameter();
void find_loop();
int called();
void function_menu();
void removeSpaces();
void removecomment();

void removecomment(char *str)
{
    int count=0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '/'&&str[i+1]=='/')
        {
            str[i]='\0';
            break;
        }
        else if(strstr(str,"printf")!=NULL||strstr(str,"scanf")!=NULL)
        {
            str[i]='\0';
        }
    }
}
void removeSpaces(char *str)
{

    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];

    str[count] = '\0';
}
void function_menu(char name[100])
{
    int s=findstart(name);
    int end=findend(name,s);

    function_parameter(s);
    find_returntype(s);
    for(int i=s+1;i<end;i++)
    {
        findvariable(i);
        find_loop(i);
        int f =called(i);

        if(countf[f]==1)
        {
            removeSpaces(function_name[f]);
            function_menu(function_name[f]);
            int g =called(i);

            if(countf[g]==1)
            {
               removeSpaces(function_name[g]);
            function_menu(function_name[g]);
            int gg=called(i);
            if(countf[gg]==1)
            {
                removeSpaces(function_name[gg]);
            function_menu(function_name[gg]);
            }
            }
        }

    }


}
int called(int name)
{
    int i=name;
    int end = findend(name,i);
    printf("\n");
    int f1=0;
        int j=0;
        for(;j<fi;j++)
        {

               if(countf[j]>=1)
            {
                continue;

            }


            if(strstr(filestring[i],function_name[j])!=NULL)
            {
                char news[100];
                removeSpaces(filestring[i]);
                strcpy(news,function_name[j]);
                strcat(news,"(");

                if(strstr(filestring[i],news)!=NULL)
                {
                    countf[j]=countf[j]+1;
                    f1=1;
                    printf("Call function : %s\n",function_name[j]);
                }
                menu[i]=3;
            }
              if(f1==1)
              {
               break;
              }
        }

    if(f1==1)
    {
      return j;
    }
    else
        {
        return 99;
    }
}

void find_loop(int starting)
{
     int i=starting;
    char *bri="(";
    char *brf=")";
    int count =0;


      if(strstr(filestring[i], "else if")!=NULL&& strstr(filestring[i], "(")!=NULL && strstr(filestring[i], ")")!=NULL&& strstr(filestring[i], ";")==NULL)
      {
          menu[i]=2;
          printf("\nelse if condition : ");
          for(int j=0;;j++)
          {
              if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
      }
      else if(strstr(filestring[i], "for")!=NULL&& strstr(filestring[i], "(")!=NULL && strstr(filestring[i], ")")!=NULL&& strstr(filestring[i], ";")!=NULL)
      {
          menu[i]=2;
          removeSpaces(filestring[i]);
          if(filestring[i][0]=='f'&&filestring[i][1]=='o'&&filestring[i][2]=='r')
          {
          printf("\nfor condition : ");
          for(int j=0;;j++)
          {
              if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
          }
      }
      else if(strstr(filestring[i], "if")!=NULL&& strstr(filestring[i], "(")!=NULL && strstr(filestring[i], ")")!=NULL&& strstr(filestring[i], ";")==NULL)
      {
          char c[100];
          strcpy(c,filestring[i]);
          removeSpaces(c);
          if(strstr(c,"elseif"))
          {
          menu[i]=2;
          printf("\nelse if condition : ");
          for(int j=0;;j++)
          {
              if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
      }
      else
      {


          menu[i]=2;
          printf("\nif condition : ");
          for(int j=0;;j++)
          {
              if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
      }
      }
      else if(strstr(filestring[i], "while")!=NULL&& strstr(filestring[i], "(")!=NULL && strstr(filestring[i], ")")!=NULL)
      {
          menu[i]=2;
          char news[100];
                strcpy(news,"while");
                strcat(news,"(");
                if(strstr(filestring[i],news)!=NULL)
                {
                   printf("\nwhile condition : ");
          for(int j=0;;j++)
          {
             if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
                }

      }

}
void function_parameter(int number)
{

           char c[100];
           char intp[100][100];
           int int_count=0,j=0;
           int i=0;
           strcpy(c,filestring[number]);

          menu[i]=2;
          printf("\nParameters : ");
          for(int j=0;;j++)
          {
              if(filestring[number][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[number][k]=='\0')
                      {
                          break;
                      }
                      if(filestring[number][k]=='('||filestring[number][k]==')')
                      {
                          continue;
                      }
                      printf("%c",filestring[number][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");

}
void find_returntype(int starting)
{
    char type[20];
    char ch[100];
    strcpy(ch,filestring[starting]);
    char c[100];

    for(int i=0;;i++)
    {

        if(ch[i]=='(')
        {
            ch[i]=='\0';
            break;
        }
    }
    strcpy(c,ch);

     if(strstr(c, "*int") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"*int");

    }
    else if(strstr(c, "*char") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"char");
    }

    else if(strstr(c, "*double") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"double");
    }
    else if(strstr(c, floatf) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"float");
    }
    else if(strstr(c, "*float") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"float");
    }
    else if(strstr(c, "short int") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"short int");
    }

    else if(strstr(c, "unsigned long long int") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"unsigned long long int");
    }
    else if(strstr(c, "unsigned long int") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"unsigned long int");
    }
    else if(strstr(c, "unsigned int") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"unsigned int");
    }
    else if(strstr(c, "long long int") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"long long int");
    }
    else if(strstr(c, "long int") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"long int");
    }
    else if(strstr(c, intf) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"int");

    }
    else if(strstr(c, "long double") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"long double");
    }
    else if(strstr(c, doublef) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"double");
    }
    else if(strstr(c, "unsigned char") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"unsigned char");
    }
    else if(strstr(c, "signed char") != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"signed char");
    }
    else if(strstr(c, charf) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"char");
    }
    printf("\nReturn type = %s",type);

}
void findvariable(int iterator)
{

   char ch,str[1000];
   char c[100];
   char *v1="int";
   char *v2 = "char";
   char *v3 = "double";
   char *v4 = "float";
   char *v=";";
   char *vp ="(";

   char vname[500],vcname[500],vdname[500],vfname[500];

       strcpy(c,filestring[iterator]);
        if(strstr(c, "unsigned char") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='u'&&check[1]=='n'&&check[2]=='s')
      {
      for(i=0;;i++)
       {
           if(c[i]=='u'&&c[i+1]=='n'&&c[i+2]=='s'&&c[i+3]=='i')
           {
               i=i+13;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Unsigned char variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
    else if(strstr(c, "signed char") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='s'&&check[1]=='i'&&check[2]=='g')
      {
      for(i=0;;i++)
       {
           if(c[i]=='s'&&c[i+1]=='i'&&c[i+2]=='g'&&c[i+3]=='n')
           {
               i=i+11;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Signed char variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
       else if(strstr(c, "long double") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='l'&&check[1]=='o'&&check[2]=='n')
      {
      for(i=0;;i++)
       {
           if(c[i]=='l'&&c[i+1]=='o'&&c[i+2]=='n'&&c[i+3]=='g')
           {
               i=i+11;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of long double integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }

        else if(strstr(c, "unsigned long long int") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='u'&&check[1]=='n'&&check[2]=='s')
      {
      for(i=0;;i++)
       {
           if(c[i]=='u'&&c[i+1]=='n'&&c[i+2]=='s'&&c[i+3]=='i')
           {
               i=i+22;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Unsigned long long integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
    else if(strstr(c, "unsigned long int") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='u'&&check[1]=='n'&&check[2]=='s')
      {
      for(i=0;;i++)
       {
           if(c[i]=='u'&&c[i+1]=='n'&&c[i+2]=='s'&&c[i+3]=='i')
           {
               i=i+17;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Unsigned long integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
    else if(strstr(c, "unsigned int") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='u'&&check[1]=='n'&&check[2]=='s')
      {
      for(i=0;;i++)
       {
           if(c[i]=='u'&&c[i+1]=='n'&&c[i+2]=='s'&&c[i+3]=='i')
           {
               i=i+12;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Unsigned integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
    else if(strstr(c, "long long int") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='l'&&check[1]=='o'&&check[2]=='n')
      {
      for(i=0;;i++)
       {
           if(c[i]=='l'&&c[i+1]=='o'&&c[i+2]=='n'&&c[i+3]=='g')
           {
               i=i+13;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of long long integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }

    else if(strstr(c, "long int") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");

      if(check[0]=='l'&&check[1]=='o'&&check[2]=='n')
      {
      for(i=0;;i++)
       {
           if(c[i]=='l'&&c[i+1]=='o'&&c[i+2]=='n'&&c[i+3]=='g')
           {
               i=i+8;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of long integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
        else if(strstr(c, "short int") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");
      if(check[0]=='s'&&check[1]=='h'&&check[2]=='o')
      {
      for(i=0;;i++)
       {
           if(c[i]=='s'&&c[i+1]=='h'&&c[i+2]=='o'&&c[i+3]=='r')
           {
               i=i+9;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Short integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
      else if(strstr(c, v1) != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      if(check[0]=='i'&&check[1]=='n'&&check[2]=='t')
      {
      for(i=0;;i++)
       {
           if(c[i]=='i'&&c[i+1]=='n'&&c[i+2]=='t'&&c[i+3]==' ')
           {
               i=i+3;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Integer variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
    else if(strstr(c, v3) != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");
      if(check[0]=='d'&&check[1]=='o'&&check[2]=='u')
      {
      for(i=0;;i++)
       {
           if(c[i]=='d'&&c[i+1]=='o'&&c[i+2]=='u'&&c[i+3]=='b')
           {
               i=i+6;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Double variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }
    else if(strstr(c, "float") != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
            int ci=0,cc=0,cd=0,cf=0;
            int k=0,kc=0,kd=0,kf=0;
            int i=0,end=0;
            menu[iterator]=1;
      char check[100];
      strcpy(check,c);
      removeSpaces(check);
      strcpy(vname,"");
      if(check[0]=='f'&&check[1]=='l'&&check[2]=='o')
      {
      for(i=0;;i++)
       {
           if(c[i]=='f'&&c[i+1]=='l'&&c[i+2]=='o'&&c[i+3]=='a')
           {
               i=i+5;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
      printf("\nDeclaration of Float variables = ");
    for(int i=0;i<k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");

    }

       else if(strstr(c, v2) != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {
         int ci=0,cc=0,cd=0,cf=0;
         int k=0,kc=0,kd=0,kf=0;
         int i=0,end=0;
        menu[iterator]=1;
        char check[100];
      strcpy(check,c);
      removeSpaces(check);
      if(check[0]=='c'&&check[1]=='h'&&check[2]=='a')
      {
      for(i=0;;i++)
       {
           if(c[i]=='c'&&c[i+1]=='h'&&c[i+2]=='a'&&c[i+3]=='r'&&c[i+4]==' ')
           {
               i=i+4;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }
           if(c[i]==',')
           {
               vcname[kc]='/';
               kc++;
               cc++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vcname[k]='/';
                        kc++;
                        cc++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vcname[kc]= c[i];
           kc++;
       }
       vcname[kc]='/';
       kc++;
       cc=cc+1;
    }
    printf("\nDeclaration of char variables = ");
     for(int i=0;i<kc-1;i++)
    {
        if(vcname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vcname[i]);
    }
   printf("\n");
}



}

int findstart(char name[100])
{

    int i=0,start=0;
    char c[100];
    for(i=0;;i++)
    {
        strcpy(c,filestring[i]);
        if( strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
      {
          char check[100];
          strcpy(check,c);
          removeSpaces(check);
          if((check[0]=='i'&&check[1]=='n'&&check[2]=='t')||(check[0]=='v'&&check[1]=='o'&&check[2]=='i'&&check[3]=='d')||(check[0]=='d'&&check[1]=='o'&&check[2]=='u'&&check[3]=='b')||(check[0]=='*')||(check[0]=='c'&&check[1]=='h'&&check[2]=='a')||(check[0]=='l'&&check[1]=='o'&&check[2]=='n')||(check[0]=='u'&&check[1]=='n')||(check[0]=='s'&&check[1]=='h'))
          {
              if(strstr(c,name)!=NULL)
              {
                  start=i;
                  break;
              }

      }}

    }
    return start;
}

int findend(char name[100], int start)
{
    int i=0,end=0;
    char *bri="{";
    char *brf="}";
    int count =0;
    for(i=start;i<line;i++)
    {

      if(strstr(filestring[i], "{")!=NULL&& strstr(filestring[i], ";")==NULL && strstr(filestring[i], "(")==NULL)
      {
          count++;

      }
      else if(strstr(filestring[i], "}")!=NULL&& strstr(filestring[i], ";")==NULL && strstr(filestring[i], "(")==NULL)
      {
          count--;
          if(count==0)
          {
              end=i;

              break ;
          }
      }
      else continue;


    }
    return end;
}

int findfunction()
{
      FILE *fptr;
      char c[100];

      fptr = fopen("i.txt","r");
      if(fptr == NULL)
   {
      printf("Error!");

   }

     int i,k=0,si=0;
     char intfunction[100];
      while(fgets(c, sizeof(c), fptr))
    {
        line++;
        removecomment(c);
        strcpy(filestring[si],c);
        si++;
      if( strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
      {
          char check[100];
          strcpy(check,c);
          removeSpaces(check);
          if((check[0]=='i'&&check[1]=='n'&&check[2]=='t')||(check[0]=='v'&&check[1]=='o'&&check[2]=='i')||(check[0]=='d'&&check[1]=='o'&&check[2]=='u'&&check[3]=='b')||(check[0]=='*')||(check[0]=='c'&&check[1]=='h')||(check[0]=='l'&&check[1]=='o'&&check[2]=='n')||(check[0]=='u'&&check[1]=='n')||(check[0]=='s'&&check[1]=='h'))
          {
          for(i=0;;i++)
       {
           if(c[i]=='(')
           {
               break;
           }
       }
       i=i-1;
       for(;;i--)
       {
           if(c[i]!=' ')
           {
               break;
           }
       }
       for(;;i--)
       {
           if(c[i]==' ')
           {
               break;
           }
       }
       for(i=i+1;;i++)
       {
           if(c[i]==' ')
           {
               continue;
           }
           if(c[i]=='(')
           {
               intfunction[k]='/';
               k++;
               break;
           }
           intfunction[k]=c[i];
           k++;
       }
      }
      }
    }
    fclose(fptr);
    printf("Funtions are = ");
    int l=0;
    for(i=0;i<k;i++)
    {
        if(intfunction[i]=='/')
        {
            fi++;
            l=0;
            continue;
        }
         function_name[fi][l]=intfunction[i];
         l++;
    }
    for(i=0;i<fi;i++)
    {
        printf("%s ,",function_name[i]);
    }
}
int main()
{
    findfunction();
    for(int i=0;i<100;i++)
   {
       menu[i]=0;
       countf[i]=0;
   }
   function_menu("main");

}

