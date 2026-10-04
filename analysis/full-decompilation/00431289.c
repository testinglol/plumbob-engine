
int FUN_00431289(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  iVar4 = *(int *)(extraout_ECX + 0x1c) * *(int *)(extraout_ECX + 8) * *(int *)(extraout_ECX + 4) +
          0x40;
  iVar2 = FUN_0041ffd9(iVar4);
  if (iVar2 == 0) {
    iVar4 = -200;
  }
  else {
    uVar3 = FUN_00420048(iVar2);
    FUN_004644dc(uVar3,iVar4,1,0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0043143a(unaff_EBP + -0x34,*(undefined4 *)(unaff_EBP + 0x14));
    FUN_0042004f(iVar2);
    FUN_004200aa(iVar2,*(undefined4 *)(unaff_EBP + -0x2c));
    FUN_0046f824(unaff_EBP + -0x74,0,0x40);
    uVar3 = *(undefined4 *)(extraout_ECX + 0x10);
    *(undefined ***)(unaff_EBP + -0x80) = &PTR_FUN_0066651c;
    FUN_0046f8cb(uVar3);
    piVar1 = *(int **)(unaff_EBP + 8);
    (**(code **)(*piVar1 + 0x74))
              (iVar2,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
               unaff_EBP + -0x80,1);
    iVar4 = FUN_00401f6f();
    if (iVar4 == 0) {
      (**(code **)(*piVar1 + 0x7c))(iVar2);
      iVar4 = FUN_00401f6f();
      FUN_00465a06(iVar2);
    }
    else {
      FUN_00420028(iVar2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046453f();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

