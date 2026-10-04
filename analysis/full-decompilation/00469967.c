
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00469967(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  float10 fVar8;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar5 = FUN_00469872();
  puVar6 = (uint *)FUN_00469872();
  if ((iVar5 != 0) && (puVar6 != (uint *)0x0)) {
    if (param_2 == 0) {
      uVar1 = *puVar6;
      if ((-1 < (int)uVar1) &&
         (piVar2 = *(int **)*param_1, uVar1 < (uint)((piVar2[1] - *piVar2) / 0x14))) {
        iVar7 = *piVar2;
        *param_4 = *(int *)(iVar5 + 0x14);
        param_4[1] = *(int *)(iVar5 + 0x18);
        return (float10)*(int *)(iVar7 + uVar1 * 0x14 + 0x10);
      }
    }
    else if (param_3 != 1) {
      if (*(uint *)(iVar5 + 4) == puVar6[1]) {
        *param_4 = *(int *)(iVar5 + 0x14);
        iVar7 = *(int *)(iVar5 + 0x18);
      }
      else {
        FUN_00469700(iVar5,puVar6,&local_14);
        iVar7 = (local_8 + local_10) / 2;
        *param_4 = (local_c + local_14) / 2;
      }
      param_4[1] = iVar7;
      fVar3 = (float)(*param_4 - *(int *)(iVar5 + 0x14));
      fVar4 = (float)(param_4[1] - *(int *)(iVar5 + 0x18));
      fVar8 = (float10)FUN_00636264((double)(fVar3 * fVar3 + fVar4 * fVar4));
      return (float10)((int)(puVar6[4] + 2 + *(int *)(iVar5 + 0x10)) >> 1) *
             (float10)(float)(fVar8 + (float10)_DAT_00667280);
    }
  }
  return (float10)_DAT_0066657c;
}

