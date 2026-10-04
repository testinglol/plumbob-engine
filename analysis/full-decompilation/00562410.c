
undefined1 FUN_00562410(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int extraout_ECX;
  undefined1 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  uVar4 = 1;
  uVar3 = 1;
  if (*(int *)(extraout_ECX + 0xd4) == 1) {
    FUN_00429c21();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar2 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0x160),unaff_EBP + -0x28);
    if (cVar2 != '\0') {
      if (*(int *)(unaff_EBP + -0x1c) < *(int *)(iVar1 + 0x1b0)) {
        uVar4 = 0;
      }
      else if ((*(int *)(iVar1 + 0x1a4) == 0) || (*(int *)(iVar1 + 0x1b8) != -1)) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        goto LAB_005624cc;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar3 = uVar4;
  }
  else {
    if (*(int *)(extraout_ECX + 0xd4) == 2) {
      if (((*(int *)(iVar1 + 0x1b8) != -1) || (*(int *)(iVar1 + 0x1ac) != 0)) &&
         (*(int *)(iVar1 + 0x1a8) == 0)) goto LAB_0056246e;
    }
    else if (*(int *)(iVar1 + 0x1b8) != -1) goto LAB_0056246e;
LAB_005624cc:
    uVar3 = 0;
  }
LAB_0056246e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

