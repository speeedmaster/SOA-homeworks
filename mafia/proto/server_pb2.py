# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/server.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x12proto/server.proto\"Q\n\x0fRegisterRequest\x12\x10\n\x08username\x18\x01 \x01(\t\x12\x10\n\x08hostname\x18\x02 \x01(\t\x12\x0c\n\x04port\x18\x03 \x01(\x05\x12\x0c\n\x04uuid\x18\x04 \x01(\t\"F\n\x10RegisterResponse\x12\x10\n\x08username\x18\x01 \x01(\t\x12\x12\n\nsession_id\x18\x02 \x01(\x05\x12\x0c\n\x04role\x18\x03 \x01(\t\"W\n\x12UserMessageRequest\x12\x0c\n\x04uuid\x18\x01 \x01(\t\x12\x12\n\nsession_id\x18\x02 \x01(\x05\x12\x0f\n\x07message\x18\x03 \x01(\t\x12\x0e\n\x06secret\x18\x04 \x01(\x08\"\x15\n\x13UserMessageResponse2w\n\x06Server\x12\x31\n\x08Register\x12\x10.RegisterRequest\x1a\x11.RegisterResponse\"\x00\x12:\n\x0bUserMessage\x12\x13.UserMessageRequest\x1a\x14.UserMessageResponse\"\x00\x62\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'proto.server_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _REGISTERREQUEST._serialized_start=22
  _REGISTERREQUEST._serialized_end=103
  _REGISTERRESPONSE._serialized_start=105
  _REGISTERRESPONSE._serialized_end=175
  _USERMESSAGEREQUEST._serialized_start=177
  _USERMESSAGEREQUEST._serialized_end=264
  _USERMESSAGERESPONSE._serialized_start=266
  _USERMESSAGERESPONSE._serialized_end=287
  _SERVER._serialized_start=289
  _SERVER._serialized_end=408
# @@protoc_insertion_point(module_scope)