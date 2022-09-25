extends Control


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
    # Decoding
    var qr: Image = Image.load_from_file("res://qrcode.png")
    var qr_decode_result: QRDecodeResult = QRNative.decode_image(qr)
    if qr_decode_result.is_valid():
        print(qr_decode_result.get_content())
    
    # Encoding
    var qr_content: String = "This is the content of my QR Code!"
    var qr_code: Image = QRNative.encode_string(qr_content, 100, 100, 5)
    $QRCode.set_texture(ImageTexture.create_from_image(qr_code))
