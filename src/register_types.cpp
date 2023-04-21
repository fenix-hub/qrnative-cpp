#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "QRNative.h"
#include "QRDecodeResult.h"

using namespace godot;

void initialize_qrnative(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<QRDecodeResult>();
        ClassDB::register_class<QRNative>();

        UtilityFunctions::print("QRNative lib initialized.");
    }
}

void uninitialize_qrnative(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
	}
}

extern "C"
{
    GDExtensionBool GDE_EXPORT qrnative_init(const GDExtensionInterface *p_interface, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

		init_obj.register_initializer(initialize_qrnative);
		init_obj.register_terminator(uninitialize_qrnative);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}