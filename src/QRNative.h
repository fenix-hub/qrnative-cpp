#ifndef QRRADER_H
#define QRRADER_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/image.hpp>

#include "zxing-cpp/core/src/ReadBarcode.h"
#include "zxing-cpp/core/src/Result.h"
#include "zxing-cpp/core/src/qrcode/QRWriter.h"
#include "zxing-cpp/core/src/BitMatrix.h"
#include "zxing-cpp/core/src/CharacterSet.h"
#include "zxing-cpp/core/src/TextUtfEncoding.h"

#include "QRDecodeResult.h"

using namespace godot;

class QRNative : public Object
{
    GDCLASS(QRNative, Object);

    static QRNative *singleton;

protected:
    static void _bind_methods();

public:
    static QRNative *get_singleton();

    QRNative();
    ~QRNative();

    QRDecodeResult* decode_bytes(PackedByteArray image_data, int image_width, int image_height);
    QRDecodeResult* decode_image(Ref<godot::Image> image);

    Ref<godot::Image> encode_string(const String &content, int image_width, int image_height, int margin);
    Ref<godot::Image> encode_bytes(PackedByteArray content, int image_width, int image_height, int margin);
};

#endif // QRRADER_H