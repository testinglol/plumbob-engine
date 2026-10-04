
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00590b8f(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  *(char *)(param_1 + 0x109) = *(char *)(param_1 + 0xd9);
  if (*(char *)(param_1 + 0xd9) == '\0') {
    if (_DAT_0066657c <= *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x80)) {
      if ((_DAT_0066657c <= *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x84)) &&
         (*(int *)(param_1 + 8) != 0)) {
        *(undefined4 *)(param_1 + 0x78) = 0;
        iVar2 = FUN_00415707(param_2);
        uVar1 = FUN_005a0912(param_1 + 0x38,iVar2 + 0xec,param_2);
        *(undefined1 *)(param_1 + 0x109) = uVar1;
      }
    }
  }
  return *(undefined1 *)(param_1 + 0x109);
}

