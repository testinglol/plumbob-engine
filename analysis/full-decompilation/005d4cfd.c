
uint __thiscall FUN_005d4cfd(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_1[1] - *param_1;
  if (uVar1 < param_3) {
    uVar1 = uVar1 & 0xffffff00;
  }
  else {
    uVar1 = 0;
    if (param_3 != 0) {
      do {
        if (*(char *)(*param_1 + uVar1) != *(char *)(uVar1 + param_2)) break;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_3);
    }
    uVar1 = CONCAT31((int3)(uVar1 >> 8),uVar1 == param_3);
  }
  return uVar1;
}

