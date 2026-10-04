
bool FUN_005dac30(uint param_1,WPARAM param_2,LPARAM param_3)

{
  BOOL BVar1;
  UINT Msg;
  
  if (param_1 < 0xd) {
    if (param_1 == 0xc) {
      Msg = 0x205;
      goto LAB_005dacf2;
    }
    if (param_1 < 7) {
      if (param_1 == 6) {
        Msg = 0x101;
        goto LAB_005dacf2;
      }
      if (param_1 == 1) {
        Msg = 0x600;
        goto LAB_005dacf2;
      }
      if (param_1 == 2) {
        Msg = 0x601;
        goto LAB_005dacf2;
      }
      if (param_1 == 3) {
        Msg = 0x500;
        goto LAB_005dacf2;
      }
      if (param_1 == 5) {
        Msg = 0x100;
        goto LAB_005dacf2;
      }
    }
    else {
      if (param_1 == 7) {
        Msg = 0x201;
        goto LAB_005dacf2;
      }
      if (param_1 == 8) {
        Msg = 0x204;
        goto LAB_005dacf2;
      }
      if (param_1 == 0xb) {
        Msg = 0x202;
        goto LAB_005dacf2;
      }
    }
  }
  else {
    if (param_1 == 0xd) {
      Msg = 0x200;
      goto LAB_005dacf2;
    }
    if (param_1 == 0xf) {
      Msg = 0xa0;
      goto LAB_005dacf2;
    }
    if (param_1 == 0x10) {
      Msg = 0x700;
      goto LAB_005dacf2;
    }
    if (param_1 == 0x11) {
      Msg = 0x800;
      goto LAB_005dacf2;
    }
    if (param_1 == 0x12) {
      Msg = 0x801;
      goto LAB_005dacf2;
    }
    if (param_1 == 0x13) {
      Msg = 0x802;
      goto LAB_005dacf2;
    }
    if (param_1 == 0x17) {
      Msg = 0x900;
      goto LAB_005dacf2;
    }
  }
  Msg = 0;
LAB_005dacf2:
  (**(code **)(*DAT_006fe8bc + 0x1c))();
  BVar1 = PostMessageA(DAT_006fe8cc,Msg,param_2,param_3);
  return BVar1 != 0;
}

