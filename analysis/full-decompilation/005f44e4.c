
undefined4 FUN_005f44e4(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x114) + 0x48))();
  if (cVar1 == '\0') {
    uVar2 = FUN_005db0bf();
    FUN_005b86bd(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if ((*(int *)(extraout_ECX + 0x130) == 1) &&
       (iVar3 = 0,
       *(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + -0x18) &&
       -1 < *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18))) {
      do {
        if (*(byte *)(iVar3 + *(int *)(unaff_EBP + -0x18)) < 0x20) {
          FUN_00406466(iVar3,1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18));
    }
    cVar1 = FUN_005f3061(*(undefined4 *)(unaff_EBP + -0x18));
    if (cVar1 == '\0') {
      FUN_0057a14d(*(undefined4 *)(extraout_ECX + 0x19c));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

