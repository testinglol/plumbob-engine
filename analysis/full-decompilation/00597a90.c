
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00597a90(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int *param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[5] = param_4;
  iVar1 = *param_6;
  param_1[10] = 0;
  param_1[0xb] = iVar1;
  param_1[8] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 1;
  param_1[0x14] = 0x3f800000;
  param_1[0xf] = 0;
  param_1[0x11] = 0;
  param_1[0x15] = 0;
  param_1[7] = param_7;
  param_1[6] = param_7;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  FUN_0059863e(param_5);
  *(int *)param_1[1] = *(int *)param_1[1] + 1;
  iVar1 = param_1[1];
  iVar5 = *(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20) >> 2;
  if (iVar5 == 0) {
    param_1[0xe] = 0;
  }
  else {
    param_1[0xe] = *(int *)(**(int **)(iVar1 + 0x20) + 0x14);
  }
  if (_DAT_0067343c < ABS((float)param_1[9])) {
    fVar3 = *(float *)(iVar1 + 0x2c) / (float)param_1[9];
  }
  else {
    fVar3 = 0.0;
  }
  param_1[8] = (int)fVar3;
  if ((float)param_1[8] < _DAT_0066657c) {
    param_1[8] = (int)-(float)param_1[8];
  }
  param_2 = 0;
  if (0 < iVar5) {
    do {
      iVar1 = *(int *)(*(int *)(param_1[1] + 0x20) + param_2 * 4);
      iVar2 = *param_1;
      if (*(uint *)(iVar1 + 0xc) < (uint)(*(int *)(iVar2 + 0x74) - *(int *)(iVar2 + 0x70) >> 2)) {
        param_3 = *(int *)(*(int *)(iVar2 + 0x70) + *(uint *)(iVar1 + 0xc) * 4);
      }
      else {
        param_3 = 0;
      }
      uVar4 = 0;
      if (param_3 != 0) {
        iVar2 = *(int *)(iVar1 + 0x30);
        if ((iVar2 != 0) && ((*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) & 0xfffffff8U) != 0)) {
          uVar4 = FUN_0059478f();
        }
        local_10 = param_3;
        local_c = iVar1;
        local_8 = uVar4;
        FUN_0059b187(&local_10);
      }
      param_2 = param_2 + 1;
    } while (param_2 < iVar5);
  }
  return;
}

