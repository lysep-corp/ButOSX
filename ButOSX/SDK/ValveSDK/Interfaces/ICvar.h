class ICvar {
public:
    template <typename... Values>
    void ConsoleColorPrintf(const Color& MsgColor, const char* szMsgFormat, Values... Parameters)
    {
        typedef void (* oConsoleColorPrintf)(void*, const Color&, const char*, ...);
        return getvfunc<oConsoleColorPrintf>(this, 25)(this, MsgColor, szMsgFormat, Parameters...);
    }
    
    template <typename... Values>
    void ConsoleDPrintf(const char* szMsgFormat, Values... Parameters)
    {
        typedef void (* oConsoleDPrintf)(void*, const char*, ...);
        return getvfunc<oConsoleDPrintf>(this, 27)(this, szMsgFormat, Parameters...);
    }
};
