
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00633f35(float *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 extraout_ECX;
  float10 fVar3;
  undefined1 local_18 [4];
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  FUN_00636080();
  uStack_c = 0;
  puStack_10 = (undefined1 *)0x633f4a;
  iVar2 = FUN_006327fb();
  if (iVar2 != 0) {
    puStack_10 = local_18;
    uStack_c = 0x14;
    uStack_14 = 0x633f5f;
    iVar2 = FUN_00634652();
    if (0 < iVar2) {
      puStack_10 = local_18;
      uStack_c = 0;
      uStack_14 = 0x633f72;
      fVar3 = (float10)FUN_0063b338();
      fVar1 = _DAT_00689168;
      if (((((float10)_DAT_006734f0 < fVar3) ||
           (fVar1 = _DAT_00689158, fVar3 < (float10)_DAT_00689160)) ||
          (((float10)_DAT_006669e8 < fVar3 &&
           (fVar1 = _DAT_00689148, fVar3 < (float10)_DAT_00689150)))) ||
         ((fVar3 < (float10)_DAT_006669e8 && (fVar1 = _DAT_00689138, (float10)_DAT_00689140 < fVar3)
          ))) {
        *param_1 = fVar1;
      }
      else {
        *param_1 = (float)fVar3;
      }
    }
    uStack_c = 0x633ff3;
    FUN_00632716();
  }
  return extraout_ECX;
}

