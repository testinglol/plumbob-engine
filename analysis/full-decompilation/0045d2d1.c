
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045d2d1(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float10 fVar5;
  float local_10;
  float local_c;
  
  local_c = 0.0;
  local_10 = 0.0;
  if ((*(short *)(param_1 + 0x600) == 0) ||
     (piVar4 = &DAT_006e5110, 0x11 < *(short *)(param_1 + 0x600))) {
    piVar4 = &DAT_006e51a8;
  }
  iVar3 = *piVar4;
  iVar2 = iVar3 + piVar4[1] * 0x14;
  for (; iVar3 != iVar2; iVar3 = iVar3 + 0x14) {
    fVar1 = *(float *)(param_1 + 0x78c + *(int *)(iVar3 + 0x10) * 4);
    fVar5 = (float10)FUN_004167d4(fVar1);
    if ((*(short *)(param_1 + 0x60e) < 2) || (fVar1 != _DAT_00667424)) {
      local_c = (float)(fVar5 * (float10)fVar1 + (float10)local_c);
      local_10 = (float)(fVar5 + (float10)local_10);
    }
    iVar2 = *piVar4 + piVar4[1] * 0x14;
  }
  *(float *)(param_1 + 0x798) = local_c / local_10;
  return;
}

