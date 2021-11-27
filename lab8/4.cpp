#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

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

struct Member
{
    int id;
    int scans;
    double max_na;
    double min_na;
};

bool operator<(const Member &ml, const Member &mr)
{
    return ml.id < mr.id;
}
bool comp(const Member &ml, const Member &mr)
{
    return (ml.max_na - ml.min_na) < (mr.max_na - mr.min_na);
}

int main()
{
    set<Member> members;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int dummy_i, id;
        double dummy, na;
        cin >> dummy_i >> id >> dummy >> dummy >> dummy >> na >> dummy;

        auto it = members.begin();
        while (it != members.end())
        {
            if (it->id == id)
            {
                Member m;
                m.id = id;
                m.max_na = max(it->max_na, na);
                m.min_na = min(it->min_na, na);
                m.scans = it->scans + 1;
                members.erase(*it);
                members.emplace(m);
                break;
            }
            it++;
        }
        if (it == members.end())
        {
            Member m;
            m.id = id;
            m.scans = 1;
            m.max_na = na;
            m.min_na = na;
            members.emplace(m);
        }
    }

    vector<Member> ms_vec(members.size());
    copy(members.begin(), members.end(), ms_vec.begin());
    sort(ms_vec.begin(), ms_vec.end(), comp);

    int k = 0;
    for (auto m : ms_vec)
    {
        if (m.scans > 1)
        {
            cout << m.id;
            if (k < 2)
            {
                cout << ' ';
            }
            k++;
            if (k == 3)
            {
                break;
            }
        }
    }
    if (k == 0)
    {
        cout << -1;
    }

    return 0;
}
