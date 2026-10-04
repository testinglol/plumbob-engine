
char __thiscall FUN_005bf0b2(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_8 [3];
  char local_5;
  
  auStack_8 = SUB43(param_1,0);
  local_5 = '\x01';
  if (0 < param_3) {
    if (*(int *)(param_1 + 0x6c) == *(int *)(param_1 + 0x70)) {
      auStack_8 = (undefined1  [3])((uint3)auStack_8 & 0xffff);
      local_5 = '\x01';
      FUN_005bfb21(*(undefined4 *)(param_1 + 0x68),auStack_8 + 2);
    }
    iVar2 = *(int *)(param_1 + 0x7c);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x4c);
    }
    if (*(int *)(param_1 + 0x68) < iVar2 + param_3) {
      do {
        if (local_5 == '\0') {
          return '\0';
        }
        iVar1 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 0x7c);
        iVar2 = param_3;
        if (iVar1 < param_3) {
          iVar2 = iVar1;
        }
        if (iVar2 != 0) {
          FUN_00636510(*(int *)(param_1 + 0x7c) + *(int *)(param_1 + 0x6c),param_2,iVar2);
          *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + iVar2;
          param_2 = param_2 + iVar2;
          param_3 = param_3 - iVar2;
        }
        if (*(int *)(param_1 + 0x7c) == *(int *)(param_1 + 0x68)) {
          local_5 = FUN_005bf04f();
        }
      } while (param_3 != 0);
    }
    else {
      FUN_00636510(iVar2 + *(int *)(param_1 + 0x6c),param_2,param_3);
      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + param_3;
    }
  }
  return local_5;
}

