
void FUN_00434f7b(void)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  if ((DAT_006f0138 != '\0') && (*(int *)(extraout_ECX + 0x184) != -1)) {
    cVar1 = *(char *)(extraout_ECX + 0xfd);
    *(char *)(unaff_EBP + -0xf) = cVar1;
    cVar2 = *(char *)(extraout_ECX + 0xfc);
    uVar3 = *(undefined1 *)(extraout_ECX + 0xfe);
    *(char *)(unaff_EBP + -0x10) = cVar2;
    *(undefined1 *)(unaff_EBP + -0xe) = uVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if ((-1 < cVar2) &&
       ((((int)cVar2 < *(int *)(DAT_006e54dc + 0x10) && (-1 < cVar1)) &&
        ((int)cVar1 < *(int *)(DAT_006e54dc + 0x10))))) {
      iVar4 = extraout_ECX;
      FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
      FUN_004a6a15(unaff_EBP + -0x10,iVar4);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

