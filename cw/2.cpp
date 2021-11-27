#include <iostream>
#include <map>
#include <set>

class inputStringCalls{
	private:
		std::string in, sub;
		int time = 0;
	public:
		friend std::fstream& operator>>(std::fstream &file, inputStringCalls &input);
		
		std::string getin(){
			return this->in;
		}
		
		std::string getsub(){
			return this->sub;
		}
		
		int gettime(){
			return this->time;
		}
};

using namespace std;

struct Entry
{
    unsigned long date;
    int number;
};

bool operator<(const Entry &le, const Entry &re)
{
    return le.date < re.date;
}
bool operator==(const Entry &le, const Entry &re)
{
    return le.date == re.date;
}

int main()
{
    // map<unsigned long, int> data;
    set<Entry> data;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int d, m, y, n;
        char dot;
        cin >> d >> dot >> m >> dot >> y >> n;
        unsigned long date = y * 10000 + m * 100 + d;
        Entry e;
        e.date = date;
        e.number = n;

        auto it = data.begin();
        while (it != data.end())
        {
            if (*it == e)
            {
                if (e.number > it->number)
                {
                    data.erase(*it);
                    data.emplace(e);
                }
                break;
            }
            it++;
        }
        if (it == data.end())
        {
            data.emplace(e);
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int d, m, y;
        char dot;
        cin >> d >> dot >> m >> dot >> y;
        unsigned long date = 10000 * y + 100 * m + d;
        int max_p = 0;
        for (auto e : data)
        {
            if (e.date > date)
            {
                break;
            }
            else
            {
                if (e.number > max_p)
                {
                    max_p = e.number;
                }
            }
        }

        cout << max_p << endl;
    }

    return 0;
}
