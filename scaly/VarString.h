#ifndef __Scaly__VarString__
#define __Scaly__VarString__
namespace scaly {

class _VarString : public Object {
public:
    _VarString();
    _VarString(const char* theString);
    _VarString(const _VarString& theString);
    _VarString(_LetString& theString);
    _VarString(size_t theLength);
    _VarString(size_t theLength, size_t theCapacity);
    _VarString(char c);
     char* getNativeString() const;
     size_t getLength();
     char operator [](size_t i);
    _VarString& operator += (char c);
    _VarString& operator += (const char* theString);
    _VarString& operator + (const char* theString);
    _VarString& operator += (const _VarString& theString);
    _VarString& operator += (_LetString& theString);
    _VarString& operator + (const _VarString& thestring);
     bool operator == (const char* theString);
     bool operator != (const char* theString);
     bool operator == (const _VarString& theString);
     bool operator != (const _VarString& theString);
    _Array<_VarString>& Split(_Page* _rp, char c);

private:
    void reallocate(size_t newLength);
    bool extend(size_t size);
    void allocate(size_t size);

    char* string;
    size_t length;
    size_t capacity;
};

}
#endif