
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_00633c6a(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_1[0x13] == -1) {
    uVar3 = (-(uint)((param_3 & 0x80) != 0) & 0x4000) + 0x4000;
    if ((param_3 & 0x20) == 0) {
      uVar3 = uVar3 | 0x100;
    }
    uVar4 = 0x40;
    if ((param_3 & 0x40) != 0) {
      uVar3 = uVar3 | 0x400;
    }
    if ((param_3 & 8) != 0) {
      param_3 = param_3 | 2;
      uVar3 = uVar3 | 8;
    }
    if ((param_3 & 0x10) != 0) {
      param_3 = param_3 | 2;
      uVar3 = uVar3 | 0x200;
    }
    if ((param_3 & 2) == 0) {
      if ((param_3 & 1) == 0) {
        return (int *)0x0;
      }
    }
    else {
      if ((param_3 & 1) == 0) {
        uVar3 = uVar3 | 1;
      }
      else {
        uVar3 = uVar3 | 2;
      }
      if ((param_3 & 0x4d) == 0) {
        param_3 = param_3 | 0x10;
        uVar3 = uVar3 | 0x200;
      }
    }
    param_4 = param_4 & (DAT_00689074 | _DAT_0068907c | _DAT_00689078);
    if (param_4 != 0) {
      if (param_4 == 0x800) {
        uVar4 = 0x10;
      }
      else if (param_4 == 0xa00) {
        uVar4 = 0x20;
      }
      else if (param_4 == 0xc00) {
        uVar4 = 0x30;
      }
      else if (param_4 == 0xe00) {
        uVar4 = 0x40;
      }
    }
    iVar1 = FUN_006399e0(param_2,uVar3,uVar4,0x180);
    param_1[0x13] = iVar1;
    if (iVar1 != -1) {
      if (param_1[0xc] < 0) {
        FUN_00633e5e(param_1 + 0xd);
      }
      param_1[0x14] = 1;
      if ((param_1[2] == 0) && (param_1[5] == 0)) {
        pvVar2 = operator_new(0x200);
        if (pvVar2 == (void *)0x0) {
          param_1[2] = 1;
        }
        else {
          FUN_006345ae(pvVar2,(int)pvVar2 + 0x200,1);
        }
      }
      if (((param_3 & 4) == 0) || (iVar1 = (**(code **)(*param_1 + 0xc))(0,2,param_3), iVar1 != -1))
      {
        if (param_1[0xc] < 0) {
          FUN_00633e69(param_1 + 0xd);
          return param_1;
        }
        return param_1;
      }
      FUN_00632d35();
      if (param_1[0xc] < 0) {
        FUN_00633e69(param_1 + 0xd);
      }
    }
  }
  return (int *)0x0;
}

