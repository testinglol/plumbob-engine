
void FUN_004929ee(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  iVar4 = DAT_006e54dc;
  *(int *)(unaff_EBP + -0x20) = DAT_006e54dc;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  iVar4 = *(int *)(iVar4 + 0x10);
  iVar2 = *(int *)(extraout_ECX + 0x3c);
  *(int *)(unaff_EBP + -0x24) = iVar4;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 8) == iVar4)) &&
     (*(undefined4 *)(unaff_EBP + -0x10) = 0, 0 < iVar4)) {
    do {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      iVar4 = *(char *)(unaff_EBP + -0x10) * 4;
      do {
        *(undefined1 *)(unaff_EBP + -0x12) = 1;
        *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + -0x10);
        *(char *)(unaff_EBP + -0x13) = *(char *)(unaff_EBP + -0x18);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar3 = (int)*(char *)(unaff_EBP + -0x18);
        cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x1c) + 0x3c) + 0xc) +
                                  iVar4) + iVar3);
        iVar2 = *(int *)(*(int *)(*(int *)(unaff_EBP + -0x20) + 0x34) + 0xc);
        if (cVar1 != *(char *)(*(int *)(iVar2 + iVar4) + iVar3)) {
          *(char *)(*(int *)(iVar4 + iVar2) + iVar3) = cVar1;
          FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
          FUN_00492be0(unaff_EBP + -0x14);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x24));
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x24));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

