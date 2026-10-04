
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059076c(void)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar9;
  float10 fVar10;
  
  FUN_00634c24();
  iVar2 = *(int *)(extraout_ECX + 0xb4);
  *(undefined1 *)(extraout_ECX + 0x150) = 0;
  if (*(int *)(extraout_ECX + 0x164) == iVar2) goto LAB_005908a4;
  iVar7 = *(int *)(extraout_ECX + 0x138);
  if ((0 < *(short *)(iVar7 + 0x5e6)) &&
     (iVar6 = *(short *)(iVar7 + 0x5e6) + -1, *(short *)(iVar7 + 0x5e6) = (short)iVar6, iVar6 == 0))
  {
    *(undefined2 *)(iVar7 + 0x5e0) = 8;
  }
  if ((*(byte *)(iVar7 + 0x5e0) & 1) == 0) {
    *(float *)(extraout_ECX + 0x218) = *(float *)(extraout_ECX + 0x218) * (float)_DAT_00672030;
  }
  else {
    for (fVar4 = *(float *)(extraout_ECX + 0x210) - *(float *)(extraout_ECX + 0x214);
        fVar4 < _DAT_00672024; fVar4 = fVar4 + _DAT_0066c7bc) {
    }
    for (; _DAT_00668318 <= fVar4; fVar4 = fVar4 - _DAT_0066c7bc) {
    }
    fVar5 = _DAT_00666a28;
    if ((fVar4 <= _DAT_00666a28) && (fVar5 = fVar4, fVar4 < _DAT_0067203c)) {
      fVar5 = _DAT_0067203c;
    }
    fVar5 = fVar5 + *(float *)(extraout_ECX + 0x218);
    bVar3 = _DAT_00672038 <= fVar5;
    *(float *)(extraout_ECX + 0x218) = fVar5;
    if (bVar3) {
      if (fVar5 <= _DAT_00668654) goto LAB_0059089e;
      *(undefined4 *)(extraout_ECX + 0x218) = 0x3fc00000;
    }
    else {
      *(undefined4 *)(extraout_ECX + 0x218) = 0xbfc00000;
    }
    if (*(short *)(iVar7 + 0x5e4) == 0) {
      *(undefined2 *)(iVar7 + 0x5e0) = 5;
    }
    else if (*(short *)(iVar7 + 0x5e4) == 1) {
      *(undefined2 *)(iVar7 + 0x5e0) = 4;
    }
  }
LAB_0059089e:
  *(int *)(extraout_ECX + 0x164) = iVar2;
LAB_005908a4:
  if ((_DAT_00666a4c <= *(float *)(extraout_ECX + 0x218)) ||
     (*(float *)(extraout_ECX + 0x218) <= _DAT_0067202c)) {
    iVar7 = FUN_00599121(0x1f);
    fVar4 = _DAT_00671ed8 + _DAT_00671ed8;
    fVar5 = *(float *)(extraout_ECX + 0x218) * _DAT_00668220;
    iVar2 = *(int *)(iVar7 + 0x24);
    puVar1 = (undefined4 *)(iVar7 + 0x3c);
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    *(float *)(unaff_EBP + -0x10) = fVar5 * fVar4;
    FUN_005c4870(puVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    fVar9 = (float10)FUN_005c48d0();
    if (fVar9 == (float10)_DAT_0066657c) {
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0x3f800000;
    }
    else {
      fVar9 = (float10)1 / fVar9;
      *(float *)(unaff_EBP + -0x2c) = (float)((float10)*(float *)(unaff_EBP + -0x2c) * fVar9);
      *(float *)(unaff_EBP + -0x28) = (float)((float10)*(float *)(unaff_EBP + -0x28) * fVar9);
      *(float *)(unaff_EBP + -0x24) = (float)((float10)*(float *)(unaff_EBP + -0x24) * fVar9);
      *(float *)(unaff_EBP + -0x20) = (float)((float10)*(float *)(unaff_EBP + -0x20) * fVar9);
    }
    FUN_005c4900(unaff_EBP + -0x8c);
    fVar10 = (float10)fpatan(-(float10)*(float *)(unaff_EBP + -0x74),
                             (float10)*(float *)(unaff_EBP + -0x78));
    fVar9 = fVar10 + (float10)*(float *)(unaff_EBP + -0x10);
    fVar4 = _DAT_00672028;
    if ((fVar9 < (float10)_DAT_00672028) || (fVar4 = _DAT_00671ea0, (float10)_DAT_00671ea0 < fVar9))
    {
      *(float *)(unaff_EBP + -0x10) = (float)((float10)fVar4 - fVar10);
    }
    *(undefined4 *)(extraout_ECX + 0x154) = *puVar1;
    *(undefined4 *)(extraout_ECX + 0x158) = *(undefined4 *)(iVar7 + 0x40);
    *(undefined4 *)(extraout_ECX + 0x15c) = *(undefined4 *)(iVar7 + 0x44);
    *(undefined4 *)(extraout_ECX + 0x160) = *(undefined4 *)(iVar7 + 0x48);
    *(undefined1 *)(extraout_ECX + 0x150) = 1;
    FUN_005c4830();
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    FUN_005c4a60(unaff_EBP + -0x10,unaff_EBP + -0x18,unaff_EBP + -0x14);
    puVar8 = (undefined4 *)FUN_00590a83(unaff_EBP + -0x4c,unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar8;
    *(undefined4 *)(unaff_EBP + -0x28) = puVar8[1];
    *(undefined4 *)(unaff_EBP + -0x24) = puVar8[2];
    *(undefined4 *)(unaff_EBP + -0x20) = puVar8[3];
    FUN_005c4890();
    *puVar1 = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(iVar7 + 0x40) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(iVar7 + 0x48) = *(undefined4 *)(unaff_EBP + -0x20);
    FUN_00596177(iVar2 + 0x4c,iVar2 + 0x58);
    FUN_005a1466(0x1f,0);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005c4890();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c4890();
  }
  else {
    *(undefined4 *)(extraout_ECX + 0x218) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

