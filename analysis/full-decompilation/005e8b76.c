
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005e8b76(int param_1,undefined4 *param_2,float param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_004cb21d(*param_2,(*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x88)) + param_2[3]);
  if (param_3 == _DAT_0066657c) {
    *(undefined1 *)(param_1 + 0xec) = 1;
  }
  iVar2 = __ftol();
  piVar1 = (int *)(param_1 + 0xf0);
  *piVar1 = iVar2;
  if (iVar2 < 0) {
    *piVar1 = 0;
  }
  else if (0xff < iVar2) {
    *piVar1 = 0xff;
  }
  return;
}

