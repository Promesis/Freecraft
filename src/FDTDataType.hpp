#ifndef FDTDataType_hpp
#define FDTDataType_hpp


//Tags of data.
enum class FDTDataTag
{
    FDTNone,

    FDTShort,
    FDTInt,
    FDTLong,
    FDTLongLong,

    FDTUnsignedShort,
    FDTUnsignedInt,
    FDTUnsignedLong,
    FDTUnsignedLongLong,

    FDTFloat,
    FDTDouble,

    FDTChar,
    FDTUnsignedChar,
    FDTWChar,
    FDTChar16,
    FDTChar32

};


class FDTData
{
protected:
    FDTDataTag _tag;
    /*
    union
    {
        // data
        unsigned short _us;
        unsigned int _ui;
        unsigned long _ul;
        unsigned long long _ull;
        short _s;
        int _i;
        long _l;
        long _ll;

        float _f;
        double _d;

        char _c;
        wchar_t _wc;
        char16_t _c16;
        char32_t _c32;

        unsigned char _uc;
        //unsigned wchar_t _uwc;
        //unsigned char16_t _uc16;
    };
    */
    
public:
    virtual FDTDataTag getTag(void) = 0;
    FDTData(const FDTData &dat);
    FDTData(FDTData &&datR);
    //FDTData(FDTDataTag tag=FDTDataTag::FDTNone);
    FDTData(void);
    virtual ~FDTData(void);
    virtual const FDTData &operator=(const FDTData &dat) = 0;

    virtual const FDTData &getData(void) const = 0;
    virtual void setData(const FDTData &dat) = 0;

};

class FDTInt : public FDTData
{
protected:
    int data;
public:
    FDTDataTag getTag(void);
    ~FDTInt(void);
    FDTInt(int _int=0);
    FDTInt(const FDTInt &_int);
    FDTInt(FDTInt &&_intR);
    const FDTInt &operator=(const FDTInt &_int);
    const FDTInt &operator=(FDTInt &&_intR);
    const FDTInt &getData(void) const;
    void setData(const FDTInt &dat);
    operator int(void) const;
};

class FDTShort : public FDTData
{
protected:
    short data;
public:
    FDTDataTag getTag(void);
    ~FDTShort(void);
    FDTShort(short _short=0);
    FDTShort(const FDTShort &_short);
    FDTShort(FDTShort &&_shortR);
    const FDTShort &operator=(const FDTShort &_short);
    const FDTShort &operator=(FDTShort &&_shortR);
    const FDTShort&getData(void) const;
    void setData(const FDTShort &dat);
    operator short(void) const;
};

class FDTFloat : public FDTData
{
protected:
    float data;
public:
    FDTDataTag getTag(void);
    ~FDTFloat(void);
    FDTFloat(short _float=0);
    FDTFloat(const FDTFloat &_float);
    FDTFloat(FDTFloat &&_floatR);
    const FDTFloat &operator=(const FDTFloat &_float);
    const FDTFloat &operator=(FDTFloat &&_floatR);
    const FDTFloat &getData(void) const;
    void setData(const FDTFloat &dat);
    operator float(void) const;
};

#endif