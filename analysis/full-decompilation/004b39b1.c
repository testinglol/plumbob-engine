
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004b39b1(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  void *pvVar6;
  int *piVar7;
  int extraout_ECX;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  undefined4 uVar11;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffd48;
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  iVar8 = *(int *)(extraout_ECX + 0x6c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((((iVar8 == 0) || (*(int *)(extraout_ECX + 0x68) == 0)) || (DAT_006e4870 == '\x01')) ||
     ((*(int *)(unaff_EBP + 0x18) == 0 || (*(int *)(unaff_EBP + 0x1c) == 0)))) {
    uVar1 = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x18) = (int)*(char *)(unaff_EBP + 10);
    *(undefined1 *)(unaff_EBP + -0x11) = 1;
    FUN_004b38e5();
    uVar3 = FUN_006359f2(DAT_006f6b5c,0,&cXObject::RTTI_Type_Descriptor,
                         &cXPerson::RTTI_Type_Descriptor);
    *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
    uVar3 = *(undefined4 *)(*(int *)(extraout_ECX + 0x68) + 0x14);
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(*(int *)(extraout_ECX + 0x68) + 0x10);
    uVar11 = DAT_006d6184;
    *(undefined4 *)(unaff_EBP + -0x28) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x40) = uVar11;
    FUN_0049ea40();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0049eb08();
    FUN_00635e55(unaff_EBP + -0x2b8,8,0x40,FUN_004678f9);
    puVar4 = (undefined4 *)(extraout_ECX + 0x208);
    puVar10 = (undefined4 *)(unaff_EBP + -0x2b8);
    for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar1 = FUN_00584812();
    *(undefined1 *)(unaff_EBP + -0x34) = uVar1;
    *(undefined4 *)(unaff_EBP + -0x38) = DAT_006e54ac;
    DAT_006e54ac = 0;
    uVar1 = *(undefined1 *)(extraout_ECX + 0x51);
    *(undefined1 *)(extraout_ECX + 0x51) = 0;
    *(undefined1 *)(unaff_EBP + -0x12) = uVar1;
    FUN_00586fdc();
    DAT_006d6184 = 0;
    FUN_00584818(0);
    *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(extraout_ECX + 0x84);
    cVar2 = FUN_004b0db9();
    if (cVar2 == '\0') {
      *(undefined1 *)(unaff_EBP + -0x11) = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x3c) = 1;
      iVar8 = FUN_005cf06d(*(undefined4 *)(unaff_EBP + 0x18));
      if (-1 < iVar8) {
        uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
        puVar4 = (undefined4 *)(unaff_EBP + -0xb8);
        puVar10 = (undefined4 *)(unaff_EBP + -0x7c);
        for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar10 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar10 = puVar10 + 1;
        }
        *(undefined4 *)(unaff_EBP + -0x7c) = uVar3;
        *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + 0x14);
        *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x18);
        *(undefined4 *)(unaff_EBP + -0x70) = 0;
        *(undefined4 *)(unaff_EBP + -0x6c) = 0;
        *(undefined4 *)(unaff_EBP + -0x50) = 0;
        *(undefined4 *)(unaff_EBP + -0x4c) = 0;
        *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + 0x18);
        *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + 0x1c);
        *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x50);
        *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x4c);
        *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x48);
        *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x44);
        *(undefined1 *)(unaff_EBP + -0x58) = 0;
        *(undefined1 *)(unaff_EBP + -0x57) = 1;
        *(undefined1 *)(unaff_EBP + -0x56) = 1;
        FUN_004b3938();
        uVar11 = 0;
        uVar3 = *(undefined4 *)(unaff_EBP + -0x18);
        puVar4 = (undefined4 *)FUN_00434d3d(unaff_EBP + -0x1c);
        FUN_004a7baa(*puVar4,puVar4[1],uVar3,uVar11);
        iVar9 = *(int *)(extraout_ECX + 0x170) + DAT_006f0080;
        iVar5 = *(int *)(extraout_ECX + 0x174) + DAT_006f0084;
        *(undefined4 *)(extraout_ECX + 0x170) = 0;
        iVar8 = *(int *)(unaff_EBP + 0x20);
        *(undefined4 *)(extraout_ECX + 0x174) = 0;
        FUN_004a83dc(iVar9,iVar5 + iVar8);
        *(undefined1 **)(unaff_EBP + 0x18) = &stack0xfffffd44;
        FUN_004796d9(unaff_EBP + 0x10);
        *(undefined1 *)(unaff_EBP + 0x1b) = *(undefined1 *)(unaff_EBP + 0x11);
        FUN_004b3e97(unaff_EBP + 0x14,unaff_EBP + 0x1c);
        *(int *)(unaff_EBP + 0x1c) =
             *(int *)(unaff_EBP + 0x1c) -
             ((uint)*(byte *)(unaff_EBP + 0x1b) << ((char)DAT_006f0088 + 1U & 0x1f));
        *(undefined2 *)(unaff_EBP + -0x46) = *(undefined2 *)(unaff_EBP + 0x14);
        *(undefined2 *)(unaff_EBP + -0x48) = *(undefined2 *)(unaff_EBP + 0x1c);
        FUN_004ab995(unaff_EBP + -0x54);
        FUN_004a7d36();
        FUN_004a8aa5();
        pvVar6 = operator_new(0x74);
        *(void **)(unaff_EBP + 0x18) = pvVar6;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (pvVar6 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_004b4533();
        }
        *(undefined1 *)(unaff_EBP + -4) = 2;
        *(undefined4 *)(unaff_EBP + 0x18) = uVar3;
        FUN_004b038a(*(undefined4 *)(unaff_EBP + 0xc));
        *(undefined1 *)(unaff_EBP + -4) = 4;
        *(undefined2 *)(unaff_EBP + -0x1c) = *(undefined2 *)(unaff_EBP + -100);
        *(undefined2 *)(unaff_EBP + -0x18) = *(undefined2 *)(unaff_EBP + -0x5c);
        *(undefined2 *)(unaff_EBP + -0x1a) = *(undefined2 *)(unaff_EBP + -0x68);
        *(undefined2 *)(unaff_EBP + -0x16) = *(undefined2 *)(unaff_EBP + -0x60);
        _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x1c);
        _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x18);
        iVar8 = *(int *)(*DAT_006e486c + 0x14);
        for (puVar4 = *(undefined4 **)(iVar8 + 0x84); puVar4 != *(undefined4 **)(iVar8 + 0x88);
            puVar4 = puVar4 + 1) {
          piVar7 = (int *)(**(code **)(*(int *)*puVar4 + 0x8c))();
          iVar5 = *piVar7;
          *(int **)(unaff_EBP + 0x1c) = piVar7;
          cVar2 = (**(code **)(iVar5 + 0x6c))();
          if (cVar2 != '\0') {
            (**(code **)(**(int **)(unaff_EBP + 0x1c) + 0x54))();
          }
        }
        FUN_004ad0c7(*(undefined4 *)(unaff_EBP + 0x18));
        FUN_004aa3e7(&DAT_006f0bc0);
        uVar1 = FUN_004b3d0e();
        return uVar1;
      }
      *(undefined1 *)(unaff_EBP + -0x11) = 0;
      FUN_004b0db9();
    }
    DAT_006d6184 = *(undefined4 *)(unaff_EBP + -0x40);
    FUN_005cf06d(*(undefined4 *)(unaff_EBP + -0x2c));
    FUN_004b3938();
    FUN_00586fdc();
    FUN_00584818(*(undefined4 *)(unaff_EBP + -0x34));
    DAT_006e54ac = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined1 *)(extraout_ECX + 0x51) = *(undefined1 *)(unaff_EBP + -0x12);
    FUN_0049ea67();
    if ((undefined4 *)(extraout_ECX + 0x208) != (undefined4 *)(unaff_EBP + -0x2b8)) {
      puVar4 = (undefined4 *)(unaff_EBP + -0x2b8);
      puVar10 = (undefined4 *)(extraout_ECX + 0x208);
      for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    *(undefined1 *)(extraout_ECX + 0x4e) = 1;
    FUN_004abb9e();
    (**(code **)(*(int *)DAT_006e486c[0x12] + 0x18))();
    FUN_005db0b7();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00635f6d(unaff_EBP + -0x2b8,8,0x40);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0049ea8c();
    uVar1 = *(undefined1 *)(unaff_EBP + -0x11);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

