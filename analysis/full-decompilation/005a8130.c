
uint FUN_005a8130(uint param_1,int param_2,int param_3,int param_4)

{
  if (DAT_006d2008 != param_1) {
    if (DAT_006f76e4 == 0) {
      param_1 = param_1 & 0xfffffffb;
    }
    if (DAT_006f76e8 == 0) {
      param_1 = param_1 & 0xfffffffd;
    }
    if (DAT_006f76ec == 0) {
      param_1 = param_1 & 0xfffeffff;
    }
    if (DAT_006d200c == 0) {
      DAT_006d200c = 0xc;
    }
    if (DAT_006d2010 == 0) {
      DAT_006d2010 = 0x20;
    }
    if ((DAT_006f76f4 == 0) || (DAT_006f76f8 == 0)) {
      param_1 = param_1 & 0xfffdffff;
    }
    if (((param_1 & 0x30000) == 0x30000) && (DAT_006f76fc == 0)) {
      param_1 = param_1 & 0xfffdffff;
    }
    if (((param_1 & 1) != 0) && ((param_1 & 0x20000) != 0)) {
      param_1 = param_1 & 0xfffdffff;
    }
    if (DAT_006f7700 == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
    DAT_006f76f0 = param_1 & 0x10000000;
    DAT_006f76cc = *(code **)(&DAT_006d2018 + (param_1 & 0x1f) * 4);
    DAT_006d2008 = param_1;
    if ((param_1 & 0x30000) == 0) {
      DAT_006f76bc = (code *)0x0;
    }
    else {
      DAT_006f76bc = *(code **)(&DAT_006d2098 + (param_1 >> 0xf & 7 | param_1 & 1) * 4);
    }
  }
  if (((0 < param_2) && (param_3 != 0)) && (param_4 != 0)) {
    if (DAT_006f76cc != (code *)0x0) {
      DAT_006f76d0 = DAT_006f7700;
      DAT_006f76d4 = DAT_006f7704;
      DAT_006f76d8 = param_3;
      DAT_006f76c8 = param_4;
      (*DAT_006f76cc)(param_2,param_3,param_4);
    }
    if (DAT_006f76bc != (code *)0x0) {
      (*DAT_006f76bc)(param_2,param_4);
    }
    return param_1;
  }
  return 0;
}

