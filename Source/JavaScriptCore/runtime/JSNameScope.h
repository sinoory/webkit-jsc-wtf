/*
 * Copyright (C) 2008, 2009 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef JSNameScope_h
#define JSNameScope_h

#include "JSEnvironmentRecord.h"
#include "JSGlobalObject.h"

namespace JSC {

// Used for scopes with a single named variable: catch and named function expression.
class JSNameScope : public JSEnvironmentRecord {
public:
    typedef JSEnvironmentRecord Base;

    enum Type {
        CatchScope,
        FunctionNameScope
    };

    static JSNameScope* create(ExecState* exec, JSScope* currentScope, const Identifier& identifier, JSValue value, unsigned attributes, Type type)
    {
        VM& vm = exec->vm();
        JSNameScope* scopeObject = new (NotNull, allocateCell<JSNameScope>(vm.heap)) JSNameScope(vm, exec->lexicalGlobalObject(), currentScope, type);
        scopeObject->finishCreation(vm, identifier, value, attributes);
        return scopeObject;
    }

    static JSNameScope* create(VM& vm, JSGlobalObject* globalObject, const Identifier& identifier, JSValue value, unsigned attributes, JSScope* next, Type type)
    {
        JSNameScope* scopeObject = new (NotNull, allocateCell<JSNameScope>(vm.heap)) JSNameScope(vm, globalObject, next, type);
        scopeObject->finishCreation(vm, identifier, value, attributes);
        return scopeObject;
    }

    static void visitChildren(JSCell*, SlotVisitor&);
    static JSValue toThis(JSCell*, ExecState*, ECMAMode);
    static bool getOwnPropertySlot(JSObject*, ExecState*, PropertyName, PropertySlot&);
    static void put(JSCell*, ExecState*, PropertyName, JSValue, PutPropertySlot&);

    static Structure* createStructure(VM& vm, JSGlobalObject* globalObject, JSValue proto) { return Structure::create(vm, globalObject, proto, TypeInfo(NameScopeObjectType, StructureFlags), info()); }

    DECLARE_INFO;

    bool isFunctionNameScope() const { return m_type == FunctionNameScope; }
    bool isCatchScope() const { return m_type == CatchScope; }

    JSValue value() const { return m_registerStore.get(); }

protected:
    void finishCreation(VM& vm, const Identifier& identifier, JSValue value, unsigned attributes)
    {
        Base::finishCreation(vm);
        m_registerStore.set(vm, this, value);
        symbolTable()->add(identifier.impl(), SymbolTableEntry(-1, attributes));
    }

    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | Base::StructureFlags;

private:
    JSNameScope(VM& vm, JSGlobalObject* globalObject, JSScope* next, Type type)
        : Base(
            vm,
            globalObject->nameScopeStructure(),
            reinterpret_cast<Register*>(&m_registerStore + 1),
            next
        )
        , m_type(type)
    {
    }

    WriteBarrier<Unknown> m_registerStore;
    Type m_type;
};

}

#endif // JSNameScope_h
