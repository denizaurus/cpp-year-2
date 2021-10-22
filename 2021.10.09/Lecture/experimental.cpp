//
//// OPERATORS
//
//friend std::ostream & operator<< (std::ostream &, const Storage &);
//friend std::istream & operator>> (std::istream &, Storage &);
//
//int   operator[] (size_t) const;
//int & operator[] (size_t);
//
//Storage & operator= (const Storage &);
//Storage & operator= (Storage &&);
//
//Storage & operator+= (const Storage &);
//
//friend Storage operator+  (const Storage &, const Storage &);
//friend bool operator== (const Storage &, const Storage &);
//friend bool operator!= (const Storage &, const Storage &);
//friend bool operator>  (const Storage &, const Storage &);
//friend bool operator<  (const Storage &, const Storage &);
//friend bool operator>= (const Storage &, const Storage &);
//friend bool operator<= (const Storage &, const Storage &);

//std::ostream & operator<< (std::ostream & stream, const Storage & s)
//{
//	stream << "Array: ";
//
//	for (auto i = 0U; i < s.m_length; ++i)
//	{
//		stream << s.m_arr[i] << " ";
//	}
//
//	stream << "\nVector: ";
//
//	for (int element : s.m_v)
//	{
//		stream << element << " ";
//	}
//
//	return stream;
//}
//
//std::istream & operator>> (std::istream & stream, const Storage & s)
//{
//	// skip, return later
//}
//
//int Storage::operator[] (size_t index) const
//{
//	return m_v[index];
//}
//
//int & Storage::operator[] (size_t index)
//{
//	return m_v[index];
//}
//
//Storage & Storage::operator= (const Storage & other)
//{
//	if (this == &other) { return *this; };
//
//	m_length = other.m_length;
//	m_v = other.m_v;
//
//	if (m_arr) { delete[] m_arr; };
//
//	m_arr = new int[m_length];
//
//	for (auto i = 0U; i < m_length; ++i)
//	{
//		m_arr[i] = other.m_arr[i];
//	}
//
//	return *this;
//}
//
//Storage & Storage::operator= (Storage && other)
//{
//
//	m_arr = other.m_arr;
//	m_length = other.m_length;
//	m_v = std::move(other.m_v);
//
//	other.m_arr = nullptr;
//	other.m_length = 0;
//	other.m_v = {};
//
//	return *this;
//
//}
//
//Storage & Storage::operator+= (const Storage & other)
//{
//	for (int i : other.m_v)
//	{
//		m_v.push_back(i);
//	}
//
//	int * temp = new int[m_length + other.m_length];
//
//	for (auto i = 0U; i < m_length; ++i) // copying from this array
//	{
//		temp[i] = m_arr[i];
//	}
//
//	for (auto i = 0U; i < other.m_length; ++i) // copying from other array
//	{
//		temp[m_length + i] = m_arr[i];
//	}
//
//	m_arr = temp;
//	m_length += other.m_length;
//	temp = nullptr;
//
//	return *this;
//}
//
//Storage operator+  (const Storage & lhs, const Storage & rhs)
//{
//	return Storage(lhs) += rhs;
//}
//
//bool operator== (const Storage & lhs, const Storage & rhs)
//{
//	if (lhs.m_length != rhs.m_length) { return false; }
//	if (lhs.m_v != rhs.m_v) { return false; }
//
//	for (auto i = 0U; i < lhs.m_length; ++i)
//	{
//		if (lhs.m_arr[i] != rhs.m_arr[i]) { return false; }
//	}
//
//	return true;
//}



//void Storage::swap(Storage & other)
//{
//	std::swap(m_arr, other.m_arr);
//	std::swap(m_length, other.m_length);
//	std::swap(m_v, other.m_v);
//}
//
//void Storage::find(int x)
//{
//	size_t pos;
//
//	auto it_1 = std::find(m_arr, m_arr + m_length, x);
//
//	if (it_1 != m_arr + m_length)
//	{
//		pos = std::distance(m_arr, it_1);
//		std::cout << x << " found in array at position " << pos << std::endl;
//	}
//
//	auto it_2 = std::find(std::begin(m_v), std::end(m_v), x);
//
//	if (it_2 != std::end(m_v))
//	{
//		pos = std::distance(std::begin(m_v), it_2);
//		std::cout << x << " found in vector at position " << pos << std::endl;
//	}
//
//	std::cout << x << " not found" << std::endl;
//}


//// MEMBER FUNCTIONS
//
//void swap(Storage &);
//void find(int);



// PARSER


//std::vector < int > parse(std::string s)
//{
//	std::vector out = { 0, 1 }; // num, den
//	int temp_i;
//
//	auto pos = s.find('/');
//	if (pos == std::string::npos)
//	{
//		std::cout << "Invalid input.";
//		return {};
//	}
//
//	temp_i = std::stoi(s.substr(0, pos));
//	out[0] = temp_i;
//
//	temp_i = std::stoi(s.substr(pos + 1));
//
//	if (temp_i == 0)
//	{
//		std::cout << "Invalid input.";
//		return {};
//	}
//
//	out[0] *= sign(temp_i);
//	out[1] = temp_i * sign(temp_i);
//
//	return out;
//}