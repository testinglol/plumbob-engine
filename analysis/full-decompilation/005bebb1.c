
undefined4 __fastcall FUN_005bebb1(int param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    uVar2 = 0;
  }
  else {
    FUN_005bf04f();
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x1c));
    if (BVar1 == 0) {
      FUN_005bfa81();
    }
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined1 *)(param_1 + 0x18) = 0;
    uVar2 = 1;
  }
  return uVar2;
}

