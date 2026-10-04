
undefined4 * __thiscall FUN_00609062(undefined4 *param_1,uint param_2)

{
  char cVar1;
  void *pvVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 local_110 [260];
  int local_c;
  char *local_8;
  
  local_c = 0;
  if (param_2 == 0) {
    param_2 = 0x34860;
    local_8 = s_font12j_fon_006d9878;
    *param_1 = 0xc;
    param_1[2] = 6;
    param_1[3] = 0xc;
    param_1[4] = 0;
    param_1[5] = 0xc;
    param_1[6] = 0xc;
    param_1[7] = 1;
    param_1[8] = 0xc;
    param_1[9] = 0x18;
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 2) {
        param_2 = 0x6dd80;
        local_8 = s_font16b5_fon_006d9578;
        *param_1 = 0x10;
        param_1[2] = 8;
        param_1[3] = 0x10;
        param_1[4] = 0;
        param_1[5] = 0x10;
        param_1[6] = 0x10;
        param_1[7] = 1;
        param_1[8] = 0x10;
        param_1[9] = 0x20;
        param_1[10] = 0x366c;
      }
      else if (param_2 == 3) {
        param_2 = 0x43f20;
        local_8 = s_font16gb_fon_006d9568;
        *param_1 = 0x10;
        param_1[2] = 8;
        param_1[3] = 0x10;
        param_1[4] = 0;
        param_1[5] = 0x10;
        param_1[6] = 0x10;
        param_1[7] = 1;
        param_1[8] = 0x10;
        param_1[9] = 0x20;
        param_1[10] = 0x2179;
      }
      else if (param_2 == 4) {
        param_2 = 0x2800;
        local_8 = s_font20th_fon_006d9588;
        *param_1 = 0x14;
        param_1[3] = 0x14;
        param_1[2] = 0xc;
        param_1[5] = 0xc;
        param_1[4] = 1;
        param_1[6] = 0x14;
        param_1[7] = 1;
        param_1[8] = 0x28;
        param_1[9] = 0x28;
        param_1[10] = 0;
      }
      else {
        if (param_2 == 5) {
          param_2 = 0xfaac;
          local_8 = s_font12k_fon_006d98a0;
          *param_1 = 0xc;
          param_1[2] = 6;
          param_1[3] = 0xc;
          param_1[4] = 0;
          param_1[5] = 0xc;
          param_1[6] = 0xd;
          param_1[7] = 1;
          param_1[8] = 0xc;
          param_1[9] = 0x1a;
        }
        else {
          if (param_2 != 6) {
            *param_1 = 0;
            param_1[1] = 0;
            return param_1;
          }
          param_2 = 0x135c0;
          local_8 = s_font16k_fon_006d98ac;
          *param_1 = 0x10;
          param_1[2] = 8;
          param_1[3] = 0x10;
          param_1[4] = 0;
          param_1[5] = 0x10;
          param_1[6] = 0x10;
          param_1[7] = 1;
          param_1[8] = 0x10;
          param_1[9] = 0x20;
        }
        param_1[10] = 0xa2e;
      }
      goto LAB_0060925c;
    }
    param_2 = 0x46080;
    local_8 = s_font16j_fon_006d9884;
    *param_1 = 0x10;
    param_1[2] = 8;
    param_1[3] = 0x10;
    param_1[4] = 0;
    param_1[5] = 0x10;
    param_1[6] = 0x10;
    param_1[7] = 1;
    param_1[8] = 0x10;
    param_1[9] = 0x20;
  }
  param_1[10] = 0x2284;
LAB_0060925c:
  param_1[0xb] = 1;
  param_1[0xc] = 1;
  pvVar2 = operator_new(param_2);
  param_1[1] = pvVar2;
  if (pvVar2 != (void *)0x0) {
    FUN_006358b0(local_110,&DAT_006ff2f4);
    FUN_006358c0(local_110,local_8);
    puVar3 = local_110;
    uVar4 = 0;
    FUN_005b8e25(puVar3,0);
    local_8 = (char *)FUN_005b936f(puVar3,uVar4);
    if (local_8 != (char *)0x0) {
      cVar1 = FUN_005b904f(param_1[1],param_2);
      if (cVar1 != '\0') {
        local_c = 1;
      }
      pcVar5 = local_8;
      FUN_005b8e25(local_8);
      FUN_005b95c0(pcVar5);
      if (local_c != 0) {
        return param_1;
      }
    }
  }
  if (param_1[1] != 0) {
    FUN_006321f0(param_1[1]);
    param_1[1] = 0;
  }
  *param_1 = 0;
  return param_1;
}

