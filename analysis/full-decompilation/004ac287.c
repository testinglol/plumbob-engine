
void FUN_004ac287(void)

{
  char cVar1;
  int *extraout_ECX;
  int iVar2;
  int iVar3;
  int unaff_EBP;
  int *piVar4;
  undefined8 uVar5;
  
  FUN_00634c24();
  iVar2 = *(int *)(DAT_006e54dc + 0x10);
  *(undefined1 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + -0xf) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  *(int *)(unaff_EBP + -0x1c) = iVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004a8000(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (0 < iVar2) {
    do {
      cVar1 = *(char *)(unaff_EBP + -0xf);
      iVar2 = *(int *)(unaff_EBP + -0x14);
      iVar3 = 0;
      do {
        uVar5 = __allshl();
        if (((uint)uVar5 & extraout_ECX[(cVar1 + iVar2) * 2 + 0x82]) != 0 ||
            ((uint)((ulonglong)uVar5 >> 0x20) & (extraout_ECX + (cVar1 + iVar2) * 2 + 0x82)[1]) != 0
           ) {
          *(char *)(unaff_EBP + -0x16) = (char)extraout_ECX[6];
          *(undefined1 *)(unaff_EBP + -4) = 1;
          *(char *)(unaff_EBP + -0x18) = (char)iVar3 + *(char *)(unaff_EBP + -0x10);
          *(char *)(unaff_EBP + -0x17) = *(char *)(unaff_EBP + -0x14) + *(char *)(unaff_EBP + -0xf);
          (**(code **)(*extraout_ECX + 0x40))(unaff_EBP + -0x18);
          *(undefined1 *)(unaff_EBP + -4) = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(unaff_EBP + -0x1c));
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x1c));
  }
  piVar4 = extraout_ECX + 0x82;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x7e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x4e) = 1;
  return;
}

