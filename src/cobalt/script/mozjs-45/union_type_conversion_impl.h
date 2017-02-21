// This file was GENERATED by command:
//     pump.py union_type_conversion_impl.h.pump
// DO NOT EDIT BY HAND!!!

/*
 * Copyright 2016 Google Inc. All Rights Reserved.
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

#ifndef COBALT_SCRIPT_MOZJS_45_UNION_TYPE_CONVERSION_IMPL_H_
#define COBALT_SCRIPT_MOZJS_45_UNION_TYPE_CONVERSION_IMPL_H_

#include "cobalt/base/type_id.h"
#include "cobalt/script/mozjs-45/mozjs_exception_state.h"
#include "cobalt/script/mozjs-45/mozjs_global_environment.h"
#include "cobalt/script/mozjs-45/mozjs_object_handle.h"
#include "cobalt/script/mozjs-45/mozjs_user_object_holder.h"
#include "cobalt/script/mozjs-45/type_traits.h"
#include "cobalt/script/union_type.h"

// Conversion to/from JS::Value for IDL union types.

namespace cobalt {
namespace script {
namespace mozjs {

template <typename T1, typename T2>
void ToJSValue(JSContext* context, const script::UnionType2<T1, T2>& in_union,
               JS::MutableHandleValue out_value) {
  if (in_union.template IsType<T1>()) {
    ToJSValue(context, in_union.template AsType<T1>(), out_value);
    return;
  }
  if (in_union.template IsType<T2>()) {
    ToJSValue(context, in_union.template AsType<T2>(), out_value);
    return;
  }
  NOTREACHED();
  out_value.setUndefined();
}

template <typename T1, typename T2>
void FromJSValue(JSContext* context, JS::HandleValue value,
                 int conversion_flags, ExceptionState* exception_state,
                 script::UnionType2<T1, T2>* out_union) {
  DCHECK_EQ(0, conversion_flags);
  // JS -> IDL type conversion procedure described here:
  // http://heycam.github.io/webidl/#es-union

  // 1. If the union type includes a nullable type and V is null or undefined,
  // then return the IDL value null.
  if (value.isNull() || value.isUndefined()) {
    // If the type was nullable or undefined, we should have caught that as a
    // part of the base::optional<T> conversion.
    NOTREACHED();
    return;
  }
  // Typedef for readability.
  typedef ::cobalt::script::internal::UnionTypeTraits<T1> UnionTypeTraitsT1;
  typedef ::cobalt::script::internal::UnionTypeTraits<T2> UnionTypeTraitsT2;

  // Forward declare all potential types
  T1 t1;
  T2 t2;

  // 3.1 If types includes an interface type that V implements, then return the
  //     IDL value that is a reference to the object V.
  // 3.2 If types includes object, then return the IDL value that is a reference
  //     to the object V.
  //
  // The specification doesn't dictate what should happen if V implements more
  // than one of the interfaces. For example, if V implements interface B and
  // interface B inherits from interface A, what happens if both A and B are
  // union members? Blink doesn't seem to do anything special for this case.
  // Just choose the first interface in the flattened members that matches.
  if (value.isObject()) {
    JS::RootedObject rooted_object(context);
    bool success = JS_ValueToObject(context, value, &rooted_object);
    DCHECK(success);
    MozjsGlobalEnvironment* global_environment =
        static_cast<MozjsGlobalEnvironment*>(JS_GetContextPrivate(context));
    const WrapperFactory* wrapper_factory =
        global_environment->wrapper_factory();
    if (UnionTypeTraitsT1::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT1::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType2<T1, T2>(t1);
      return;
    }
    if (UnionTypeTraitsT2::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT2::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType2<T1, T2>(t2);
      return;
    }
  }

  // TODO: Support Date, RegExp, DOMException, Error, ArrayBuffer, DataView,
  //       TypedArrayName, callback functions, dictionary, array type.
  //       And sequences if necessary.

  // 14. If V is a Boolean value, then:
  //   1. If types includes a boolean, then return the result of converting V
  //      to boolean.
  if (value.isBoolean()) {
    if (UnionTypeTraitsT1::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType2<T1, T2>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType2<T1, T2>(t2);
      return;
    }
  }

  // 15. If V is a Number value, then:
  //   1. If types includes a numeric type, then return the result of converting
  //      V to that numeric type.
  if (value.isNumber()) {
    if (UnionTypeTraitsT1::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType2<T1, T2>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType2<T1, T2>(t2);
      return;
    }
  }

  // 16. If types includes a string type, then return the result of converting V
  // to that type.
  if (value.isString()) {
    if (UnionTypeTraitsT1::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType2<T1, T2>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType2<T1, T2>(t2);
      return;
    }
  }

  // 17. If types includes a numeric type, then return the result of converting
  // V to that numeric type.
  if (UnionTypeTraitsT1::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t1);
    *out_union = script::UnionType2<T1, T2>(t1);
    return;
  }
  if (UnionTypeTraitsT2::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t2);
    *out_union = script::UnionType2<T1, T2>(t2);
    return;
  }
  // 18. If types includes a boolean, then return the result of converting V to
  // boolean.
  if (UnionTypeTraitsT1::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t1);
    *out_union = script::UnionType2<T1, T2>(t1);
    return;
  }
  if (UnionTypeTraitsT2::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t2);
    *out_union = script::UnionType2<T1, T2>(t2);
    return;
  }
  // 19. Throw a TypeError.
  exception_state->SetSimpleException(kNotUnionType);
}

template <typename T1, typename T2, typename T3>
void ToJSValue(JSContext* context,
               const script::UnionType3<T1, T2, T3>& in_union,
               JS::MutableHandleValue out_value) {
  if (in_union.template IsType<T1>()) {
    ToJSValue(context, in_union.template AsType<T1>(), out_value);
    return;
  }
  if (in_union.template IsType<T2>()) {
    ToJSValue(context, in_union.template AsType<T2>(), out_value);
    return;
  }
  if (in_union.template IsType<T3>()) {
    ToJSValue(context, in_union.template AsType<T3>(), out_value);
    return;
  }
  NOTREACHED();
  out_value.setUndefined();
}

template <typename T1, typename T2, typename T3>
void FromJSValue(JSContext* context, JS::HandleValue value,
                 int conversion_flags, ExceptionState* exception_state,
                 script::UnionType3<T1, T2, T3>* out_union) {
  DCHECK_EQ(0, conversion_flags);
  // JS -> IDL type conversion procedure described here:
  // http://heycam.github.io/webidl/#es-union

  // 1. If the union type includes a nullable type and V is null or undefined,
  // then return the IDL value null.
  if (value.isNull() || value.isUndefined()) {
    // If the type was nullable or undefined, we should have caught that as a
    // part of the base::optional<T> conversion.
    NOTREACHED();
    return;
  }
  // Typedef for readability.
  typedef ::cobalt::script::internal::UnionTypeTraits<T1> UnionTypeTraitsT1;
  typedef ::cobalt::script::internal::UnionTypeTraits<T2> UnionTypeTraitsT2;
  typedef ::cobalt::script::internal::UnionTypeTraits<T3> UnionTypeTraitsT3;

  // Forward declare all potential types
  T1 t1;
  T2 t2;
  T3 t3;

  // 3.1 If types includes an interface type that V implements, then return the
  //     IDL value that is a reference to the object V.
  // 3.2 If types includes object, then return the IDL value that is a reference
  //     to the object V.
  //
  // The specification doesn't dictate what should happen if V implements more
  // than one of the interfaces. For example, if V implements interface B and
  // interface B inherits from interface A, what happens if both A and B are
  // union members? Blink doesn't seem to do anything special for this case.
  // Just choose the first interface in the flattened members that matches.
  if (value.isObject()) {
    JS::RootedObject rooted_object(context);
    bool success = JS_ValueToObject(context, value, &rooted_object);
    DCHECK(success);
    MozjsGlobalEnvironment* global_environment =
        static_cast<MozjsGlobalEnvironment*>(JS_GetContextPrivate(context));
    const WrapperFactory* wrapper_factory =
        global_environment->wrapper_factory();
    if (UnionTypeTraitsT1::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT1::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType3<T1, T2, T3>(t1);
      return;
    }
    if (UnionTypeTraitsT2::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT2::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType3<T1, T2, T3>(t2);
      return;
    }
    if (UnionTypeTraitsT3::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT3::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType3<T1, T2, T3>(t3);
      return;
    }
  }

  // TODO: Support Date, RegExp, DOMException, Error, ArrayBuffer, DataView,
  //       TypedArrayName, callback functions, dictionary, array type.
  //       And sequences if necessary.

  // 14. If V is a Boolean value, then:
  //   1. If types includes a boolean, then return the result of converting V
  //      to boolean.
  if (value.isBoolean()) {
    if (UnionTypeTraitsT1::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType3<T1, T2, T3>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType3<T1, T2, T3>(t2);
      return;
    }

    if (UnionTypeTraitsT3::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType3<T1, T2, T3>(t3);
      return;
    }
  }

  // 15. If V is a Number value, then:
  //   1. If types includes a numeric type, then return the result of converting
  //      V to that numeric type.
  if (value.isNumber()) {
    if (UnionTypeTraitsT1::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType3<T1, T2, T3>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType3<T1, T2, T3>(t2);
      return;
    }

    if (UnionTypeTraitsT3::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType3<T1, T2, T3>(t3);
      return;
    }
  }

  // 16. If types includes a string type, then return the result of converting V
  // to that type.
  if (value.isString()) {
    if (UnionTypeTraitsT1::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType3<T1, T2, T3>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType3<T1, T2, T3>(t2);
      return;
    }

    if (UnionTypeTraitsT3::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType3<T1, T2, T3>(t3);
      return;
    }
  }

  // 17. If types includes a numeric type, then return the result of converting
  // V to that numeric type.
  if (UnionTypeTraitsT1::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t1);
    *out_union = script::UnionType3<T1, T2, T3>(t1);
    return;
  }
  if (UnionTypeTraitsT2::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t2);
    *out_union = script::UnionType3<T1, T2, T3>(t2);
    return;
  }
  if (UnionTypeTraitsT3::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t3);
    *out_union = script::UnionType3<T1, T2, T3>(t3);
    return;
  }
  // 18. If types includes a boolean, then return the result of converting V to
  // boolean.
  if (UnionTypeTraitsT1::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t1);
    *out_union = script::UnionType3<T1, T2, T3>(t1);
    return;
  }
  if (UnionTypeTraitsT2::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t2);
    *out_union = script::UnionType3<T1, T2, T3>(t2);
    return;
  }
  if (UnionTypeTraitsT3::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t3);
    *out_union = script::UnionType3<T1, T2, T3>(t3);
    return;
  }
  // 19. Throw a TypeError.
  exception_state->SetSimpleException(kNotUnionType);
}

template <typename T1, typename T2, typename T3, typename T4>
void ToJSValue(JSContext* context,
               const script::UnionType4<T1, T2, T3, T4>& in_union,
               JS::MutableHandleValue out_value) {
  if (in_union.template IsType<T1>()) {
    ToJSValue(context, in_union.template AsType<T1>(), out_value);
    return;
  }
  if (in_union.template IsType<T2>()) {
    ToJSValue(context, in_union.template AsType<T2>(), out_value);
    return;
  }
  if (in_union.template IsType<T3>()) {
    ToJSValue(context, in_union.template AsType<T3>(), out_value);
    return;
  }
  if (in_union.template IsType<T4>()) {
    ToJSValue(context, in_union.template AsType<T4>(), out_value);
    return;
  }
  NOTREACHED();
  out_value.setUndefined();
}

template <typename T1, typename T2, typename T3, typename T4>
void FromJSValue(JSContext* context, JS::HandleValue value,
                 int conversion_flags, ExceptionState* exception_state,
                 script::UnionType4<T1, T2, T3, T4>* out_union) {
  DCHECK_EQ(0, conversion_flags);
  // JS -> IDL type conversion procedure described here:
  // http://heycam.github.io/webidl/#es-union

  // 1. If the union type includes a nullable type and V is null or undefined,
  // then return the IDL value null.
  if (value.isNull() || value.isUndefined()) {
    // If the type was nullable or undefined, we should have caught that as a
    // part of the base::optional<T> conversion.
    NOTREACHED();
    return;
  }
  // Typedef for readability.
  typedef ::cobalt::script::internal::UnionTypeTraits<T1> UnionTypeTraitsT1;
  typedef ::cobalt::script::internal::UnionTypeTraits<T2> UnionTypeTraitsT2;
  typedef ::cobalt::script::internal::UnionTypeTraits<T3> UnionTypeTraitsT3;
  typedef ::cobalt::script::internal::UnionTypeTraits<T4> UnionTypeTraitsT4;

  // Forward declare all potential types
  T1 t1;
  T2 t2;
  T3 t3;
  T4 t4;

  // 3.1 If types includes an interface type that V implements, then return the
  //     IDL value that is a reference to the object V.
  // 3.2 If types includes object, then return the IDL value that is a reference
  //     to the object V.
  //
  // The specification doesn't dictate what should happen if V implements more
  // than one of the interfaces. For example, if V implements interface B and
  // interface B inherits from interface A, what happens if both A and B are
  // union members? Blink doesn't seem to do anything special for this case.
  // Just choose the first interface in the flattened members that matches.
  if (value.isObject()) {
    JS::RootedObject rooted_object(context);
    bool success = JS_ValueToObject(context, value, &rooted_object);
    DCHECK(success);
    MozjsGlobalEnvironment* global_environment =
        static_cast<MozjsGlobalEnvironment*>(JS_GetContextPrivate(context));
    const WrapperFactory* wrapper_factory =
        global_environment->wrapper_factory();
    if (UnionTypeTraitsT1::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT1::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t1);
      return;
    }
    if (UnionTypeTraitsT2::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT2::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t2);
      return;
    }
    if (UnionTypeTraitsT3::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT3::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t3);
      return;
    }
    if (UnionTypeTraitsT4::is_interface_type &&
        wrapper_factory->DoesObjectImplementInterface(
            rooted_object, UnionTypeTraitsT4::GetTypeID())) {
      FromJSValue(context, value, conversion_flags, exception_state, &t4);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t4);
      return;
    }
  }

  // TODO: Support Date, RegExp, DOMException, Error, ArrayBuffer, DataView,
  //       TypedArrayName, callback functions, dictionary, array type.
  //       And sequences if necessary.

  // 14. If V is a Boolean value, then:
  //   1. If types includes a boolean, then return the result of converting V
  //      to boolean.
  if (value.isBoolean()) {
    if (UnionTypeTraitsT1::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t2);
      return;
    }

    if (UnionTypeTraitsT3::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t3);
      return;
    }

    if (UnionTypeTraitsT4::is_boolean_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t4);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t4);
      return;
    }
  }

  // 15. If V is a Number value, then:
  //   1. If types includes a numeric type, then return the result of converting
  //      V to that numeric type.
  if (value.isNumber()) {
    if (UnionTypeTraitsT1::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t2);
      return;
    }

    if (UnionTypeTraitsT3::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t3);
      return;
    }

    if (UnionTypeTraitsT4::is_numeric_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t4);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t4);
      return;
    }
  }

  // 16. If types includes a string type, then return the result of converting V
  // to that type.
  if (value.isString()) {
    if (UnionTypeTraitsT1::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t1);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t1);
      return;
    }

    if (UnionTypeTraitsT2::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t2);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t2);
      return;
    }

    if (UnionTypeTraitsT3::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t3);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t3);
      return;
    }

    if (UnionTypeTraitsT4::is_string_type) {
      FromJSValue(context, value, conversion_flags, exception_state, &t4);
      *out_union = script::UnionType4<T1, T2, T3, T4>(t4);
      return;
    }
  }

  // 17. If types includes a numeric type, then return the result of converting
  // V to that numeric type.
  if (UnionTypeTraitsT1::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t1);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t1);
    return;
  }
  if (UnionTypeTraitsT2::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t2);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t2);
    return;
  }
  if (UnionTypeTraitsT3::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t3);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t3);
    return;
  }
  if (UnionTypeTraitsT4::is_numeric_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t4);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t4);
    return;
  }
  // 18. If types includes a boolean, then return the result of converting V to
  // boolean.
  if (UnionTypeTraitsT1::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t1);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t1);
    return;
  }
  if (UnionTypeTraitsT2::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t2);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t2);
    return;
  }
  if (UnionTypeTraitsT3::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t3);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t3);
    return;
  }
  if (UnionTypeTraitsT4::is_boolean_type) {
    FromJSValue(context, value, conversion_flags, exception_state, &t4);
    *out_union = script::UnionType4<T1, T2, T3, T4>(t4);
    return;
  }
  // 19. Throw a TypeError.
  exception_state->SetSimpleException(kNotUnionType);
}

}  // namespace mozjs
}  // namespace script
}  // namespace cobalt

#endif  // COBALT_SCRIPT_MOZJS_45_UNION_TYPE_CONVERSION_IMPL_H_