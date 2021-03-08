#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

template <typename tpl>

class MyVector
{
private:
	tpl* Data;
	size_t Len;
public:
	MyVector(size_t Kolvo = 0)
	{
		Len = Kolvo;
		Data = new tpl[Len];
	}
	MyVector(const MyVector& CopyMyVec)
	{
		Len = CopyMyVec.Len;
		Data = new tpl[Len];
		for (size_t i = 0; i < Len; ++i) Data[i] = CopyMyVec.Data[i];
	}
	~MyVector()
	{
		delete[] Data;
		Len = 0;
	}
	tpl at(int NumElm)
	{
		if (NumElm < 0) for (; NumElm < 0; NumElm = Len + NumElm);
		else if (NumElm >= Len) for (; NumElm >= Len; NumElm = NumElm - Len);
		return Data[NumElm];
	}
	size_t size()
	{
		return Len;
	}
	int resize(int n, tpl Value = 0)
	{
		if (n < Len)
		{
			tpl* TmpArr = new tpl[n];
			for (size_t i = 0; i < n; ++i) TmpArr[i] = Data[i];
			delete[] Data;
			Data = TmpArr;
			Len = n;
			return 0;
		}
		else if (n > Len)
		{
			tpl* TmpArr = new tpl[n];
			for (size_t i = 0; i < n; ++i)
			{
				if (i < Len) TmpArr[i] = Data[i];
				else TmpArr[i] = Value;
			}
			delete[] Data;
			Data = TmpArr;
			Len = n;
			return 0;
		}
		else if (n == Len) return 3;
	}
	bool empty()
	{
		if (Len == 0) return true;
		else return false;
	}
	int push_back(tpl Elm)
	{
		if (Len == 0)
		{
			Data = new tpl[1];
			++Len;
			Data[Len - 1] = Elm;
			return 0;
		}
		else
		{
			tpl* TmpArr = new tpl[Len + 1];
			for (size_t i = 0; i < Len; ++i) TmpArr[i] = Data[i];
			TmpArr[Len++] = Elm;
			delete[] Data;
			Data = TmpArr;
			return 0;
		}
	}
	int pop_back()
	{
		if (Len == 0) return 1;
		tpl* TmpArr = new tpl[--Len];
		for (size_t i = 0; i < Len; ++i) TmpArr[i] = Data[i];
		delete[] Data;
		Data = TmpArr;
		return 0;
	}
	int insert(size_t it, size_t n, tpl Value)
	{
		if (it >= Len) return 1;
		tpl* TmpArr = new tpl[Len + n];
		bool IsIt = false;
		for (size_t i = 0; i < Len; ++i)
		{
			if (i == it)
			{
				for (size_t j = i; j < i + n; ++j) TmpArr[j] = Value;
				IsIt = true;
			}
			if (IsIt) TmpArr[i + n] = Data[i];
			else TmpArr[i] = Data[i];
		}
		delete[] Data;
		Data = TmpArr;
		Len = Len + n;
		return 0;
	}
	int insert(size_t n, tpl Value)
	{
		tpl* TmpArr = new tpl[Len + n];
		for (size_t i = 0; i < n; ++i) TmpArr[i] = Value;
		for (size_t i = 0; i < Len; ++i) TmpArr[i + n] = Data[i];
		delete[] Data;
		Data = TmpArr;
		Len = Len + n;
		return 0;
	}
	tpl front()
	{
		return Data[0];
	}
	tpl back()
	{
		return Data[Len - 1];
	}
	int erase(int n)
	{
		tpl* TmpArr = new tpl[Len - 1];
		bool IsN = false;
		if (n < 0) for (; n < 0; n = Len + n);
		else if (n >= Len) for (; n >= Len; n = n - Len);
		for (size_t i = 0; i < Len; ++i)
		{
			if (IsN) TmpArr[i - 1] = Data[i];
			else if (i == n) IsN = true;
			else TmpArr[i] = Data[i];
		}
		delete[] Data;
		Data = TmpArr;
		--Len;
		return 0;
	}
	int clear()
	{
		delete[] Data;
		Len = 0;
		return 0;
	}
	int swap(int NumElm1, int NumElm2)
	{
		tpl tmp;
		if (NumElm1 < 0) for (; NumElm1 < 0; NumElm1 = Len + NumElm1);
		else if (NumElm1 >= Len) for (; NumElm1 >= Len; NumElm1 = NumElm1 - Len);
		if (NumElm2 < 0) for (; NumElm2 < 0; NumElm2 = Len + NumElm2);
		else if (NumElm2 >= Len) for (; NumElm2 >= Len; NumElm2 = NumElm2 - Len);
		tmp = Data[NumElm1];
		Data[NumElm1] = Data[NumElm2];
		Data[NumElm2] = tmp;
		return 0;
	}
};

int vec_out(MyVector<int> Vec);
int vec_sort(MyVector<int>& Vec, int Left, int Right);

int main()
{
	MyVector<int> Vec;
	int LenVec = 0;
	std::cin >> LenVec;
	for (size_t i = 0; i < LenVec; ++i)
	{
		int tmp = 0;
		std::cin >> tmp;
		Vec.push_back(tmp);
	}

	std::cout << Vec.size() << "\nEnter number of element for output: ";
	std::cin >> LenVec;
	std::cout << "Output: " << Vec.at(LenVec) << "\n";
	std::cout << "Is empty: " << Vec.empty() << "\n";
	std::cout << "Front: " << Vec.front() << " Back: " << Vec.back();
	Vec.pop_back();
	vec_out(Vec);
	Vec.erase(2);
	vec_out(Vec);
	Vec.insert(2, 21);
	vec_out(Vec);
	Vec.insert(3, 3, 42);
	vec_out(Vec);
	Vec.resize(4);
	vec_out(Vec);
	Vec.resize(8);
	vec_out(Vec);
	Vec.swap(0, Vec.size() - 1);
	vec_out(Vec);
	vec_sort(Vec, 0, Vec.size() - 1);
	vec_out(Vec);
	Vec.clear();
	vec_out(Vec);
	Vec.push_back(1);
	vec_out(Vec);
	getchar();
	getchar();
	return 0;
}

int vec_out(MyVector<int> Vec)
{
	size_t LenVec = Vec.size();
	std::cout << "\n";
	for (size_t i = 0; i < LenVec; ++i) std::cout << Vec.at(i) << " ";
	std::cout << "\n";
	return 0;
}

int vec_sort(MyVector<int>& Vec, int Left, int Right)
{
	int i = Left;
	int j = Right;
	int Opora = Vec.at((Left + Right) / 2);
	while (i <= j)
	{
		while (Vec.at(i) < Opora) ++i;
		while (Vec.at(j) > Opora) --j;
		if (i <= j)
		{
			Vec.swap(i, j);
			++i;
			--j;
		}
	}
	if (Left < j) vec_sort(Vec, Left, j);
	if (i < Right) vec_sort(Vec, i, Right);
	return 0;
}