
void __fastcall FUN_00487c19(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004573f9();
  *(int *)(param_1 + 0x44) = iVar1;
  *(undefined1 *)(param_1 + 0xad) = 0;
  if ((iVar1 == 0) || (*(short *)(*(int *)(iVar1 + 0x60) + 0x8a) == 0)) {
    *(undefined4 *)(param_1 + 0x24) = 6;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 7;
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  iVar2 = FUN_00486a5e(iVar1);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x34) = 3;
LAB_00487c6d:
    *(undefined1 *)(param_1 + 0x75) = 0;
    *(undefined1 *)(param_1 + 0x76) = 0;
    *(undefined1 *)(param_1 + 0x77) = 1;
    *(undefined1 *)(param_1 + 0x78) = 1;
    *(undefined1 *)(param_1 + 0x94) = 0;
    *(undefined1 *)(param_1 + 0x28) = 1;
    return;
  }
  iVar2 = FUN_00486a5e(iVar1);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x34) = 4;
    goto LAB_00487c6d;
  }
  iVar2 = FUN_00486a5e(iVar1);
  if (iVar2 == 0) {
    iVar2 = FUN_00486a5e(iVar1);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x34) = 6;
      *(undefined1 *)(param_1 + 0x75) = 0;
      *(undefined1 *)(param_1 + 0x76) = 0;
      *(undefined1 *)(param_1 + 0x77) = 1;
      *(undefined1 *)(param_1 + 0x78) = 0;
      *(undefined1 *)(param_1 + 0x94) = 0;
      *(undefined1 *)(param_1 + 0xad) = 1;
      return;
    }
    iVar2 = FUN_00486a5e(iVar1);
    if (iVar2 == 0) {
      iVar2 = FUN_00486a5e(iVar1);
      if (iVar2 == 0) {
        iVar1 = FUN_00486a5e(iVar1);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x34) = 1;
        }
        else {
          *(undefined4 *)(param_1 + 0x34) = 9;
        }
        *(undefined1 *)(param_1 + 0x75) = 0;
        *(undefined1 *)(param_1 + 0x76) = 0;
        *(undefined1 *)(param_1 + 0x77) = 0;
        goto LAB_00487d4a;
      }
      *(undefined4 *)(param_1 + 0x34) = 8;
    }
    else {
      *(undefined4 *)(param_1 + 0x34) = 7;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
  *(undefined1 *)(param_1 + 0x75) = 0;
  *(undefined1 *)(param_1 + 0x76) = 0;
  *(undefined1 *)(param_1 + 0x77) = 1;
LAB_00487d4a:
  *(undefined1 *)(param_1 + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x94) = 0;
  return;
}

