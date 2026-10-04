
int __thiscall FUN_00406b44(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  iVar5 = 0;
  FUN_004659fc(0);
  local_8 = 0;
  FUN_004659fc(0xffffff9e);
  piVar4 = (int *)(param_1 + 0xc);
  while( true ) {
    if ((int *)*piVar4 == (int *)0x0) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)*piVar4 + 0x34))(param_2);
    iVar2 = FUN_00401f6f();
    if (iVar2 != 0) break;
    if ((short)param_3 <= (short)iVar1) {
      local_8 = (**(code **)(**(int **)(param_1 + 0xc + iVar5 * 0x14) + 0x40))
                          (param_2,param_3,param_4);
      uVar3 = FUN_00401f6f();
      FUN_004659fc(uVar3);
      if (local_8 == 0) {
        return 0;
      }
      uVar3 = 0;
      goto LAB_00406be1;
    }
    param_3 = param_3 - iVar1;
    if ((short)param_3 < 1) {
      return 0;
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 5;
    if (7 < iVar5) {
      return 0;
    }
  }
  uVar3 = FUN_00401f6f();
LAB_00406be1:
  FUN_004659fc(uVar3);
  return local_8;
}

