
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00526547(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_00524b60();
  FUN_004cb1a2(300,0xb9);
  iVar4 = *(int *)(param_1 + 0xec);
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0x50) == *(int *)(iVar4 + 0x4c))) {
    iVar4 = local_18 + 9;
  }
  else {
    iVar4 = (*(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80)) + 0x1b + local_18;
  }
  FUN_004cb21d(local_1c + 9,iVar4);
  if (*(int *)(param_1 + 0x100) != 0) {
    FUN_00526e2d();
    FUN_00526df4();
    FUN_005353fa();
  }
  fVar5 = (float10)FUN_0052678f();
  local_c = (float)fVar5;
  uStack_10 = (float)fVar5;
  iVar3 = *(int *)(*(int *)(param_1 + 0xf0) + 0x84) - *(int *)(*(int *)(param_1 + 0xf0) + 0x7c);
  iVar4 = iVar3;
  if ((float10)_DAT_0066ceb0 < ABS(fVar5 - (float10)*(float *)(param_1 + 0x134))) {
    while( true ) {
      fVar5 = (float10)FUN_0052678f();
      local_c = (float)fVar5;
      if ((float10)*(float *)(param_1 + 0x134) <= fVar5) break;
      FUN_004ec186();
      iVar4 = *(int *)(*(int *)(param_1 + 0xf0) + 0x84) - *(int *)(*(int *)(param_1 + 0xf0) + 0x7c);
    }
    FUN_004ec186();
    local_8 = 1;
    do {
      fVar5 = (float10)FUN_0052678f();
      uStack_10 = (float)fVar5;
      if (fVar5 <= (float10)*(float *)(param_1 + 0x134)) break;
      FUN_004ec186();
      iVar3 = *(int *)(*(int *)(param_1 + 0xf0) + 0x84) - *(int *)(*(int *)(param_1 + 0xf0) + 0x7c);
      local_8 = local_8 + 1;
    } while (local_8 < 10);
    local_8 = 1;
    do {
      iVar2 = FUN_00636bef();
      if (iVar2 < 0x15) break;
      FUN_004ec186();
      fVar5 = (float10)FUN_0052678f();
      iVar2 = *(int *)(param_1 + 0xf0);
      if ((float10)*(float *)(param_1 + 0x134) <= fVar5) {
        local_c = (float)fVar5;
        iVar4 = *(int *)(iVar2 + 0x84) - *(int *)(iVar2 + 0x7c);
      }
      else {
        uStack_10 = (float)fVar5;
        iVar3 = *(int *)(iVar2 + 0x84) - *(int *)(iVar2 + 0x7c);
      }
      local_8 = local_8 + 1;
    } while (local_8 < 10);
  }
  fVar5 = (float10)FUN_00637fe4((double)(uStack_10 - *(float *)(param_1 + 0x134)));
  fVar6 = (float10)FUN_00637fe4((double)(local_c - *(float *)(param_1 + 0x134)));
  iVar2 = *(int *)(*(int *)(param_1 + 0xf0) + 0x84);
  piVar1 = (int *)(*(int *)(param_1 + 0xf0) + 0x7c);
  if (fVar6 <= (float10)(double)fVar5) {
    if (iVar4 == iVar2 - *piVar1) goto LAB_00526781;
  }
  else if (iVar3 == iVar2 - *piVar1) goto LAB_00526781;
  FUN_004ec186();
LAB_00526781:
  FUN_0052678f();
  return;
}

