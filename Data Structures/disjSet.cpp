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
                rank[a_id]=rank[a_id]+1;
            }
        }
        return true;    
    }
};

