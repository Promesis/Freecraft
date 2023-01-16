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
    virtual ~FDTData(void);
    virtual const FDTData &operator=(const FDTData &dat) = 0;

    virtual const FDTData &getData(void) const = 0;
    virtual void setData(const FDTData &dat) = 0;

};

class FDTInt : virtual public FDTData
{
protected:
    int data;
public:
    
};


#endif