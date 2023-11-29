/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:01 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/29 18:31:32 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(ssize_t *a, ssize_t *b)
{
	ssize_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_quick_sort(ssize_t *stack, ssize_t start, ssize_t end)
{
	ssize_t	pivot;
	ssize_t	i;
	ssize_t	j;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;
		while (i < j)
		{
			while (stack[i] <= stack[pivot] && i < end)
				i++;
			while (stack[j] > stack[pivot])
				j--;
			if (i < j)
				ft_swap(&stack[i], &stack[j]);
		}
		ft_swap(&stack[pivot], &stack[j]);
		ft_quick_sort(stack, start, j - 1);
		ft_quick_sort(stack, j + 1, end);
	}
}

static ssize_t	*ft_fill_stack(t_list **lst)
{
	ssize_t	i;
	t_list	*tmp;
	ssize_t	*stack;

	tmp = *lst;
	stack = malloc(sizeof(ssize_t) * ft_lstsize(*lst));
	if (!stack)
		return (NULL);
	i = -1;
	while (tmp)
	{
		stack[++i] = ((t_data *)tmp->content)->value;
		tmp = tmp->next;
	}
	return (stack);
}

t_list	**indexing(t_list **lst)
{
	ssize_t	*stack;
	ssize_t	i;
	ssize_t	j;
	t_list	*tmp;

	tmp = *lst;
	stack = ft_fill_stack(lst);
	if (!stack)
		return (NULL);
	ft_quick_sort(stack, 0, ft_lstsize(*lst) - 1);
	tmp = *lst;
	i = ft_lstsize(*lst);
	while (tmp)
	{
		j = -1;
		while (++j < i)
			if (((t_data *)tmp->content)->value == stack[j])
				((t_data *)tmp->content)->index = j + 1;
		tmp = tmp->next;
	}
	free(stack);
	return (lst);
}

#include <fcntl.h>
int main(void)
{
	t_list	*lst;
	t_list	*not_push;
	t_list	*new;
	t_data	*data;
	//ssize_t	num[450] = {8514, 7144, 1886, 6687, 8473, 2242, 2397, 7692, 1592, 9320, 7407, 5763, 6151, 2754, 1553, 6002, 5251, 9911, 1420, 1856, 1625, 1456, 9992, 1438, 1124, 7187, 805, 1833, 1876, 9845, 293, 3008, 746, 6676, 1151, 493, 2501, 6920, 7850, 5496, 7830, 9155, 6694, 7525, 5094, 7114, 5883, 4176, 1725, 8739, 6527, 6914, 2417, 3878, 6129, 149, 7071, 2430, 6464, 5292, 6184, 4154, 8100, 9077, 7951, 9020, 1840, 7185, 5923, 9681, 835, 1861, 519, 1007, 7274, 947, 8013, 12, 4164, 9294, 4224, 1526, 5108, 6623, 7117, 9343, 669, 3602, 3014, 2382, 2300, 6504, 395, 7604, 6562, 2717, 2315, 196, 7216, 7689, 3768, 1825, 4255, 6413, 7045, 4568, 1533, 8361, 7458, 2580, 4324, 5885, 1232, 3874, 4423, 3698, 7089, 3291, 9598, 6525, 338, 7891, 4392, 7232, 7938, 946, 4039, 7027, 4222, 4620, 8576, 724, 2400, 5701, 5260, 6681, 5145, 4148, 1499, 2542, 4651, 9388, 9295, 2854, 2408, 4563, 354, 2394, 3027, 728, 8474, 714, 8018, 7360, 9869, 5641, 8947, 7883, 2611, 5856, 1827, 8038, 8812, 8818, 683, 9517, 5984, 2955, 1941, 5111, 1539, 5638, 9233, 112, 9240, 2097, 986, 2590, 6975, 6348, 7768, 5767, 3936, 1717, 3875, 2549, 40, 8602, 2563, 1474, 6677, 952, 9042, 5822, 455, 632, 1299, 5808, 5208, 8724, 1467, 7551, 9454, 5337, 1882, 589, 9596, 3975, 3382, 9234, 1785, 6263, 3410, 4751, 3886, 8582, 2325, 4374, 6457, 5981, 487, 1661, 5817, 1885, 8105, 3743, 5689, 7321, 6279, 6826, 4467, 6466, 2961, 9314, 619, 89, 9838, 3007, 4767, 8825, 2816, 2108, 9839, 2591, 3451, 6062, 415, 6181, 4325, 9150, 3322, 6477, 3340, 6838, 9870, 874, 392, 2396, 6288, 633, 117, 9832, 2681, 8482, 8254, 3215, 2602, 9433, 1277, 8839, 2980, 6029, 3417, 4592, 5941, 6650, 9833, 9378, 8225, 3470, 3727, 4289, 5339, 2843, 6733, 6022, 9698, 6118, 1906, 1311, 6944, 3127, 9361, 9116, 8326, 9853, 6347, 8325, 1313, 5497, 3302, 1027, 5662, 6053, 101, 639, 6765, 8262, 123, 6206, 5595, 5804, 7353, 8802, 4314, 9618, 4387, 1034, 2426, 8698, 3050, 3937, 5787, 8610, 4045, 1191, 9594, 514, 6735, 9824, 9404, 9663, 8951, 3720, 3938, 6955, 7494, 8800, 869, 7066, 5009, 4099, 4495, 8296, 939, 1551, 3285, 277, 3561, 1983, 3270, 4249, 9747, 2051, 204, 8016, 2498, 2352, 3993, 664, 2090, 4822, 2985, 6692, 9937, 4212, 3757, 6375, 2786, 1811, 2278, 863, 9380, 408, 5204, 1771, 332, 7371, 9763, 303, 2819, 3632, 4180, 7345, 7655, 8584, 5093, 6440, 5105, 4232, 5102, 2456, 692, 5813, 6406, 6533, 6613, 21, 3801, 7987, 1494, 8556, 3333, 8251, 6521, 548, 6282, 2956, 4715, 2215, 6463, 4960, 412, 4401, 8099, 1167, 355, 7623, 344, 2137, 4436, 345, 1711, 7527, 1309, 4299, 5161, 4899, 8539, 346, 7616, 1572, 220, 8075, 3421, 5874, 1562, 477, 6125, 2516, 1547, 7554, 7220, 9143, 7145, 5279, 6927, 7519, 124, 1872};
	ssize_t	num[499] = {-9657, -7218, -6271, -468, -6333, 7142, 8425, -6425, -7535, 7646, -3053, 4790, -6977, -7322, -1662, -3943, -2004, 6813, 9062, -5390, 3023, -6153, 1573, -9269, 2288, -331, -305, 7600, 3167, 5251, 2777, 4202, -4453, -6892, -2182, 8547, 667, 5502, 3969, -1752, -3036, -7381, 2643, 2979, 3520, 7396, 3048, 5385, -2870, -7994, 2250, -8375, -7187, 1604, -2590, -7256, -9068, -5105, 4714, -5270, -8633, -3111, -3125, 7002, -7285, 2848, -2407, 3007, 6591, 6468, -1634, -9173, 476, 5890, -5892, -1595, 2546, -9439, 2139, -3407, -4304, 5122, -2402, 738, -2861, 5008, -2322, 982, 7788, 1916, -4717, -9794, 6918, 4023, 9477, -9336, 4225, 3785, 9256, -5201, 9060, 1966, 8029, -800, 8561, 7531, -2165, -985, 5367, 8929, 8407, 4083, -3921, -1281, 7097, -4413, 7538, 4687, 5448, 7010, 2928, -1394, 423, 5235, 5571, 3231, 1727, 298, 1056, -5338, 3415, 4624, 4237, -8448, 2344, 4286, 9655, -6876, 9433, -2830, 4441, 4997, 8636, -3005, -8004, -6282, -5801, 1646, 659, -9942, -4532, 4709, 3288, -6954, -3015, -6888, -9813, -3098, -6619, 3819, 428, -9100, 6454, 5023, 9420, -7748, 3424, -5608, -7176, 9962, 4655, 7757, -463, -804, -9157, -4956, -85, 4848, 8861, -9143, 3388, 5563, 1939, 6453, -9727, 8507, 6782, 7360, 4195, -5874, 6988, -6080, 712, -7883, 1148, -2062, -3925, -5439, 8689, -5065, 7724, 7541, 1376, -5625, 3857, -6957, -7543, 9674, -2756, 7540, -2678, 3219, 1837, -3863, -797, -2828, 9183, 6876, -9611, 4599, 8829, 8081, 1327, 3834, -51, -7898, 6839, -5265, -1045, -4408, -8359, 1894, 5731, -8871, 7994, 6961, -1568, -1918, 4719, -6465, -7387, 1439, 3940, -5106, -7472, -4034, 4707, -7905, 172, 9083, -7511, 3038, -6552, 6054, 3681, 4168, -4416, 6376, -8461, -3772, -6936, -4412, -7957, 6027, -9006, 8178, 1404, 4739, 2058, -8291, 3986, 3790, 8982, 1904, -4919, -6460, 6997, 6197, 2157, 5865, 3861, 6447, 9396, -814, -9648, 1627, 7868, 8323, 8773, -8058, -9692, 2914, 8137, -3485, -6108, -2766, -5027, -5664, -6475, 7075, 2480, -6910, -2608, -6802, 1341, -6612, 6111, -9202, 6025, 1067, -9770, -9175, 2186, 2109, 2044, -3765, 5880, -8722, -8969, 3814, -6817, -5361, -2252, -699, -8142, -3793, 5942, -3786, 7020, -4222, -3445, -1726, -6368, -9912, 5618, -9079, 6963, 9512, -1888, -8870, -4666, 9760, -5432, 5520, 8486, 7907, -5469, -1648, 7137, -5183, -5012, 7452, -7340, -6758, -6272, -2141, 8756, -6779, 1093, 3643, 7461, -6349, 4414, -7053, -4734, -1221, 4598, -9111, 8832, 1987, 5216, 2881, -6074, -5157, 8663, -7323, -9517, -1613, 5362, -2848, 2214, -3469, 3958, 2197, 9032, -5015, -6091, 7931, -4491, -933, 8474, -1669, -9958, 6622, -6711, -4912, -826, -5745, 4379, 6781, -3105, -2127, 1171, -9432, 2232, -5467, -1711, 5419, 6168, -7718, -5859, 4164, -1071, -9507, 1710, -2760, 4170, -294, -9435, -7418, 5244, 3927, 6725, 1951, -9080, 3213, -4620, 6931, -3309, -9103, -7193, -4588, -6109, 1569, -9066, 9370, -4544, 7661, -8720, -5902, 3483, -1192, -9504, 413, -4902, 9842, 7748, -6985, -72, -4972, 8463, -3899, 8161, 9622, -6829, -4761, 3256, 314, -5828, -2511, 2074, 787, 6649, -9735, 6867, -7083, 89, -6949, 2444, 8649, -7597, 7427, 6932, 7441, -5604, 8661, 1051, -1502, -4839, 5310, -6117, -2988, 5729, 566, 5380, 8429, -3662, 390, -9053, 5240, -1085, -5710, -8216, 1782, 7519, 3968, -2247, -7216, -3664};
	//ssize_t	num[15] = {-567, 891, -185, 308, -721, 442, -834, 632, 147, -512, 775, -232, 419, -695, 197};
	//ssize_t	num[100] = {930, 6650, 4266, 1566, 3174, 8051, 6016, 3416, 8448, 3037, 3233, 8329, 2864, 6413, 1305, 1182, 4273, 4056, 6802, 7352, 4363, 6988, 168, 2746, 2440, 6772, 2429, 1700, 3072, 9477, 2752, 6897, 4042, 9382, 7610, 5650, 6757, 3179, 3840, 6991, 9650, 1358, 8386, 9196, 8498, 9733, 6341, 7464, 2992, 7592, 5663, 1718, 6776, 7104, 4848, 4538, 3677, 7609, 2466, 3109, 1936, 3041, 1452, 8893, 6520, 9141, 1744, 5441, 9409, 4414, 6821, 5289, 2256, 3904, 8266, 7359, 9532, 4800, 4811, 1386, 2584, 5317, 9660, 8675, 1532, 851, 3364, 4002, 7108, 123, 4936, 2553, 3907, 3385, 5783, 4671, 9881, 5599, 4191, 8356};
	//ssize_t	num[100] = {7438, -5590, 731, -1420, -7419, -7875, -6719, -1152, 3662, 7256, 5349, 9733, 8144, -1665, -9574, 7100, 3504, 8123, -7220, 2759, 5214, 9340, 1592, 4192, -3523, -8318, 4945, 748, 8391, -3139, -598, 9356, 8077, 2543, -1815, 2443, -578, 7661, -4058, -362, -986, 9035, -1698, -324, -3858, -8745, -8238, -9272, -4264, 168, -3848, 124, 1652, -806, 2251, -6288, -5623, 7857, 3135, -9645, 4754, -7469, -6920, -7882, 2944, -9030, -7530, -4387, -5890, 2985, 1146, -5571, -1248, -7958, -7040, -3048, -4838, 8233, 5067, -5423, 5488, 1560, -290, 356, 6580, -8297, -9812, -1904, -8649, -1062, -8966, 7607, 6622, -9012, 1246, 7205, 9124, 9517, 1273, 7120};
	//ssize_t	num[100] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//ssize_t	num[5] = {1, 5, 2, 4, 3};
	//ssize_t		num[3] = {2, 1, 0};
	//ssize_t		num[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int		i;
	int		fd;
	char	*moves;

	data = malloc(sizeof(t_data));
	data->value = num[0];
	data->index = 0;
	lst = ft_lstnew(data);
	i = 1;
	while (i < 499)
	{
		data = malloc(sizeof(t_data));
		data->value = num[i];
		data->index = 0;
		data->dist = 0;
		data->obm = NULL;
		new = ft_lstnew(data);
		ft_lstadd_back(&lst, new);
		i++;
	}
	indexing(&lst);
	//ft_print_status(lst, NULL, "");
	ft_set_swap(&lst);
	not_push = ft_lis(lst);
	/* while (not_push)
	{
		printf("index: %zu\n", (*(size_t *)not_push->content));
		not_push = not_push->next;
	} */
	moves = ft_calculate(&lst, not_push);
	//printf("%s", moves);
	fd = open("moves.txt", O_RDWR);
	write(fd, moves, ft_strlen(moves));
	t_list *animate;
	data = malloc(sizeof(t_data));
	data->value = num[0];
	data->index = 0;
	animate = ft_lstnew(data);
	i = 1;
	while (i < 499)
	{
		data = malloc(sizeof(t_data));
		data->value = num[i];
		data->index = 0;
		data->dist = 0;
		data->obm = NULL;
		new = ft_lstnew(data);
		ft_lstadd_back(&animate, new);
		i++;
	}
	indexing(&animate);
	t_list *stack_b = NULL;
	ft_animation(animate, stack_b, moves);
	return (0);
}
