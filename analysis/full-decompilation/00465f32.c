
undefined2 FUN_00465f32(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  undefined4 uVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005c22bb();
  FUN_005c1033();
  uVar5 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_005c171f(*(undefined4 *)(unaff_EBP + 8));
  uVar1 = *(undefined4 *)(extraout_ECX + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar4 = FUN_005c1940(unaff_EBP + -0x28,uVar1,uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042004f();
  if (iVar4 != 0) {
    if (iVar4 == 5) {
      uVar5 = 0xffffff9e;
    }
    else if (iVar4 == 6) {
      uVar5 = 0xffffff38;
    }
    else {
      uVar5 = 0xffffffff;
    }
  }
  FUN_004659fc(uVar5);
  uVar2 = FUN_005c11a7();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c1070();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

