
uint __thiscall FUN_0053c06c(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_1 | param_2;
  if ((((uVar1 & 0x10) != 0) && (uVar1 != 0x10)) || (((uVar1 & 0x20) != 0 && (uVar1 != 0x20)))) {
    return uVar1 & 0xffffff00;
  }
  uVar1 = param_1[10];
  if ((uVar1 & 0xf) == 0) {
LAB_0053c0bf:
    uVar1 = CONCAT31((int3)(uVar1 >> 8),1);
  }
  else {
    if ((param_1[9] != 0) && (iVar2 = 4 - param_1[9], iVar2 != 0)) {
      param_2 = *(uint *)(&DAT_006f4620 + (iVar2 * 0x40 + param_2) * 4);
    }
    if (param_2 == 1) {
      uVar1 = ~uVar1 >> 2;
    }
    else if (param_2 == 2) {
      uVar1 = ~uVar1 >> 3;
    }
    else if (param_2 == 4) {
      uVar1 = ~uVar1 >> 1;
    }
    else {
      if (param_2 != 8) goto LAB_0053c0bf;
      uVar1 = ~uVar1;
    }
    uVar1 = uVar1 & 1;
  }
  return uVar1;
}

