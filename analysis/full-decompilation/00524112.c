
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00524112(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_1c;
  int local_18;
  undefined8 local_14;
  float local_c;
  int local_8;
  
  FUN_00524b60(&local_1c);
  FUN_004cb1a2(300,0xb9);
  iVar5 = *(int *)(param_1 + 0xe4);
  if ((iVar5 == 0) || (*(int *)(iVar5 + 0x50) == *(int *)(iVar5 + 0x4c))) {
    iVar5 = local_18 + 9;
  }
  else {
    iVar5 = (*(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x80)) + 0x1b + local_18;
  }
  FUN_004cb21d(local_1c + 9,iVar5);
  cVar2 = FUN_005a5e72();
  if (cVar2 != '\0') {
    iVar5 = *(int *)(param_1 + 0xe8);
    iVar3 = FUN_00524bd9();
    iVar5 = *(int *)(iVar5 + 0x80);
    iVar4 = FUN_00524b9b();
    local_14 = (double)CONCAT44(iVar3 + 0x1b + (local_18 - iVar5),iVar4 + 0x12);
    FUN_005353fa();
  }
  fVar6 = (float10)FUN_00524386();
  local_c = (float)fVar6;
  iVar3 = *(int *)(*(int *)(param_1 + 0xe8) + 0x84) - *(int *)(*(int *)(param_1 + 0xe8) + 0x7c);
  iVar5 = iVar3;
  local_14._4_4_ = (float)fVar6;
  if ((float10)_DAT_0066ceb0 < ABS(fVar6 - (float10)*(float *)(param_1 + 0x140))) {
    while( true ) {
      fVar6 = (float10)FUN_00524386();
      local_c = (float)fVar6;
      if ((float10)*(float *)(param_1 + 0x140) <= fVar6) break;
      FUN_004ec186();
      iVar5 = *(int *)(*(int *)(param_1 + 0xe8) + 0x84) - *(int *)(*(int *)(param_1 + 0xe8) + 0x7c);
    }
    FUN_004ec186();
    local_8 = 1;
    do {
      fVar6 = (float10)FUN_00524386();
      local_14._4_4_ = (float)fVar6;
      if (fVar6 <= (float10)*(float *)(param_1 + 0x140)) break;
      FUN_004ec186();
      iVar3 = *(int *)(*(int *)(param_1 + 0xe8) + 0x84) - *(int *)(*(int *)(param_1 + 0xe8) + 0x7c);
      local_8 = local_8 + 1;
    } while (local_8 < 10);
    local_8 = 1;
    do {
      iVar4 = FUN_00636bef();
      if (iVar4 < 0x15) break;
      FUN_004ec186();
      fVar6 = (float10)FUN_00524386();
      iVar4 = *(int *)(param_1 + 0xe8);
      if ((float10)*(float *)(param_1 + 0x140) <= fVar6) {
        local_c = (float)fVar6;
        iVar5 = *(int *)(iVar4 + 0x84) - *(int *)(iVar4 + 0x7c);
      }
      else {
        local_14._4_4_ = (float)fVar6;
        iVar3 = *(int *)(iVar4 + 0x84) - *(int *)(iVar4 + 0x7c);
      }
      local_8 = local_8 + 1;
    } while (local_8 < 10);
  }
  fVar6 = (float10)FUN_00637fe4((double)(local_14._4_4_ - *(float *)(param_1 + 0x140)));
  local_14 = (double)fVar6;
  fVar6 = (float10)FUN_00637fe4((double)(local_c - *(float *)(param_1 + 0x140)));
  iVar4 = *(int *)(*(int *)(param_1 + 0xe8) + 0x84);
  piVar1 = (int *)(*(int *)(param_1 + 0xe8) + 0x7c);
  if (fVar6 <= (float10)local_14) {
    if (iVar5 == iVar4 - *piVar1) goto LAB_00524352;
  }
  else if (iVar3 == iVar4 - *piVar1) goto LAB_00524352;
  FUN_004ec186();
LAB_00524352:
  FUN_00524386();
  iVar5 = *(int *)(param_1 + 0xec);
  if (iVar5 != 0) {
    FUN_004cb21d(((*(int *)(param_1 + 0x84) - *(int *)(iVar5 + 0x84)) - *(int *)(param_1 + 0x7c)) +
                 -5 + *(int *)(iVar5 + 0x7c),5);
  }
  return;
}

