
void FUN_005746a7(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00580cd2(unaff_EBP + -0xe,unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00575b70(100,unaff_EBP + -0x11,unaff_EBP + -0x10,unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00580a92(unaff_EBP + -0x1c);
  while (iVar1 = *(int *)(unaff_EBP + -0x1c), iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 4);
    if (*(int *)(iVar1 + 8) < 1) {
      *(int *)(unaff_EBP + -0x20) = *(int *)(iVar1 + 8);
      *(undefined4 *)(unaff_EBP + -0x24) = uVar2;
      FUN_00576538(*(int *)(unaff_EBP + -0x3c) + 1);
      FUN_00576349(unaff_EBP + -0x2c,unaff_EBP + -0x24);
    }
    else {
      piVar3 = (int *)FUN_00573466(uVar2);
      (**(code **)(*piVar3 + 0x34))();
    }
    FUN_00576e56();
  }
  FUN_005824b6();
  FUN_00580a92(unaff_EBP + -0x24);
  iVar1 = *(int *)(unaff_EBP + -0x24);
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
  while (iVar1 != 0) {
    FUN_00576538(*(int *)(extraout_ECX + 0xe4) + 1);
    FUN_00576349(unaff_EBP + -0x2c,iVar1 + 4);
    FUN_00576e56();
    iVar1 = *(int *)(unaff_EBP + -0x1c);
  }
  FUN_005745d3();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005824b6();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005481b6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00575ab3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

