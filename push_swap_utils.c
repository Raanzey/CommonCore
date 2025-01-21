/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:57:21 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/21 19:00:52 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_node *step_ss(t_node *node)
{
    t_node *temp = node->next; // İlk düğümün işaret ettiği ikinci düğümü tut
    node->next = temp->next;  // İlk düğüm, ikinci düğümün işaret ettiği düğümü göstersin
    temp->next = node;        // İkinci düğüm, ilk düğümü göstersin
    return temp;    
}
