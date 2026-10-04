
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004167d4(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float10 fVar4;
  int *local_8;
  
  if (param_1[2] == 0) {
    fVar4 = (float10)_DAT_0066657c;
  }
  else {
    iVar1 = param_1[2] + -1;
    iVar2 = iVar1;
    local_8 = param_1;
    if (-1 < iVar1) {
      pfVar3 = (float *)(*param_1 + iVar1 * 8);
      do {
        local_8 = (int *)(param_2 - *pfVar3);
        if (_DAT_0066657c < (float)local_8) break;
        iVar2 = iVar2 + -1;
        pfVar3 = pfVar3 + -2;
      } while (-1 < iVar2);
    }
    if (iVar2 == iVar1) {
      fVar4 = (float10)*(float *)(*param_1 + 4 + iVar2 * 8);
    }
    else if (iVar2 == -1) {
      fVar4 = (float10)*(float *)(*param_1 + 4);
    }
    else {
      iVar1 = *param_1 + iVar2 * 8;
      fVar4 = ((float10)*(float *)(iVar1 + 0xc) - (float10)*(float *)(iVar1 + 4)) *
              (float10)(float)local_8 * (float10)*(float *)(param_1[1] + iVar2 * 4) +
              (float10)*(float *)(iVar1 + 4);
    }
  }
  return fVar4;
}

