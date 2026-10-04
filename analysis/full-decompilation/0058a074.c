
void FUN_0058a074(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  piVar2 = *(int **)(*(int *)(unaff_EBP + 8) * 4 + *(int *)(extraout_ECX + 0x268));
  if (*piVar2 == 0) {
    cVar4 = '\x01';
  }
  else {
    cVar4 = FUN_0058a133(piVar2,*(undefined4 *)(unaff_EBP + 0xc),puVar1);
  }
  if (cVar4 != '\0') {
    *(undefined4 *)(unaff_EBP + 8) = puVar1[1];
    uVar5 = (**(code **)*puVar1)();
    uVar5 = FUN_005b86cf(*(undefined4 *)(unaff_EBP + 8),uVar5);
    *(undefined4 *)(unaff_EBP + 8) = uVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar5 = (*(undefined4 **)(unaff_EBP + 0xc))[1];
    uVar6 = (**(code **)**(undefined4 **)(unaff_EBP + 0xc))();
    uVar5 = FUN_005b86cf(uVar5,uVar6);
    iVar3 = *(int *)(extraout_ECX + 8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0058372c(DAT_006f6b64,*(undefined4 *)(iVar3 + 4),uVar5,*(undefined4 *)(unaff_EBP + 8));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

