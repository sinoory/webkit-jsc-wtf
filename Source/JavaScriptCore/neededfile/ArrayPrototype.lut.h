// Automatically generated from /home/sin/work/webkit/webv8/dbg/Source/JavaScriptCore/runtime/ArrayPrototype.cpp using /home/sin/work/webkit/webv8/dbg/Source/JavaScriptCore/create_hash_table. DO NOT EDIT!

#include "JSCBuiltins.h"

#include "Lookup.h"

namespace JSC {

static const struct CompactHashIndex arrayPrototypeTableIndex[67] = {
    { -1, -1 },
    { 20, 66 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 1, -1 },
    { -1, -1 },
    { 25, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 15, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 6, -1 },
    { -1, -1 },
    { 14, -1 },
    { 21, -1 },
    { 11, 65 },
    { 17, -1 },
    { -1, -1 },
    { 0, -1 },
    { 10, -1 },
    { -1, -1 },
    { 4, -1 },
    { -1, -1 },
    { -1, -1 },
    { 23, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 19, -1 },
    { 16, -1 },
    { 9, -1 },
    { -1, -1 },
    { -1, -1 },
    { 18, -1 },
    { 2, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 7, -1 },
    { 5, 64 },
    { -1, -1 },
    { -1, -1 },
    { 8, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 3, -1 },
    { -1, -1 },
    { -1, -1 },
    { 13, -1 },
    { 12, -1 },
    { 22, -1 },
    { 24, -1 },
};


static const struct HashTableValue arrayPrototypeTableValues[26] = {
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPETOSTRING)
   { "toString", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeToStringCodeGenerator), (intptr_t)0 },
 #else
   { "toString", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncToString), (intptr_t)(0) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPETOLOCALESTRING)
   { "toLocaleString", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeToLocaleStringCodeGenerator), (intptr_t)0 },
 #else
   { "toLocaleString", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncToLocaleString), (intptr_t)(0) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPECONCAT)
   { "concat", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeConcatCodeGenerator), (intptr_t)1 },
 #else
   { "concat", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncConcat), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEFILL)
   { "fill", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeFillCodeGenerator), (intptr_t)1 },
 #else
   { "fill", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncFill), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEJOIN)
   { "join", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeJoinCodeGenerator), (intptr_t)1 },
 #else
   { "join", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncJoin), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEPOP)
   { "pop", ((DontEnum|Function) & ~Function) | Builtin, ArrayPopIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypePopCodeGenerator), (intptr_t)0 },
 #else
   { "pop", DontEnum|Function, ArrayPopIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncPop), (intptr_t)(0) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEPUSH)
   { "push", ((DontEnum|Function) & ~Function) | Builtin, ArrayPushIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypePushCodeGenerator), (intptr_t)1 },
 #else
   { "push", DontEnum|Function, ArrayPushIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncPush), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEREVERSE)
   { "reverse", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeReverseCodeGenerator), (intptr_t)0 },
 #else
   { "reverse", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncReverse), (intptr_t)(0) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPESHIFT)
   { "shift", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeShiftCodeGenerator), (intptr_t)0 },
 #else
   { "shift", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncShift), (intptr_t)(0) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPESLICE)
   { "slice", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeSliceCodeGenerator), (intptr_t)2 },
 #else
   { "slice", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncSlice), (intptr_t)(2) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPESORT)
   { "sort", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeSortCodeGenerator), (intptr_t)1 },
 #else
   { "sort", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncSort), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPESPLICE)
   { "splice", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeSpliceCodeGenerator), (intptr_t)2 },
 #else
   { "splice", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncSplice), (intptr_t)(2) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEUNSHIFT)
   { "unshift", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeUnshiftCodeGenerator), (intptr_t)1 },
 #else
   { "unshift", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncUnShift), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEEVERY)
   { "every", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeEveryCodeGenerator), (intptr_t)1 },
 #else
   { "every", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncEvery), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEFOREACH)
   { "forEach", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeForEachCodeGenerator), (intptr_t)1 },
 #else
   { "forEach", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncForEach), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPESOME)
   { "some", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeSomeCodeGenerator), (intptr_t)1 },
 #else
   { "some", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncSome), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEINDEXOF)
   { "indexOf", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeIndexOfCodeGenerator), (intptr_t)1 },
 #else
   { "indexOf", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncIndexOf), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPELASTINDEXOF)
   { "lastIndexOf", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeLastIndexOfCodeGenerator), (intptr_t)1 },
 #else
   { "lastIndexOf", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncLastIndexOf), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEFILTER)
   { "filter", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeFilterCodeGenerator), (intptr_t)1 },
 #else
   { "filter", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncFilter), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEREDUCE)
   { "reduce", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeReduceCodeGenerator), (intptr_t)1 },
 #else
   { "reduce", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncReduce), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEREDUCERIGHT)
   { "reduceRight", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeReduceRightCodeGenerator), (intptr_t)1 },
 #else
   { "reduceRight", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncReduceRight), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEMAP)
   { "map", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeMapCodeGenerator), (intptr_t)1 },
 #else
   { "map", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncMap), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEENTRIES)
   { "entries", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeEntriesCodeGenerator), (intptr_t)0 },
 #else
   { "entries", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncEntries), (intptr_t)(0) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEKEYS)
   { "keys", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeKeysCodeGenerator), (intptr_t)0 },
 #else
   { "keys", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncKeys), (intptr_t)(0) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEFIND)
   { "find", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeFindCodeGenerator), (intptr_t)1 },
 #else
   { "find", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncFind), (intptr_t)(1) },
 #endif
 #if JSC_BUILTIN_EXISTS(ARRAYPROTOTYPEFINDINDEX)
   { "findIndex", ((DontEnum|Function) & ~Function) | Builtin, NoIntrinsic, (intptr_t)static_cast<BuiltinGenerator>(arrayPrototypeFindIndexCodeGenerator), (intptr_t)1 },
 #else
   { "findIndex", DontEnum|Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(arrayProtoFuncFindIndex), (intptr_t)(1) },
 #endif
};

JS_EXPORT_PRIVATE extern const struct HashTable arrayPrototypeTable =
    { 26, 63, false, arrayPrototypeTableValues, 0, arrayPrototypeTableIndex };
} // namespace
