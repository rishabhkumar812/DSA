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

