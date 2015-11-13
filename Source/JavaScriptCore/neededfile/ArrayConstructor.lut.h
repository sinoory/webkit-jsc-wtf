// Automatically generated from /home/sin/work/webkit/webv8/dbg/Source/JavaScriptCore/runtime/ArrayConstructor.cpp using /home/sin/work/webkit/webv8/dbg/Source/JavaScriptCore/create_hash_table. DO NOT EDIT!

#include "JSCBuiltins.h"

#include "Lookup.h"

namespace JSC {

static const struct CompactHashIndex arrayConstructorTableIndex[4] = {
    { -1, -1 },
    { 0, -1 },
    { -1, -1 },
    { 1, -1 },
};


static const struct HashTableValue arrayConstructorTableValues[2] = {
 #if JSC_BUILTIN_EXISTS(ARRAYCONSTRUCTORISARRAY)
   { "isArray", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayConstructorIsArrayCodeGenerator), (intptr_t)1 },
 #else
   { "isArray", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayConstructorIsArray), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYCONSTRUCTOROF)
   { "of", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayConstructorOfCodeGenerator), (intptr_t)0 },
 #else
   { "of", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayConstructorOf), (intptr_t)(0) },
 #endif
};

JS_EXPORT_PRIVATE extern const struct HashTable arrayConstructorTable =
    { 2, 3, false, arrayConstructorTableValues, 0, arrayConstructorTableIndex };
} // namespace
