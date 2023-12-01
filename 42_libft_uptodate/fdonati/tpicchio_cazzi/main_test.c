/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:39:29 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/01 13:09:07 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int main(void)
{
	t_list	*lst;
	t_list	*not_push;
	t_list	*new;
	t_data	*data;
	//ssize_t	num[450] = {8514, 7144, 1886, 6687, 8473, 2242, 2397, 7692, 1592, 9320, 7407, 5763, 6151, 2754, 1553, 6002, 5251, 9911, 1420, 1856, 1625, 1456, 9992, 1438, 1124, 7187, 805, 1833, 1876, 9845, 293, 3008, 746, 6676, 1151, 493, 2501, 6920, 7850, 5496, 7830, 9155, 6694, 7525, 5094, 7114, 5883, 4176, 1725, 8739, 6527, 6914, 2417, 3878, 6129, 149, 7071, 2430, 6464, 5292, 6184, 4154, 8100, 9077, 7951, 9020, 1840, 7185, 5923, 9681, 835, 1861, 519, 1007, 7274, 947, 8013, 12, 4164, 9294, 4224, 1526, 5108, 6623, 7117, 9343, 669, 3602, 3014, 2382, 2300, 6504, 395, 7604, 6562, 2717, 2315, 196, 7216, 7689, 3768, 1825, 4255, 6413, 7045, 4568, 1533, 8361, 7458, 2580, 4324, 5885, 1232, 3874, 4423, 3698, 7089, 3291, 9598, 6525, 338, 7891, 4392, 7232, 7938, 946, 4039, 7027, 4222, 4620, 8576, 724, 2400, 5701, 5260, 6681, 5145, 4148, 1499, 2542, 4651, 9388, 9295, 2854, 2408, 4563, 354, 2394, 3027, 728, 8474, 714, 8018, 7360, 9869, 5641, 8947, 7883, 2611, 5856, 1827, 8038, 8812, 8818, 683, 9517, 5984, 2955, 1941, 5111, 1539, 5638, 9233, 112, 9240, 2097, 986, 2590, 6975, 6348, 7768, 5767, 3936, 1717, 3875, 2549, 40, 8602, 2563, 1474, 6677, 952, 9042, 5822, 455, 632, 1299, 5808, 5208, 8724, 1467, 7551, 9454, 5337, 1882, 589, 9596, 3975, 3382, 9234, 1785, 6263, 3410, 4751, 3886, 8582, 2325, 4374, 6457, 5981, 487, 1661, 5817, 1885, 8105, 3743, 5689, 7321, 6279, 6826, 4467, 6466, 2961, 9314, 619, 89, 9838, 3007, 4767, 8825, 2816, 2108, 9839, 2591, 3451, 6062, 415, 6181, 4325, 9150, 3322, 6477, 3340, 6838, 9870, 874, 392, 2396, 6288, 633, 117, 9832, 2681, 8482, 8254, 3215, 2602, 9433, 1277, 8839, 2980, 6029, 3417, 4592, 5941, 6650, 9833, 9378, 8225, 3470, 3727, 4289, 5339, 2843, 6733, 6022, 9698, 6118, 1906, 1311, 6944, 3127, 9361, 9116, 8326, 9853, 6347, 8325, 1313, 5497, 3302, 1027, 5662, 6053, 101, 639, 6765, 8262, 123, 6206, 5595, 5804, 7353, 8802, 4314, 9618, 4387, 1034, 2426, 8698, 3050, 3937, 5787, 8610, 4045, 1191, 9594, 514, 6735, 9824, 9404, 9663, 8951, 3720, 3938, 6955, 7494, 8800, 869, 7066, 5009, 4099, 4495, 8296, 939, 1551, 3285, 277, 3561, 1983, 3270, 4249, 9747, 2051, 204, 8016, 2498, 2352, 3993, 664, 2090, 4822, 2985, 6692, 9937, 4212, 3757, 6375, 2786, 1811, 2278, 863, 9380, 408, 5204, 1771, 332, 7371, 9763, 303, 2819, 3632, 4180, 7345, 7655, 8584, 5093, 6440, 5105, 4232, 5102, 2456, 692, 5813, 6406, 6533, 6613, 21, 3801, 7987, 1494, 8556, 3333, 8251, 6521, 548, 6282, 2956, 4715, 2215, 6463, 4960, 412, 4401, 8099, 1167, 355, 7623, 344, 2137, 4436, 345, 1711, 7527, 1309, 4299, 5161, 4899, 8539, 346, 7616, 1572, 220, 8075, 3421, 5874, 1562, 477, 6125, 2516, 1547, 7554, 7220, 9143, 7145, 5279, 6927, 7519, 124, 1872};
	//ssize_t	num[500] = {-6708,5362,-9110,2216,7174,6260,-7072,-6086,-9498,917,-9980,191,-8473,-3085,5819,-9090,8764,-950,6629,651,4577,9714,-5700,1889,-1826,1649,-951,4038,-6986,-6644,-9068,3098,-325,9746,-1794,-4715,8264,6671,6353,-5752,-1223,3131,3624,-2470,-4668,9297,-2755,8457,-4906,-6001,3549,-4257,2978,-4651,-2325,-2695,-6903,-8765,993,-245,8192,-8947,-7508,2268,2704,-3164,-3338,8135,-663,-5600,4931,-6368,356,8788,2233,-656,9331,-6827,-98,5544,-3272,2493,7194,690,-6858,2616,-8467,-962,3815,-7771,7630,4955,5991,3860,9041,6469,3582,-152,3483,-5105,-8908,3337,882,7260,-7313,-2266,4266,3968,-5369,6711,5123,-1282,-3127,-9665,4374,-5404,-2528,-4839,4099,-8175,4928,4357,8141,4176,-7439,-2038,2642,-7526,-5291,-3090,843,1345,-7546,-6404,7601,5320,3607,6574,8108,-3997,885,8525,5333,5889,-1600,4829,9323,-9494,3534,9560,-397,-1030,-1115,7794,-526,8612,-8439,9959,-8923,6083,-7048,738,9612,-2851,-2869,-7176,2679,5059,5184,-3101,9177,1731,-4528,-6693,-2772,-8333,4145,-2782,-9737,-4121,-491,8092,-2444,2818,453,-569,-9578,-392,2073,-2823,-2504,7343,-8714,9235,6476,9447,1844,-1469,8132,7475,-1459,1433,8460,-1936,9238,6268,-6457,9639,-2786,122,-6574,-6468,-4823,1710,9972,-1764,3729,-1727,9015,7410,8387,4891,-6938,7830,-4142,-5158,779,4189,-9058,-994,2305,-578,-9730,-3463,4355,7520,-3959,-7233,1127,1703,-4520,8786,1296,-7002,-1325,-4134,-6400,-8365,-4877,2812,-3434,-6605,-6193,-5382,-1610,1196,3671,-2916,-3476,-3281,4078,-4920,7139,-810,2773,3852,2939,5301,-2761,7015,-8227,2190,-7483,-1361,-3177,-9405,-3726,-2334,1147,-6601,2151,-1947,-749,5064,3544,8381,-254,6995,-8376,2610,1874,4027,-1831,-9345,3605,9745,-5738,6026,9271,-524,-1063,-7271,-1071,-4424,-2491,-6372,-5544,-1792,-9463,4745,-9757,712,1895,5790,8054,-2426,3985,-1915,9419,1220,-395,3997,-6801,4204,6865,2273,2473,-5373,9881,3079,4606,-3585,-9838,-3796,-5886,3159,-3995,-786,-8392,2579,-6062,-4922,1459,8125,907,-2008,8150,-3255,3286,-6326,7609,-7568,1681,-5260,-4084,-6987,8634,5863,6158,-8837,-798,-1551,-6609,-5829,-1946,5747,-3623,1307,9775,3820,-4933,6983,-5854,3962,3945,-6730,2125,-5734,525,-2899,593,-9341,-3859,-5671,-7980,8207,-6814,6190,-7580,5988,-8247,-3214,4822,-8388,-7228,6459,-4356,-545,-7285,6691,3181,-5307,8900,-4566,6944,-5938,-8349,1290,-8012,9397,-7814,4449,-9639,-7890,-8881,5935,9740,-1661,-572,3443,9567,-5121,5976,-243,9398,-8464,-9169,7506,-4592,2976,7303,6871,680,1747,9474,-9074,9344,8905,9984,6060,-6852,8416,669,8821,-3116,9969,3539,3252,-1103,9295,-1471,-6125,-4086,-8574,-8867,1685,5377,4889,-2306,-9618,-1596,4697,7760,-3771,-9585,-1098,8713,6641,2943,8472,5593,1493,1205,-1578,-4767,-7657,-3007,-4156,9073,135,-9816,-9777,378,1180,-2904,-6138,4200,-6048,-5485,-6542,-6065,7746,-9097,-9822,4786,-845,8328,5085,6233,7063};
	//ssize_t	num[15] = {-567, 891, -185, 308, -721, 442, -834, 632, 147, -512, 775, -232, 419, -695, 197};
	//ssize_t	num[100] = {930, 6650, 4266, 1566, 3174, 8051, 6016, 3416, 8448, 3037, 3233, 8329, 2864, 6413, 1305, 1182, 4273, 4056, 6802, 7352, 4363, 6988, 168, 2746, 2440, 6772, 2429, 1700, 3072, 9477, 2752, 6897, 4042, 9382, 7610, 5650, 6757, 3179, 3840, 6991, 9650, 1358, 8386, 9196, 8498, 9733, 6341, 7464, 2992, 7592, 5663, 1718, 6776, 7104, 4848, 4538, 3677, 7609, 2466, 3109, 1936, 3041, 1452, 8893, 6520, 9141, 1744, 5441, 9409, 4414, 6821, 5289, 2256, 3904, 8266, 7359, 9532, 4800, 4811, 1386, 2584, 5317, 9660, 8675, 1532, 851, 3364, 4002, 7108, 123, 4936, 2553, 3907, 3385, 5783, 4671, 9881, 5599, 4191, 8356};
	//ssize_t	num[100] = {7438, -5590, 731, -1420, -7419, -7875, -6719, -1152, 3662, 7256, 5349, 9733, 8144, -1665, -9574, 7100, 3504, 8123, -7220, 2759, 5214, 9340, 1592, 4192, -3523, -8318, 4945, 748, 8391, -3139, -598, 9356, 8077, 2543, -1815, 2443, -578, 7661, -4058, -362, -986, 9035, -1698, -324, -3858, -8745, -8238, -9272, -4264, 168, -3848, 124, 1652, -806, 2251, -6288, -5623, 7857, 3135, -9645, 4754, -7469, -6920, -7882, 2944, -9030, -7530, -4387, -5890, 2985, 1146, -5571, -1248, -7958, -7040, -3048, -4838, 8233, 5067, -5423, 5488, 1560, -290, 356, 6580, -8297, -9812, -1904, -8649, -1062, -8966, 7607, 6622, -9012, 1246, 7205, 9124, 9517, 1273, 7120};
	//ssize_t	num[100] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	ssize_t	num[5] = {1, 5, 2, 4, 3};
	//ssize_t	num[3] = {0, 1, 2};
	//ssize_t	num[10] = {-9819,5528,5040,-4168,-8362,-9664,4654,2353,-6604,-7641};
	int		size = 5;
	int		i;
	char	*moves;

	data = malloc(sizeof(t_data));
	data->value = num[0];
	data->index = 0;
	data->dist = 0;
	data->obm = NULL;
	lst = ft_lstnew(data);
	i = 1;
	while (i < size)
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
	ft_set_swap(&lst);
	not_push = ft_lis(&lst);
	moves = ft_calculate(&lst, not_push);
	printf("%s", moves);
	free(moves);
	ft_lstclear(&not_push, free);
	ft_lstclear(&lst, free);
	/*int		fd;
	FILE	*file;
	file = fopen("moves.txt", "w");
	fd = fileno(file);
	write(fd, moves, ft_strlen(moves));
	fclose(file);
	t_list *animate;
	data = malloc(sizeof(t_data));
	data->value = num[0];
	data->index = 0;
	animate = ft_lstnew(data);
	i = 1;
	while (i < size)
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
	ft_animation(not_push, animate, stack_b, moves); */
	return (0);
}
