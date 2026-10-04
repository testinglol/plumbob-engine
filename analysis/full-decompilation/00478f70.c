
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00478f70(int param_1,uint *param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  byte bStack_9;
  
  uVar4 = param_2[1] & 0xf;
  uVar5 = *param_2 & 0xf;
  fVar2 = (float)uVar4;
  fVar3 = (float)uVar5;
  uVar1 = *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x14) + 0xc) +
                            (char)((int)param_2[1] >> 4) * 4) + (char)((int)*param_2 >> 4) * 4);
  uVar6 = uVar1 >> 8 & 0xff;
  fVar7 = (float10)uVar6;
  if ((((_DAT_0066657c <= fVar2) && (_DAT_0066657c <= fVar3)) && (fVar2 <= _DAT_00666a54)) &&
     (fVar3 <= _DAT_00666a54)) {
    if (fVar2 == fVar3) {
      fVar7 = (float10)(int)((uVar1 >> 0x18) - uVar6) * (float10)uVar4 * (float10)_DAT_00667278 +
              fVar7;
    }
    else {
      bStack_9 = (byte)(uVar1 >> 0x18);
      if (fVar2 <= fVar3) {
        fVar8 = (float10)(int)((uVar1 & 0xff) - uVar6) * (float10)uVar5 * (float10)_DAT_00667278;
        fVar9 = (((float10)(int)(bStack_9 - uVar6) * (float10)uVar5 * (float10)_DAT_00667278 - fVar8
                 ) * (float10)uVar4) / (float10)uVar5;
      }
      else {
        fVar8 = (float10)(int)((uVar1 >> 0x10 & 0xff) - uVar6) * (float10)uVar4 *
                (float10)_DAT_00667278;
        fVar9 = (((float10)(int)(bStack_9 - uVar6) * (float10)uVar4 * (float10)_DAT_00667278 - fVar8
                 ) * (float10)uVar5) / (float10)uVar4;
      }
      fVar7 = fVar9 + fVar8 + fVar7;
    }
  }
  return fVar7;
}

