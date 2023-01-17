#ifndef FDTDataType_hpp
#define FDTDataType_hpp

/**
 * @author Promesis
 *
 */

/**
 * @brief tags of data.
 * 
 */
enum class FDTDataTag
{
    /// none
    FDTNone,
    /// short
    FDTShort,
    /// int
    FDTInt,
    /// long
    FDTLong,
    /// long long
    FDTLongLong,
    /// unsigned short
    FDTUnsignedShort,
    /// unsigned int
    FDTUnsignedInt,
    /// unsigned long
    FDTUnsignedLong,
    /// unsigned long long
    FDTUnsignedLongLong,
    /// float
    FDTFloat,
    /// double
    FDTDouble,
    /// char
    FDTChar,
    /// unsigned char
    FDTUnsignedChar,
    /// wchar_t
    FDTWChar,
    /// char16_t
    FDTChar16,
    /// char32_t
    FDTChar32

};

/**
 * @brief base class of data.
 * 
 */
class FDTData
{
protected:
    /**
     * @brief tag of current data.
     * 
     */
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
    /**
     * @brief Get the Tag of object. pure virtual function.
     * @return FDTDataTag 
     */
    virtual FDTDataTag getTag(void) = 0;
    /**
     * @brief Construct a new FDTData object(copy ctor).
     * 
     * @param dat a const FDTData reference.
     */
    FDTData(const FDTData &dat);
    /**
     * @brief Construct a new FDTData object(move ctor).
     * 
     * @param datR right value.
     */
    FDTData(FDTData &&datR);
    //FDTData(FDTDataTag tag=FDTDataTag::FDTNone);
    /**
     * @brief Construct a new FDTData object(default ctor).
     * 
     */
    FDTData(void);
    /**
     * @brief Destroy the FDTData object.
     * 
     */
    virtual ~FDTData(void);
    /**
     * @brief copy assignmemt operator. pure virtual function.
     * 
     * @param dat a const FDTData reference.
     * @return const FDTData& 
     */
    virtual const FDTData &operator=(const FDTData &dat) = 0;
    /**
     * @brief Get the Data. pure virtual function.
     * 
     * @return const FDTData& 
     */
    virtual const FDTData &getData(void) const = 0;
    /**
     * @brief Set the Data. pure virtual function.
     * 
     * @param dat const FDTData reference. data to set.
     */
    virtual void setData(const FDTData &dat) = 0;

};

class FDTInt : public FDTData
{
protected:
    /**
     * @brief data if this FDTInt instance.
     * 
     */
    int data;
public:
    /**
     * @brief Get the Tag of object.
     * 
     * @return FDTDataTag 
     */
    FDTDataTag getTag(void);
    /**
     * @brief Destroy the FDTInt object.
     * 
     */
    ~FDTInt(void);
    /**
     * @brief Construct a new FDTInt object. default ctor.
     * 
     * @param _int value to set. default is zero.
     */
    FDTInt(int _int=0);
    /**
     * @brief Construct a new FDTInt object. copy ctor.
     * 
     * @param _int object to assign.
     */
    FDTInt(const FDTInt &_int);
    /**
     * @brief Construct a new FDTInt object. move ctor.
     * 
     * @param _intR object to assign. right val.
     */
    FDTInt(FDTInt &&_intR);
    /**
     * @brief copy assigent operator.
     * 
     * @param _int value to set.
     * @return const FDTInt& 
     */
    const FDTInt &operator=(const FDTInt &_int);
    /**
     * @brief move assignment operator.
     * 
     * @param _intR right value to set.
     * @return const FDTInt& 
     */
    const FDTInt &operator=(FDTInt &&_intR);
    /**
     * @brief Get the Data of object.
     * 
     * @return const FDTInt& 
     */
    const FDTInt &getData(void) const;
    /**
     * @brief Set the Data of object.
     * 
     * @param dat a FDTInt instance.
     * @see FDTInt
     */
    void setData(const FDTInt &dat);
    /**
     * @brief conversation function.
     * 
     */
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