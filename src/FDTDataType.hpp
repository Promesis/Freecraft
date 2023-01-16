#ifndef FDTDataType_hpp
#define FDTDataType_hpp


//Tags of data.
enum class FDTDataTag
{
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
    FDTWchar,
    FDTChar16,
    FDTChar32
};


class FDTData
{
private:
    FDTDataTag tag;
public:
    virtual FDTDataTag getTag(void);
};


#endif