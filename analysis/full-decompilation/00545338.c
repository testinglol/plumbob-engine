
undefined4 __thiscall FUN_00545338(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0xec);
  if (iVar1 != 0) {
    if (iVar1 == 0xff) {
      local_c = param_1;
      local_8 = param_1;
      uVar2 = FUN_005dd085(param_2,param_3);
      return uVar2;
    }
    local_c = 0;
    local_8 = 0;
    (*DAT_006f0674)(param_2,param_3,param_2,param_3,*(undefined4 *)(param_1 + 0x58),&local_c,iVar1);
  }
  return 1;
}

