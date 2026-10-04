
void __fastcall FUN_005c5ed0(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float10 fVar9;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  int local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar7 = *(int *)(param_1 + 0x34);
  if (iVar7 != *(int *)(param_1 + 0x38)) {
    do {
      local_50 = 0.0;
      local_4c = 0.0;
      local_48 = 0.0;
      uVar4 = FUN_00462bc9(&local_48,&local_4c,&local_50);
      FUN_00462be8(uVar4);
      iVar7 = iVar7 + 0x18;
    } while (iVar7 != *(int *)(param_1 + 0x38));
  }
  piVar8 = *(int **)(param_1 + 0x1c);
  if (piVar8 != *(int **)(param_1 + 0x20)) {
    do {
      iVar7 = *(int *)(param_1 + 0x34);
      iVar2 = *(int *)(param_1 + 4);
      iVar5 = *piVar8 * 0x18;
      iVar3 = *(int *)(iVar5 + iVar7);
      iVar6 = piVar8[1] * 0x18;
      pfVar1 = (float *)(iVar2 + *(int *)(iVar7 + iVar6) * 0xc);
      local_30 = *pfVar1;
      local_2c = pfVar1[1];
      local_28 = pfVar1[2];
      local_48 = *(float *)(iVar2 + 8 + iVar3 * 0xc) - local_28;
      local_40 = piVar8[2] * 0x18;
      local_4c = *(float *)(iVar2 + 4 + iVar3 * 0xc) - local_2c;
      local_c = *(float *)(iVar2 + *(int *)(local_40 + iVar7) * 0xc);
      iVar7 = iVar2 + *(int *)(local_40 + iVar7) * 0xc;
      local_8 = *(float *)(iVar7 + 4);
      local_4 = *(float *)(iVar7 + 8);
      local_50 = *(float *)(iVar2 + iVar3 * 0xc) - local_30;
      FUN_00462bc9(&local_50,&local_4c,&local_48);
      local_48 = local_4 - local_28;
      local_4c = local_8 - local_2c;
      local_50 = local_c - local_30;
      FUN_00462bc9(&local_50,&local_4c,&local_48);
      local_48 = local_14 * local_24 - local_18 * local_20;
      local_4c = local_1c * local_18 - local_10 * local_24;
      local_50 = local_10 * local_20 - local_1c * local_14;
      FUN_00462bc9(&local_50,&local_4c,&local_48);
      fVar9 = (float10)FUN_005c4810();
      local_44 = (float)SQRT(fVar9);
      FUN_005c47e0(&local_44);
      piVar8 = piVar8 + 4;
      pfVar1 = (float *)(iVar5 + 8 + *(int *)(param_1 + 0x34));
      *pfVar1 = local_3c + *(float *)(iVar5 + 8 + *(int *)(param_1 + 0x34));
      pfVar1[1] = local_38 + pfVar1[1];
      pfVar1[2] = local_34 + pfVar1[2];
      pfVar1 = (float *)(*(int *)(param_1 + 0x34) + 8 + iVar6);
      *pfVar1 = local_3c + *(float *)(*(int *)(param_1 + 0x34) + 8 + iVar6);
      pfVar1[1] = local_38 + pfVar1[1];
      pfVar1[2] = local_34 + pfVar1[2];
      pfVar1 = (float *)(local_40 + 8 + *(int *)(param_1 + 0x34));
      *pfVar1 = local_3c + *(float *)(local_40 + 8 + *(int *)(param_1 + 0x34));
      pfVar1[1] = local_38 + pfVar1[1];
      pfVar1[2] = local_34 + pfVar1[2];
    } while (piVar8 != *(int **)(param_1 + 0x20));
  }
  iVar7 = *(int *)(param_1 + 0x34);
  if (iVar7 != *(int *)(param_1 + 0x38)) {
    do {
      FUN_0049b802();
      iVar7 = iVar7 + 0x18;
    } while (iVar7 != *(int *)(param_1 + 0x38));
  }
  return;
}

