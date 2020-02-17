idf_component_register(
  SRCS  "main.cpp"
        "AC101.cpp"
        "u8g2_esp32_hal.cpp"
        "rotary_encoder.cpp"
        "heavy/Heavy_heavy.cpp"
        "heavy/HeavyContext.cpp"
        "heavy/HvHeavy.cpp"
        "heavy/HvLightPipe.c"
        "heavy/HvMessage.c"
        "heavy/HvMessagePool.c"
        "heavy/HvMessageQueue.c"
        "heavy/HvSignalDel1.c"
        "heavy/HvSignalLine.c"
        "heavy/HvSignalPhasor.c"
        "heavy/HvSignalRPole.c"
        "heavy/HvSignalSamphold.c"
        "heavy/HvSignalSample.c"
        "heavy/HvSignalVar.c"
        "heavy/HvSignalLine.c"
        "heavy/HvSignalTabread.c"
        "heavy/HvSignalTabwrite.c"
        "heavy/HvTable.c"
        "heavy/HvUtils.c"
        "heavy/HvControlBinop.c"
        "heavy/HvControlVar.c"
        "heavy/HvControlCast.c"
        "heavy/HvControlDelay.c"
        "heavy/HvControlSystem.c"
        "heavy/HvControlVar.c"
        "heavy/HvControlIf.c"
        "heavy/HvControlPack.c"
        "heavy/HvControlRandom.c"
        "heavy/HvControlTabread.c"
        #"heavy/HvControlPrint.c"
        "heavy/HvControlSlice.c"
        "heavy/HvControlUnop.c"
  INCLUDE_DIRS "heavy/")

set_source_files_properties("heavy/HvHeavy.cpp"
      PROPERTIES COMPILE_FLAGS
      -Wno-unknown-pragmas
  )

add_definitions("-ffast-math -DHV_SIMD_NONE")
#add_definitions("-ffast-math -DNDEBUG -DHV_SIMD_NONE")
