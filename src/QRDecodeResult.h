#ifndef QRDECODERESULT_H
#define QRDECODERESULT_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref.hpp>

namespace godot {

    class QRDecodeResult : public RefCounted {
        GDCLASS(QRDecodeResult, RefCounted);

    protected:
        void _init();
        static void _bind_methods();

    private:
        bool valid;
        String content;

    public:
        QRDecodeResult();
        QRDecodeResult(bool valid, String content);
        ~QRDecodeResult();

        void set_valid(bool valid);
        bool is_valid();
        void set_content(String content);
        String get_content();
    };

}

#endif