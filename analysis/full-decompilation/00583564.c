
void FUN_00583564(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 << (0x20U - (char)(param_3 << 3) & 0x1f);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = (char)((uint)iVar1 >> 0x18);
    param_1 = param_1 + 1;
    iVar1 = iVar1 << 8;
  }
  return;
}

