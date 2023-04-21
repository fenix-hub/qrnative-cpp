#include "QRNative.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;
using namespace ZXing;

DecodeHints hints;

void QRNative::_bind_methods()
{
    ClassDB::bind_static_method("QRNative", D_METHOD("decode_bytes", "image_data", "image_width", "image_height"), &QRNative::decode_bytes);
    ClassDB::bind_static_method("QRNative", D_METHOD("decode_image", "image"), &QRNative::decode_image);
    ClassDB::bind_static_method("QRNative", D_METHOD("encode_bytes", "content", "image_width", "image_height", "margin"), &QRNative::encode_bytes);
    ClassDB::bind_static_method("QRNative", D_METHOD("encode_string", "content", "image_width", "image_height", "margin"), &QRNative::encode_string);
}

QRNative::QRNative()
{
    hints.setFormats({BarcodeFormat::QRCode});
}

QRNative::~QRNative()
{
}

QRDecodeResult* QRNative::decode_bytes(godot::PackedByteArray image_data, int image_width, int image_height)
{
    // Create ImageView
    ImageView image{image_data.ptr(), image_width, image_height, ImageFormat::RGB};

    // Read QR Code
    Result result = ReadBarcode(image, hints);

    // Return a QRDecodeResult
    Ref<QRDecodeResult> decode_result;
    decode_result.instantiate();
    decode_result->set_valid(result.isValid());
    decode_result->set_content(String(result.text().c_str()));
    return (QRDecodeResult *)memnew(QRDecodeResult(decode_result->is_valid(), decode_result->get_content()));
}

QRDecodeResult* QRNative::decode_image(const Ref<godot::Image> image)
{
    Ref<godot::Image> d_img = image->duplicate();

    // Always convert to FORMAT_RGB8
    d_img->convert(godot::Image::FORMAT_RGB8);
    return decode_bytes(d_img->get_data(), d_img->get_width(), d_img->get_height());
}

Ref<godot::Image> QRNative::encode_string(const String &content, int image_width, int image_height, int margin)
{
    ZXing::QRCode::Writer writer = ZXing::QRCode::Writer();
    writer.setEncoding(CharacterSet::UTF8).setMargin(margin);
    Matrix matrix = ToMatrix<uint8_t>(
        writer.encode(std::wstring(content.wide_string().get_data()), image_width, image_height)
    );

    Ref<godot::Image> image = godot::Image::create(matrix.width(), matrix.height(), false, godot::Image::FORMAT_RGB8);

    for (int i = 0; i < matrix.width(); i++)
    {
        for (int j = 0; j < matrix.height(); j++)
        {
            float value = matrix.get(i, j) * 255.0f;
            image->set_pixel(i, j, Color(value, value, value));
        }
    }

    return image;
}

Ref<godot::Image> QRNative::encode_bytes(PackedByteArray content, int image_width, int image_height, int margin)
{
    return encode_string(content.get_string_from_utf8(), image_width, image_height, margin);
}