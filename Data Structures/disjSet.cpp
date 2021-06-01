#include<bits/stdc++.h>
using namespace std;
#define debug false

template <typename T>
class disJSet
{
    map<T,T> parent;
    map<T,int> rank;
    public:
    //Linear time complexity 
    void makeSet(vector<T> it)
    {
        for(T i:it)
        {
            parent[i]=i;
            rank[i]=0;
        }

        if(debug)
        {
            for(pair<int,int> p:{pair<int,int>(2,4)})
            {
                cout<<"parent for ";
                cout<<"("<<p.first<<","<<p.second<<") is ";
                cout<<"("<<parent[p].first<<","<<parent[p].second<<")"<<endl;
                cout<<"p!=parent[p] "<<(p!=parent[p])<<" p==parent[p] "<<(p==parent[p])<<endl;
                //cout<<"find(p) "<<find(p).first<<<<endl;
            }
        }
    }

    //Time complexity of O(log*n)
    T find(T el)
    {
        if(el!=parent[el])
            parent[el]=find(parent[el]);
        
        return parent[el];
    }

    //Time complexity of O(log*n)
    bool unionOp(T a,T b)
    {
        T a_id=find(a);
        T b_id=find(b);

        if(a_id==b_id)
            return false;

        if(rank[a_id]<rank[b_id])
            parent[a_id]=b_id;
        else
        {
            parent[b_id]=a_id;
            if(rank[a_id]==rank[b_id])
            {
                rank[b_id]=rank[b_id]+1;
            }
        }    
    }
};

int main()
{
    char ch;
    disJSet<pair<int,int>> ds;
    vector<pair<int,int>> v;

    cout<<"Enter 10 pairs"<<endl;
    for(int i=0;i<10;++i)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(pair<int,int>(x,y));
    }
    ds.makeSet(v);

    do
    {
        for(pair<int,int> i:v)
        {
            pair<int,int> p=ds.find(i);
            cout<<"parent of ("<<i.first<<","<<i.second<<") = ("<<p.first<<","<<p.second<<")"<<endl;
        }

        int a,b,c,d;
        cout<<"Type two elements for union"<<endl;
        cin>>a>>b>>c>>d;

        cout<<"Union is "<<ds.unionOp(pair<int,int>(a,b),pair<int,int>(c,d))<<endl;

        cout<<"Do you want to continue "<<endl;
        cin>>ch;

    } while (ch=='y');
    
}

