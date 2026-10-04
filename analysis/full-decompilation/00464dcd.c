
undefined4 FUN_00464dcd(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00464515();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar2 + 4))(unaff_EBP + -0x60,*(undefined4 *)(unaff_EBP + 0xc));
  iVar2 = *(int *)(unaff_EBP + -0x58);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = iVar2;
  FUN_0046453f();
  iVar2 = FUN_0041ffd9(iVar2 + 0xc);
  *(int *)(unaff_EBP + 8) = iVar2;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar4 = (undefined1 *)FUN_00420048(iVar2);
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    *(undefined4 *)(puVar4 + 4) = uVar3;
    uVar3 = (**(code **)(*piVar1 + 8))();
    *(undefined4 *)(puVar4 + 8) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x10);
    *(undefined1 **)(unaff_EBP + -0x38) = puVar4 + 0xc;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    *(undefined2 *)(unaff_EBP + -0x28) = 0;
    *(undefined1 *)(unaff_EBP + -0x26) = 0;
    *(undefined1 *)(unaff_EBP + -0x25) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    (**(code **)(*piVar1 + 4))(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + 0xc));
    FUN_0042004f(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046453f();
    uVar3 = *(undefined4 *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

