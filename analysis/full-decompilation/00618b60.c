
void FUN_00618b60(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar5 = (*param_1 * 0x100) / 0x3f;
  uVar1 = (param_1[1] * 0x100) / 0x3f;
  uVar2 = (param_1[2] * 0x100) / 0x3f;
  uVar6 = uVar1;
  if ((int)uVar1 < (int)uVar5) {
    uVar6 = uVar5;
  }
  if ((int)uVar6 <= (int)uVar2) {
    uVar6 = uVar2;
  }
  uVar3 = uVar2;
  if ((int)uVar5 < (int)uVar1) {
    if ((int)uVar5 < (int)uVar2) {
      uVar3 = uVar5;
    }
  }
  else if ((int)uVar1 < (int)uVar2) {
    uVar3 = uVar1;
  }
  uVar8 = uVar6 - uVar3;
  uVar7 = uVar8 >> 1;
  if ((uVar6 == 0) || (uVar6 == uVar3)) {
    param_1 = (int *)0x0;
    uVar5 = 0xffffffff;
  }
  else {
    param_1 = (int *)(((uVar8 * 0x100) / uVar6) * 0xff >> 8);
    if (param_1 == (int *)0x0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar3 = ((uVar5 * 0xffffff + uVar6) * 0x100 + uVar7) / uVar8;
      uVar4 = ((uVar1 * 0xffffff + uVar6) * 0x100 + uVar7) / uVar8;
      uVar8 = ((uVar2 * 0xffffff + uVar6) * 0x100 + uVar7) / uVar8;
      if (uVar5 == uVar6) {
        uVar5 = uVar8 - uVar4;
      }
      else if (uVar1 == uVar6) {
        uVar5 = (uVar3 - uVar8) + 0x200;
      }
      else {
        uVar5 = (uint)param_1;
        if (uVar2 == uVar6) {
          uVar5 = (uVar4 - uVar3) + 0x400;
        }
      }
    }
  }
  if (uVar5 < 3) {
    uVar5 = 0;
  }
  if (param_1 < 3) {
    param_1 = (int *)0x0;
  }
  *param_2 = uVar5;
  param_2[1] = (uint)param_1;
  param_2[2] = uVar6 * 0xff >> 8;
  return;
}

