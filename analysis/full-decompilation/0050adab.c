
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0050adab(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5,
            uint param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    *param_5 = 0;
    param_5[1] = 0;
    param_5[2] = 0;
    param_5[3] = 0;
    if (param_6 < (uint)param_1[0x11]) {
      return 1;
    }
    FUN_0050ad4b(1);
    return 1;
  }
  if (iVar1 == 1) {
    if ((DAT_006e5490 < (uint)param_1[0xf]) && (param_6 < (uint)(param_1[0x11] + _DAT_0066aee4)))
    goto LAB_0050ae0d;
    uVar2 = 2;
  }
  else {
    if (iVar1 != 2) goto LAB_0050ae0d;
    param_1[5] = param_1[5] + param_7;
    param_1[7] = param_1[7] + param_7;
    if (*(int *)(param_3 + 4) < param_1[5]) goto LAB_0050ae0d;
    uVar2 = 3;
    param_1[7] = (param_1[7] - param_1[5]) + *(int *)(param_3 + 4);
    param_1[5] = *(int *)(param_3 + 4);
  }
  FUN_0050ad4b(uVar2);
LAB_0050ae0d:
  *param_5 = param_1[4];
  param_5[1] = param_1[5];
  param_5[2] = param_1[6];
  param_5[3] = param_1[7];
  if ((*param_1 == 3) && ((uint)param_1[0xf] <= DAT_006e5490)) {
    FUN_0050ad4b(4);
    return 0;
  }
  return 1;
}

