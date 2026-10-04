
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0050ae69(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1[6] <= param_1[4]) {
    return;
  }
  if (param_1[5] < param_1[7]) {
    if (*param_1 != 0) {
      if (*param_1 == 2) {
        iVar3 = __ftol();
        iVar1 = *(int *)(DAT_006e486c + 0x34);
      }
      else {
        FUN_00473496(DAT_006e5490);
        iVar3 = __ftol();
        iVar1 = *(int *)(DAT_006e486c + 0x34);
      }
      if (iVar1 == 1) {
        uVar2 = FUN_0049a996(iVar3 >> 3);
      }
      else {
        uVar2 = FUN_0049a775(iVar3 >> 3);
      }
      uVar4 = (**(code **)(*DAT_006f35fc + 0x1c))();
      (**(code **)(*DAT_006f35fc + 0x20))(uVar2);
      (**(code **)(*DAT_006f35fc + 0x80))(param_2,param_1 + 4,param_1[1],param_1[2] - param_1[1],1);
      (**(code **)(*DAT_006f35fc + 0x20))(uVar4);
      return;
    }
    return;
  }
  return;
}

