
undefined2 __fastcall FUN_0059a443(float *param_1)

{
  float fVar1;
  float fVar2;
  undefined1 uVar3;
  byte bVar4;
  
  fVar1 = param_1[3];
  fVar2 = *param_1;
  bVar4 = fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8);
  uVar3 = 0;
  if (fVar1 >= fVar2) {
    fVar1 = param_1[4];
    fVar2 = param_1[1];
    bVar4 = fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8);
    if (fVar1 >= fVar2) {
      fVar1 = param_1[5];
      fVar2 = param_1[2];
      bVar4 = fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8);
      if (fVar1 >= fVar2) goto LAB_0059a467;
    }
  }
  uVar3 = 1;
LAB_0059a467:
  return CONCAT11(bVar4,uVar3);
}

