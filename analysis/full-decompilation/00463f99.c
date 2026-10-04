
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463f99(int param_1,float param_2)

{
  short sVar1;
  uint uVar2;
  int *piVar3;
  float10 fVar4;
  float fVar5;
  
  uVar2 = (uint)*(ushort *)((int)param_2 + 0x56);
  fVar4 = (float10)FUN_00463da6(uVar2);
  if ((fVar4 < (float10)DAT_00667468) || ((float10)_DAT_0066746c < fVar4)) {
    if (fVar4 != (float10)_DAT_00667470) {
      sVar1 = *(short *)((int)param_2 + 0x84);
      piVar3 = *(int **)(param_1 + 0x90);
      param_2 = DAT_00667468;
      for (; piVar3 != *(int **)(param_1 + 0x94); piVar3 = piVar3 + 1) {
        if ((((*(short *)(*piVar3 + 0x84) == sVar1) &&
             (fVar4 = (float10)FUN_00463da6(uVar2), (float10)DAT_00667468 <= fVar4)) &&
            (fVar4 <= (float10)_DAT_0066746c)) && ((float10)param_2 <= fVar4)) {
          param_2 = (float)(fVar4 + (float10)_DAT_00667280);
        }
      }
      FUN_00463155(uVar2,param_2);
      FUN_00463804(uVar2,param_2);
      FUN_00463155(uVar2,param_2);
    }
  }
  else {
    FUN_00463155(uVar2,_DAT_00667470);
    fVar5 = _DAT_00667470;
    FUN_00463804(uVar2,_DAT_00667470);
    FUN_00463155(uVar2,fVar5);
  }
  return;
}

