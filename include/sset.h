#pragma once
#define SSET

template <typename T>

class SortedSet {
        public:
            virtual ~SortedSet() {}

            virtual bool add(T x ) = 0;

            virtual bool remove(T x) = 0;

            virtual bool hasElement(T x) = 0;

            virtual int size() const = 0;
};
