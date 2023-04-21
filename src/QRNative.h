#ifndef QRNATIVE_H
#define QRNATIVE_H

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

namespace godot {

    class QRNative : public RefCounted {
        GDCLASS(QRNative, RefCounted);

    protected:
        static void _bind_methods();

    public:
        QRNative();
        ~QRNative();

        static QRDecodeResult* decode_bytes(PackedByteArray image_data, int image_width, int image_height);
        static QRDecodeResult* decode_image(const Ref<godot::Image> image);
        static Ref<godot::Image> encode_string(const String &content, int image_width, int image_height, int margin);
        static Ref<godot::Image> encode_bytes(PackedByteArray content, int image_width, int image_height, int margin);
    };
}

#endif