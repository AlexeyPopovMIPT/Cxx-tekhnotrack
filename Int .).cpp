#include <stdio.h>

#define $ printf("Line %d: ", __LINE__);
#define FUNC(decl) decl { SpaceManager manager(#decl); 

#define   GREEN "\x1b[32;40m"
#define     RED "\x1b[31;40m"
#define    BLUE "\x1b[34;40m"
#define DEFAULT "\x1b[37;40m"
#define  INVERT "\x1b[30;47m"




#pragma warning (disable: 4996)


struct SpaceManager
{
    static int spacesCount;

    SpaceManager()
    {
        spacesCount += 4;
    }

    SpaceManager(const char* funcsig)
    {
        printf(BLUE "%*c%s" DEFAULT " {\n", spacesCount, ' ', funcsig);
        spacesCount += 4;
    }

    ~SpaceManager()
    {
        spacesCount -= 4;
        printf("%*c}\n", spacesCount, ' ');
    }

    int getCount()
    {
        return spacesCount;
    }

    void PrintSpace()
    {
        printf("%*c", spacesCount, ' ');
    }

};

int SpaceManager::spacesCount = 0;


 

class Int32
{
    static int constructions;
    static int destr;
    __int32 val;
    static bool licenseActivated;

    struct
    {
        __int8 _assignments = 9;
        __int8 _additions = 4;
        __int8 _bitOperations = 3;
        __int8 _multiples = 2;
        __int8 _divisions = 2;
        __int8 _comparings = 4;
    } Remaining;

    static const char* colours[16];

    void PrintPointer(const void* ptr)
    {
        int idx = ((int)ptr >> 4) & 0xF;
        printf("\x1b[%s;40m[0x%p]" DEFAULT, colours[idx], ptr);
    }

public:

    FUNC(Int32 (int value))
    
        ++constructions;
        manager.PrintSpace();
        printf(GREEN "Called ");
        PrintPointer(this);
        printf(GREEN " construction from %d" DEFAULT "\n", value);
        val = value;
    }


    FUNC(Int32 (const Int32 &copy))
    
       ++constructions;
       manager.PrintSpace();
       printf(GREEN "Called ");
       PrintPointer(this);
       printf(GREEN " construction from ");
       PrintPointer(&copy);
       printf(GREEN "(%d)" DEFAULT "\n", copy.val);
       val = copy.val;
       Remaining._assignments--;
    }
    

    FUNC(~Int32())
    
        manager.PrintSpace();
        printf(RED "Called ");
        PrintPointer(this);
        printf(RED "(%d) destruction" DEFAULT "\n", this->val);
        ++destr;
    }

    FUNC(int GetValue())
    
        return this->val;
    }

    FUNC(void ActivateLicense(int key))

        if (key == ((0xD7EA77LU + 0xC4) | (int)(void*)this))
        {
            manager.PrintSpace();
            printf("Thanks for purchasing the license\n");
            licenseActivated = true;
        }
        else
        {
            manager.PrintSpace();
            printf("Wrong activation key\n");
        }
    }

    FUNC(void getRemaining(Int32* assignments, Int32* additions, Int32* bitOperations,
                        Int32* multiples, Int32* divisions, Int32* comparings))
    
        if (assignments)   assignments->val   = this->Remaining._assignments;
        if (additions)     additions->val     = this->Remaining._additions;
        if (bitOperations) bitOperations->val = this->Remaining._bitOperations;
        if (multiples)     multiples->val     = this->Remaining._multiples;
        if (divisions)     divisions->val     = this->Remaining._divisions;
        if (comparings)    comparings->val    = this->Remaining._comparings;
        return;

    }

#define TRIAL_CHECKRHS(OPER, ret)                                                     \
        if (!(licenseActivated ||rhs.Remaining._##OPER))                              \
        {                                                                             \
            manager.PrintSpace();                                                     \
            printf("\nRight operator ran out of "#OPER"! Buy license version\n");     \
            return ret;                                                               \
        }

#define TRIAL_CHECKLHS(OPER, ret)                                                     \
        if (!(licenseActivated || this->Remaining._##OPER))                           \
        {                                                                             \
            manager.PrintSpace();                                                     \
            printf("\nLeft operator ran out of "#OPER"! Buy license version\n");      \
            return ret;                                                               \
        }

#define BINARY(sign, oper)                                                                              \
        FUNC(Int32 operator ##sign (Int32 &rhs))                                                        \
                                                                                                        \
            manager.PrintSpace();                                                                       \
            printf("Called ");                                                                          \
            PrintPointer(this);                                                                         \
            printf("(%d) " #sign , this->val);                                                          \
            PrintPointer(&rhs);                                                                         \
            printf("(%d)\n", rhs.val);                                                                  \
            TRIAL_CHECKLHS(oper, rhs);                                                                  \
            TRIAL_CHECKRHS(oper, *this);                                                                \
            this->Remaining._##oper--;                                                                  \
            rhs.Remaining._##oper--;                                                                    \
            return Int32(this->val sign rhs.val);                                                       \
        }

    BINARY(+, additions)
    BINARY(-, additions)
    BINARY(*, multiples)
    BINARY(/, divisions)
    BINARY(&, bitOperations)
    BINARY(|, bitOperations)
    BINARY(^, bitOperations)

#undef BINARY

FUNC(Int32 operator % (Int32 & rhs))
        
    manager.PrintSpace();
    printf("Called ");
    PrintPointer(this);
    printf("(%d) %% ", this->val);
    PrintPointer(&rhs);
    printf("(%d)\n", rhs.val);

    TRIAL_CHECKLHS(bitOperations, rhs);
    TRIAL_CHECKRHS(bitOperations, *this);

    this->Remaining._bitOperations--;
    rhs.Remaining._bitOperations--;

    return Int32(this->val % rhs.val);

}


#define BINARY(sign)                                                                                     \
        FUNC(Int32& operator ##sign (Int32 &rhs))                                                        \
                                                                                                         \
            manager.PrintSpace();                                                                        \
            printf("Called ");                                                                           \
            PrintPointer(this);                                                                          \
            printf("(%d) " #sign , this->val);                                                           \
            PrintPointer(&rhs);                                                                          \
            printf("(%d)\n", rhs.val);                                                                   \
            if (!licenseActivated)                                                                       \
            {                                                                                            \
                manager.PrintSpace();                                                                    \
                printf("Operation" #sign "is unavailable in trial version\n");                           \
                return *this;                                                                            \
            }                                                                                            \
            this->val sign rhs.val;                                                                      \
            return *this;                                                                                \
        }

    BINARY(+=)
    BINARY(-=)
    BINARY(*=)
    BINARY(/=)
    BINARY(|=)
    BINARY(&=)
    BINARY(^=)
    BINARY(<<= )
    BINARY(>>= )

FUNC (Int32& operator %= (Int32 &rhs))
    
    manager.PrintSpace();
    printf("Called ");
    PrintPointer(this);
    printf("(%d) %%= ", this->val);
    PrintPointer(&rhs);
    printf("(%d)\n", rhs.val);
    if (!licenseActivated)
    {
        manager.PrintSpace();
        printf("Operation" "%%=" "is unavailable in trial version\n");
        return *this;
    }  
    this->val %= rhs.val;
    return *this;
}


#undef BINARY





#define BINARY(sign)                                                                                    \
        FUNC(bool operator ##sign (Int32 rhs))                                                          \
                                                                                                        \
            manager.PrintSpace();                                                                       \
            printf("Called ");                                                                          \
            PrintPointer(this);                                                                         \
            printf("(%d) " #sign , this->val);                                                          \
            PrintPointer(&rhs);                                                                         \
            printf("(%d)\n", rhs.val);                                                                  \
            TRIAL_CHECKLHS(comparings, false);                                                          \
            TRIAL_CHECKRHS(comparings, false);                                                          \
            this->Remaining._comparings--;                                                              \
            rhs.Remaining._comparings--;                                                                \
            return this->val sign rhs.val;                                                              \
        }

    BINARY(> )
    BINARY(>=)
    BINARY(< )
    BINARY(<=)
    BINARY(==)
    BINARY(!=)
#undef BINARY




FUNC (const Int32& operator = (Int32 rhs))
    
    manager.PrintSpace();
    printf("Called ");
    PrintPointer(this);
    printf("(%d) := ", this->val);
    PrintPointer(&rhs);
    printf("(%d)\n", rhs.val);

    TRIAL_CHECKLHS(assignments, *this);

    this->Remaining._assignments--;
    this->val = rhs.val;
    this->Remaining = rhs.Remaining;

    return *this;
}

    

#undef CHECKLHS
#undef CHECKRHS

};

bool Int32::licenseActivated = false;
int Int32::constructions = 0;
int Int32::destr = 0;
const char* Int32::colours[] = { "37", "31", "32", "33", "34", "35", "36", "37", "90", "91", "92", "93", "94", "95", "96", "97" };


FUNC(void BubbleSort(Int32 arr[], Int32 len, Int32 i, Int32 j))


    Int32 one(1);

    if (j == len - i)
    {
        if (i == len)
        {
            return;
        }
        i = i + one;
        BubbleSort(arr, len, i, Int32(0));
        return;
    }

    Int32 size(sizeof(Int32));
    Int32 jsize(size * j);

    Int32 jxx(j + one);
    Int32 jxxsize(size * jxx);

    Int32 arrptr((int)arr);

    Int32* jptr = (Int32*)((arrptr + jsize).GetValue());
    Int32* jxxptr = (Int32*)((arrptr + jxxsize).GetValue());

    *jptr = Int32(jptr->GetValue());
    Int32 v1(*jptr);

    if (v1 > *jxxptr)
    {
        *jptr = *jxxptr;
        *jxxptr = v1;
    }

    BubbleSort(arr, len, i, jxx);

}

FUNC(int main())

    Int32 six(6);
    Int32 zero(0);

    Int32 arr[] = { Int32(7), Int32(6), Int32(5), Int32(4), Int32(3), Int32(2), Int32(1) };
    BubbleSort(arr, six, zero, zero);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i].GetValue());
    }

    return 0;

}



