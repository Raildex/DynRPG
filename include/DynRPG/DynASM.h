#ifndef DYNASM_H
#define DYNASM_H
//! \namespace RPG The one and only namespace in which all DynRPG classes, variables and functions reside, except for callbacks.
namespace RPG
{
    //! \cond
    // Used for asm statements when input parameters may be written to
    static void *_eax __attribute__((unused));
    static void *_edx __attribute__((unused));
    static void *_ecx __attribute__((unused));
    //! \endcond

    //! Not implemented yet
    typedef void UnknownPointer;
} // namespace RPG
#endif