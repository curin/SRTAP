#include <DynamicOutput/Output.hpp>
#include <Mod/CppUserModBase.hpp>
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UObject.hpp>

namespace SRTAP
{
    using namespace RC;
    using namespace Unreal;
    
    /**
    * MyExampleMod: UE4SS c++ mod class defintion
    */
    class SpyroRTAPMod : public RC::CppUserModBase {
    public:
        
        // constructor
        SpyroRTAPMod() {
            ModVersion = STR("0.1");
            ModName = STR("SRTAP");
            ModAuthors = STR("UE4SS, Curin");
            ModDescription = STR("adds archipelago support to Spyro: Reignited Trilogy");
            // Do not change this unless you want to target a UE4SS version
            // other than the one you're currently building with somehow.
            //ModIntendedSDKVersion = STR("2.6");
            
            Output::send<LogLevel::Warning>(STR("[SpyroRTAPMod]: Init.\n"));
        }
        
        // destructor
        ~SpyroRTAPMod() override {
            // fill when required
        }

        auto on_program_start() -> void override
        {
        }

        auto on_dll_load(std::wstring_view dll_name) -> void override
        {
        }

        auto on_unreal_init() -> void override
        {
            // You are allowed to use the 'Unreal' namespace in this function and anywhere else after this function has fired.
            auto Object = UObjectGlobals::StaticFindObject<UObject*>(nullptr, nullptr, STR("/Script/CoreUObject.Object"));
            Output::send<LogLevel::Verbose>(STR("Object Name: {}\n"), Object->GetFullName());
        }

    };//class
}

/**
* export the start_mod() and uninstall_mod() functions to
* be used by the core ue4ss system to load in our dll mod
*/
#define SpyroRTAPMod_EXPORT __declspec(dllexport) 
extern "C" {
    SpyroRTAPMod_EXPORT RC::CppUserModBase* start_mod(){ return new SRTAP::SpyroRTAPMod(); }
    SpyroRTAPMod_EXPORT void uninstall_mod(RC::CppUserModBase* mod) { delete mod; }
}
    




