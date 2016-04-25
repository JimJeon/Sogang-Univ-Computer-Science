#ifndef __STR__
#define __STR__

class Str {
    private:
        char *str;
        int len;
    public:
        Str(int);
        Str(const char *);
        ~Str();
        int length(void);
        char *contents(void);
        int compare(Str&);
        int compare(const char *);
        void operator=(const char *);
        void operator=(Str&);
};
#endif
