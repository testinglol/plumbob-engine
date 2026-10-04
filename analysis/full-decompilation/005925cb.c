
void __thiscall FUN_005925cb(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((char)param_1[0x36] != '\0') {
    *(undefined1 *)(param_1 + 0x36) = 0;
    (**(code **)(*param_1 + 0x14))();
  }
  iVar1 = FUN_0059d9ba(param_1[0x4e],param_2);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x7c) = 1;
  }
  return;
}

