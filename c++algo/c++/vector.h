//vector.h
#pragma once
namespace ehlib
{

    template<typename Data>
    class vector
    {        
        Data *base;
        size_t bcapacity;
        size_t bsize;

    public:
        class iterator
        {    
            Data *pos;

        public:
            iterator(Data *pos=0)
            {
                this->pos = pos;
            }

            Data operator *()const
            {
                 return *pos;
            }

            int operator-(const iterator &iter)const
            {
                return pos - iter.pos;                
            }

            iterator &operator++()
            {                   
                pos++;
                return (*this);
            }


            const iterator operator++(int)
            {
                iterator re(*this);                
                pos++;
                return re;
            }

            bool operator !=(const iterator &iter)const
            {
                return pos != iter.pos;
            }
            bool operator ==(const iterator &iter)const
            {
                return pos == iter.pos;
            }
        };
        typedef iterator const_iterator;

        vector()
        {
            base = 0;
            bcapacity = bsize = 0;
        }

        ~vector()
        {
            if(base)
            {
                delete[] base;
            }
        }

        void resize(size_t nsize,Data data=0)
        {
            if(nsize>bcapacity)
            {
                reserve(nsize);
            }
            while(bsize<nsize)
            {
                push_back(data);
            }
        }

        void reserve(size_t ncapacity)
        {
            Data *temp = new Data[ncapacity]; //새로운 저장소를 할당
            bcapacity = ncapacity; //새로운 저장소 용량 대입
            if(bsize) //보관한 자료가 있다면
            {
                for(size_t n=0; n<bsize; n++)
                {
                    temp[n] = base[n]; //기존 저장소에 보관한 자료를 새로운 저장소로 복사
                }
                delete[] base; //기존 저장소를 소멸
            }
            base=temp; //base에 새로운 저장소를 대입
        }

        void push_back(Data data)
        {
            insert(end(),data);
        }
        void insert(iterator at, Data data)
        {
            size_t index = at-base;
            if(bsize == bcapacity)
            {
                reserve(bcapacity+10);
            }
            for(size_t pos=bsize; pos>index; pos--)
            {
                base[pos] = base[pos-1];
            }
            base[index] = data;
            bsize++;
        }        
      
        void erase(iterator at)
        {
            bsize--;
            for(size_t index = at-base; index<bsize; index++)
            {
                base[index] =base[index+1];
            }
        }
        Data &operator[] (size_t index)
        {
            if((index>=0)&&(index<bsize))
            {
                return base[index];
            }
            throw "잘못된 인덱스를 사용하였습니다.";
        }

        Data &operator[] (size_t index)const
        {
            if((index>=0)&&(index<bsize))
            {
                return base[index];
            }
            throw "잘못된 인덱스를 사용하였습니다.";
        }

        iterator begin()
        {
            iterator iter(base);
            return iter;
        }

        iterator end()
        {            
            iterator iter(base+bsize);
            return iter;
        }

        const_iterator begin()const
        {
            iterator iter(base);
            return iter;
        }

        const_iterator end()const
        {            
            iterator iter(base+bsize);
            return iter;
        }


        size_t size()
        {
            return bsize;
        }

        size_t capacity()
        {
            return bcapacity;
        }
    };
}
