#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

        char label[20], opcode[20], operand[20], optab_opcode[20], optab_value[20], ch;
        int flag, n, start;
        FILE *assembly = fopen("assemblylanguage.txt", "r");
        FILE *symtab = fopen("symtab.txt", "w");
        FILE *intermediate = fopen("intermediate.txt", "w");

        fscanf(assembly, "%s %s %s", label, opcode, operand);

        if (strcmp(opcode, "START") == 0)
        {
                start = atoi(operand);
                n = start;
                fprintf(intermediate, "%s %s %s\n", label, opcode, operand);
        }
        while (strcmp(opcode, "END") != 0)
        {
                fscanf(assembly, "%s %s %s", label, opcode, operand);
                FILE *optab = fopen("optab.txt", "r");
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
                        printf("ERROR: OPCODE NOT PRESENT IN OPTAB.TXT!\n");
                        break;
                }
                fclose(optab);
                fprintf(intermediate, "%d %s %s %s\n", start, label, opcode, operand);

                if (strcmp(label, "**") != 0)
                {
                        fprintf(symtab, "%s %d\n", label, start);
                }

                if (strcmp(opcode, "RESW") == 0)
                {
                        start += 3 * (atoi(operand));
                }

                else if (strcmp(opcode, "RESB") == 0)
                {
                        start += atoi(operand);
                }
                else
                {
                        start += 3;
                }
        }

        printf("Length of program: %d", start - n - 3);
        fclose(assembly);
        fclose(symtab);
        fclose(intermediate);
        return 0;
}

