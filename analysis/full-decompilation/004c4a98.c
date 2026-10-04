
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004c4a98(int param_1,uint param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  fVar1 = _DAT_00666578;
  if (*(short *)(param_1 + 0x1e4) != 0) {
    uVar4 = param_2 >> 0x10 & 0xff;
    iVar3 = ((param_2 >> 0x18) - uVar4) + 5;
    iVar2 = ((param_2 >> 8 & 0xff) - uVar4) + 5;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (10 < iVar2) {
      iVar2 = 10;
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (10 < iVar3) {
      iVar3 = 10;
    }
    fVar1 = *(float *)(param_1 + (iVar2 * 0xb + iVar3) * 4);
  }
  return (float10)fVar1;
}

