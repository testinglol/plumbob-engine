
void __thiscall FUN_0047422f(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    param_1 = param_1 + 0x78;
  }
  else {
    if (param_2 != 1) goto LAB_00474264;
    param_1 = param_1 + 0xc;
  }
  if ((param_1 != 0) && (iVar1 = FUN_004705f2(param_3 + 1,0xffffffff), iVar1 != 0)) {
    FUN_0046f8cb(iVar1);
    return;
  }
LAB_00474264:
  *(undefined2 *)(param_4 + 8) = 0;
  **(undefined1 **)(param_4 + 4) = 0;
  return;
}

