
undefined4 __thiscall FUN_004051e0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ea79e(param_2);
    iVar1 = (int)*(short *)(iVar1 + 0xa2);
    if ((0xb < iVar1) || (iVar1 < 0)) {
      return 0;
    }
  }
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 * 4);
}

