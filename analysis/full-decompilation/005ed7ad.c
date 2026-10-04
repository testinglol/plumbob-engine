
undefined4 __thiscall FUN_005ed7ad(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 8) <= param_2)) {
LAB_005ed7d8:
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 == 0x10) {
      *(undefined2 *)(*(int *)(param_1 + 0x10) + param_2 * 2) = *(undefined2 *)param_3;
    }
    else {
      if (iVar1 != 0x18) {
        if (iVar1 == 0x20) {
          *(undefined4 *)(*(int *)(param_1 + 0x10) + param_2 * 4) = *param_3;
        }
        goto LAB_005ed7d8;
      }
      param_2 = param_2 * 3;
      *(undefined1 *)(param_2 + *(int *)(param_1 + 0x10)) = 0;
      *(undefined1 *)(param_2 + 1 + *(int *)(param_1 + 0x10)) = 0;
      *(undefined1 *)(param_2 + 2 + *(int *)(param_1 + 0x10)) = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

