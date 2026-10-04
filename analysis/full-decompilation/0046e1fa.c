
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046e1fa(int param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2;
  if (param_3 < 3) {
    FUN_00464b48(param_1 + 4,1);
    FUN_00464b48(param_1 + 8,1);
    if (param_3 < 1) {
      param_2 = __ftol();
      FUN_00464973(&param_2,1);
      param_2 = (int)(short)param_2;
      *(float *)(param_1 + 0xc) = (float)param_2;
    }
    else {
      FUN_00464b48(param_1 + 0xc,1);
    }
    FUN_00464973(param_1,1);
    if (1 < param_3) {
      param_2 = 0;
      FUN_00464973(&param_2,1);
    }
    if (*(int *)(iVar2 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
  }
  else {
    FUN_00464973(param_1,1);
    FUN_00464b48(param_1 + 4,1);
    FUN_00464b48(param_1 + 8,1);
    FUN_00464b48(param_1 + 0xc,1);
    FUN_00464a5e(param_1 + 0x1c,3);
    FUN_00464a5e(param_1 + 0x28,1);
    if (3 < param_3) {
      FUN_00464a5e(param_1 + 0x2c,1);
    }
    if (4 < param_3) {
      FUN_00464a5e(param_1 + 0x30,1);
      FUN_00464a5e(param_1 + 0x34,1);
      FUN_00464a5e(param_1 + 0x38,1);
      FUN_00464a5e(param_1 + 0x10,1);
      FUN_00464a5e(param_1 + 0x14,1);
    }
    if (6 < param_3) {
      FUN_00464b48(param_1 + 0x3c,1);
    }
  }
  if (7 < param_3) {
    FUN_00464a5e(param_1 + 0x18,1);
  }
  if (param_3 < 9) {
    uVar3 = *(uint *)(param_1 + 0x28);
    if ((uVar3 & 0x200) == 0) {
      if ((uVar3 & 0x400) == 0) goto LAB_0046e393;
      *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
      uVar3 = uVar3 & 0xfffffbff;
    }
    else {
      *(undefined4 *)(param_1 + 0x40) = 0xfffffffd;
      uVar3 = uVar3 & 0xfffffdff;
    }
    *(uint *)(param_1 + 0x28) = uVar3;
  }
  else {
    FUN_00464a5e(param_1 + 0x40,1);
  }
LAB_0046e393:
  if (param_3 < 10) {
    fVar1 = *(float *)(param_1 + 0x3c) * _DAT_00667278;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) << 4;
    *(float *)(param_1 + 0x3c) = fVar1;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) << 4;
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) << 4;
  }
  else {
    FUN_00464a5e(param_1 + 0x44,1);
  }
  return;
}

