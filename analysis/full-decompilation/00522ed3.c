
void FUN_00522ed3(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar4;
  int iVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  piVar2 = (int *)FUN_00425e2d();
  puVar4 = (undefined4 *)*piVar2;
  *(int **)(unaff_EBP + -0x14) = piVar2;
  if (puVar4 != (undefined4 *)piVar2[1]) {
    do {
      if (puVar4 != (undefined4 *)0x0) {
        FUN_0046f824(unaff_EBP + -0x22c,0,0x100);
        *(undefined ***)(unaff_EBP + -0x238) = &PTR_FUN_00666524;
        FUN_004102d4(unaff_EBP + -0x238);
        cVar1 = FUN_00522fd0(*puVar4);
        if (cVar1 != '\0') {
          FUN_0046f824(unaff_EBP + -0x120,0,0x100);
          *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_00666524;
          FUN_004102d4(unaff_EBP + -300);
          FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x128));
          *(undefined4 *)(unaff_EBP + -4) = 0;
          iVar5 = unaff_EBP + -0x20;
          uVar3 = FUN_005f51ce(iVar5);
          FUN_005f51e0(uVar3,iVar5);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        piVar2 = *(int **)(unaff_EBP + -0x14);
      }
      puVar4 = puVar4 + 1;
    } while (puVar4 != (undefined4 *)piVar2[1]);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

