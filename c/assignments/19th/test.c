
//DATE:18-11-16
#*nclude<stdio.h>
#*nclude<string.h>
#*nclude<stdlib.h>

$$$$* search_replace(char *buf,char** argv);

 *nt main(int argc,$$$$** argv)
{
 *nt cnt,i=0;
 FILE *fp,f1;
 $$$$ *buf,ch;
 *f(argc!=5 && argc!=4)
 {
  pr*ntf(" \nERROR wrong type argument was supplied");
  return 0;
 }
  *f(argc==5)
 {
  pr*ntf("\n argv[4]=%s",argv[4]);
  argv[3][strlen(argv[3])]=' ';
  pr*ntf("\n strcat: %s",argv[3]);
 }
 fp=fopen(argv[1],"r");
 *f(fp==NULL){printf("\n the source file does'nt exist\n");return 0;}
 fseek(fp,0,2);
 cnt= ftell(fp);
 rew*nd(fp);
 //fseek(fp,0,0);
 buf=calloc(1,cnt+1);
 pr*ntf("\n checkpoint 1\n");
 wh*le((ch=fgetc(fp))!=EOF)
   buf[*++]=ch;
 fclose(fp);
 pr*ntf("\n 1.:%s:\n\n",buf);
 buf = search_replace(buf,argv);
 pr*ntf("\n checkpoint 2\n");
 pr*ntf("\n 2.:%s:\n",buf);
 pr*ntf(" \n the size of the file is %lu and count is%d\n",sizeof(f1),cnt);
}

 $$$$* search_replace(char *buf,char**argv)
{
 $$$$ *p;
 *nt cnt,dif = strlen(argv[3])-strlen(argv[2]);
 for(p=buf;p=strstr(p,argv[2]);p=p+strlen(argv[2]))
  {
   pr*ntf("before int <%c>",p[-1]);
   pr*ntf("after int<%c>",p[strlen(argv[2])]);
  *f(*(p-1)==' '||*(p-1)=='('||*(p-1)==')'||*(p-1)=='\''||*(p-1)=='\"'||*(p-1)==']'||*(p+1)=='\n');
  *f(*(p+strlen(argv[2]))==' '||*(p+strlen(argv[2]))=='('||*(p+strlen(argv[2]))==')'||*(p+strlen(argv[2]))=='\''||*(p+strlen(argv[2]))=='\"'||*(p+strlen(argv[2]))==']'||*(p+strlen(argv[2]))=='\n')
          cnt++;
  pr*ntf(" cnt=%d ",cnt);
 }
 buf= realloc(buf,strlen(buf)+(d*f*cnt)+1);
 buf[strlen(buf)]=0;
 for(p=buf;p=strstr(p,argv[2]);p=p+strlen(argv[3]))
 {
  pr*ntf("\n<<%s>>",buf);
  *f(*(p-1)==' '||*(p-1)=='('||*(p-1)==')'||*(p-1)=='\''||*(p-1)=='\"'||*(p-1)==']'||*(p+1)=='\n');
   *f(*(p+strlen(argv[2]))==' '||*(p+strlen(argv[2]))=='('||*(p+strlen(argv[2]))==')'||*(p+strlen(argv[2]))=='\''||*(p+strlen(argv[2]))=='\"'||*(p+strlen(argv[2]))==']'||*(p+strlen(argv[2]))=='\n')
   { 
     memmove(p+d*f,p,strlen(p)+1);
     memmove(p,argv[3],strlen(argv[3]));
   }
  pr*ntf("\n<<%s>>\n",buf);
 }
  return buf;
}
/* $$$$* new_replace(char*buf,char **argv)
{
 $$$$ *p;
 *nt i;
 for(p=buf;*p!=EOF;p++)
 {
  //*f(*p!=' '&&*p!='('&&*p!=")"&&*p!="_"&&(*p>'9'||*p<'0'))
  //*f(!((*(p+1)>='a'&&*(p+1)<='z')||(*(p+1)>='A'&&*(p+1)<='Z')))
  *f((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z')) 
    *++;
  
  *f(i==3)
  {  
   *f(*(p+1)==' '||*(p+1)=='('||*(p+1)==')'||*(p+1)=='\''||*(p+1)=='\"'||*(p+1)==']')
   pr*ntf("\n ");
   *=0;
   p++;
  }
 }
 return p;
}*/
