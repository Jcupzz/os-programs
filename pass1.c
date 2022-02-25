#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
        FILE *assembly = fopen("assemblylanguage.txt","r");
        FILE *optab = fopen("optab.txt","r");
        FILE *symtab = fopen("symtab.txt","w");
        FILE *intermediate = fopen("intermediate.txt","w");
        char label[20],opcode[20],operand[20];
        int locctr=0,i=0,flag=0;
        while(1)
        {
                fscanf(assembly,"%s\t%s\t%s",label,opcode,operand);
                if(strcmp(opcode,"START")==0)
                {
                        locctr=atoi(operand);
                        continue;
                }
                else if(strcmp(opcode,"END")==0)
                        break;
                else if(strcmp(opcode,"RESW")==0)
                {
                        fprintf(symtab,"%s\t%d\n",label,locctr);
                        fprintf(intermediate,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
                        locctr=locctr+(3*atoi(operand));
                        flag=1;
                }
                else
                {       if(strcmp(label,".")!=0)
                                fprintf(symtab,"%s\t%d\n",label,locctr);
                        fprintf(intermediate,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
                }
                if(flag!=1)
                        locctr=locctr+3;
                else
                        flag=0;
        }
        return 0;
}
