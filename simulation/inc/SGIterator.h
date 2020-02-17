#ifndef GCW_SGITERATOR_H_
#define GCW_SGITERATOR_H_

#include <iterator>

class SpiralGalaxy;
class SGObject;

class SGIterator : public std::iterator<std::input_iterator_tag, SGObject>
{
public:
    SGIterator(const SGIterator &it);

    SGIterator &operator=(const SGIterator &it);

    SGObject &operator*() const;
    SGObject *operator->() const;

    SGIterator &operator++();
    SGIterator operator++(int);

    bool operator==(const SGIterator &) const;
    bool operator!=(const SGIterator &) const;

    operator bool() const;

    static inline SGIterator
    begin(SpiralGalaxy *galaxy) { return SGIterator(galaxy, 0); }
    static inline SGIterator
    end(SpiralGalaxy *galaxy) { return SGIterator(galaxy, -1); }

private:
    SGIterator(SpiralGalaxy *galaxy, ptrdiff_t idx = 0);

    ptrdiff_t idx;
    SpiralGalaxy *galaxy;

};

#endif // GCW_SGITERATOR_H_

