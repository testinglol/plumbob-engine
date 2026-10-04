
float10 __fastcall FUN_00421481(int *param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_8;
  
  iVar2 = *param_1;
  local_8 = 0.0;
  iVar1 = iVar2 + param_1[1] * 0x14;
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
    fVar3 = (float10)FUN_004167d4(*(undefined4 *)(param_1[0x30] + *(int *)(iVar2 + 0x10) * 4));
    iVar1 = *param_1 + param_1[1] * 0x14;
    local_8 = (float)(fVar3 + (float10)local_8);
  }
  return (float10)local_8 / (float10)param_1[1];
}

