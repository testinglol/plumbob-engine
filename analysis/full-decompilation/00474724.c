
void __thiscall FUN_00474724(int *param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1[1] - *param_1;
  iVar1 = FUN_004753b0();
  if (uVar4 - iVar1 < param_2) {
    uVar3 = uVar4 * 2;
    if (uVar4 * 2 == 0) {
      uVar3 = 0x200;
      if (0x200 < param_2 * 2) {
        uVar3 = param_2 * 2;
      }
    }
    uVar3 = uVar3 + 7 & 0xfffffff8;
    pvVar2 = operator_new(uVar3);
    if (uVar4 < uVar3) {
      FUN_005a9250((int)pvVar2 + uVar4,0,uVar3 - uVar4);
    }
    FUN_005a92b0(pvVar2,*param_1,uVar4);
    if (*param_1 != 0) {
      FUN_006321f0(*param_1);
    }
    *param_1 = (int)pvVar2;
    param_1[1] = (int)pvVar2 + uVar3;
    FUN_004753e3(param_1[3] - param_1[2] >> 2);
    FUN_00475384();
  }
  else {
    FUN_00475384();
  }
  return;
}

