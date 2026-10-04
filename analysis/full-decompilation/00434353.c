
void __thiscall FUN_00434353(int param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar4;
  int iVar2;
  void *pvVar3;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = param_3;
  iVar2 = param_2;
  FUN_0043426c(param_2,param_3);
  if (iVar1 < 1) {
    FUN_00464973(*(undefined4 *)(param_1 + 0x2c),8);
    FUN_00464973(param_1 + 0x3a,0x20);
    uVar5 = 0x20;
LAB_004343aa:
    FUN_00464973(param_1 + 0x4a,uVar5);
    uVar4 = extraout_var_00;
    if (iVar1 < 0xb) goto LAB_0043443f;
  }
  else {
    uVar4 = extraout_var;
    if (iVar1 < 0xb) {
      FUN_00464973(*(undefined4 *)(param_1 + 0x2c),8);
      FUN_00464973(param_1 + 0x3a,8);
      uVar5 = 0x24;
      goto LAB_004343aa;
    }
  }
  if (iVar1 < 0x18) {
    iVar6 = 8;
  }
  else {
    param_3 = CONCAT22(uVar4,*(undefined2 *)(param_1 + 0x30));
    FUN_00464973(&param_3,1);
    if ((*(int *)(param_1 + 0x30) < (int)(short)param_3) && (param_4 != '\0')) {
      FUN_006321f0(*(undefined4 *)(param_1 + 0x2c));
      *(int *)(param_1 + 0x30) = (int)(short)param_3;
      pvVar3 = operator_new((short)param_3 * 2);
      *(void **)(param_1 + 0x2c) = pvVar3;
      FUN_005a9250(pvVar3,0,(int)(short)param_3 << 1);
    }
    iVar6 = (int)(short)param_3;
  }
  FUN_00464973(*(undefined4 *)(param_1 + 0x2c),iVar6);
  FUN_00464973(param_1 + 0x3a,8);
  FUN_00464973(param_1 + 0x4a,0x48);
LAB_0043443f:
  param_2 = 0;
  FUN_00464973(&param_2,1);
  FUN_00475130(iVar2,iVar1,*(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x80));
  if (4 < iVar1) {
    iVar6 = iVar1;
    if (iVar1 < 7) {
      iVar6 = 0;
    }
    FUN_004651dc(iVar2,iVar6);
  }
  if ((iVar1 < 0xd) && (*(int *)(iVar2 + 0xc) == 0)) {
    *(undefined2 *)(param_1 + 0x5c) = 0;
    *(undefined2 *)(param_1 + 0x5e) = 0;
  }
  if (iVar1 < 0x22) {
    *(undefined2 *)(param_1 + 0x6a) = 0;
    *(undefined2 *)(param_1 + 0x6c) = 0;
  }
  iVar2 = FUN_00434578(iVar2,iVar1);
  if (iVar1 < 0x34) {
    iVar2 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1;
    *(short *)(param_1 + 0xd0) = (short)iVar2;
  }
  if (0x1a < iVar1) {
    param_3 = CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(param_1 + 0x38));
    FUN_00464973(&param_3,1);
    if (*(short *)(param_1 + 0x38) < (short)param_3) {
      if (param_4 == '\0') {
        if (*(int *)(param_1 + 0x34) != 0) {
          FUN_006321f0(*(int *)(param_1 + 0x34));
        }
        *(short *)(param_1 + 0x38) = (short)param_3;
        pvVar3 = operator_new((int)(short)param_3 << 1);
        *(void **)(param_1 + 0x34) = pvVar3;
        FUN_00442db0(*(undefined2 *)(param_1 + 0xf0),1);
      }
      else {
        FUN_006321f0(*(undefined4 *)(param_1 + 0x34));
        *(short *)(param_1 + 0x38) = (short)param_3;
        pvVar3 = operator_new((int)(short)param_3 << 1);
        *(void **)(param_1 + 0x34) = pvVar3;
      }
    }
    FUN_00464973(*(undefined4 *)(param_1 + 0x34),(int)(short)param_3);
  }
  if (param_4 != '\0') {
    *(undefined2 *)(param_1 + 0x4c) = 0;
  }
  return;
}

