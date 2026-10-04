
undefined4 FUN_004852d6(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar3 = *(char *)(unaff_EBP + 8);
  cVar1 = *(char *)(unaff_EBP + 0xc);
  *(char *)(unaff_EBP + 8) = cVar3;
  *(char *)(unaff_EBP + 9) = cVar1;
  *(undefined1 *)(unaff_EBP + 10) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar3) &&
       ((int)cVar3 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
      (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)cVar1)) &&
     ((int)cVar1 <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
    cVar3 = FUN_0049177e(unaff_EBP + 8);
    if (cVar3 != '\0') {
      uVar2 = *(undefined1 *)(unaff_EBP + 8);
      *(undefined4 *)(extraout_ECX + 0x38) = 1;
      *(undefined1 *)(extraout_ECX + 0x34) = uVar2;
      *(undefined1 *)(extraout_ECX + 0x35) = *(undefined1 *)(unaff_EBP + 9);
      *(undefined1 *)(extraout_ECX + 0x36) = *(undefined1 *)(unaff_EBP + 10);
      uVar4 = 0;
      goto LAB_00485351;
    }
  }
  uVar4 = 1;
LAB_00485351:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

