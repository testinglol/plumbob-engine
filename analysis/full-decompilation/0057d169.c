
undefined4 __thiscall FUN_0057d169(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = param_2;
  iVar1 = *(int *)(param_1 + 0xa4);
  iVar2 = FUN_00582457(&local_c);
  *(int *)(iVar2 + 4) = iVar1 + param_3;
  return 1;
}

