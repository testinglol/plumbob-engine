
undefined4 FUN_004550e0(void)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  short *psVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  int *extraout_ECX;
  char cVar9;
  int unaff_EBP;
  ushort uVar10;
  int iVar11;
  
  FUN_00634c24();
  cVar3 = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
  *(char *)(unaff_EBP + -0x10) = cVar3;
  cVar9 = (char)(*(int *)(unaff_EBP + 8) >> 4);
  *(char *)(unaff_EBP + -0xf) = cVar9;
  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(char *)(unaff_EBP + 0x1c) != '\0') goto LAB_0045522f;
  if ((((cVar3 < '\x01') || (iVar11 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar11 <= cVar3)) ||
      (cVar9 < '\x01')) || (iVar11 <= cVar9)) {
    DAT_006e4a7c = 1;
  }
  else {
    psVar5 = (short *)FUN_00435bca(unaff_EBP + -0x10);
    if (*psVar5 == (short)extraout_ECX[0x21]) {
      uVar8 = FUN_00433116(extraout_ECX + 0x3d,1);
      cVar3 = FUN_00433136(uVar8);
      if (cVar3 == '\0') {
        iVar11 = extraout_ECX[0x3d];
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 0xc);
        iVar2 = extraout_ECX[0x3e];
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + 8) - iVar11;
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 0xc) - iVar2;
        piVar6 = (int *)FUN_00422055(0,0);
        if ((*(int *)(unaff_EBP + -0x14) != piVar6[1]) || (*(int *)(unaff_EBP + -0x18) != *piVar6))
        {
          FUN_00422055(0,0);
          iVar11 = FUN_00452129(unaff_EBP + -0x18);
          uVar7 = FUN_00435a8f(extraout_ECX + 0x3f,iVar11);
          if ((uVar7 & 1) == 0) {
            iVar2 = extraout_ECX[0x44];
            *(char *)(unaff_EBP + 0x1c) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
            *(char *)(unaff_EBP + 0x1d) = (char)(*(int *)(unaff_EBP + 8) >> 4);
            *(char *)(unaff_EBP + 0x1e) = (char)iVar2;
            *(undefined1 *)(unaff_EBP + -4) = 1;
            uVar7 = FUN_00435a8f(unaff_EBP + 0x1c,(iVar11 + 4) % 8);
            *(undefined1 *)(unaff_EBP + -4) = 0;
            if ((uVar7 & 1) == 0) goto LAB_0045522f;
          }
          goto LAB_004552d1;
        }
      }
LAB_0045522f:
      cVar3 = (**(code **)(*extraout_ECX + 0x54))
                        (unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0x10),
                         *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18));
      if (cVar3 != '\0') {
        uVar10 = (ushort)*(undefined4 *)(unaff_EBP + 0x20) & 7;
        if ((*(int *)(unaff_EBP + 0x14) != 0) && (*(char *)(unaff_EBP + 0x24) != '\0')) {
          uVar1 = *(ushort *)(extraout_ECX + 0x13);
          *(undefined4 *)(unaff_EBP + -0x28) = 0;
          *(undefined4 *)(unaff_EBP + -0x24) = 0;
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          iVar11 = *(int *)(unaff_EBP + 0x14);
          *(ushort *)(extraout_ECX + 0x13) = uVar10;
          FUN_00433dbb(iVar11 + 0xf4,unaff_EBP + -0x28);
          sVar4 = FUN_00476f33(unaff_EBP + -0x28,*(undefined4 *)(*(int *)(unaff_EBP + 0x14) + 0x110)
                              );
          *(ushort *)(extraout_ECX + 0x13) = uVar1 & 7;
          if (sVar4 != 0) {
            *(undefined2 *)((int)extraout_ECX + 0xb6) = 0;
            goto LAB_004552d1;
          }
        }
        (**(code **)(*extraout_ECX + 0x58))
                  (unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14)
                   ,*(undefined4 *)(unaff_EBP + 0x18),1);
        *(ushort *)(extraout_ECX + 0x13) = uVar10;
        if ((*(short *)(extraout_ECX[0x46] + 0x12) == 2) &&
           (iVar11 = FUN_006359f2(extraout_ECX,0,&cXObject::RTTI_Type_Descriptor,
                                  &cXPerson::RTTI_Type_Descriptor,0), iVar11 != 0)) {
          (**(code **)(**(int **)(iVar11 + 0xadc) + 0x20))(1);
        }
        uVar8 = 1;
        goto LAB_00455327;
      }
    }
  }
LAB_004552d1:
  uVar8 = 0;
LAB_00455327:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

