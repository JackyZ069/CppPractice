#include<iostream>


class Random
{
public:
	Random(const Random&) = delete;

	static Random& Get()
	{
		return s_Instance;
	}

	static float Float() { return Get().IFloat(); }
private:
	float IFloat() { return m_RandomGenerator; }

	Random() {}

	float m_RandomGenerator = 0.5f;

	static Random s_Instance;
};

Random Random::s_Instance;


int main()
{
}

