project "exsample"
      kind "ConsoleApp"
      language "C++"
      staticruntime "off"
      
      targetdir "bin/%{cfg.buildcfg}"
      objdir "bin-int/%{cfg.buildcfg}"
   
      files 
      { 
         "**.h", 
         "**.cpp" 
      }
      includedirs 
      {
      "%{prj.name}/vendor/",
      "%{wks.location}/Qm/src/"
      }
      links 
      {
      "Qm"
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