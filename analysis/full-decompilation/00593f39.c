
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __fastcall FUN_00593f39(int param_1,float *param_2)

{
  bool bVar1;
  ushort uVar2;
  bool bVar3;
  float fVar4;
  undefined2 in_AX;
  byte bVar5;
  int iVar6;
  
  iVar6 = 0;
  bVar5 = (byte)((ushort)in_AX >> 8);
  bVar3 = true;
  param_1 = param_1 - (int)param_2;
  do {
    if (3 < iVar6) break;
    fVar4 = *(float *)(param_1 + (int)param_2) - *param_2;
    if (fVar4 < _DAT_0066657c) {
      fVar4 = -fVar4;
    }
    bVar1 = fVar4 < _DAT_0066657c;
    uVar2 = (ushort)(fVar4 == _DAT_0066657c);
    bVar5 = bVar1 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(_DAT_0066657c)) << 10) >> 8) |
            (byte)((ushort)(uVar2 << 0xe) >> 8);
    bVar3 = bVar1 || uVar2 != 0;
    iVar6 = iVar6 + 1;
    param_2 = param_2 + 1;
  } while (bVar1 || uVar2 != 0);
  return CONCAT11(bVar5,!bVar3);
}

