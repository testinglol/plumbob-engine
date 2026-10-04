
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005e98c3(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((*(char *)(param_1 + 0xe8) == '\0') && (_DAT_0066657c < *(float *)(param_1 + 0xdc))) {
    uVar2 = 0;
    uVar1 = __ftol(0);
    FUN_005dadff(param_1,uVar1,uVar2);
    *(undefined1 *)(param_1 + 0xe8) = 1;
  }
  return;
}

