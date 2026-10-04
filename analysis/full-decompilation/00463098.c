
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00463098(int param_1)

{
  bool bVar1;
  float fVar2;
  SHORT SVar3;
  SHORT SVar4;
  float fVar5;
  
  SVar3 = GetKeyState(0x10);
  SVar4 = GetKeyState(0x11);
  fVar2 = _DAT_00666578;
  if (SVar4 < 0) {
    *(float *)(param_1 + 0x54) = *(float *)(param_1 + 0x54) - _DAT_00666578;
  }
  if (SVar3 < 0) {
    *(float *)(param_1 + 0x54) = *(float *)(param_1 + 0x54) + fVar2;
  }
  fVar2 = *(float *)(param_1 + 0x54) - _DAT_006c4714;
  bVar1 = _DAT_00666c18 <= fVar2;
  *(float *)(param_1 + 0x54) = fVar2;
  if (bVar1) {
    if (fVar2 <= _DAT_00666748) {
      if (_DAT_0066657c <= fVar2) {
        fVar5 = DAT_006c470c;
        if (DAT_006c470c <= fVar2) goto LAB_00463142;
      }
      else {
        fVar5 = -DAT_006c470c;
        if (fVar2 <= fVar5) goto LAB_00463142;
      }
      *(float *)(param_1 + 0x54) = fVar5;
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = 0x3f800000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x54) = 0xbf800000;
  }
LAB_00463142:
  *(float *)(param_1 + 0x58) = _DAT_006c4710 * *(float *)(param_1 + 0x54);
  return;
}

