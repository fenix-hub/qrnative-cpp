# QRNative

///

## Contributing
If you can't compile the extension, please open an issue with the error log in your terminal and/or the error log in the editor (if you can't run the example scene).

PRs for improvements are very welcome!

## Getting started / Building the extension

### VSCode Compilation (only applicable if you are using VSCode as your code editor)
For the initial build you can run the vscode task `initial-build-extension`. This compiles both godot-cpp and the extension. For all subsequent builds, you only need to run the task `build-extension`.

### Manual Compilation

To compile the extension you need to follow these steps:

0. Click on the green "Use this template" button to generate the repository for you

1. Clone the extension recursively from this repository
```bash
# --recursive to automatically load the submodule godot-cpp
# The git adress can be found under the green "Code" dropdown menu
git clone --recursive (--GITHUB ADRESS--)
```

2. Make sure you are in the top level of the repository
```bash
pwd
.../qrnative
```

3. Go inside the godot-cpp folder
```bash
cd godot-cpp
```

4. Compile godot-cpp and generate bindings (only need to do this once when starting development or when there is an update of the submodule)
```bash
scons target=debug generate_bindings=yes
```

5. Go back to the top level of the directory
```bash
cd ..
```

6. Compile the extension
```bash
scons target=debug
```

## Using the extension
After compiling the extension succesfully, you can now use the `QRNative` class inside Godot :tada:
```gdscript
func _ready() -> void:
	# Decoding
	var qr_code: Image = load("res://qrcode.png")
	var qr_decode_result: QRDecodeResult = QRNative.decode_image(qr_code)
	if qr_decode_result.is_valid():
		print(qr_decode_result.get_content())
	
	# Encoding
	var qr_content: String = "This is the content of my QR Code!"
	var qr_code_en: Image = QRNative.encode_string(qr_content, 100, 100, 10)
	$QRCode.set_texture(ImageTexture.create_from_image(qr_code_en))
```

