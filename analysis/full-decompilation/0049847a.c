
undefined4 FUN_0049847a(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  byte *pbVar7;
  uint uVar8;
  int extraout_ECX;
  int iVar9;
  int *piVar10;
  int unaff_EBP;
  bool bVar11;
  
  FUN_00634c24();
  pcVar5 = *(char **)(unaff_EBP + 8);
  if (*pcVar5 < '\x01') {
LAB_00498816:
    *(undefined4 *)(extraout_ECX + 0x38) = 1;
  }
  else {
    iVar9 = *(int *)(DAT_006e54dc + 0x10) + -1;
    if (iVar9 <= *pcVar5) goto LAB_00498816;
    if ((pcVar5[1] < '\x01') || (iVar9 <= pcVar5[1])) goto LAB_00498816;
    if ((pcVar5[3] < '\x01') || (iVar9 <= pcVar5[3])) goto LAB_00498816;
    if ((pcVar5[4] < '\x01') || (iVar9 <= pcVar5[4])) goto LAB_00498816;
    *(undefined4 *)(extraout_ECX + 0x38) = 0;
    cVar3 = *(char *)(extraout_ECX + 0x44);
    if ((cVar3 == *(char *)(extraout_ECX + 0x46)) &&
       ((cVar3 == *(char *)(extraout_ECX + 0x45) && (cVar3 == *(char *)(extraout_ECX + 0x47))))) {
      *(undefined1 *)(unaff_EBP + -0xe) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004619d2(unaff_EBP + -0x70);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      puVar4 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x60);
      *(undefined4 *)(unaff_EBP + -0x14) = *puVar4;
      FUN_00461b74(puVar4 + 1);
      while( true ) {
        iVar9 = FUN_004619d2(unaff_EBP + -0x68);
        cVar3 = FUN_0046198c(iVar9 + 4);
        cVar3 = '\x01' - (cVar3 != '\0');
        *(char *)(unaff_EBP + -0x21) = cVar3;
        if (cVar3 == '\0') break;
        pcVar5 = (char *)FUN_00461941(unaff_EBP + -0x48);
        if ((*pcVar5 < '\x01') || (iVar9 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar9 <= *pcVar5)) {
LAB_004985e1:
          bVar11 = true;
        }
        else {
          if ((pcVar5[1] < '\x01') || (iVar9 <= pcVar5[1])) goto LAB_004985e1;
          uVar6 = FUN_00461941(unaff_EBP + -0x30);
          bVar11 = DAT_006e4a84 == 0;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          if (bVar11) {
            pbVar7 = (byte *)FUN_00489c8e(uVar6);
            uVar8 = ((byte)~*pbVar7 & 0x20) >> 5;
          }
          else {
            uVar8 = 1;
          }
          bVar11 = false;
          if (uVar8 == 0) goto LAB_004985e1;
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (bVar11) goto LAB_00498816;
        uVar6 = FUN_00461941(unaff_EBP + -0x38);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        puVar4 = (undefined4 *)FUN_004905f5(uVar6);
        uVar6 = *puVar4;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        cVar3 = *(char *)(extraout_ECX + 0x44);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
        if (((char)uVar6 != cVar3) || ((char)((uint)uVar6 >> 8) != *(char *)(extraout_ECX + 0x45)))
        goto LAB_004987eb;
        if (((char)*(undefined2 *)(unaff_EBP + -0x16) != *(char *)(extraout_ECX + 0x46)) ||
           ((char)((ushort)*(undefined2 *)(unaff_EBP + -0x16) >> 8) !=
            *(char *)(extraout_ECX + 0x47))) goto LAB_004987eb;
        uVar6 = FUN_00461941(unaff_EBP + -0x2c);
        puVar4 = DAT_006e486c;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_0043f371(*puVar4,uVar6,0);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        while (iVar9 = *(int *)(unaff_EBP + -0x40), iVar9 != 0) {
          if ((*(short *)(iVar9 + 0x8e) == 0) &&
             (cVar3 = FUN_00487d5b(*(undefined4 *)(iVar9 + 0x11c),4), cVar3 == '\0')) {
            *(undefined4 *)(extraout_ECX + 0x38) = 0xb;
            goto LAB_0049881d;
          }
          FUN_0043f3b9();
        }
        pcVar5 = (char *)FUN_00461941(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        iVar9 = FUN_004790b4();
        bVar1 = *(byte *)(*(int *)(*(int *)(iVar9 + 0x10) + *pcVar5 * 4) + (int)pcVar5[1]);
        *(byte *)(unaff_EBP + -0x5c) = bVar1;
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if ((bVar1 == 0x10) || (bVar1 < 0x10)) {
          *(undefined4 *)(extraout_ECX + 0x38) = 0x13;
          goto LAB_0049881d;
        }
        FUN_00461941(unaff_EBP + -0x28);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        cVar3 = FUN_00490021(unaff_EBP + -0x28);
        if (cVar3 != '\0') {
          FUN_00479737(unaff_EBP + -0x9c,unaff_EBP + -0x28);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          if ((*(byte *)(unaff_EBP + -0x9c) & 0x30) != 0) {
LAB_004987d9:
            *(undefined4 *)(extraout_ECX + 0x38) = 7;
            goto LAB_0049881d;
          }
          *(undefined4 *)(unaff_EBP + -0x58) = 0;
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          *(undefined4 *)(unaff_EBP + -0x54) = 3;
          *(undefined4 *)(unaff_EBP + -0x50) = 2;
          *(undefined4 *)(unaff_EBP + -0x4c) = 1;
          piVar10 = (int *)(unaff_EBP + -0x58);
          do {
            iVar9 = *piVar10;
            FUN_00461b74(&DAT_006e481c + iVar9 * 3);
            *(undefined1 *)(unaff_EBP + -0x1e) = 0;
            FUN_0046185f(unaff_EBP + -0x1c,unaff_EBP + -0x20);
            iVar2 = *(int *)(extraout_ECX + 0x3c);
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            if (((*(char *)(*(int *)(*(int *)(iVar2 + 0x10) + *(char *)(unaff_EBP + -0x1c) * 4) +
                           (int)*(char *)(unaff_EBP + -0x1b)) != -1) ||
                (cVar3 = FUN_0048ffea(unaff_EBP + -0x1c), cVar3 != '\0')) &&
               (uVar8 = FUN_0053c1aa(iVar9), (uVar8 & *(uint *)(unaff_EBP + -0x9c)) == uVar8))
            goto LAB_004987d9;
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
            piVar10 = piVar10 + 1;
          } while (*(int *)(unaff_EBP + -0x18) < 4);
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00461961();
      }
      cVar3 = FUN_00498182(extraout_ECX + 0x31,(undefined4 *)(extraout_ECX + 0x48));
      if (cVar3 != '\0') {
        uVar6 = 1;
        goto LAB_0049881f;
      }
      *(undefined4 *)(extraout_ECX + 0x48) = 0;
      *(undefined4 *)(extraout_ECX + 0x38) = 0x15;
    }
    else {
LAB_004987eb:
      *(undefined4 *)(extraout_ECX + 0x38) = 0x11;
    }
  }
LAB_0049881d:
  uVar6 = 0;
LAB_0049881f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

