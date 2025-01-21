/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:13:01 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/21 18:42:51 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void swap_step(char *str, t_stack *stk)
{
    if (ft_strncmp(str, "sa", 2) == 0|| ft_strncmp(str, "ss", 2) == 0)
        stk->a = step_ss(stk->a);
    if (ft_strncmp(str, "sb", 2) == 0|| ft_strncmp(str, "ss", 2) == 0)
       stk->b = step_ss(stk->b);
}
//     else if (str == "pa")
//     {
//         /* code */
//     }
//     else if (str == "pb")
//     {
//         /* code */
//     }
//     else if (str == "ra" || str == "rr")
//     {
//         /* code */
//     }
//     else if (str == "rb" || str == "rr")
//     {
//         /* code */
//     }
//     else if (str == "rra" || str == "rrr")
//     {
//         /* code */
//     }
//     else if (str == "rrb" || str == "rrr")
//     {
//         /* code */
//     }


t_node *addValue(t_node *node, int data)
{
    if (node == NULL)
    {
        node = malloc(sizeof(t_stack));  
        if (node == NULL)
            return NULL;
        node->data = data;
        node->next = NULL;
        return node;    
    }   
    t_node *temp = node;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = malloc(sizeof(t_stack));
    temp->next->data = data;
    temp->next->next = NULL;
    return node;     
}
void display(t_node *node)
{
    t_node *temp = node;
    while (temp != NULL )
    {
        printf("%d\n", temp->data);
        temp = temp->next;     
    }
}
int main(int argc, char **argv)
{
    t_stack *stk;
    int i;
    
    stk = malloc(sizeof(t_stack));
    stk->a = NULL;
    stk->b = NULL;
    i = 1;
    if (argc == 2) {
        argv = ft_split(argv[1], ' ');   
        i = 0;  
    }
    while (argv[i])
    { 
            stk->a = addValue(stk->a, ft_atoi(argv[i]));
            i++;
    } 
    swap_step("sa", stk);    
    display(stk->a);     
}
