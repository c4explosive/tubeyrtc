#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NN 500
typedef struct _media
{
    char ** link;
    char ** names;
    int cant;
}media;


media * crmedia()
{
    int i;
    media * mdd=malloc(sizeof(media));
    mdd->link=malloc(NN*sizeof(char*));
    mdd->names=malloc(NN*sizeof(char*));
    mdd->cant=0;
    for(i=0;i<NN;i++)
    {
	mdd->link[i]=malloc(200*sizeof(char));
	mdd->names[i]=malloc(200*sizeof(char));
    }
    return mdd;
}

int ispace(char cc)
{
    switch(cc)
    {
	case 0x9: case 0x20: return 1; break;
	default: return 0;
    }
}

//TODO: Diferentes caracteres de espaciado, 0x20, 0x9, etc.
media * parser(char* argvn)
{
    FILE * f1;
    media * md1=crmedia();
    char * t,*name,**link,**names;
    char cc;
    int i,kk,ii,j,k,l,kc=1,pass=1;
    int spp=1;
    t=malloc(200*sizeof(t));
    link=malloc(NN*sizeof(char*)); //lista de links
    name=malloc(100*sizeof(char)); //nombre de la ruta del archivo
    names=malloc(NN*sizeof(char*)); //listas de nombres
    for(i=0;i<NN;i++)
	link[i]=malloc(200*sizeof(char));
    for(i=0;i<NN;i++)
	names[i]=malloc(200*sizeof(char));
    t=getcwd(t,800*sizeof(t)); //Obtener ruta actual de trabajo.
    sprintf(name,"%s/%s",t,argvn);
    f1=fopen(name,"r");
    i=j=k=l=0;
    while(1)
    {
	cc=fgetc(f1);
	if(feof(f1)!=0)
	    break;
	if(cc==0x23)
	    pass=0;
	if(cc == 0xa)
	{
	    if(pass==1)
	    {
	       l=0;
	       k++;
	       kc=1;
	       spp=1;
	    }
	    pass=1;
	}
  	//printf("CHAR::IS: 0x%x - %d\n",cc, !ispace(cc));
	if(!ispace(cc) && cc!=0xa && kc==1 && pass==1)
	{
    	    link[i][j]=cc;
	    j++;
	} else if (!ispace(cc) && cc!=0xa && kc==0 && pass==1)
	{
	    names[k][l]=cc;
	    l++;
	}
	else if (ispace(cc) && pass==1 && spp)
	{
	    kc=0;
	    j=0;
	    i++;
	    spp=0;
	}	
    }
    ii=i;
    kk=k;
    fclose(f1);
    if(ii==kk)
    {
	md1->link=link;
	md1->names=names;
	md1->cant=ii;
    	return md1;
    }
}

char * cwdf ()
{
    char * t = malloc(200*sizeof(char));
    t=getcwd(t,800*sizeof(t));
    return t;
}

void ldebug(char * list)
{
    media * mds=parser(list);
    int i=0;
    char * t=malloc(200*sizeof(char));
    t=getcwd(t,800*sizeof(t));
    printf("Current Dir: %s\n",t);
    for(i=0;i<mds->cant;i++)
	printf("%i.) %s - %s\n",i+1,mds->link[i],mds->names[i]);
    printf("\n");
}
