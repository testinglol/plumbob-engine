
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00420fe9(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iStack_14;
  
  fVar4 = _DAT_0066657c;
  fVar3 = param_1[0x20];
  iStack_14 = 0;
  if (((uint)(int)*(short *)((int)fVar3 + 0x60e) >> 1 & 1) == 0) {
    if (((uint)(int)*(short *)((int)fVar3 + 0x60e) >> 2 & 1) != 0) {
      iStack_14 = 2;
    }
  }
  else {
    iStack_14 = 1;
  }
  if (param_1[0xb] < _DAT_0066657c) {
    fVar1 = (float)(&DAT_006e49ac)[iStack_14];
    fVar2 = param_1[5];
    param_1[5] = fVar1 + fVar2;
    iVar5 = (int)*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x10);
    if ((iVar5 <= (int)(&DAT_006e49a0)[iStack_14]) || ((int)(&DAT_006e4994)[iStack_14] <= iVar5))
    goto LAB_0042106a;
    fVar1 = (fVar1 + fVar2) - (float)(&DAT_006e4988)[iStack_14];
  }
  else {
    fVar1 = (float)(&DAT_006e49b8)[iStack_14] + param_1[5];
  }
  param_1[5] = fVar1;
LAB_0042106a:
  if (fVar4 < param_1[7] - param_1[0x17]) {
    param_1[9] = param_1[9] - (param_1[7] - param_1[0x17]) * (float)(&DAT_006e497c)[iStack_14];
  }
  param_1[6] = param_1[6] -
               ((float)(int)*(short *)((int)fVar3 + 0x592) * (float)(&DAT_006e4964)[iStack_14] +
               (float)(&DAT_006e4970)[iStack_14]);
  param_1[7] = param_1[7] - (param_1[7] + _DAT_0066674c) * (float)(&DAT_006e4958)[iStack_14];
  if (fVar4 <= param_1[0xb]) {
    param_1[0xe] = param_1[0xe] -
                   ((float)(int)*(short *)((int)fVar3 + 0x598) * (float)(&DAT_006e4940)[iStack_14] +
                   (float)(&DAT_006e494c)[iStack_14]);
  }
  if (param_1[0xb] < fVar4) {
    param_1[0xf] = (float)(&DAT_006e4928)[iStack_14] * param_1[0xf];
    param_1[8] = param_1[8] - (float)(&DAT_006e4910)[iStack_14];
    fVar3 = param_1[9] - (float)(&DAT_006e48f8)[iStack_14];
  }
  else {
    param_1[0xf] = param_1[0xf] - (float)(&DAT_006e4934)[iStack_14];
    param_1[8] = param_1[8] - (float)(&DAT_006e491c)[iStack_14];
    fVar3 = param_1[9] - (float)(&DAT_006e4904)[iStack_14];
  }
  param_1[9] = fVar3;
  fVar4 = _DAT_00666a60;
  fVar3 = _DAT_0066674c;
  iVar5 = 0x10;
  do {
    if (fVar3 < *param_1) {
      *param_1 = fVar3;
    }
    if (*param_1 < fVar4) {
      *param_1 = fVar4;
    }
    param_1[0x10] = *param_1;
    param_1 = param_1 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_0045d2d1();
  return;
}

