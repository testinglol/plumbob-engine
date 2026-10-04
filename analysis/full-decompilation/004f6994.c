
undefined4 FUN_004f6994(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = FUN_005d4956(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
  iVar1 = *(int *)(extraout_ECX + 0x48);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = (**(code **)(iVar1 + 0x2c))
                    (uVar3,uVar2,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14)
                    );
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

