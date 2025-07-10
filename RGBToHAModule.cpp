/*
 * RGB to HA Conversion Module for PixInsight
 * Module registration and initialization
 */

#include <pcl/Module.h>
#include <pcl/ProcessImplementation.h>
#include <pcl/ProcessInterface.h>
#include <pcl/Console.h>
#include <pcl/Exception.h>

#include "RGBToHAProcess.cpp"
#include "RGBToHAInterface.cpp"

namespace pcl
{

// Module metadata
class RGBToHAModule : public Module
{
public:

   virtual String Name() const
   {
      return "RGB to HA Conversion";
   }

   virtual String Version() const
   {
      return "1.0.0";
   }

   virtual String Company() const
   {
      return "Connor";
   }

   virtual String Author() const
   {
      return "Connor";
   }

   virtual String Description() const
   {
      return "Advanced RGB to Hydrogen Alpha (HA) conversion with multiple algorithms and enhancement options.";
   }

   virtual String Copyright() const
   {
      return "Copyright (c) 2024 Connor";
   }

   virtual String TradeMarks() const
   {
      return "RGB to HA Conversion";
   }

   virtual String OriginalFileName() const
   {
      return "RGBToHA-pxm.dll";
   }

   virtual void GetReleaseDate( int& year, int& month, int& day ) const
   {
      year = 2024;
      month = 12;
      day = 1;
   }

   // Module initialization
   virtual bool Initialize()
   {
      try
      {
         Console().WriteLn( "<end><cbr>Initializing RGB to HA Conversion Module..." );

         // Register the process
         TheRGBToHAProcess = new RGBToHAProcess();
         ProcessRegistry::Register( TheRGBToHAProcess );

         // Register the interface
         TheRGBToHAInterface = new RGBToHAInterface();
         InterfaceRegistry::Register( TheRGBToHAInterface );

         Console().WriteLn( "RGB to HA Conversion Module initialized successfully." );
         return true;
      }
      catch ( ... )
      {
         Console().WriteLn( "Failed to initialize RGB to HA Conversion Module." );
         return false;
      }
   }

   // Module cleanup
   virtual void Deinitialize()
   {
      try
      {
         Console().WriteLn( "<end><cbr>Deinitializing RGB to HA Conversion Module..." );

         // Unregister the interface
         if ( TheRGBToHAInterface != nullptr )
         {
            InterfaceRegistry::Unregister( TheRGBToHAInterface );
            delete TheRGBToHAInterface;
            TheRGBToHAInterface = nullptr;
         }

         // Unregister the process
         if ( TheRGBToHAProcess != nullptr )
         {
            ProcessRegistry::Unregister( TheRGBToHAProcess );
            delete TheRGBToHAProcess;
            TheRGBToHAProcess = nullptr;
         }

         Console().WriteLn( "RGB to HA Conversion Module deinitialized successfully." );
      }
      catch ( ... )
      {
         Console().WriteLn( "Failed to deinitialize RGB to HA Conversion Module." );
      }
   }

private:

   // Global process and interface instances
   static RGBToHAProcess* TheRGBToHAProcess;
   static RGBToHAInterface* TheRGBToHAInterface;
};

// Static member initialization
RGBToHAProcess* RGBToHAModule::TheRGBToHAProcess = nullptr;
RGBToHAInterface* RGBToHAModule::TheRGBToHAInterface = nullptr;

// Module instance
static RGBToHAModule* s_module = nullptr;

// Module entry point
extern "C" PCL_MODULE_EXPORT int InstallPixInsightModule( int mode )
{
   if ( mode == InstallPixInsightModule::Install )
   {
      if ( s_module == nullptr )
      {
         s_module = new RGBToHAModule();
         ModuleRegistry::Register( s_module );
      }
      return 0;
   }
   else if ( mode == InstallPixInsightModule::Uninstall )
   {
      if ( s_module != nullptr )
      {
         ModuleRegistry::Unregister( s_module );
         delete s_module;
         s_module = nullptr;
      }
      return 0;
   }
   return -1;
}

} // pcl 