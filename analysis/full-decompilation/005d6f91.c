
undefined4 FUN_005d6f91(uint param_1)

{
  if (param_1 < 0x205) {
    if (param_1 == 0x204) {
      return 8;
    }
    if (param_1 < 0x105) {
      if (param_1 != 0x104) {
        if (param_1 == 0xa0) {
          return 0xf;
        }
        if (param_1 != 0x100) {
          if (param_1 == 0x101) {
            return 6;
          }
          if (param_1 != 0x102) {
            return 0;
          }
          return 4;
        }
      }
      return 5;
    }
    if (param_1 == 0x105) {
      return 6;
    }
    if (param_1 == 0x200) {
      return 0xd;
    }
    if (param_1 == 0x201) {
      return 7;
    }
    if (param_1 == 0x202) {
      return 0xb;
    }
  }
  else if (param_1 < 0x701) {
    if (param_1 == 0x700) {
      return 0x10;
    }
    if (param_1 == 0x205) {
      return 0xc;
    }
    if (param_1 == 0x500) {
      return 3;
    }
    if (param_1 == 0x600) {
      return 1;
    }
    if (param_1 == 0x601) {
      return 2;
    }
  }
  else {
    if (param_1 == 0x800) {
      return 0x11;
    }
    if (param_1 == 0x801) {
      return 0x12;
    }
    if (param_1 == 0x802) {
      return 0x13;
    }
    if (param_1 == 0x900) {
      return 0x17;
    }
  }
  return 0;
}

