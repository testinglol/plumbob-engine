
undefined4 __fastcall FUN_005ddf50(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x18))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
    uVar3 = (**(code **)(*piVar2 + 0x150))();
    return uVar3;
  }
  return 1;
}

