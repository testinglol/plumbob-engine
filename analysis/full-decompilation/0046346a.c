
uint FUN_0046346a(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  char cVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  char cVar11;
  int extraout_ECX;
  int iVar12;
  int unaff_EBP;
  undefined4 *puVar13;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 400) == 0) {
    puVar4 = *(uint **)(unaff_EBP + 8);
    uVar8 = FUN_00422aee(puVar4,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                         *(undefined4 *)(unaff_EBP + 0x14));
    if ((char)uVar8 != '\0') {
      *(undefined4 *)(unaff_EBP + 8) = DAT_006e54dc;
      puVar10 = (undefined4 *)(unaff_EBP + -0x48);
      for (iVar12 = 0xb; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar12 = *(int *)(extraout_ECX + 400);
      *(int *)(unaff_EBP + 0x14) = iVar12;
      if (iVar12 == 0) {
        *(int *)(unaff_EBP + 0x14) = extraout_ECX;
      }
      iVar12 = *(int *)(unaff_EBP + 0x14);
      while (iVar12 != 0) {
        iVar12 = FUN_006359f2(*(undefined4 *)(unaff_EBP + 0x14),0,&cXMTObject::RTTI_Type_Descriptor,
                              &cXPortal::RTTI_Type_Descriptor,0);
        if (*(short *)(*(int *)(iVar12 + 0x118) + 0x5c) != 0) {
          iVar9 = FUN_00435968();
          *(int *)(unaff_EBP + -0x10) = iVar9;
          if (iVar9 != 0) {
            uVar8 = puVar4[1];
            uVar5 = *puVar4;
            uVar1 = *(undefined4 *)(iVar12 + 0x1a0);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            cVar6 = (char)uVar1 + (char)((int)uVar8 >> 4);
            uVar1 = *(undefined4 *)(iVar12 + 0x1a4);
            *(char *)(unaff_EBP + 0x10) = cVar6;
            cVar11 = (char)uVar1 + (char)((int)uVar5 >> 4);
            uVar1 = *(undefined4 *)(iVar12 + 0x1a8);
            *(char *)(unaff_EBP + 0x11) = cVar11;
            *(char *)(unaff_EBP + 0x12) = (char)uVar1 + (char)*(undefined4 *)(unaff_EBP + 0xc);
            if (((('\0' < cVar6) &&
                 (iVar12 = *(int *)(*(int *)(unaff_EBP + 8) + 0x10) + -1, cVar6 < iVar12)) &&
                ('\0' < cVar11)) && (cVar11 < iVar12)) {
              puVar10 = (undefined4 *)FUN_00479737(unaff_EBP + -0x74,unaff_EBP + 0x10);
              uVar1 = *(undefined4 *)(unaff_EBP + -0x10);
              puVar13 = (undefined4 *)(unaff_EBP + -0x48);
              for (iVar12 = 0xb; iVar12 != 0; iVar12 = iVar12 + -1) {
                *puVar13 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar13 = puVar13 + 1;
              }
              iVar12 = FUN_00435221(uVar1,0);
              uVar8 = (uint)*(ushort *)(unaff_EBP + -0x40 + iVar12 * 2);
              if (uVar8 != 1) {
                DAT_006e4a7c = 0x16;
                goto LAB_004634ee;
              }
            }
            *(undefined1 *)(unaff_EBP + -4) = 0;
          }
        }
        iVar12 = *(int *)(*(int *)(unaff_EBP + 0x14) + 0x18c);
        *(int *)(unaff_EBP + 0x14) = iVar12;
      }
      uVar8 = *puVar4 & 0xfffffff8 | 8;
      if ((puVar4[1] == (puVar4[1] & 0xfffffff0 | 8)) && (*puVar4 == uVar8)) {
        uVar8 = CONCAT31((int3)((*puVar4 & 0xfffffff8) >> 8),1);
        goto LAB_00463637;
      }
      DAT_006e4a7c = 3;
    }
LAB_004634ee:
    uVar8 = uVar8 & 0xffffff00;
  }
  else {
    uVar1 = *(undefined4 *)(extraout_ECX + 0x1a4);
    uVar2 = (*(undefined4 **)(unaff_EBP + 8))[1];
    uVar3 = *(undefined4 *)(extraout_ECX + 0x1a0);
    *(undefined4 *)(unaff_EBP + -0x14) = **(undefined4 **)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
    piVar7 = (int *)FUN_00422055(uVar3,uVar1);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) - piVar7[1];
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) - *piVar7;
    uVar8 = (**(code **)(**(int **)(extraout_ECX + 400) + 0x54))
                      (unaff_EBP + -0x14,*(int *)(unaff_EBP + 0xc) - *(int *)(extraout_ECX + 0x1a8),
                       *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
  }
LAB_00463637:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

