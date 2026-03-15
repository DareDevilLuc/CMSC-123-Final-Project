#include "../include/array.h"
#include "../include/deque.h"
#include "../include/list.h"
#include <algorithm>

template <typename T>
class ArrayDeque : public Deque<T>, public List<T>{
    private:
        array<T> arr;
        int j = 0;
        int sizeN = 0;

        void resize(){
            array<T> b(std::max(1, 2*size));
            for(int k = 0; k < size; k++){
                b[k] = arr[(j+k) % arr.length];
            }
            arr = b;
            j = 0;
        }


        T get(const size_t i) const override{
            return arr[(j+i) % arr.length];
        }

        T set(const size_t i, const T& x) override{
            T y = arr[(j + i) % arr.length];
            arr[(j + i) % arr.length] = x;
            return y;
        }

        void addAll(int i, List<T> &d){
            int numsOfElements = d.size();
            if(numsOfElements == 0) return;

            if(i < size/2){
                j = (j - numsOfElements + arr.length) % arr.length;
                for(int k = 0; k < i; k++){
                    arr[(j+k) % arr.length] = arr[(j + k + numsOfElements) % arr.length];
                }
            }
            else{
                for (int k = numsOfElements - 1; k > i; k--){
                    arr[(j+k) % arr.length] = arr[(j + k) % arr.length];
                }
            }
            
            for(int k = 0; k < numsOfElements; k++){
                arr[(j + i + k) % arr.length] = d[h];
            }
        }

        void add(const size_t i, const T& x) override{
            if(size + 1 > arr.length) resize();
            if(i < size/2){
                j = (j == 0) ? arr.length - 1 : j - 1;
                for(int k = 0; k < i; k++){
                    arr[(j + k) % arr.length] = arr[(j + k + 1) % arr.length];
                }
            }
            else{
                for(int k = size; k > i; k--){
                    arr[(j + k ) % arr.length] = arr[(j + k - 1) % arr.length];
                }
            }
            arr[(j+i)%arr.length] = x;
            size++;
        }

        T remove(const size_t i) override{
            T x = arr[(j + i) % arr.length];
            if(i < size/2){
                for(int k = i; k > 0; k--){
                    arr[(j + k) % arr.length] = arr[(j + k - 1) % arr.length];
                }
                j = (j + 1) % arr.length;
            }
            else{
                for(int k = i; k < size - 1; k++){
                    arr[(j + k) % arr.length] = arr[(j + k + 1) % arr.length];
                }
            }
            size--;
            if(3 * size < arr.length) resize();
            return x;
        }

    public:
        ArrayDeque() : arr(10) {}
        
        void addFirst(const T& x) override{
            add(0, x);
        }

        void addLast(const T& x) override{
            add(size, x);
        }

        T removeFirst() override{
            return remove(0);
        }

        T removeLast() override{
            return remove(size - 1);
        }

        const T peekFirst() const override{
            return get(0);
        }

        const T peekLast() const override{
            return get(size - 1);
        }

        bool isEmpty() const override{
            return (size == 0) ? true : false;
        }

        void clear() override{
            while(!isEmpty()) removeLast();
            return;
        }

        size_t size () const override{
            return size;
        }
};
