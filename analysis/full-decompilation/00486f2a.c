
void __fastcall FUN_00486f2a(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (iVar1 != 0) {
    if ((*(int *)(iVar1 + 0x1ac) == 0) || (*(short *)(iVar1 + 0x1b0) == 0)) {
      *(undefined1 *)(param_1 + 0x95) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x95) = 1;
    }
    if (*(short *)(iVar1 + 0x4a) != 0) {
      FUN_00423349(0,0);
      FUN_00423377();
    }
    if (*(char *)(param_1 + 0x95) != '\0') {
      *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0xf4);
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0xf8);
    }
    *(char *)(param_1 + 0x96) = *(char *)(param_1 + 0x95);
    *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x9c);
    *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xa0);
  }
  return;
}

