
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b32e9(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  byte bVar7;
  int extraout_ECX;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  FUN_00634c24();
  piVar6 = *(int **)(unaff_EBP + 0xc);
  *(char *)(unaff_EBP + -0x14) = (char)(piVar6[1] >> 4);
  *(char *)(unaff_EBP + -0x13) = (char)(*piVar6 >> 4);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff0c;
  *(int *)(unaff_EBP + -0x2c) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00433116(piVar6);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  cVar2 = FUN_004b3863();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  if (cVar2 == '\0') {
    FUN_004b388e();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005cf113();
    FUN_004b388e();
    uVar4 = DAT_006d6184;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
    *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(extraout_ECX + 0x51);
    *(undefined4 *)(unaff_EBP + -0x48) = _DAT_006f0bc0;
    *(undefined4 *)(unaff_EBP + -0x44) = _DAT_006f0bc4;
    *(undefined1 *)(unaff_EBP + -0x16) = DAT_006f0095;
    uVar4 = *(undefined4 *)(*(int *)(extraout_ECX + 0x68) + 0x14);
    *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(*(int *)(extraout_ECX + 0x68) + 0x10);
    uVar1 = *(undefined4 *)(extraout_ECX + 0x84);
    *(undefined4 *)(unaff_EBP + -0x34) = uVar4;
    *(undefined4 *)(unaff_EBP + -0x4c) = uVar1;
    uVar3 = FUN_00584812();
    *(undefined1 *)(unaff_EBP + -0x30) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x3c) = DAT_006e54ac;
    uVar4 = FUN_006359f2(DAT_006f6b5c,0,&cXObject::RTTI_Type_Descriptor,
                         &cXPerson::RTTI_Type_Descriptor);
    *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
    FUN_004b38e5();
    uVar3 = DAT_006e4870;
    DAT_006e4870 = 0;
    *(undefined1 *)(unaff_EBP + -0x15) = uVar3;
    FUN_00586fdc();
    FUN_00584818(0);
    uVar4 = *(undefined4 *)(unaff_EBP + 0x14);
    DAT_006d6184 = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    DAT_006f0095 = 1;
    *(undefined1 *)(extraout_ECX + 0x51) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    puVar10 = (undefined4 *)(unaff_EBP + -0xf4);
    puVar11 = (undefined4 *)(unaff_EBP + -0x88);
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    *(undefined4 *)(unaff_EBP + -0x80) = uVar4;
    *(undefined4 *)(unaff_EBP + -0x88) = *(undefined4 *)(unaff_EBP + 0x18);
    uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x20);
    iVar8 = *(int *)(*(int *)(unaff_EBP + 8) + 0x1c);
    *(int *)(unaff_EBP + -0x20) = iVar8;
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x1c);
    bVar7 = (byte)*(undefined4 *)(unaff_EBP + 0x18);
    *(int *)(unaff_EBP + -0x7c) =
         iVar8 / 2 -
         ((int)*(char *)(unaff_EBP + -0x14) - (int)*(char *)(unaff_EBP + -0x13)) *
         (8 << (bVar7 & 0x1f));
    iVar8 = *(int *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + -0x78) =
         *(int *)(*(int *)(unaff_EBP + 8) + 0x20) / 2 -
         ((int)*(char *)(unaff_EBP + -0x13) + (int)*(char *)(unaff_EBP + -0x14)) *
         (4 << (bVar7 & 0x1f));
    cVar2 = FUN_004b0db9();
    if (cVar2 != '\0') {
      uVar4 = *(undefined4 *)(iVar8 + 0x1c);
      *(undefined1 *)(unaff_EBP + 0x1b) = 1;
      iVar8 = FUN_005cf06d(uVar4);
      if (-1 < iVar8) {
        FUN_004b3938();
        uVar4 = (*(undefined4 **)(unaff_EBP + 0xc))[1];
        *(undefined4 *)(unaff_EBP + -0x20) = **(undefined4 **)(unaff_EBP + 0xc);
        iVar8 = DAT_006e54d8;
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
        FUN_0047bd91(unaff_EBP + -0x1c,unaff_EBP + -0x20,*(undefined4 *)(iVar8 + 0x84));
        FUN_004a7baa(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x1c),
                     *(undefined4 *)(unaff_EBP + 0x14),0);
        iVar9 = *(int *)(extraout_ECX + 0x170) + DAT_006f0080;
        iVar8 = (*(int *)(extraout_ECX + 0x174) - *(int *)(unaff_EBP + 0x10)) + DAT_006f0084;
        *(undefined4 *)(extraout_ECX + 0x170) = 0;
        *(undefined4 *)(extraout_ECX + 0x174) = 0;
        FUN_004a83dc(iVar9,iVar8);
        *(undefined1 **)(unaff_EBP + 0x14) = &stack0xffffff08;
        FUN_004796d9(unaff_EBP + 0x10);
        *(undefined1 *)(unaff_EBP + 0x17) = *(undefined1 *)(unaff_EBP + 0x11);
        FUN_004b3e97(unaff_EBP + -0x1c,unaff_EBP + 0xc);
        *(int *)(unaff_EBP + 0xc) =
             *(int *)(unaff_EBP + 0xc) -
             ((uint)*(byte *)(unaff_EBP + 0x17) << ((char)DAT_006f0088 + 1U & 0x1f));
        *(undefined2 *)(unaff_EBP + -0xbe) = *(undefined2 *)(unaff_EBP + -0x1c);
        *(undefined2 *)(unaff_EBP + -0xc0) = *(undefined2 *)(unaff_EBP + 0xc);
        FUN_004ab995(unaff_EBP + -0xcc);
        FUN_00584818();
        *(short *)(unaff_EBP + -0x20) = *(short *)(unaff_EBP + -0x70);
        *(int *)(unaff_EBP + -0x5c) = (int)*(short *)(unaff_EBP + -0x70);
        *(int *)(unaff_EBP + -0x58) = (int)*(short *)(unaff_EBP + -0x6c);
        *(short *)(unaff_EBP + -0x1e) = *(short *)(unaff_EBP + -0x74);
        _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x20);
        *(short *)(unaff_EBP + -0x1c) = *(short *)(unaff_EBP + -0x68);
        *(int *)(unaff_EBP + -0x54) = (int)*(short *)(unaff_EBP + -0x68);
        *(short *)(unaff_EBP + -0x1a) = *(short *)(unaff_EBP + -0x6c);
        _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x1c);
        *(int *)(unaff_EBP + -0x60) = (int)*(short *)(unaff_EBP + -0x74);
        FUN_005cddcf();
        pvVar5 = operator_new(0x74);
        *(void **)(unaff_EBP + 0x14) = pvVar5;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        if (pvVar5 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_004b4533();
        }
        *(undefined1 *)(unaff_EBP + -4) = 3;
        *(undefined4 *)(unaff_EBP + 0x14) = uVar4;
        FUN_004b038a(*(undefined4 *)(unaff_EBP + 8));
        piVar6 = DAT_006e486c;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        iVar8 = *(int *)(*piVar6 + 0x14);
        for (puVar10 = *(undefined4 **)(iVar8 + 0x84); puVar10 != *(undefined4 **)(iVar8 + 0x88);
            puVar10 = puVar10 + 1) {
          piVar6 = (int *)(**(code **)(*(int *)*puVar10 + 0x8c))();
          iVar9 = *piVar6;
          *(int **)(unaff_EBP + 0xc) = piVar6;
          cVar2 = (**(code **)(iVar9 + 0x6c))();
          if (cVar2 != '\0') {
            (**(code **)(**(int **)(unaff_EBP + 0xc) + 0x54))();
          }
        }
        FUN_004ad0c7(*(undefined4 *)(unaff_EBP + 0x14));
        FUN_004b36ba();
        return;
      }
      FUN_004b0db9();
    }
    _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x48);
    _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x44);
    uVar4 = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined1 *)(extraout_ECX + 0x51) = *(undefined1 *)(unaff_EBP + -0x17);
    DAT_006d6184 = *(undefined4 *)(unaff_EBP + -0x50);
    DAT_006f0095 = *(undefined1 *)(unaff_EBP + -0x16);
    FUN_005cf06d(uVar4);
    FUN_004b3938();
    FUN_00586fdc();
    FUN_00584818(*(undefined4 *)(unaff_EBP + -0x30));
    DAT_006e54ac = *(undefined4 *)(unaff_EBP + -0x3c);
    if (extraout_ECX + 0x88 != unaff_EBP + -0xa0) {
      FUN_004b4251();
      *(undefined1 *)(extraout_ECX + 0x94) = *(undefined1 *)(unaff_EBP + -0x94);
      *(undefined4 *)(extraout_ECX + 0x98) = *(undefined4 *)(unaff_EBP + -0x90);
    }
    iVar8 = FUN_005cf113();
    if (iVar8 != unaff_EBP + -0xb8) {
      FUN_004b4251();
      *(undefined1 *)(iVar8 + 0xc) = *(undefined1 *)(unaff_EBP + -0xac);
      *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(unaff_EBP + -0xa8);
    }
    DAT_006e4870 = *(undefined1 *)(unaff_EBP + -0x15);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005db425();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005db425();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

