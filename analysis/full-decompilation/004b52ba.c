
void FUN_004b52ba(void)

{
  char cVar1;
  undefined4 extraout_ECX;
  int iVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  cVar1 = **(char **)(unaff_EBP + 8);
  if (((('\0' < cVar1) && (iVar2 = *(int *)(DAT_006e54dc + 0x10) + -1, cVar1 < iVar2)) &&
      (cVar1 = (*(char **)(unaff_EBP + 8))[1], '\0' < cVar1)) && (cVar1 < iVar2)) {
    iVar2 = __ftol();
    *(int *)(unaff_EBP + -0x20) = iVar2;
    iVar3 = -iVar2;
    *(int *)(unaff_EBP + -0x14) = iVar3;
    *(int *)(unaff_EBP + -0x10) = iVar3;
    if (-iVar2 == iVar2 || iVar3 < iVar2) {
      do {
        for (iVar3 = *(int *)(unaff_EBP + -0x14); iVar3 <= iVar2; iVar3 = iVar3 + 1) {
          *(undefined1 *)(unaff_EBP + 10) = 0;
          *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + -0x10);
          *(char *)(unaff_EBP + 8) = (char)iVar3;
          FUN_0046185f(unaff_EBP + -0x18,unaff_EBP + 8);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          cVar1 = (char)*(undefined4 *)(unaff_EBP + -0x18);
          if ((('\0' < cVar1) && (iVar2 = *(int *)(DAT_006e54dc + 0x10) + -1, cVar1 < iVar2)) &&
             ((cVar1 = (char)((uint)*(undefined4 *)(unaff_EBP + -0x18) >> 8), '\0' < cVar1 &&
              (cVar1 < iVar2)))) {
            FUN_004b53b3(iVar3,*(undefined4 *)(unaff_EBP + -0x10));
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          iVar2 = *(int *)(unaff_EBP + -0x20);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) <= iVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

