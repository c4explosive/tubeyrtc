#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "parser.h"
#define YDL "/bin/youtube-dl"
#define FFMPEG "/bin/ffmpeg"
void dowon(char * link,char * name) //Caso 0
{
    char * command = malloc(500*sizeof(char));
    sprintf(command,"%s -f 43 %s -o %s.webm",YDL,link,name);
    system(command);
}

void convon(char * file,char * name, char * format) //Caso 1
{
    char * command = malloc(500*sizeof(char));
    sprintf(command,"%s -i %s %s.%s",FFMPEG,file,name,format);
    system(command);
}

void dconv(char * link, char *name, char * format) //Caso 2
{
    char * archh=malloc(100*sizeof(char));
    dowon(link,name);
    sprintf(archh,"%s.webm",name);
    convon(archh,name,format);
}

//Lists

void ldowon(char * lname) //Caso 3
{
    media * mds=parser(lname);
    int i;
    for(i=0;i<mds->cant;i++)
	dowon(mds->link[i],mds->names[i]);
}

void lconvon(char * lname, char * format, char * namel) //Caso 4
{
    media * mds=parser(lname);
    char * archh=malloc(100*sizeof(char));
    int i;
    char * command=malloc(500*sizeof(char));
    char * dilex=malloc(100*sizeof(char));
    chdir(cwdf());
    sprintf(command,"mkdir %s",namel);
    system(command);
    sprintf(dilex,"%s/%s",cwdf(),namel);
    chdir(dilex);
    for(i=0;i<mds->cant;i++)
    {	
    	sprintf(archh,"../%s.webm",mds->names[i]);
    	convon(archh,mds->names[i],format);
    }
}

void ldconv(char * lname,char * format, char * namel) //Caso 5
{
    ldowon(lname);
    lconvon(lname,format,namel);
}

int main(int argc, char* argv[])
{
    //dowon(argv[1],argv[2]); //Caso 0
    //convon(argv[1],argv[2],argv[3]); //Caso 1
    //dconv(argv[1],argv[2],argv[3]);  //Caso 2
    //ldowon(argv[1]); //Caso 3
    //lconvon(argv[1],argv[2],argv[3]); //Caso 4
    //ldconv(argv[1],argv[2],argv[3]); //Caso 5
    ldebug(argv[1]);
    return 0;
}
