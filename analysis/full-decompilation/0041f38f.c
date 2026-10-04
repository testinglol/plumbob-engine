
undefined4 __thiscall
FUN_0041f38f(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  short local_8;
  
  if ((short)param_4 != 0) {
    iVar1 = FUN_0041f723(param_2,param_3);
    if (iVar1 == *(int *)(param_1 + 8)) {
      if (0x7ffe < (uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc)) {
        return 0;
      }
      local_10 = param_2;
      local_8 = (short)param_4;
      local_c = param_3;
      FUN_0041f7ca(&local_10);
    }
    else {
      FUN_0041f3f8(param_4);
    }
  }
  return 1;
}

