#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "linked_list.h"
#include <string.h>

uint8_t *balancedParentheses(uint8_t *expression)
{
    stack_t *s= create_stack(strlen(expression));
    sint32_t stack_buffer=0;
    uint8_t pop_flag=0;
    uint8_t expression_flag=1;

    for (int i=0;expression[i];i++)
    {
        if (expression[i]=='{')
        {
            push(s,1);
        }
        else if (expression[i]=='(')
        {
            push(s,2);
        }
        else if (expression[i]=='}')
        {
            pop_flag=pull(s,&stack_buffer);
            if (!pop_flag || stack_buffer!=1)
            {
                expression_flag=0;
                break;
            }
        }
        else if (expression[i]==')')
        {
            pop_flag=pull(s,&stack_buffer);
            if (!pop_flag || stack_buffer!=2)
            {
                expression_flag=0;
                break;
            }
        }
    }
    if (expression_flag && get_stack_Size(s))
    {
        expression_flag=0;
    }

    return          ((expression_flag)? "Balanced":"Not Balanced");
}


int main()
{
   char str[100]={0};
   while (1)
   {
        printf("Enter the expression to be checked: ");
        fgets(str, 100, stdin);
        printf("\nExpression is %s\n\n\n",balancedParentheses(str));
   }

}
