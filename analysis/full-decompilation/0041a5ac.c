
int __thiscall FUN_0041a5ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  *(undefined1 *)(param_1 + 0x24) = 1;
  local_8 = param_1;
  if ((*(int *)(param_1 + 0x20) != 0) &&
     (iVar1 = FUN_0041950d(-(uint)(param_1 != 0) & param_1 + 0xcU,0), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = FUN_004131a0(param_3);
  if (iVar1 == 0) {
    local_8 = 0x4c;
    FUN_0041a583();
    iVar1 = FUN_00412f9f(param_2,&local_8);
    FUN_0041a583();
  }
  return iVar1;
}

