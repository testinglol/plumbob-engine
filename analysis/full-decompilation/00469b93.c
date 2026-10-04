
undefined4 __thiscall FUN_00469b93(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_00469a9d(param_2);
  if (((-1 < param_3) && (param_3 < iVar1)) && (iVar1 = FUN_00469872(param_2), iVar1 != 0)) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + (*(int *)(iVar1 + 0xc) + param_3) * 4);
  }
  return 0xffffffff;
}

