#include "QRDecodeResult.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


void QRDecodeResult::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_content", "content"), &QRDecodeResult::set_content);
    ClassDB::bind_method(D_METHOD("get_content"), &QRDecodeResult::get_content);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "content"), "set_content", "get_content");

    ClassDB::bind_method(D_METHOD("set_valid", "valid"), &QRDecodeResult::set_valid);
    ClassDB::bind_method(D_METHOD("is_valid"), &QRDecodeResult::is_valid);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "valid"), "set_valid", "is_valid");

}

void QRDecodeResult::_init()
{
    valid = false;
    content = "";
}

QRDecodeResult::QRDecodeResult() {
    valid = false;
    content = "";
}

QRDecodeResult::QRDecodeResult(bool p_valid, String p_content)
{
    valid = p_valid;
    content = p_content;
}

QRDecodeResult::~QRDecodeResult()
{
}

void QRDecodeResult::set_valid(bool p_valid)
{
    valid = p_valid;
}

bool QRDecodeResult::is_valid()
{
    return valid;
}

void QRDecodeResult::set_content(String p_content)
{
    content = p_content;
}

String QRDecodeResult::get_content()
{
    return content;
}