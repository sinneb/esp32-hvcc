idf_component_register(
  SRCS  "main.cpp"
        "AC101.cpp"
        "heavy/Heavy_heavy.cpp"
        "heavy/HeavyContext.cpp"
        "heavy/HvHeavy.cpp"
        "heavy/HvLightPipe.c"
        "heavy/HvMessage.c"
        "heavy/HvMessagePool.c"
        "heavy/HvMessageQueue.c"
        "heavy/HvSignalPhasor.c"
        "heavy/HvSignalSample.c"
        "heavy/HvSignalVar.c"
        "heavy/HvTable.c"
        "heavy/HvUtils.c"
        "heavy/HvControlBinop.c"
        "heavy/HvControlVar.c"
        "heavy/HvControlCast.c"
        "heavy/HvControlDelay.c"
        "heavy/HvControlSystem.c"
        "heavy/HvControlVar.c"
  INCLUDE_DIRS "heavy/")

set_source_files_properties("heavy/HvHeavy.cpp"
      PROPERTIES COMPILE_FLAGS
      -Wno-unknown-pragmas
  )
