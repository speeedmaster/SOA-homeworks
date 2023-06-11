#pragma once

#include <boost/archive/basic_archive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>

#include <serialization/methods/base.hpp>
#include <serialization/objects/base.hpp>


namespace serialization {

 struct XMLObject : public BaseObject {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
      ar &BOOST_SERIALIZATION_NVP(boolean);
      ar &BOOST_SERIALIZATION_NVP(floating_point);
      ar &BOOST_SERIALIZATION_NVP(integer);
      ar &BOOST_SERIALIZATION_NVP(str);
      ar &BOOST_SERIALIZATION_NVP(int_array);
      ar &BOOST_SERIALIZATION_NVP(map_string_int);
    }
 };

class XMLSerialization : public SerializationMethodBase {
 public:
  XMLSerialization() {
    object_.FillWithDefault();
  }

  ~XMLSerialization() = default;

  uint64_t GetSerializedObjectSize() override {
    Serialize();
    return data_.size();
  }

  void Serialize() override {
    std::stringstream ss;
    boost::archive::xml_oarchive o_xml(ss, boost::archive::no_header);

    o_xml << BOOST_SERIALIZATION_NVP(object_);

    data_ = ss.str();
  }

  void Deserialize() override {
    std::stringstream ss(data_);
    boost::archive::xml_iarchive i_xml(ss, boost::archive::no_header);

    i_xml >> BOOST_SERIALIZATION_NVP(object_);
  }

  uint64_t GetRunsCount() override {
    return 1000;
  }

  std::string GetMethodNameForResponce() override { return "xml     "; };

private:
  XMLObject object_;
  std::string data_;
};

} // namespace serialization
