#include <bits/stdc++.h>
using namespace std;

#pragma region Template

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define pi pair<int, int>
#define vpi vector<pi>
#define vpll vector<pll>
#define fo(i, stIdx, enIdx) for (ll i = stIdx; i < enIdx; i++)
#define foN(i, stIdx, enIdx) for (ll i = stIdx; i > enIdx; i--)
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T, greater<T>>;

#pragma endregion

#pragma region FUNCTIONS DECLARATION

template <typename T>
void PrintVector(vector<T> x);
template <typename T>
void InputVector(vector<T> &x, ll len);
template <typename T>
void InputVectorWithPreSum(vector<T> &x, vector<T> &pre, ll len);
bool IsPrime(ll x);

#pragma endregion

struct MapLocation
{
    int x, y;

    MapLocation(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

vector<MapLocation> directions = {
    MapLocation(1, 0),
    MapLocation(-1, 0),
    MapLocation(0, 1),
    MapLocation(0, -1)};

int lenX, lenY;
vi d[50];

int countAllSquareNeighbours(int x, int y)
{
    if (x < 1 || y < 1 || x >= lenX - 1 || y >= lenY - 1)
        return 5;

    int count = 0;
    if (d[y + 1][x] == 0)
        count++;
    if (d[y - 1][x] == 0)
        count++;
    if (d[y][x - 1] == 0)
        count++;
    if (d[y][x + 1] == 0)
        count++;

    return count;
}

vi GetRandomIndex(int Length)
{
    vi d;

    while (d.size() != Length)
    {
        int rd = rand() % 4;
        if (find(d.begin(), d.end(), rd) == d.end())
        {
            d.push_back(rd);
        }
    }

    return d;
}

void Generate(int x, int y)
{
    if (countAllSquareNeighbours(x, y) >= 2)
        return;

    d[y][x] = 0;
    vi idxs = GetRandomIndex(4);

    fo(i, 0, 4)
    {
        Generate(x + directions[idxs[i]].x, y + directions[idxs[i]].y);
    }
}

void Generate()
{
    int x = rand() % lenX + 1;
    int y = rand() % lenY + 1;
    // debug2(x, y);
    Generate(x, y);
}

void DrawMaze()
{
    fo(i, 0, lenY)
    {
        fo(j, 0, lenX)
        {
            if (d[i][j] == 1)
                cout << "🟥";
            else
                cout << "🟩";
        }
        cout << endl;
    }
}

void Solve()
{
    cin >> lenX >> lenY;

    fo(i, 0, lenY)
    {
        fo(j, 0, lenX)
        {
            d[i].push_back(1);
        }
    }

    Generate();
    DrawMaze();
}

int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(0));
    Solve();

    return 0;
}

#pragma region FUNCTION DEFINITION

template <typename T>
void PrintVector(vector<T> x)
{
    ll len = x.size();
    debug(len);
    fo(i, 0, len)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

template <typename T>
void InputVector(vector<T> &x, ll len)
{
    x.clear();
    fo(i, 0, len)
    {
        T val;
        cin >> val;
        x.push_back(val);
    }
}

template <typename T>
void InputVectorWithPreSum(vector<T> &x, vector<T> &pre, ll len)
{
    x.clear(), pre.clear();
    fo(i, 1, len + 1)
    {
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
    }
}

bool IsPrime(ll x)
{
    if (x == 0)
        return false;
    if (x >= 1 && x <= 3)
        return true;

    bool isPrime = true;
    for (int i = 2; i < (int)(sqrt(x) + 1); i++)
    {
        if (x % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

#pragma endregion