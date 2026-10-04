
uint __thiscall FUN_005a267a(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 == *param_2) {
    uVar1 = uVar1 - 1;
    if (-1 < (int)uVar1) {
      do {
        if (*(char *)(param_1[1] + uVar1) != *(char *)(param_2[1] + uVar1)) goto LAB_005a2685;
        uVar1 = uVar1 - 1;
      } while (-1 < (int)uVar1);
    }
    uVar1 = CONCAT31((int3)(uVar1 >> 8),1);
  }
  else {
LAB_005a2685:
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}

