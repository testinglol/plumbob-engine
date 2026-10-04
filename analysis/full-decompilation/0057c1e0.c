
void __thiscall FUN_0057c1e0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *param_1 = &PTR_FUN_00671880;
  param_1[5] = 0;
  param_1[1] = 0xabadcafe;
  param_1[3] = param_2;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 0x2e) = 0;
  if (*(char *)(param_1 + 7) == '\0') {
    param_1[8] = 0x1f;
    param_1[9] = 0x11;
    param_1[10] = param_1 + 0xe;
    *(undefined1 *)(param_1 + 0xd) = 0;
    do {
      *(undefined4 *)(param_1[10] + iVar1 * 4) = 0x80000000;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1[8]);
  }
  *(undefined1 *)(param_1 + 7) = 1;
  return;
}

