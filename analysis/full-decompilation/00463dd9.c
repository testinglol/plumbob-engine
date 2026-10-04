
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00463dd9(float param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  int iVar8;
  int local_c;
  
  iVar2 = (int)param_1;
  sVar1 = *(short *)(param_2 + 0x56);
  if (sVar1 == 0) {
    local_c = 0;
  }
  else {
    local_c = 0;
    for (piVar3 = *(int **)((int)param_1 + 0x90); piVar3 != *(int **)(iVar2 + 0x94);
        piVar3 = piVar3 + 1) {
      if (*(short *)(*piVar3 + 0x84) == *(short *)(param_2 + 0x84)) {
        fVar5 = (float10)FUN_00463da6(sVar1);
        if (fVar5 == (float10)DAT_00667478) {
          FUN_00463155(sVar1,DAT_00667474);
          fVar5 = (float10)FUN_004341ed(*piVar3);
          for (piVar4 = *(int **)(iVar2 + 0x90); piVar4 != *(int **)(iVar2 + 0x94);
              piVar4 = piVar4 + 1) {
            if (*(short *)(*piVar4 + 0x84) == *(short *)(param_3 + 0x84)) {
              fVar6 = (float10)FUN_00463a65(*piVar4);
              if (fVar6 != (float10)DAT_00667474) {
                iVar8 = *piVar4;
                FUN_00463804(iVar8);
                fVar7 = (float10)FUN_00463a65(iVar8);
                if (fVar7 <= (float10)(float)fVar6) {
                  fVar7 = (float10)FUN_004341ed(param_3);
                  fVar6 = fVar7 + (float10)(float)fVar6 + (float10)(float)fVar5;
                  param_1 = (float)fVar6;
                  if ((float10)DAT_00667464 < fVar6) {
                    param_1 = DAT_00667464;
                  }
                  fVar6 = (float10)FUN_00463da6(sVar1);
                  if ((float10)param_1 < fVar6) {
                    FUN_00463155(sVar1,param_1);
                  }
                }
              }
            }
          }
          fVar5 = (float10)FUN_00463da6(sVar1);
        }
        param_1 = (float)fVar5;
        if (((fVar5 != (float10)DAT_00667474) && (fVar5 != (float10)_DAT_00667470)) &&
           ((local_c == 0 || (fVar5 = (float10)FUN_00463da6(sVar1), (float10)param_1 < fVar5)))) {
          local_c = *piVar3;
        }
      }
    }
  }
  return local_c;
}

