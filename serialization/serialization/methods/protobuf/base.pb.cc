// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: base.proto

#include "base.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_base_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_base_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_Object_MapStringIntEntry_DoNotUse;
}  // namespace protobuf_base_2eproto
namespace protobuf_serialization {
class Object_MapStringIntEntry_DoNotUseDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Object_MapStringIntEntry_DoNotUse>
      _instance;
} _Object_MapStringIntEntry_DoNotUse_default_instance_;
class ObjectDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Object>
      _instance;
} _Object_default_instance_;
}  // namespace protobuf_serialization
namespace protobuf_base_2eproto {
static void InitDefaultsObject_MapStringIntEntry_DoNotUse() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protobuf_serialization::_Object_MapStringIntEntry_DoNotUse_default_instance_;
    new (ptr) ::protobuf_serialization::Object_MapStringIntEntry_DoNotUse();
  }
  ::protobuf_serialization::Object_MapStringIntEntry_DoNotUse::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Object_MapStringIntEntry_DoNotUse =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsObject_MapStringIntEntry_DoNotUse}, {}};

static void InitDefaultsObject() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protobuf_serialization::_Object_default_instance_;
    new (ptr) ::protobuf_serialization::Object();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protobuf_serialization::Object::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Object =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsObject}, {
      &protobuf_base_2eproto::scc_info_Object_MapStringIntEntry_DoNotUse.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Object_MapStringIntEntry_DoNotUse.base);
  ::google::protobuf::internal::InitSCC(&scc_info_Object.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object_MapStringIntEntry_DoNotUse, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object_MapStringIntEntry_DoNotUse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object_MapStringIntEntry_DoNotUse, key_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object_MapStringIntEntry_DoNotUse, value_),
  0,
  1,
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object, boolean_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object, floating_point_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object, integer_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object, str_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object, int_array_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protobuf_serialization::Object, map_string_int_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::protobuf_serialization::Object_MapStringIntEntry_DoNotUse)},
  { 9, -1, sizeof(::protobuf_serialization::Object)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::protobuf_serialization::_Object_MapStringIntEntry_DoNotUse_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::protobuf_serialization::_Object_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "base.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\nbase.proto\022\026protobuf_serialization\"\341\001\n"
      "\006Object\022\017\n\007boolean\030\001 \001(\010\022\026\n\016floating_poi"
      "nt\030\002 \001(\001\022\017\n\007integer\030\003 \001(\004\022\013\n\003str\030\004 \001(\t\022\021"
      "\n\tint_array\030\005 \003(\004\022H\n\016map_string_int\030\006 \003("
      "\01320.protobuf_serialization.Object.MapStr"
      "ingIntEntry\0323\n\021MapStringIntEntry\022\013\n\003key\030"
      "\001 \001(\t\022\r\n\005value\030\002 \001(\004:\0028\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 272);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "base.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_base_2eproto
namespace protobuf_serialization {

// ===================================================================

Object_MapStringIntEntry_DoNotUse::Object_MapStringIntEntry_DoNotUse() {}
Object_MapStringIntEntry_DoNotUse::Object_MapStringIntEntry_DoNotUse(::google::protobuf::Arena* arena) : SuperType(arena) {}
void Object_MapStringIntEntry_DoNotUse::MergeFrom(const Object_MapStringIntEntry_DoNotUse& other) {
  MergeFromInternal(other);
}
::google::protobuf::Metadata Object_MapStringIntEntry_DoNotUse::GetMetadata() const {
  ::protobuf_base_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_base_2eproto::file_level_metadata[0];
}
void Object_MapStringIntEntry_DoNotUse::MergeFrom(
    const ::google::protobuf::Message& other) {
  ::google::protobuf::Message::MergeFrom(other);
}


// ===================================================================

void Object::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Object::kBooleanFieldNumber;
const int Object::kFloatingPointFieldNumber;
const int Object::kIntegerFieldNumber;
const int Object::kStrFieldNumber;
const int Object::kIntArrayFieldNumber;
const int Object::kMapStringIntFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Object::Object()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_base_2eproto::scc_info_Object.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:protobuf_serialization.Object)
}
Object::Object(const Object& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      int_array_(from.int_array_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  map_string_int_.MergeFrom(from.map_string_int_);
  str_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.str().size() > 0) {
    str_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.str_);
  }
  ::memcpy(&floating_point_, &from.floating_point_,
    static_cast<size_t>(reinterpret_cast<char*>(&boolean_) -
    reinterpret_cast<char*>(&floating_point_)) + sizeof(boolean_));
  // @@protoc_insertion_point(copy_constructor:protobuf_serialization.Object)
}

void Object::SharedCtor() {
  str_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&floating_point_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&boolean_) -
      reinterpret_cast<char*>(&floating_point_)) + sizeof(boolean_));
}

Object::~Object() {
  // @@protoc_insertion_point(destructor:protobuf_serialization.Object)
  SharedDtor();
}

void Object::SharedDtor() {
  str_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Object::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Object::descriptor() {
  ::protobuf_base_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_base_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Object& Object::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_base_2eproto::scc_info_Object.base);
  return *internal_default_instance();
}


void Object::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf_serialization.Object)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  int_array_.Clear();
  map_string_int_.Clear();
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&floating_point_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&boolean_) -
      reinterpret_cast<char*>(&floating_point_)) + sizeof(boolean_));
  _internal_metadata_.Clear();
}

bool Object::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protobuf_serialization.Object)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // bool boolean = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &boolean_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double floating_point = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &floating_point_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint64 integer = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &integer_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string str = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_str()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->str().data(), static_cast<int>(this->str().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "protobuf_serialization.Object.str"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated uint64 int_array = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, this->mutable_int_array())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 1, 42u, input, this->mutable_int_array())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // map<string, uint64> map_string_int = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          Object_MapStringIntEntry_DoNotUse::Parser< ::google::protobuf::internal::MapField<
              Object_MapStringIntEntry_DoNotUse,
              ::std::string, ::google::protobuf::uint64,
              ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
              ::google::protobuf::internal::WireFormatLite::TYPE_UINT64,
              0 >,
            ::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 > > parser(&map_string_int_);
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
              input, &parser));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            parser.key().data(), static_cast<int>(parser.key().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "protobuf_serialization.Object.MapStringIntEntry.key"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protobuf_serialization.Object)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protobuf_serialization.Object)
  return false;
#undef DO_
}

void Object::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protobuf_serialization.Object)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool boolean = 1;
  if (this->boolean() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->boolean(), output);
  }

  // double floating_point = 2;
  if (this->floating_point() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->floating_point(), output);
  }

  // uint64 integer = 3;
  if (this->integer() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->integer(), output);
  }

  // string str = 4;
  if (this->str().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->str().data(), static_cast<int>(this->str().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protobuf_serialization.Object.str");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->str(), output);
  }

  // repeated uint64 int_array = 5;
  if (this->int_array_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(5, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _int_array_cached_byte_size_));
  }
  for (int i = 0, n = this->int_array_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64NoTag(
      this->int_array(i), output);
  }

  // map<string, uint64> map_string_int = 6;
  if (!this->map_string_int().empty()) {
    typedef ::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::const_pointer
        ConstPtr;
    typedef ConstPtr SortItem;
    typedef ::google::protobuf::internal::CompareByDerefFirst<SortItem> Less;
    struct Utf8Check {
      static void Check(ConstPtr p) {
        ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
          p->first.data(), static_cast<int>(p->first.length()),
          ::google::protobuf::internal::WireFormatLite::SERIALIZE,
          "protobuf_serialization.Object.MapStringIntEntry.key");
      }
    };

    if (output->IsSerializationDeterministic() &&
        this->map_string_int().size() > 1) {
      ::std::unique_ptr<SortItem[]> items(
          new SortItem[this->map_string_int().size()]);
      typedef ::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::size_type size_type;
      size_type n = 0;
      for (::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::const_iterator
          it = this->map_string_int().begin();
          it != this->map_string_int().end(); ++it, ++n) {
        items[static_cast<ptrdiff_t>(n)] = SortItem(&*it);
      }
      ::std::sort(&items[0], &items[static_cast<ptrdiff_t>(n)], Less());
      ::std::unique_ptr<Object_MapStringIntEntry_DoNotUse> entry;
      for (size_type i = 0; i < n; i++) {
        entry.reset(map_string_int_.NewEntryWrapper(
            items[static_cast<ptrdiff_t>(i)]->first, items[static_cast<ptrdiff_t>(i)]->second));
        ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
            6, *entry, output);
        Utf8Check::Check(items[static_cast<ptrdiff_t>(i)]);
      }
    } else {
      ::std::unique_ptr<Object_MapStringIntEntry_DoNotUse> entry;
      for (::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::const_iterator
          it = this->map_string_int().begin();
          it != this->map_string_int().end(); ++it) {
        entry.reset(map_string_int_.NewEntryWrapper(
            it->first, it->second));
        ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
            6, *entry, output);
        Utf8Check::Check(&*it);
      }
    }
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:protobuf_serialization.Object)
}

::google::protobuf::uint8* Object::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:protobuf_serialization.Object)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool boolean = 1;
  if (this->boolean() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->boolean(), target);
  }

  // double floating_point = 2;
  if (this->floating_point() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->floating_point(), target);
  }

  // uint64 integer = 3;
  if (this->integer() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->integer(), target);
  }

  // string str = 4;
  if (this->str().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->str().data(), static_cast<int>(this->str().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protobuf_serialization.Object.str");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->str(), target);
  }

  // repeated uint64 int_array = 5;
  if (this->int_array_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      5,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _int_array_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt64NoTagToArray(this->int_array_, target);
  }

  // map<string, uint64> map_string_int = 6;
  if (!this->map_string_int().empty()) {
    typedef ::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::const_pointer
        ConstPtr;
    typedef ConstPtr SortItem;
    typedef ::google::protobuf::internal::CompareByDerefFirst<SortItem> Less;
    struct Utf8Check {
      static void Check(ConstPtr p) {
        ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
          p->first.data(), static_cast<int>(p->first.length()),
          ::google::protobuf::internal::WireFormatLite::SERIALIZE,
          "protobuf_serialization.Object.MapStringIntEntry.key");
      }
    };

    if (deterministic &&
        this->map_string_int().size() > 1) {
      ::std::unique_ptr<SortItem[]> items(
          new SortItem[this->map_string_int().size()]);
      typedef ::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::size_type size_type;
      size_type n = 0;
      for (::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::const_iterator
          it = this->map_string_int().begin();
          it != this->map_string_int().end(); ++it, ++n) {
        items[static_cast<ptrdiff_t>(n)] = SortItem(&*it);
      }
      ::std::sort(&items[0], &items[static_cast<ptrdiff_t>(n)], Less());
      ::std::unique_ptr<Object_MapStringIntEntry_DoNotUse> entry;
      for (size_type i = 0; i < n; i++) {
        entry.reset(map_string_int_.NewEntryWrapper(
            items[static_cast<ptrdiff_t>(i)]->first, items[static_cast<ptrdiff_t>(i)]->second));
        target = ::google::protobuf::internal::WireFormatLite::
                   InternalWriteMessageNoVirtualToArray(
                       6, *entry, deterministic, target);
;
        Utf8Check::Check(items[static_cast<ptrdiff_t>(i)]);
      }
    } else {
      ::std::unique_ptr<Object_MapStringIntEntry_DoNotUse> entry;
      for (::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::const_iterator
          it = this->map_string_int().begin();
          it != this->map_string_int().end(); ++it) {
        entry.reset(map_string_int_.NewEntryWrapper(
            it->first, it->second));
        target = ::google::protobuf::internal::WireFormatLite::
                   InternalWriteMessageNoVirtualToArray(
                       6, *entry, deterministic, target);
;
        Utf8Check::Check(&*it);
      }
    }
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf_serialization.Object)
  return target;
}

size_t Object::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf_serialization.Object)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated uint64 int_array = 5;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      UInt64Size(this->int_array_);
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _int_array_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // map<string, uint64> map_string_int = 6;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->map_string_int_size());
  {
    ::std::unique_ptr<Object_MapStringIntEntry_DoNotUse> entry;
    for (::google::protobuf::Map< ::std::string, ::google::protobuf::uint64 >::const_iterator
        it = this->map_string_int().begin();
        it != this->map_string_int().end(); ++it) {
      entry.reset(map_string_int_.NewEntryWrapper(it->first, it->second));
      total_size += ::google::protobuf::internal::WireFormatLite::
          MessageSizeNoVirtual(*entry);
    }
  }

  // string str = 4;
  if (this->str().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->str());
  }

  // double floating_point = 2;
  if (this->floating_point() != 0) {
    total_size += 1 + 8;
  }

  // uint64 integer = 3;
  if (this->integer() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->integer());
  }

  // bool boolean = 1;
  if (this->boolean() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Object::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protobuf_serialization.Object)
  GOOGLE_DCHECK_NE(&from, this);
  const Object* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Object>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protobuf_serialization.Object)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protobuf_serialization.Object)
    MergeFrom(*source);
  }
}

void Object::MergeFrom(const Object& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf_serialization.Object)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  int_array_.MergeFrom(from.int_array_);
  map_string_int_.MergeFrom(from.map_string_int_);
  if (from.str().size() > 0) {

    str_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.str_);
  }
  if (from.floating_point() != 0) {
    set_floating_point(from.floating_point());
  }
  if (from.integer() != 0) {
    set_integer(from.integer());
  }
  if (from.boolean() != 0) {
    set_boolean(from.boolean());
  }
}

void Object::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protobuf_serialization.Object)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Object::CopyFrom(const Object& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf_serialization.Object)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Object::IsInitialized() const {
  return true;
}

void Object::Swap(Object* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Object::InternalSwap(Object* other) {
  using std::swap;
  int_array_.InternalSwap(&other->int_array_);
  map_string_int_.Swap(&other->map_string_int_);
  str_.Swap(&other->str_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(floating_point_, other->floating_point_);
  swap(integer_, other->integer_);
  swap(boolean_, other->boolean_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Object::GetMetadata() const {
  protobuf_base_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_base_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf_serialization
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::protobuf_serialization::Object_MapStringIntEntry_DoNotUse* Arena::CreateMaybeMessage< ::protobuf_serialization::Object_MapStringIntEntry_DoNotUse >(Arena* arena) {
  return Arena::CreateInternal< ::protobuf_serialization::Object_MapStringIntEntry_DoNotUse >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::protobuf_serialization::Object* Arena::CreateMaybeMessage< ::protobuf_serialization::Object >(Arena* arena) {
  return Arena::CreateInternal< ::protobuf_serialization::Object >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
