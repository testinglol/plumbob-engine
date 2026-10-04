
void __thiscall FUN_0046b26e(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined **local_18 [3];
  undefined1 local_c [8];
  
  piVar2 = (int *)(param_1 + 0xac);
  iVar1 = 0;
  if (*piVar2 != 0) {
    do {
      piVar2 = piVar2 + 6;
      iVar1 = iVar1 + 1;
    } while (*piVar2 != 0);
    if (0xf < iVar1) {
      return;
    }
  }
  if ((-1 < param_2) && (param_2 < 4)) {
    param_1 = param_1 + iVar1 * 0x18;
    *(int *)(param_1 + 0xac) = param_2;
    FUN_0046f824(local_c,0,8);
    local_18[0] = &PTR_FUN_00666644;
    FUN_0046f847(param_3,0xffffffff);
    FUN_0046f8e4(local_18);
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  return;
}

