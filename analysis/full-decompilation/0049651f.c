
undefined4 FUN_0049651f(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
  FUN_00494e93(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 8),uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00494e93(unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + 0xc),uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  while ((((char)*(undefined4 *)(unaff_EBP + -0x10) != *(char *)(unaff_EBP + 8) ||
          ((char)((uint)*(undefined4 *)(unaff_EBP + -0x10) >> 8) != *(char *)(unaff_EBP + 9))) ||
         (*(char *)(unaff_EBP + -0xe) != *(char *)(unaff_EBP + 10)))) {
    cVar1 = FUN_004951a5(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0x14),uVar3);
    if (cVar1 == '\0') {
      uVar3 = 0;
LAB_004965d8:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar3;
    }
    FUN_004960a5(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0x14),uVar3);
    puVar2 = (undefined1 *)FUN_00494f77(unaff_EBP + 0x10,unaff_EBP + 8,uVar3);
    *(undefined1 *)(unaff_EBP + 8) = *puVar2;
    *(undefined1 *)(unaff_EBP + 9) = puVar2[1];
    *(undefined1 *)(unaff_EBP + 10) = puVar2[2];
  }
  puVar4 = (undefined1 *)FUN_00494f05(unaff_EBP + 0x14,unaff_EBP + 8,uVar3);
  puVar2 = *(undefined1 **)(unaff_EBP + 0x18);
  *puVar2 = *puVar4;
  puVar2[1] = puVar4[1];
  puVar2[2] = puVar4[2];
  uVar3 = 1;
  goto LAB_004965d8;
}

