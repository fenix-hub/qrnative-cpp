#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

#include "QRNative.h"
#include "QRDecodeResult.h"

using namespace godot;

static QRNative *_qrnative_singleton;

void initialize_qrnative(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		
		ClassDB::register_class<QRDecodeResult>();
		ClassDB::register_class<QRNative>();

		_qrnative_singleton = memnew(QRNative);
		Engine::get_singleton()->register_singleton("QRNative", QRNative::get_singleton());
		
	}

}

void uninitialize_qrnative(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		Engine::get_singleton()->unregister_singleton("QRNative");
		memdelete(_qrnative_singleton);
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