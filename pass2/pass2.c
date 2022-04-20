#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char label[100], opcode[100], operand[100], int_label[100], int_opcode[100], int_operand[100], optab_opcode[100], optab_value[100], symb[100], symb_val[100], ch[100];
    int flag, n, locctr;
    FILE *assembly, *symtab, *intermediate, *optab, *fp5;
    assembly = fopen("assemblylanguage.txt", "r");
    symtab = fopen("symtab.txt", "w");
    intermediate = fopen("intermediate.txt", "w");
    fscanf(assembly, "%s %s %s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        locctr = atoi(operand);
        n = locctr;
        fprintf(intermediate, "%s %s %s\n", label, opcode, operand);
    }

    while (strcmp(opcode, "END") != 0)
    {
        fscanf(assembly, "%s %s %s\n", label, opcode, operand);
        optab = fopen("optab.txt", "r");
        flag = 0;
        while (fscanf(optab, "%s %s", optab_opcode, optab_value) != EOF)
        {
            if (strcmp(opcode, optab_opcode) == 0)
            {
                flag = 1;
                continue;
            }
        }
        if (flag == 0)
        {
            printf("Error optab_opcode not present");
            break;
        }
        fclose(optab);
        fprintf(intermediate, "%d %s %s %s\n", locctr, label, opcode, operand);
        if (strcmp(label, "**") != 0)
        {
            fprintf(symtab, "%s %d\n", label, locctr);
        }
        if (strcmp(opcode, "RESW") == 0)
        {
            locctr += 3 * (atoi(operand));
        }
        else if (strcmp(opcode, "RESB") == 0)
        {
            locctr += atoi(operand);
        }
        else
        {
            locctr += 3;
        }
    }
    printf("Length of program: %d", locctr - n - 3);
    fclose(assembly);
    fclose(symtab);
    fclose(intermediate);
    assembly = fopen("assemblylanguage.txt", "r");
    symtab = fopen("object_code.txt", "w");
    fp5 = fopen("intermediate.txt", "r");
    fscanf(fp5, "%s %s %s", int_label, int_opcode, int_operand);
    fprintf(symtab, "%s %s %s\n", int_label, int_opcode, int_operand);
    fscanf(assembly, "%s %s %s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0)
    {
        fscanf(assembly, "%s %s %s", label, opcode, operand);
        fscanf(fp5, "%s %s %s %s", ch, int_label, int_opcode, int_operand);
        intermediate = fopen("optab.txt", "r");
        flag = 0;
        while (fscanf(intermediate, "%s %s", optab_opcode, optab_value) != EOF)
        {
            if (strcmp(opcode, optab_opcode) == 0)
            {
                optab = fopen("symtab.txt", "r");
                while (fscanf(optab, "%s %s", symb, symb_val) != EOF)
                {
                    if (strcmp(operand, symb) == 0)
                    {
                        fprintf(symtab, "%s %s %s %s %s%s\n", ch, int_label, int_opcode, int_operand, optab_value, symb_val);
                        flag = 1;
                    }
                }
                fclose(optab);
            }
        }
        fclose(intermediate);
        if (flag == 0)
        {
            fprintf(symtab, "%s %s %s %s\n", ch, int_label, int_opcode, int_operand);
        }
    }
    fclose(assembly);
    fclose(fp5);
    fclose(symtab);
    return 0;
}
