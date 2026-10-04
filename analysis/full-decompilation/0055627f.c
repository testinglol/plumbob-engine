
undefined1 FUN_0055627f(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  int extraout_ECX;
  undefined1 uVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  uVar5 = 1;
  uVar4 = 1;
  iVar2 = *(int *)(extraout_ECX + 0xd4);
  if (iVar2 == 1) {
    FUN_00429c21();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar3 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0xe4),unaff_EBP + -0x28);
    if (cVar3 != '\0') {
      if (*(int *)(unaff_EBP + -0x1c) < *(int *)(iVar1 + 0x1b0)) {
        uVar5 = 0;
      }
      else if ((*(int *)(iVar1 + 0x1a4) == 0) || (*(int *)(iVar1 + 0x1b8) != -1)) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        goto LAB_0055634e;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar4 = uVar5;
  }
  else {
    if ((iVar2 == 2) || (iVar2 == 3)) {
      if (((*(int *)(iVar1 + 0x1b8) != -1) || (*(int *)(iVar1 + 0x1ac) != 0)) &&
         (*(int *)(iVar1 + 0x1a8) == 0)) goto LAB_005562dd;
    }
    else if (((iVar2 == 4) || (0x5c < *(int *)(iVar1 + 0x1d8))) || (*(int *)(iVar1 + 0x1b8) != -1))
    goto LAB_005562dd;
LAB_0055634e:
    uVar4 = 0;
  }
LAB_005562dd:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

