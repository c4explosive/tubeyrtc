#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parser.h>
int opc(char * argv1) //Verificar funciones y guion; Retorna 9 por si hay error
{
    int i=0,opp;
    char *op=malloc(30*sizeof(char));
    char * fxs[]={"d","c","dc","ld","lc","ldc"};
    if(argv1[0]=='-')
    {
    	for(i=0;i<strlen(argv1)-1;i++)
    	{
	    op[i]=argv1[i+1];
    	}
    	for(i=0;i<sizeof(fxs)/sizeof(char*);i++)
    	{
	    if(!strcmp(fxs[i],op))
	    {
	    	return i;	    
	    	break;
	    }
    	}
	return 9;
    }
    else
	return 9;
}

int veroa(int argc,int op) //Verificar argumentos y cantidad argumentos; 1 si esta bien y 0 si esta mal
{
    if(argc==3 && (op==0 || op==4 || op==5))
	return 1;
    else if (argc == 2 && (op==3)
 	return 1;
    else if(argc==4 && (op==1 || op==2 || op==4 || op==5))
	return 1;
    else
	return 0;
}

int main(int argc, char * argv[])
{
    /*if(veroa(argc-1,opc(argv[1])))
    {
    }*/
    return 0;
}
