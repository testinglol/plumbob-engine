
void __thiscall FUN_004aeeb8(undefined1 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_004aeea6();
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      *param_1 = 0x7f;
      param_1[1] = 0x7f;
    }
    else if (iVar1 == 2) {
      if (param_2 == 0) {
        *param_1 = param_1[2];
        param_1[1] = param_1[3];
      }
      param_1[2] = 0x7f;
      param_1[3] = 0x7f;
    }
  }
  return;
}

