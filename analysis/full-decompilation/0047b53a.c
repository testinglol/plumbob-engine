
void FUN_0047b53a(void)

{
  char cVar1;
  int iVar2;
  int extraout_ECX;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  iVar4 = *(int *)(extraout_ECX + 0x10);
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) << 2;
  iVar4 = iVar4 + -1;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(int *)(unaff_EBP + -0x28) = iVar4;
  if (1 < iVar4) {
    do {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      if (1 < iVar4) {
        iVar5 = (int)*(char *)(unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x24) = iVar5;
        do {
          *(undefined1 *)(unaff_EBP + 10) = 0;
          *(char *)(unaff_EBP + 8) = *(char *)(unaff_EBP + -0x14);
          *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + -0x10);
          iVar2 = *(int *)(extraout_ECX + 0x20);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          iVar6 = *(char *)(unaff_EBP + -0x14) * 4;
          iVar3 = (int)*(char *)(*(int *)(*(int *)(iVar2 + 0xc) + iVar6) + iVar5);
          iVar2 = (int)*(char *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x1c) + 0xc) + iVar6) +
                                iVar5);
          *(int *)(unaff_EBP + -0x18) = iVar2;
          *(int *)(unaff_EBP + -0x20) = iVar3;
          if (iVar2 < iVar3) {
            cVar1 = FUN_0047b670(extraout_ECX,unaff_EBP + 8,4);
            if ((((cVar1 != '\0') ||
                 (cVar1 = FUN_0047b670(extraout_ECX,unaff_EBP + 8,5), cVar1 != '\0')) ||
                (cVar1 = FUN_0047b670(extraout_ECX,unaff_EBP + 8,6), cVar1 != '\0')) ||
               (cVar1 = FUN_0047b670(extraout_ECX,unaff_EBP + 8,7), cVar1 != '\0')) {
              iVar4 = *(int *)(unaff_EBP + -0x20);
              iVar2 = *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + -0x1c);
              if (iVar4 < iVar2) {
                *(int *)(unaff_EBP + -0x18) = iVar4;
                iVar2 = iVar4;
              }
              iVar5 = *(int *)(unaff_EBP + -0x24);
              *(char *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x1c) + 0xc) + iVar6) + iVar5) =
                   (char)iVar2;
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            iVar4 = *(int *)(unaff_EBP + -0x28);
          }
          else {
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          }
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(int *)(unaff_EBP + -0x14) < iVar4);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < iVar4);
  }
  FUN_0040766a(0x83,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

