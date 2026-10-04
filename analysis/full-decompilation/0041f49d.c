
undefined4 __thiscall
FUN_0041f49d(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  
  if ((short)param_4 != 0) {
    iVar2 = FUN_0041f723(param_2,param_3);
    if ((iVar2 == *(int *)(param_1 + 8)) || (*(short *)(iVar2 + 8) < (short)param_4)) {
      return 0;
    }
    sVar1 = FUN_0041f473(param_4);
    if (sVar1 == 0) {
      FUN_00472be0(iVar2);
    }
  }
  return 1;
}

