#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个结构体来存储花朵的信息
struct Flower
{
	int index;         // 花朵的位置
	int value;         // 花朵的美丽值
	long long product; // 花朵位置与美丽值的乘积

	// 重载小于运算符，用于排序
	bool operator<(const Flower &other) const
	{
		return product < other.product;
	}
};

// 计算逆序对的函数（使用归并排序的思想）
int mergeAndCount(vector<Flower> &flowers, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// 创建临时数组
	vector<Flower> L(n1), R(n2);
	for (int i = 0; i < n1; ++i)
		L[i] = flowers[left + i];
	for (int i = 0; i < n2; ++i)
		R[i] = flowers[mid + 1 + i];

	int i = 0, j = 0, k = left, inv_count = 0;

	// 归并过程
	while (i < n1 && j < n2)
	{
		if (L[i].value <= R[j].value)
		{
			flowers[k++] = L[i++];
		}
		else
		{
			flowers[k++] = R[j++];
			// 由于L[i].value > R[j].value，且L[i]在R[j]的左侧，所以形成逆序对
			inv_count += (mid - left + 1) - i;
		}
	}

	// 复制L[]的剩余元素（如果有）
	while (i < n1)
		flowers[k++] = L[i++];

	// 复制R[]的剩余元素（如果有）
	while (j < n2)
		flowers[k++] = R[j++];

	return inv_count;
}

// 归并排序并计算逆序对的函数
int mergeSortAndCount(vector<Flower> &flowers, int left, int right)
{
	int inv_count = 0;
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		inv_count += mergeSortAndCount(flowers, left, mid);
		inv_count += mergeSortAndCount(flowers, mid + 1, right);

		inv_count += mergeAndCount(flowers, left, mid, right);
	}
	return inv_count;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("flower3.in","r",stdin);
//	freopen("flower.out","w",stdout);
#endif	
	int n;
	cin >> n;
	vector<Flower> flowers(n);

	for (int i = 0; i < n; ++i)
	{
		flowers[i].index = i + 1;
		cin >> flowers[i].value;
		flowers[i].product = (long long)flowers[i].index * flowers[i].value;
	}

	// 对花朵进行排序
	sort(flowers.begin(), flowers.end());

	// 计算逆序对数量（即最小交换次数）
	int minSwaps = mergeSortAndCount(flowers, 0, n - 1);

	// 输出结果
	cout << 2*minSwaps << endl;

	return 0;
}