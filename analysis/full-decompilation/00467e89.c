
undefined2 __thiscall FUN_00467e89(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0x10) {
    if (param_3 == 0) {
      param_3 = 4;
    }
  }
  else if ((param_2 == 0x20) && (param_3 == 0)) {
    param_3 = 1;
  }
  iVar1 = FUN_00435221(param_2,param_3);
  return *(undefined2 *)(param_1 + 0x14 + iVar1 * 2);
}

