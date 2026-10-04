
void FUN_004cbf52(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  void *pvVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  int extraout_ECX;
  uint extraout_ECX_00;
  int unaff_EBP;
  int iVar13;
  bool bVar14;
  uint uStack_1d4;
  char *pcStack_1d0;
  int iStack_1cc;
  code *pcStack_1c8;
  
  FUN_00634c24();
  bVar14 = DAT_006f29ec != '\0';
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  if ((bVar14) && (DAT_006f0e9c == 0)) {
    pcStack_1c8 = (code *)s_catalogreport_txt_006c78e4;
    iStack_1cc = 0x4cbf8b;
    DAT_006f0e9c = FUN_00635845();
  }
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -0xe) = 1;
  cVar4 = FUN_005a5e72();
  if (cVar4 == '\0') {
    iVar5 = *(int *)(extraout_ECX + 0x24);
    if (iVar5 == 1) {
      iVar5 = (*(undefined4 **)(extraout_ECX + 0x28))[0x18];
      *(undefined4 *)(unaff_EBP + -0x18) = **(undefined4 **)(extraout_ECX + 0x28);
      *(int *)(unaff_EBP + -0x24) = (int)*(short *)(iVar5 + 0x52);
    }
    else if (iVar5 == 2) {
      iVar5 = *(int *)(extraout_ECX + 0x44);
      if ((iVar5 < 1) || (0x1d < iVar5)) goto LAB_004cc0c9;
      puVar10 = (undefined4 *)FUN_004c656a();
      uVar11 = *puVar10;
      *(int *)(unaff_EBP + -0x24) = iVar5;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar11;
    }
    else {
      if (iVar5 == 3) {
        iVar5 = *(int *)(extraout_ECX + 0x40);
      }
      else {
        if (((iVar5 != 4) ||
            ((iVar5 = *(int *)(extraout_ECX + 0x3c), 0x1e < iVar5 && (iVar5 < 0xf8)))) ||
           ((0xff < iVar5 && (iVar5 < 0xffff)))) goto LAB_004cc0c9;
        iVar5 = iVar5 + 0x200;
      }
      *(int *)(unaff_EBP + -0x24) = iVar5;
      puVar10 = (undefined4 *)FUN_004c656a();
      *(undefined4 *)(unaff_EBP + -0x18) = *puVar10;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      pcStack_1c8 = (code *)(unaff_EBP - 0x1c);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      iStack_1cc = *(undefined4 *)(unaff_EBP + -0x24);
      pcStack_1d0 = *(char **)(unaff_EBP + -0x18);
      uStack_1d4 = 0x4cc06a;
      FUN_005a55f6();
      if (*(int *)(unaff_EBP + -0x1c) != 0) {
        pcStack_1c8 = (code *)0x4cc07c;
        FUN_005a5e48();
        *(undefined1 *)(unaff_EBP + -0xe) = 0;
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
      }
      if ((*(int *)(extraout_ECX + 0x28) == 0) || (cVar4 = FUN_004576f4(), cVar4 != '\0')) {
        *(undefined1 *)(unaff_EBP + -0xe) = 1;
        cVar4 = FUN_005a5e72();
        if ((cVar4 != '\0') &&
           ((iVar5 = FUN_004096c2(), *(int *)(iVar5 + 0x1c) != 0x4a ||
            (iVar5 = FUN_004096c2(), *(int *)(iVar5 + 0x20) != 0x25)))) {
          pcStack_1c8 = (code *)0x4cc0c5;
          FUN_005a5e48();
          *(undefined1 *)(unaff_EBP + -0xd) = 0;
        }
      }
    }
  }
LAB_004cc0c9:
  if (DAT_006f0e9c != 0) {
    iStack_1cc = *(undefined4 *)(extraout_ECX + 4);
    pcStack_1c8 = (code *)(uint)*(byte *)(unaff_EBP + -0xd);
    pcStack_1d0 = s__s__loaded____d__generable____d_006c78c0;
    uStack_1d4 = DAT_006f0e9c;
    FUN_006357d8();
  }
  if ((*(char *)(unaff_EBP + -0xe) != '\0') && (DAT_006f29ec != '\0')) {
    pcStack_1c8 = (code *)0x4cc106;
    FUN_005a5e48();
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  cVar4 = FUN_005a5e72();
  iVar5 = extraout_ECX;
  if ((cVar4 == '\0') &&
     ((*(int *)(extraout_ECX + 0x24) != 1 || (cVar4 = FUN_004576f4(), cVar4 != '\0')))) {
    pcStack_1c8 = FUN_005c1719;
    iStack_1cc = 2;
    uStack_1d4 = unaff_EBP - 0x30;
    pcStack_1d0 = (char *)0x4;
    FUN_00635e55();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar5 = FUN_004096c2();
    iVar5 = *(int *)(iVar5 + 0x20);
    *(int *)(unaff_EBP + -0x28) = iVar5;
    *(int *)(unaff_EBP + -0x48) = iVar5 + -8;
    *(int *)(unaff_EBP + -0x44) = iVar5 + -8;
    piVar6 = (int *)FUN_004096c2();
    pcStack_1c8 = (code *)0x4cc175;
    cVar4 = (**(code **)(*piVar6 + 0x20))();
    if (cVar4 != '\0') {
      iVar13 = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(int *)(unaff_EBP + -0x1c) = iVar5 - (iVar5 >> 0x1f);
      *(undefined4 *)(unaff_EBP + -0x34) = 1;
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) >> 1;
      while( true ) {
        *(int *)(unaff_EBP + -0x14) =
             *(int *)(unaff_EBP + -0x38 + iVar13) * iVar5 + *(int *)(unaff_EBP + -0x1c);
        piVar6 = (int *)FUN_004096c2();
        piVar7 = (int *)FUN_004096c2();
        iVar8 = (**(code **)(*piVar7 + 0xd0))();
        iVar5 = *piVar6;
        *(uint *)(unaff_EBP + -0x14) =
             ((uint)(iVar8 * *(int *)(unaff_EBP + -0x1c)) >> 1) + *(int *)(unaff_EBP + -0x14);
        iVar5 = (**(code **)(iVar5 + 0xcc))();
        iVar13 = iVar13 + 4;
        *(uint *)(unaff_EBP + -0x68 + iVar13) =
             (uint)*(ushort *)(iVar5 + *(int *)(unaff_EBP + -0x14) * 2);
        if (7 < iVar13) break;
        iVar5 = *(int *)(unaff_EBP + -0x28);
      }
      piVar6 = (int *)FUN_004096c2();
      pcStack_1c8 = (code *)0x4cc1fd;
      (**(code **)(*piVar6 + 0x24))();
    }
    pcStack_1d0 = *(char **)(unaff_EBP + -0x20);
    pcStack_1c8 = (code *)(unaff_EBP + -0x48);
    iStack_1cc = unaff_EBP + -100;
    uStack_1d4 = 0x4cc212;
    cVar4 = FUN_004e58e7();
    if (cVar4 != '\0') {
      pcStack_1c8 = (code *)0x4cc224;
      pvVar9 = operator_new(100);
      *(void **)(unaff_EBP + -0x14) = pvVar9;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar9 != (void *)0x0) {
        FUN_005dfb13();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      pcStack_1c8 = (code *)0x4cc24c;
      FUN_005a5e48();
      cVar4 = FUN_005a5e72();
      if (cVar4 != '\0') {
        puVar10 = (undefined4 *)FUN_004096c2();
        pcStack_1c8 = (code *)0x0;
        iStack_1cc = 0;
        uVar11 = *puVar10;
        *(uint **)(unaff_EBP + -0x14) = &uStack_1d4;
        *(undefined4 *)(unaff_EBP + -0x14) = uVar11;
        uStack_1d4 = extraout_ECX_00;
        pcStack_1d0 = (char *)extraout_ECX_00;
        FUN_00436a50(4);
        cVar4 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0xc))
                          (*(int *)(unaff_EBP + -0x48) * 2,*(undefined4 *)(unaff_EBP + -0x44));
        if (cVar4 == '\0') {
          pcStack_1c8 = (code *)0x4cc34d;
          FUN_005a5e48();
        }
        else {
          piVar6 = (int *)FUN_004096c2();
          pcStack_1c8 = (code *)0x4cc2a3;
          cVar4 = (**(code **)(*piVar6 + 0x20))();
          if (cVar4 != '\0') {
            iVar5 = FUN_004096c2();
            uVar11 = *(undefined4 *)(iVar5 + 0x14);
            *(undefined4 *)(unaff_EBP + -0x58) = uVar11;
            uVar1 = *(undefined4 *)(iVar5 + 0x18);
            *(undefined4 *)(unaff_EBP + -0x54) = uVar1;
            uVar2 = *(undefined4 *)(iVar5 + 0x1c);
            *(undefined4 *)(unaff_EBP + -0x50) = uVar2;
            uVar3 = *(undefined4 *)(iVar5 + 0x20);
            *(undefined4 *)(unaff_EBP + -0x40) = uVar11;
            *(undefined4 *)(unaff_EBP + -0x4c) = uVar3;
            *(undefined4 *)(unaff_EBP + -0x3c) = uVar1;
            *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
            *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
            piVar6 = (int *)FUN_004096c2();
            pcStack_1c8 = (code *)(unaff_EBP + -0x40);
            iVar5 = *piVar6;
            iStack_1cc = unaff_EBP + -0x58;
            pcStack_1d0 = (char *)0x4cc2f7;
            pcStack_1d0 = (char *)FUN_004096c2();
            uStack_1d4 = 0x4cc300;
            (**(code **)(iVar5 + 0x9c))();
            iVar5 = *(int *)(unaff_EBP + -0x50) - *(int *)(unaff_EBP + -0x58);
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + iVar5;
            *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + iVar5;
            uStack_1d4 = 0x4cc313;
            piVar6 = (int *)FUN_004096c2();
            uStack_1d4 = 0;
            iVar5 = *piVar6;
            uVar11 = FUN_004096c2(unaff_EBP + -0x58,unaff_EBP + -0x40);
            (**(code **)(iVar5 + 0x9c))(uVar11);
            piVar6 = (int *)FUN_004096c2();
            (**(code **)(*piVar6 + 0x24))(0x10);
          }
        }
      }
      iVar5 = 2;
      do {
        pcStack_1c8 = (code *)0x4cc35c;
        FUN_005a5e48();
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    FUN_005a5e72();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    pcStack_1c8 = (code *)0x2;
    pcStack_1d0 = (char *)(unaff_EBP + -0x30);
    iStack_1cc = 4;
    uStack_1d4 = 0x4cc385;
    FUN_00635f6d();
    iVar5 = *(int *)(unaff_EBP + -0x20);
  }
  if ((((*(char *)(unaff_EBP + -0xd) == '\0') && (*(int **)(unaff_EBP + -0x18) != (int *)0x0)) &&
      (cVar4 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x20))(), cVar4 != '\0')) &&
     (cVar4 = FUN_005a5e72(), cVar4 != '\0')) {
    piVar6 = (int *)FUN_004096c2();
    pcStack_1c8 = (code *)0x4cc3c9;
    cVar4 = (**(code **)(*piVar6 + 0x20))();
    if (cVar4 != '\0') {
      piVar6 = (int *)FUN_004096c2();
      uVar11 = (**(code **)(*piVar6 + 0xcc))();
      *(undefined4 *)(unaff_EBP + -0x28) = uVar11;
      piVar6 = (int *)FUN_004096c2();
      uVar12 = (**(code **)(*piVar6 + 0xd0))();
      iVar13 = FUN_004096c2();
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar13 + 0x20);
      iVar13 = FUN_004096c2();
      pcStack_1d0 = *(char **)(iVar13 + 0x1c);
      pcStack_1c8 = (code *)0x0;
      iStack_1cc = *(undefined4 *)(unaff_EBP + -0x14);
      uStack_1d4 = uVar12 >> 1;
      uVar11 = FUN_004b7f6b(*(undefined4 *)(unaff_EBP + -0x28));
      *(undefined4 *)(unaff_EBP + -0x20) = uVar11;
      piVar6 = (int *)FUN_004096c2();
      pcStack_1c8 = (code *)0x4cc438;
      (**(code **)(*piVar6 + 0x24))();
      if (*(int *)(unaff_EBP + -0x20) != 0) {
        iStack_1cc = unaff_EBP + -0xa4;
        pcStack_1c8 = (code *)0x0;
        pcStack_1d0 = (char *)0x4cc458;
        FUN_0046f824();
        pcStack_1c8 = (code *)s_Catalog_006c78b8;
        *(undefined ***)(unaff_EBP + -0xb0) = &PTR_FUN_0066651c;
        iStack_1cc = 0x4cc474;
        FUN_0046f847();
        piVar6 = *(int **)(unaff_EBP + -0x18);
        pcStack_1c8 = (code *)(unaff_EBP + -0xb0);
        iStack_1cc = *(undefined4 *)(unaff_EBP + -0x24);
        pcStack_1d0 = (char *)0x424d505f;
        uStack_1d4 = *(uint *)(unaff_EBP + -0x20);
        (**(code **)(*piVar6 + 0x74))();
        iVar13 = FUN_00401f6f();
        if ((iVar13 != 0) && (DAT_006f0e9c != 0)) {
          FUN_0046f824(unaff_EBP + -0x1b4,0,0x104);
          iVar13 = *piVar6;
          *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_006664e8;
          (**(code **)(iVar13 + 0x24))(unaff_EBP + -0x1c0);
          FUN_006357d8(DAT_006f0e9c,s__s__Could_not_add_to_resource_fi_006c7890,
                       *(undefined4 *)(iVar5 + 4),*(undefined4 *)(unaff_EBP + -0x1bc));
        }
        (**(code **)(*piVar6 + 0x1c))();
        FUN_00401f6f();
        pcStack_1c8 = (code *)0x4cc50b;
        FUN_00465a06();
        FUN_00401f6f();
      }
    }
  }
  cVar4 = FUN_005a5e72();
  if (cVar4 == '\0') {
    pcStack_1c8 = (code *)0x4cc529;
    FUN_005a5e1c();
  }
  if (DAT_006f0e9c != 0) {
    pcStack_1c8 = (code *)0x4cc538;
    FUN_006372ee();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

