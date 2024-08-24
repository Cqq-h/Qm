project "Qm"
      kind "StaticLib"
      language "C++"
      staticruntime "off"
      
      targetdir "bin/%{cfg.buildcfg}"
      objdir "bin-int/%{cfg.buildcfg}"
   
      files 
      { 
         "src/**.h", 
         "src/**.cpp" 
      }

      filter "system:windows"
         cppdialect "C++20"
         systemversion "latest"
         
      filter "configurations:Debug"
         defines { "DEBUG" }
         symbols "On"
   
      filter "configurations:Release"
         defines { "NDEBUG" }
         optimize "On"