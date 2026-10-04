
int FUN_005eff44(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  if (DAT_006feca0 == (int *)0x0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    if (param_3 == (undefined4 *)0x0) {
      iVar1 = (**(code **)(*DAT_006feca0 + 0x18))
                        (DAT_006feca0,param_1 + 0x78,(undefined4 *)(param_1 + 8),0);
      if (iVar1 < 0) {
        return iVar1;
      }
      param_3 = *(undefined4 **)(param_1 + 8);
      unaff_EDI = param_1 + 4;
      puVar2 = (undefined4 *)*param_3;
    }
    else {
      iVar1 = (**(code **)(*DAT_006feca0 + 0x18))(DAT_006feca0,param_1 + 0x78,param_3,0);
      if (iVar1 < 0) {
        return iVar1;
      }
      param_3 = (undefined4 *)*param_3;
      if (param_3 == (undefined4 *)0x0) {
        return iVar1;
      }
      puVar2 = (undefined4 *)*param_3;
    }
    iVar1 = (*(code *)*puVar2)(param_3,&DAT_00677308,unaff_EDI);
  }
  return iVar1;
}

