
void FUN_004681f5(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar5;
  
  FUN_00634c24();
  iVar4 = *(int *)(DAT_006e486c + 4);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(int *)(unaff_EBP + -0x18) = iVar4;
  if (iVar4 != 0) {
    iVar4 = extraout_ECX;
    for (pcVar5 = *(char **)(extraout_ECX + 4); pcVar5 != *(char **)(iVar4 + 8); pcVar5 = pcVar5 + 3
        ) {
      cVar1 = *pcVar5;
      cVar2 = pcVar5[1];
      cVar3 = pcVar5[2];
      *(char *)(unaff_EBP + -0x10) = cVar1;
      *(char *)(unaff_EBP + -0xf) = cVar2;
      *(char *)(unaff_EBP + -0xe) = cVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (*(char *)(unaff_EBP + 8) == '\0') {
LAB_00468282:
        FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
        (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x40))(unaff_EBP + -0x10);
      }
      else {
        iVar4 = cVar1 * 4;
        if ((*(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x20 + cVar3 * 4) + 0xc) + iVar4)
                       + cVar2 * 2) != 0) ||
           (*(char *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x40 + cVar3 * 4) + 0xc) + iVar4) +
                     cVar2 * 0xe) != '\0')) {
          iVar4 = *(int *)(unaff_EBP + -0x14);
          goto LAB_00468282;
        }
        iVar4 = *(int *)(unaff_EBP + -0x14);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

