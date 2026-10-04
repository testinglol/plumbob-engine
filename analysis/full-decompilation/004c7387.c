
void FUN_004c7387(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  int unaff_EBP;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x30) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0x80000000;
  *(undefined4 *)(unaff_EBP + -0x24) = 0x80000000;
  iVar3 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x18) = iVar3;
  if (iVar3 == 0) goto LAB_004c7815;
  if (999 < *(int *)(iVar3 + 0x20)) {
    puVar4 = (undefined4 *)
             FUN_004c1bfd(unaff_EBP + -0x100,*(undefined4 *)(unaff_EBP + 0x10),
                          *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                          *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x20),0,0);
    *(undefined4 *)(unaff_EBP + -0x30) = *puVar4;
    *(undefined4 *)(unaff_EBP + -0x2c) = puVar4[1];
    *(undefined4 *)(unaff_EBP + -0x28) = puVar4[2];
    *(undefined4 *)(unaff_EBP + -0x24) = puVar4[3];
    goto LAB_004c7815;
  }
  iVar5 = FUN_004c1ba2(*(undefined4 *)(unaff_EBP + 0x10));
  *(int *)(unaff_EBP + -0x10) = iVar5 + 10;
  iVar6 = FUN_004c1bb9(*(undefined4 *)(unaff_EBP + 0x10));
  if (iVar6 == 0) {
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
  }
  else {
    *(int *)(unaff_EBP + 0xc) = iVar6 + 10;
  }
  if (*(char *)(unaff_EBP + 0x24) == '\0') {
    *(bool *)(unaff_EBP + 0x24) = *(int *)(unaff_EBP + 0xc) != 0;
  }
  else {
    *(undefined1 *)(unaff_EBP + 0x24) = 1;
  }
  *(undefined1 *)(unaff_EBP + -0x1c) = 0;
  uVar7 = *(uint *)(unaff_EBP + 0x1c) & 4;
  *(uint *)(unaff_EBP + -0x20) = uVar7;
  if ((short)uVar7 != 0) {
    uVar1 = FUN_004b46de();
    *(undefined1 *)(unaff_EBP + -0x1c) = uVar1;
    FUN_004b46e2(1);
  }
  FUN_004c783e(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x20),iVar5,
               *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
               *(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x1c),
               *(undefined4 *)(unaff_EBP + 0x24));
  *(int *)(unaff_EBP + -0x30) = (int)*(short *)(unaff_EBP + -0x8e) + *(int *)(unaff_EBP + -0x7c);
  *(int *)(unaff_EBP + -0x2c) = (int)*(short *)(unaff_EBP + -0x90) + *(int *)(unaff_EBP + -0x74);
  *(int *)(unaff_EBP + -0x28) = (int)*(short *)(unaff_EBP + -0x8a) - *(int *)(unaff_EBP + -0x78);
  *(int *)(unaff_EBP + -0x24) = (int)*(short *)(unaff_EBP + -0x8c) - *(int *)(unaff_EBP + -0x70);
  cVar2 = FUN_004c7929(&DAT_006f0bc0);
  if (cVar2 == '\0') {
    uVar11 = *(undefined4 *)(unaff_EBP + 0x20);
    cVar2 = FUN_004b465e();
    if ((cVar2 != '\0') && (cVar2 = FUN_004b4665(), cVar2 != '\0')) {
      puVar8 = PTR_DAT_006c75e4;
      if ((*(char *)(unaff_EBP + -0x62) != '\0') &&
         (((*(int *)(unaff_EBP + -0x88) == 0x1f5 || (*(int *)(unaff_EBP + -0x88) == 0x1f7)) ||
          (puVar8 = PTR_DAT_006c7624, *(int *)(unaff_EBP + -0x88) == 0x1fa)))) {
        puVar8 = (undefined *)0x0;
      }
      if (puVar8 == (undefined *)0x0) {
        iVar6 = (int)*(short *)(unaff_EBP + -0x90);
        *(int *)(unaff_EBP + 0xc) = *(short *)(unaff_EBP + -0x8c) - iVar6;
        iVar3 = DAT_006f0bcc;
        iVar5 = DAT_006f0bbc / 2;
        iVar9 = (int)*(short *)(unaff_EBP + -0x8e);
        *(int *)(unaff_EBP + 0x18) = iVar5;
        *(int *)(unaff_EBP + 0x14) = iVar3 + (iVar5 * iVar6 + iVar9) * 2;
        iVar5 = DAT_006f0bd4 / 2;
        *(int *)(unaff_EBP + 0x24) = iVar5;
        *(int *)(unaff_EBP + -0x14) = iVar6;
        iVar3 = DAT_006f0bd0;
        *(int *)(unaff_EBP + -0x10) = iVar9;
        iVar10 = *(short *)(unaff_EBP + -0x8a) - iVar9;
        *(int *)(unaff_EBP + 0x1c) = iVar3 + (iVar5 * iVar6 + iVar9) * 2;
        SetRect((LPRECT)(unaff_EBP + -0xa8),*(int *)(unaff_EBP + -0x7c),*(int *)(unaff_EBP + -0x74),
                *(int *)(unaff_EBP + -0x78),*(int *)(unaff_EBP + -0x70));
        *(undefined ***)(unaff_EBP + -0xd8) = &PTR_FUN_00668958;
        *(undefined4 *)(unaff_EBP + -0xd4) = *(undefined4 *)(unaff_EBP + -0x98);
        *(undefined4 *)(unaff_EBP + -0xd0) = *(undefined4 *)(unaff_EBP + -0x98);
        *(undefined4 *)(unaff_EBP + -0xcc) = 0;
        *(undefined4 *)(unaff_EBP + -200) = 0;
        *(undefined1 *)(unaff_EBP + -0xc4) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined ***)(unaff_EBP + -0xc0) = &PTR_FUN_00668958;
        *(undefined4 *)(unaff_EBP + -0xbc) = *(undefined4 *)(unaff_EBP + -0x94);
        *(undefined4 *)(unaff_EBP + -0xb8) = *(undefined4 *)(unaff_EBP + -0x94);
        *(undefined4 *)(unaff_EBP + -0xb4) = 0;
        *(undefined4 *)(unaff_EBP + -0xb0) = 0;
        *(undefined1 *)(unaff_EBP + -0xac) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if ((*(byte *)(unaff_EBP + -100) & 1) == 0) {
          FUN_004ca790();
        }
        else {
          FUN_004ca8f1(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14),iVar10,
                       *(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0xd8,
                       *(undefined4 *)(unaff_EBP + -0x68),unaff_EBP + -0xc0,
                       *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                       *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x24),
                       unaff_EBP + -0xa8,*(undefined4 *)(unaff_EBP + 0x20));
        }
        if (*(int *)(*(int *)(unaff_EBP + -0x18) + 0x20) == 0x1fa) {
          if (DAT_006f0139 == '\0') {
            iVar3 = FUN_004c1bca(*(undefined4 *)(unaff_EBP + 0x10));
            *(undefined ***)(unaff_EBP + -0x60) = &PTR_FUN_00668958;
            *(int *)(unaff_EBP + -0x5c) = iVar3 + 10;
            *(int *)(unaff_EBP + -0x58) = iVar3 + 10;
            *(undefined4 *)(unaff_EBP + -0x54) = 0;
            *(undefined4 *)(unaff_EBP + -0x50) = 0;
            *(undefined1 *)(unaff_EBP + -0x4c) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 2;
            iVar3 = FUN_004c1bdb(*(undefined4 *)(unaff_EBP + 0x10));
            *(undefined ***)(unaff_EBP + -0x48) = &PTR_FUN_00668958;
            *(int *)(unaff_EBP + -0x44) = iVar3 + 10;
            *(int *)(unaff_EBP + -0x40) = iVar3 + 10;
            *(undefined4 *)(unaff_EBP + -0x3c) = 0;
            *(undefined4 *)(unaff_EBP + -0x38) = 0;
            *(undefined1 *)(unaff_EBP + -0x34) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 3;
            if ((*(byte *)(unaff_EBP + -100) & 1) == 0) {
              FUN_004ca790();
            }
            else {
              FUN_004ca8f1(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14),
                           iVar10,*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x60,
                           *(undefined4 *)(unaff_EBP + -0x68),unaff_EBP + -0x48,
                           *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                           *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x24),
                           unaff_EBP + -0xa8,*(undefined4 *)(unaff_EBP + 0x20));
            }
          }
          else {
            iVar3 = FUN_004c1bca(*(undefined4 *)(unaff_EBP + 0x10));
            *(undefined ***)(unaff_EBP + -0x48) = &PTR_FUN_00668958;
            *(int *)(unaff_EBP + -0x44) = iVar3 + 10;
            *(int *)(unaff_EBP + -0x40) = iVar3 + 10;
            *(undefined4 *)(unaff_EBP + -0x3c) = 0;
            *(undefined4 *)(unaff_EBP + -0x38) = 0;
            *(undefined1 *)(unaff_EBP + -0x34) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 4;
            iVar3 = FUN_004c1bdb(*(undefined4 *)(unaff_EBP + 0x10));
            *(undefined ***)(unaff_EBP + -0x60) = &PTR_FUN_00668958;
            *(int *)(unaff_EBP + -0x5c) = iVar3 + 10;
            *(int *)(unaff_EBP + -0x58) = iVar3 + 10;
            *(undefined4 *)(unaff_EBP + -0x54) = 0;
            *(undefined4 *)(unaff_EBP + -0x50) = 0;
            *(undefined1 *)(unaff_EBP + -0x4c) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 5;
            iVar3 = FUN_004c1bec(*(undefined4 *)(unaff_EBP + 0x10));
            *(undefined ***)(unaff_EBP + -0xf0) = &PTR_FUN_00668958;
            *(int *)(unaff_EBP + -0xec) = iVar3 + 10;
            *(int *)(unaff_EBP + -0xe8) = iVar3 + 10;
            *(undefined4 *)(unaff_EBP + -0xe4) = 0;
            *(undefined4 *)(unaff_EBP + -0xe0) = 0;
            *(undefined1 *)(unaff_EBP + -0xdc) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 6;
            if ((*(byte *)(unaff_EBP + -100) & 1) == 0) {
              (*DAT_006ede5c)();
            }
            else {
              (*DAT_006ede60)(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14),
                              iVar10,*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x48,
                              *(undefined4 *)(unaff_EBP + -0x68),unaff_EBP + -0x60,unaff_EBP + -0xf0
                              ,*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                              *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x24),
                              unaff_EBP + -0xa8,*(undefined4 *)(unaff_EBP + 0x20));
            }
            *(undefined ***)(unaff_EBP + -0xf0) = &PTR_LAB_00668678;
            *(undefined ***)(unaff_EBP + -0x60) = &PTR_LAB_00668678;
            *(undefined ***)(unaff_EBP + -0x48) = &PTR_LAB_00668678;
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined ***)(unaff_EBP + -0xc0) = &PTR_LAB_00668678;
        *(undefined ***)(unaff_EBP + -0xd8) = &PTR_LAB_00668678;
      }
      else {
        FUN_004c79b5(puVar8,uVar11);
      }
      goto LAB_004c77f4;
    }
    if (*(short *)(unaff_EBP + -0x20) == 0) goto LAB_004c7815;
    uVar11 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  else {
LAB_004c77f4:
    if (*(short *)(unaff_EBP + -0x20) == 0) goto LAB_004c7815;
    uVar11 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  FUN_004b46e2(uVar11);
LAB_004c7815:
  puVar4 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar4 = *(undefined4 *)(unaff_EBP + -0x30);
  puVar4[1] = *(undefined4 *)(unaff_EBP + -0x2c);
  puVar4[2] = *(undefined4 *)(unaff_EBP + -0x28);
  puVar4[3] = *(undefined4 *)(unaff_EBP + -0x24);
  return;
}

