class IInputSystem
{
public:
    
    void EnableInput(bool bEnable)
    {
        typedef void (* oEnableInput)(void*, bool);
        return getvfunc<oEnableInput>(this, 11)(this, bEnable);
    }
    
    
    void ResetInputState()
    {
        typedef void (* oResetInputState)(void*);
        return getvfunc<oResetInputState>(this, 39)(this);
    }
    
    
};
