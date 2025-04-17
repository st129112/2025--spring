#include<iostream>

class ArrayList
{
private:
	int len;
	int* data;
	void init(int len = 10)
	{
		//(*this).len = len;
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
		if (this->data != nullptr)
		{
			for (int i = 0; i < this->len; ++i)
			{
				set(i, 0);
			}
		}
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}
	void expand(int number = 1)
	{
		int newlen = this->len + number;
		int* newdata = (int*)malloc(sizeof(int) * newlen);
		if (newdata != nullptr)
		{
			for (int i = 0; i < this->len;++i)
			{
				newdata[i] = get(i);
			}
		}
		if (this->data != nullptr)
		{
			free(this->data);
			this->data = newdata;
		}
		this->len = newlen;
	}
	void swap(int i1, int i2)
	{
		int c = get(i1);
		set(i1, get(i2));
		set(i2, c);
	}



public:
	ArrayList(int len = 10)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}
	ArrayList(ArrayList& list)
	{
		//this->len = list.len;
		//this->data = list.data;
		this->init(this->len);
		for (int i = 0; i < this->len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		if (this->data != nullptr)
		{
			for (int i = 0; i < this->len; ++i)
			{
				this->data[i] = 0;
			}
			free(this->data);
			this->data = nullptr;
			this->len = 0;
		}
	}
	void randomize(int min = 10, int max = 99)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return len;
	}

	void pushBack(int element)
	{
		expand();
		set(this->len - 1, element);
	}
	void pushFront(int element)
	{
		pushBack(element);
		shift(1);
	}
	void insert(int index, int element)
	{
		expand();
		for (int i = len - 1; i > index; --i)
		{
			set(i, get(i - 1));
		}
		set(index, element);
	}
	int popBack()
	{
		int res = get(this->len - 1);
		int reduced = 1;

		if (reduced > len)
		{
			return;
		}
		int newlen = this->len - reduced;
		int* newdata = (int*)malloc(sizeof(int) * newlen);
		if (newdata != nullptr)
		{
			for (int i = 0; i < newlen; ++i)
			{
				newdata[i] = this->data[i];
			}
		}
		if (this->data != nullptr)
		{
			free(this->data);
			this->data = newdata;
			this->len = newlen;
		}
		return res;
	}
	int popFront()
	{
		shift(-1);
		return popBack();
	}
	int extract(int index)
	{
		int res = get(index);
		for (int i = index; i < this->len - 1; ++i)
		{
			set(i, get(i + 1));
		}
		int reduced = 1;
		if (reduced > len)
		{
			return;
		}
		int newlen = this->len - reduced;
		int* newdata = (int*)malloc(sizeof(int) * newlen);
		if (newdata != nullptr)
		{
			for (int i = 0; i < newlen; ++i)
			{
				newdata[i] = this->data[i];
			}
		}
		if (this->data != nullptr)
		{
			free(this->data);
			this->data = newdata;
			this->len = newlen;
		}
		return res;
	}
	void reverse(int start, int end)
	{
		if (!indexValid(start) || !indexValid(end))
		{
			return;
		}
		int rnglen = end - start + 1;
		for (int i = 0; i < rnglen / 2; ++i)
		{
			swap(start + i, end - i);
		}
	}
	int sum()
	{
		int res = 0;
		for (int i = 0; i < this->len; ++i)
		{
			res += get(i);
		}
		return res;
	}
	int secondMax()
	{
		int mx1 = get(0);
		int mx2 = get(0);
		for (int i = 0; i < this->len; ++i)
		{
			if (mx1 <= get(i))
			{
				mx2 = mx1;
				mx1 = get(i);
			}
			else if (mx2 <= get(i))
			{
				mx2 = get(i);
			}
		}
		return mx2;
	}
	int lastMinIndex()
	{
		int mnInd = 0;
		for (int i = 0; i < len; ++i)
		{
			if (get(i) <= get(mnInd))
			{
				mnInd = i;
			}
		}
		return mnInd;
	}
	int shift(int k)
	{
		reverse(0, len - k - 1);
		reverse(len - k, len - 1);
		reverse(0, len - 1);
	}
	int countOdd()
	{
		int count = 0;
		for (int i = 0; i < len; ++i)
		{
			if (get(i) % 2 == 1)
			{
				++count;
			}
		}
		return count;
	}
	int sumEven()
	{
		int sum = 0;
		for (int i = 0; i < count(); ++i)
		{
			if (get(i) % 2 == 0)
			{
				sum += get(i);
			}
		}
		return sum;
	}
};

int max(ArrayList list)
{
	int mx = list.get(0);
	for (int i = 0; i < list.count(); ++i)
	{
		mx = (mx > list.get(i) ? mx : list.get(i));
	}
	return mx;
}

int main(int argc, char* argv[])
{
	return 0;
}