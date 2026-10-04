
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005f70ff(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = param_1[0x37];
  iVar2 = param_1[0x36];
  if (iVar1 == iVar2) {
    *param_2 = 0;
  }
  else {
    iVar3 = param_1[0x3b];
    iVar4 = param_1[0x39];
    if (param_1[0x35] == 1) {
      iVar7 = (**(code **)(*param_1 + 0x1cc))();
    }
    else {
      iVar7 = (**(code **)(*param_1 + 0x1d0))();
      param_3 = param_4;
    }
    iVar5 = param_1[0x36];
    iVar6 = param_1[0x37];
    if (iVar5 <= iVar6) {
      iVar8 = iVar5;
      do {
        if ((float)((param_3 - iVar7 / 2) - param_1[0x39]) <
            ((float)(iVar8 - iVar5) + _DAT_00666578) *
            ((float)(iVar3 - iVar4) / (float)(iVar1 - iVar2))) {
          *param_2 = iVar8;
          return 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 <= iVar6);
    }
    *param_2 = iVar6;
  }
  return 1;
}

