/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:55:36 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/29 17:17:09 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lis_build(t_list *node, t_list *lst)
{
	t_list	*lis_lst;
	t_list	*lis_lst_crcl;

	lis_lst = ft_lis_lin(node, ft_lstsize(node));
	if (lis_lst == NULL)
		return (NULL);
	lis_lst_crcl = ft_lis_crcl(lis_lst, lst);
	if (lis_lst_crcl != NULL)
	{
		ft_lstadd_front(&lis_lst, ft_lstlast(lis_lst_crcl));
		lis_lst = lis_lst_crcl;
	}
	return (lis_lst);
}

t_list	*ft_lis(t_list *lst)
{
	t_list	*lis_lst;
	t_list	*lis_lst_r;
	t_list	*node;
	size_t	min_lis;

	lis_lst_r = NULL;
	node = lst;
	min_lis = 2147483647;
	while (node != NULL)
	{
		if (min_lis >= ((t_data *) node->content)->index)
		{
			lis_lst = ft_lis_build(node, lst);
			if (ft_lstsize(lis_lst) > ft_lstsize(lis_lst_r))
			{
				ft_lstclear(&lis_lst_r, free);
				lis_lst_r = lis_lst;
			}
			else
				ft_lstclear(&lis_lst, free);
		}
		min_lis = ft_min_index(lis_lst_r);
		node = node->next;
	}
	return (lis_lst_r);
}


/* int	main()
{
	t_list	*stack_a;
	t_list	*lis;
	t_list	*node;
	t_data	*data;
	size_t	arr_a[500] = { 10, 70, 105, 242, 102, 433, 463, 99, 59, 446, 186, 370, 78, 67, 220, 166, 213, 416, 485, 129, 318, 106, 279, 20, 305, 244, 245, 445, 321, 380, 311, 353, 158, 84, 208, 469, 262, 388, 345, 216, 187, 64, 310, 316, 331, 435, 320, 385, 191, 50, 304, 43, 73, 280, 201, 69, 31, 138, 367, 132, 40, 183, 182, 427, 68, 312, 203, 317, 410, 409, 222, 23, 259, 397, 114, 224, 309, 16, 298, 180, 163, 375, 204, 264, 192, 373, 205, 266, 451, 289, 151, 5, 420, 347, 493, 19, 354, 334, 488, 134, 484, 292, 456, 239, 470, 441, 209, 234, 383, 481, 462, 348, 168, 228, 431, 160, 442, 364, 387, 428, 315, 227, 257, 377, 391, 324, 284, 253, 268, 131, 328, 362, 355, 42, 306, 356, 496, 86, 492, 194, 359, 372, 471, 189, 49, 103, 118, 282, 261, 2, 156, 366, 326, 80, 188, 85, 4, 185, 93, 337, 258, 28, 408, 374, 491, 55, 329, 123, 74, 500, 363, 450, 243, 238, 24, 144, 247, 371, 480, 25, 327, 390, 290, 407, 8, 468, 415, 434, 352, 115, 425, 111, 263, 54, 271, 212, 167, 127, 475, 139, 448, 444, 275, 122, 339, 79, 58, 497, 198, 443, 199, 323, 286, 170, 240, 195, 487, 419, 12, 361, 478, 457, 273, 338, 249, 53, 417, 133, 233, 162, 44, 287, 394, 36, 455, 423, 225, 214, 368, 97, 63, 277, 342, 137, 61, 165, 365, 52, 252, 486, 60, 319, 95, 401, 333, 350, 159, 405, 41, 173, 82, 161, 51, 400, 34, 460, 276, 369, 295, 45, 346, 335, 482, 288, 145, 98, 426, 404, 299, 395, 340, 406, 490, 237, 11, 281, 452, 461, 477, 48, 9, 314, 458, 177, 109, 196, 140, 121, 96, 430, 308, 83, 200, 89, 274, 94, 402, 21, 399, 269, 6, 22, 300, 297, 294, 174, 396, 38, 35, 336, 88, 130, 206, 241, 47, 171, 398, 172, 429, 164, 179, 217, 100, 3, 392, 30, 424, 494, 215, 37, 152, 498, 128, 389, 467, 453, 125, 221, 432, 135, 142, 438, 65, 91, 104, 210, 476, 90, 270, 332, 439, 101, 358, 76, 150, 229, 360, 26, 479, 293, 376, 313, 112, 136, 474, 66, 13, 223, 382, 193, 302, 178, 343, 301, 483, 141, 110, 454, 157, 235, 466, 219, 1, 411, 92, 146, 236, 119, 357, 414, 184, 211, 272, 18, 303, 126, 218, 386, 403, 56, 116, 349, 232, 14, 283, 197, 351, 246, 17, 62, 379, 341, 413, 291, 29, 322, 153, 421, 181, 27, 72, 154, 108, 278, 32, 489, 155, 447, 39, 113, 330, 230, 15, 256, 147, 499, 449, 77, 248, 143, 465, 169, 459, 495, 87, 149, 325, 254, 117, 202, 296, 265, 412, 7, 418, 75, 251, 81, 307, 472, 57, 436, 422, 437, 124, 473, 267, 226, 148, 381, 107, 190, 393, 260, 384, 464, 176, 255, 33, 378, 231, 120, 46, 285, 440, 344, 207, 71, 175, 250 };
	int		i;

	stack_a = NULL;
	lis = NULL;
	i = 0;
	while (i < 500)
	{
		data = malloc(sizeof(t_data));
		data->index = arr_a[i];
		data->value = arr_a[i];
		data->dist = 0;
		data->obm = NULL;
		ft_lstadd_back(&stack_a, ft_lstnew(data));
		i++;
	}
	lis = ft_lis(stack_a);
	node = lis;
	while (node != NULL)
	{
		printf("%zu ", (*(size_t *) node->content));
		node = node->next;
	}
	printf("\n");
	ft_lstclear(&lis, free);
	ft_lstclear(&stack_a, free);
	return (0);
} */

