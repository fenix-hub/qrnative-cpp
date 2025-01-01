extends Control


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
    # Decoding
    var img: Image = load("res://qrcode.png")
    var qr_decode_result: QRDecodeResult = QRNative.decode_image(img)
    $Box/Decoding/QRCode.set_texture(ImageTexture.create_from_image(img))
    if qr_decode_result.is_valid():
        $Box/Decoding/text.set_text(qr_decode_result.get_content())

    # Encoding
    var qr_content: String = "This is the content of my QR Code!"
    $Box/Encoding/text.set_text(qr_content)
    var qr_code: Image = QRNative.encode_string(qr_content, 100, 100, 5)
    $Box/Encoding/QRCode.set_texture(ImageTexture.create_from_image(qr_code))
#    pass


func _on_line_edit_text_changed(new_text: String) -> void:
    $Box/Realtime/QRCode.set_texture(
        ImageTexture.create_from_image(
            QRNative.encode_string(new_text, 100, 100, 5)
        )
    )
