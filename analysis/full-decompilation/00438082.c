
void FUN_00438082(undefined4 *param_1,float *param_2,float *param_3)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float local_54 [6];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  local_3c = 0x7fffffff;
  local_38 = 0x7fffffff;
  local_34 = 0x80000000;
  local_30 = 0x80000000;
  local_c = (int *)FUN_00407498((int)*(short *)(param_3 + 4));
  pfVar4 = param_3;
  pfVar6 = param_2;
  if (local_c != (int *)0x0) {
    pfVar5 = local_54;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar5 = *param_2;
      param_2 = param_2 + 1;
      pfVar5 = pfVar5 + 1;
    }
    param_2 = (float *)param_3[1];
    param_3 = (float *)*param_3;
    FUN_00439195((int)*(short *)(local_8 + 0x4c),&param_3,&param_2);
    fVar1 = pfVar4[2];
    *pfVar6 = (float)param_3 + *pfVar6;
    pfVar6[1] = (float)param_2 + pfVar6[1];
    pfVar6[2] = fVar1 + pfVar6[2];
    FUN_004b9b69(pfVar6);
    piVar2 = local_c;
    FUN_00438fc0(&local_2c,1);
    FUN_0043908c(1);
    (**(code **)(*piVar2 + 0x30))(&local_1c,pfVar6);
    if ((local_1c < local_14) && (local_18 < local_10)) {
      FUN_00422698();
    }
    else if ((local_2c < local_24) && (local_28 < local_20)) {
      FUN_00439016(&local_2c,1);
    }
    else {
      FUN_0043908c(1);
    }
    pfVar4 = local_54;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar6 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar6 = pfVar6 + 1;
    }
  }
  *param_1 = local_3c;
  param_1[1] = local_38;
  param_1[2] = local_34;
  param_1[3] = local_30;
  return;
}

