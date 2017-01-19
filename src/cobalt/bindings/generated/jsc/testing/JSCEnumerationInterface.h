/*
 * Copyright 2017 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// This file has been auto-generated by bindings/code_generator_cobalt.py. DO NOT MODIFY!
// Auto-generated from template: bindings/javascriptcore/templates/interface.h.template

// clang-format off

#ifndef JSCEnumerationInterface_h
#define JSCEnumerationInterface_h

#include "base/hash_tables.h"
#include "base/lazy_instance.h"
#include "base/memory/ref_counted.h"
#include "base/threading/thread_checker.h"
#include "cobalt/base/polymorphic_downcast.h"
#include "cobalt/script/wrappable.h"
#include "cobalt/bindings/testing/enumeration_interface.h"

#include "base/threading/thread_local_storage.h"
#include "cobalt/script/javascriptcore/jsc_global_object.h"
#include "cobalt/script/javascriptcore/script_object_registry.h"
#include "cobalt/script/javascriptcore/thread_local_hash_table.h"
#include "cobalt/script/javascriptcore/wrapper_base.h"
#include "cobalt/script/javascriptcore/wrapper_factory.h"
#include "third_party/WebKit/Source/JavaScriptCore/config.h"
#include "third_party/WebKit/Source/JavaScriptCore/runtime/ClassInfo.h"
#include "third_party/WebKit/Source/JavaScriptCore/runtime/JSObject.h"
#include "third_party/WebKit/Source/JavaScriptCore/runtime/Lookup.h"

namespace cobalt {
namespace bindings {
namespace testing {

class JSCEnumerationInterface
    : public script::javascriptcore::InterfaceBase {
  typedef script::javascriptcore::InterfaceBase BaseClass;
 public:

  // Get the prototype object for this wrapper class.
  static JSC::JSObject* GetPrototype(JSC::JSGlobalObject* global_object);

  // Get the interface object for this wrapper class.
  static JSC::JSObject* GetConstructor(JSC::ExecState* exec_state);

  // JavaScriptCore functions and members

  DECLARE_CLASSINFO();

  // Needed when JSC::OverridesGetOwnPropertySlot StructureFlag is set
  // Must be public so that it can be accessible from getStaticValueSlot<>.
  static bool getOwnPropertySlot(JSC::JSCell*, JSC::ExecState*,
                                 JSC::PropertyName,
                                 JSC::PropertySlot&);

  // static override. Needed to support setting a property.
  static void put(JSC::JSCell*, JSC::ExecState*, JSC::PropertyName,
                  JSC::JSValue, JSC::PutPropertySlot&);

  // static override. This function will be called after a new object has
  // been created.
  void finishCreation(JSC::JSGlobalData& global_data);

  static script::javascriptcore::WrapperFactory::CreateWrapperFunction
      GetCreateWrapperFunction() {
    return base::Bind(&Create);
  }

 private:
  // Create a new wrapper for |wrappable|, which will be cast to EnumerationInterface.
  static JSC::JSObject* Create(
      script::javascriptcore::JSCGlobalObject* global_object,
      const scoped_refptr<script::Wrappable>& wrappable);

 protected:

  static const unsigned StructureFlags =
      JSC::OverridesGetOwnPropertySlot |
      BaseClass::StructureFlags;

  JSCEnumerationInterface(
      JSC::JSGlobalData* global_data,
      JSC::Structure* structure,
      script::javascriptcore::ScriptObjectRegistry* script_object_registry,
      const scoped_refptr<EnumerationInterface>& impl);
  ~JSCEnumerationInterface();

 private:
  class InterfaceObject;
  class Prototype;

  static const JSC::HashTableValue property_table_values[];
  static const JSC::HashTable property_table_prototype;
  static base::LazyInstance<
      cobalt::script::javascriptcore::ThreadLocalHashTable>
          thread_local_property_table;

  static const JSC::HashTable* GetPropertyTable(JSC::ExecState* exec_state);

  static bool HasOwnPropertyOrPrototypeProperty(JSC::JSCell* cell,
      JSC::ExecState* exec_state, JSC::PropertyName property_name);

#ifdef __LB_SHELL__FORCE_LOGGING__
  struct NonTrivialStaticFields {
    // TODO: Only log attempts of usage of unsupported Web APIs.
    base::hash_set<std::string> properties_warned_about;
    base::Lock lock_;
  };
  static base::LazyInstance<NonTrivialStaticFields> non_trivial_static_fields;
#endif  // __LB_SHELL__FORCE_LOGGING__
};

}  // namespace bindings
}  // namespace testing
}  // namespace cobalt

#endif  // JSCEnumerationInterface_h
