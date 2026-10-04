
undefined4 FUN_0048fc3a(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  byte *pbVar6;
  uint uVar7;
  int extraout_ECX;
  int iVar8;
  int *piVar9;
  int unaff_EBP;
  bool bVar10;
  
  FUN_00634c24();
  pcVar4 = *(char **)(unaff_EBP + 8);
  if (*pcVar4 < '\x01') {
LAB_0048ffd0:
    *(undefined4 *)(extraout_ECX + 0x54) = 1;
  }
  else {
    iVar8 = *(int *)(DAT_006e54dc + 0x10) + -1;
    if (iVar8 <= *pcVar4) goto LAB_0048ffd0;
    if ((pcVar4[1] < '\x01') || (iVar8 <= pcVar4[1])) goto LAB_0048ffd0;
    if ((pcVar4[3] < '\x01') || (iVar8 <= pcVar4[3])) goto LAB_0048ffd0;
    if ((pcVar4[4] < '\x01') || (iVar8 <= pcVar4[4])) goto LAB_0048ffd0;
    *(undefined4 *)(extraout_ECX + 0x54) = 0;
    cVar2 = *(char *)(extraout_ECX + 0x50);
    if ((cVar2 == *(char *)(extraout_ECX + 0x52)) &&
       ((cVar2 == *(char *)(extraout_ECX + 0x51) && (cVar2 == *(char *)(extraout_ECX + 0x53))))) {
      *(undefined1 *)(unaff_EBP + -0xe) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004619d2(unaff_EBP + -0x70);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      puVar3 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x60);
      *(undefined4 *)(unaff_EBP + -0x14) = *puVar3;
      FUN_00461b74(puVar3 + 1);
      while( true ) {
        iVar8 = FUN_004619d2(unaff_EBP + -0x68);
        cVar2 = FUN_0046198c(iVar8 + 4);
        cVar2 = '\x01' - (cVar2 != '\0');
        *(char *)(unaff_EBP + -0x21) = cVar2;
        if (cVar2 == '\0') break;
        pcVar4 = (char *)FUN_00461941(unaff_EBP + -0x48);
        if ((*pcVar4 < '\x01') || (iVar8 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar8 <= *pcVar4)) {
LAB_0048fda1:
          bVar10 = true;
        }
        else {
          if ((pcVar4[1] < '\x01') || (iVar8 <= pcVar4[1])) goto LAB_0048fda1;
          uVar5 = FUN_00461941(unaff_EBP + -0x30);
          bVar10 = DAT_006e4a84 == 0;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          if (bVar10) {
            pbVar6 = (byte *)FUN_00489c8e(uVar5);
            uVar7 = ((byte)~*pbVar6 & 0x20) >> 5;
          }
          else {
            uVar7 = 1;
          }
          bVar10 = false;
          if (uVar7 == 0) goto LAB_0048fda1;
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (bVar10) goto LAB_0048ffd0;
        uVar5 = FUN_00461941(unaff_EBP + -0x38);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        puVar3 = (undefined4 *)FUN_004905f5(uVar5);
        uVar5 = *puVar3;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        cVar2 = *(char *)(extraout_ECX + 0x50);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar5;
        if (((char)uVar5 != cVar2) || ((char)((uint)uVar5 >> 8) != *(char *)(extraout_ECX + 0x51)))
        goto LAB_0048ffa5;
        if (((char)*(undefined2 *)(unaff_EBP + -0x16) != *(char *)(extraout_ECX + 0x52)) ||
           ((char)((ushort)*(undefined2 *)(unaff_EBP + -0x16) >> 8) !=
            *(char *)(extraout_ECX + 0x53))) goto LAB_0048ffa5;
        uVar5 = FUN_00461941(unaff_EBP + -0x2c);
        puVar3 = DAT_006e486c;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_0043f371(*puVar3,uVar5,0);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        while (iVar8 = *(int *)(unaff_EBP + -0x40), iVar8 != 0) {
          if ((*(short *)(iVar8 + 0x8e) == 0) &&
             (cVar2 = FUN_00487d5b(*(undefined4 *)(iVar8 + 0x11c),4), cVar2 == '\0')) {
            *(undefined4 *)(extraout_ECX + 0x54) = 0xb;
            goto LAB_0048ffd7;
          }
          FUN_0043f3b9();
        }
        pcVar4 = (char *)FUN_00461941(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        iVar8 = FUN_004790b8();
        cVar2 = *(char *)(*(int *)(*(int *)(iVar8 + 0x10) + *pcVar4 * 4) + (int)pcVar4[1]);
        *(char *)(unaff_EBP + -0x5c) = cVar2;
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if (cVar2 != -1) {
          *(undefined4 *)(extraout_ECX + 0x54) = 0x1d;
          goto LAB_0048ffd7;
        }
        FUN_00461941(unaff_EBP + -0x28);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        cVar2 = FUN_00490021(unaff_EBP + -0x28);
        if (cVar2 != '\0') {
          FUN_00479737(unaff_EBP + -0x9c,unaff_EBP + -0x28);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          if ((*(byte *)(unaff_EBP + -0x9c) & 0x30) != 0) {
LAB_0048ff9c:
            *(undefined4 *)(extraout_ECX + 0x54) = 7;
            goto LAB_0048ffd7;
          }
          *(undefined4 *)(unaff_EBP + -0x58) = 0;
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          *(undefined4 *)(unaff_EBP + -0x54) = 3;
          *(undefined4 *)(unaff_EBP + -0x50) = 2;
          *(undefined4 *)(unaff_EBP + -0x4c) = 1;
          piVar9 = (int *)(unaff_EBP + -0x58);
          do {
            iVar8 = *piVar9;
            FUN_00461b74(&DAT_006e481c + iVar8 * 3);
            *(undefined1 *)(unaff_EBP + -0x1e) = 0;
            FUN_0046185f(unaff_EBP + -0x1c,unaff_EBP + -0x20);
            iVar1 = *(int *)(extraout_ECX + 0x38);
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            if (((*(byte *)(*(int *)(*(int *)(iVar1 + 0x10) + *(char *)(unaff_EBP + -0x1c) * 4) +
                           (int)*(char *)(unaff_EBP + -0x1b)) < 0x10) ||
                (cVar2 = FUN_0048ffea(unaff_EBP + -0x1c), cVar2 != '\0')) &&
               (uVar7 = FUN_0053c1aa(iVar8), (uVar7 & *(uint *)(unaff_EBP + -0x9c)) == uVar7))
            goto LAB_0048ff9c;
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
            piVar9 = piVar9 + 1;
          } while (*(int *)(unaff_EBP + -0x18) < 4);
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00461961();
      }
      cVar2 = FUN_0048fb2b(extraout_ECX + 0x40,(undefined4 *)(extraout_ECX + 0x48));
      if (cVar2 != '\0') {
        uVar5 = 1;
        goto LAB_0048ffd9;
      }
      *(undefined4 *)(extraout_ECX + 0x48) = 0;
      *(undefined4 *)(extraout_ECX + 0x54) = 0x15;
    }
    else {
LAB_0048ffa5:
      *(undefined4 *)(extraout_ECX + 0x54) = 0x11;
    }
  }
LAB_0048ffd7:
  uVar5 = 0;
LAB_0048ffd9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

