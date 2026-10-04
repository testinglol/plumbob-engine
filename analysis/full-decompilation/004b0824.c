
void FUN_004b0824(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  undefined1 extraout_var;
  byte *pbVar4;
  byte *pbVar5;
  char cVar6;
  int unaff_EBP;
  undefined4 local_20;
  
  FUN_00634c24();
  iVar2 = 0;
  do {
    *(undefined1 *)(*(int *)(extraout_ECX + 0x1ec) + iVar2) = 0;
    *(undefined1 *)(*(int *)(extraout_ECX + 0x1f0) + iVar2) = 0x40;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x80);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  do {
    iVar2 = 0;
    do {
      cVar1 = *(char *)(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -0x12) = 0;
      cVar6 = (char)iVar2;
      *(char *)(unaff_EBP + -0x14) = cVar6;
      *(char *)(unaff_EBP + -0x13) = cVar1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((((-1 < cVar6) && ((int)cVar6 < *(int *)(DAT_006e54dc + 0x10))) && (-1 < cVar1)) &&
         ((int)cVar1 < *(int *)(DAT_006e54dc + 0x10))) {
        local_20 = unaff_EBP + -0x14;
        FUN_004a8000();
        *(undefined4 **)(unaff_EBP + -0x1c) = &local_20;
        local_20 = CONCAT13(extraout_var,
                            CONCAT12(*(undefined1 *)(unaff_EBP + -0x12),
                                     CONCAT11(*(undefined1 *)(unaff_EBP + -0x13),
                                              *(undefined1 *)(unaff_EBP + -0x14))));
        FUN_004796d9(unaff_EBP + -0x10);
        iVar3 = (int)*(char *)(unaff_EBP + -0x13) + (int)*(char *)(unaff_EBP + -0x14);
        pbVar4 = (byte *)(*(int *)(extraout_ECX + 0x1ec) + iVar3);
        pbVar5 = (byte *)(unaff_EBP + -0x10);
        if (*(byte *)(unaff_EBP + -0x10) <= *pbVar4) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
        pbVar4 = (byte *)(*(int *)(extraout_ECX + 0x1ec) + iVar3);
        pbVar5 = (byte *)(unaff_EBP + -0xf);
        if (*(byte *)(unaff_EBP + -0xf) <= *pbVar4) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
        pbVar4 = (byte *)(*(int *)(extraout_ECX + 0x1ec) + iVar3);
        pbVar5 = (byte *)(unaff_EBP + -0xe);
        if (*(byte *)(unaff_EBP + -0xe) <= *pbVar4) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
        pbVar4 = (byte *)(*(int *)(extraout_ECX + 0x1ec) + iVar3);
        pbVar5 = (byte *)(unaff_EBP + -0xd);
        if (*(byte *)(unaff_EBP + -0xd) <= *pbVar4) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
        pbVar4 = (byte *)(*(int *)(extraout_ECX + 0x1f0) + iVar3);
        pbVar5 = (byte *)(unaff_EBP + -0x10);
        if (*pbVar4 <= *(byte *)(unaff_EBP + -0x10)) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
        pbVar4 = (byte *)(*(int *)(extraout_ECX + 0x1f0) + iVar3);
        pbVar5 = (byte *)(unaff_EBP + -0xf);
        if (*pbVar4 <= *(byte *)(unaff_EBP + -0xf)) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
        pbVar4 = (byte *)(*(int *)(extraout_ECX + 0x1f0) + iVar3);
        pbVar5 = (byte *)(unaff_EBP + -0xe);
        if (*pbVar4 <= *(byte *)(unaff_EBP + -0xe)) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
        pbVar4 = (byte *)(iVar3 + *(int *)(extraout_ECX + 0x1f0));
        pbVar5 = (byte *)(unaff_EBP + -0xd);
        if (*pbVar4 <= *(byte *)(unaff_EBP + -0xd)) {
          pbVar5 = pbVar4;
        }
        *pbVar4 = *pbVar5;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x40);
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
  } while (*(int *)(unaff_EBP + -0x18) < 0x40);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

