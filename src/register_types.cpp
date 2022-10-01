#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/godot.hpp>

#include "QRNative.h"
#include "QRDecodeResult.h"

using namespace godot;

static QRNative *_qrnative_singleton;

void qrnative_initialize(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		
		ClassDB::register_class<QRDecodeResult>();
		ClassDB::register_class<QRNative>();

		_qrnative_singleton = memnew(QRNative);
		Engine::get_singleton()->register_singleton("QRNative", QRNative::get_singleton());
		
	}

}

void qrnative_terminate(ModuleInitializationLevel p_level) 
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		Engine::get_singleton()->unregister_singleton("QRNative");
		memdelete(_qrnative_singleton);
	}
}

extern "C"
{

	// Initialization.

	GDNativeBool GDN_EXPORT qrnative_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

		init_obj.register_initializer(qrnative_initialize);
		init_obj.register_terminator(qrnative_terminate);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}