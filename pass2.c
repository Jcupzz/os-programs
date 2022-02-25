#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[100], str2[100], str3[100], intstr1[100], intstr2[100], intstr3[100], opcode[100], value[100], symb[100], valuesym[100], ch[100];
    int flag, n, start;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    fp1 = fopen("ASSEMBLE.txt", "r");
    fp2 = fopen("symbtab.txt", "w");
    fp3 = fopen("intermediate.txt", "w");
    fscanf(fp1, "%s %s %s", str1, str2, str3);
    if (strcmp(str2, "START") == 0)
    {
        start = atoi(str3);
        n = start;
        fprintf(fp3, "%s %s %s\n", str1, str2, str3);
    }

    while (strcmp(str2, "END") != 0)
    {
        fscanf(fp1, "%s %s %s\n", str1, str2, str3);
        fp4 = fopen("optab.txt", "r");
        flag = 0;
        while (fscanf(fp4, "%s %s", opcode, value) != EOF)
        {
            if (strcmp(str2, opcode) == 0)
            {
                flag = 1;
                continue;
            }
        }
        if (flag == 0)
        {
            printf("Error opcode not present");
            break;
        }
        fclose(fp4);
        fprintf(fp3, "%d %s %s %s\n", start, str1, str2, str3);
        if (strcmp(str1, "**") != 0)
        {
            fprintf(fp2, "%s %d\n", str1, start);
        }
        if (strcmp(str2, "RESW") == 0)
        {
            start += 3 * (atoi(str3));
        }
        else if (strcmp(str2, "RESB") == 0)
        {
            start += atoi(str3);
        }
        else
        {
            start += 3;
        }
    }
    printf("Length of program: %d", start - n - 3);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fp1 = fopen("ASSEMBLE.txt", "r");
    fp2 = fopen("object_code.txt", "w");
    fp5 = fopen("intermediate.txt", "r");
    fscanf(fp5, "%s %s %s", intstr1, intstr2, intstr3);
    fprintf(fp2, "%s %s %s\n", intstr1, intstr2, intstr3);
    fscanf(fp1, "%s %s %s", str1, str2, str3);
    while (strcmp(str2, "END") != 0)
    {
        fscanf(fp1, "%s %s %s", str1, str2, str3);
        fscanf(fp5, "%s %s %s %s", ch, intstr1, intstr2, intstr3);
        fp3 = fopen("optab.txt", "r");
        flag = 0;
        while (fscanf(fp3, "%s %s", opcode, value) != EOF)
        {
            if (strcmp(str2, opcode) == 0)
            {
                fp4 = fopen("symbtab.txt", "r");
                while (fscanf(fp4, "%s %s", symb, valuesym) != EOF)
                {
                    if (strcmp(str3, symb) == 0)
                    {
                        fprintf(fp2, "%s %s %s %s %s%s\n", ch, intstr1, intstr2, intstr3, value, valuesym);
                        flag = 1;
                    }
                }
                fclose(fp4);
            }
        }
        fclose(fp3);
        if (flag == 0)
        {
            fprintf(fp2, "%s %s %s %s\n", ch, intstr1, intstr2, intstr3);
        }
    }
    fclose(fp1);
    fclose(fp5);
    fclose(fp2);
    return 0;
}
