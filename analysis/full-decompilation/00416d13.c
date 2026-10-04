
undefined4 FUN_00416d13(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int extraout_ECX;
  undefined4 *puVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  piVar2 = *(int **)(unaff_EBP + 8);
  iVar3 = (**(code **)(*piVar2 + 0x38))(0x4e414d45,0,FUN_00416e17);
  *(int *)(unaff_EBP + 8) = iVar3;
  if (iVar3 == 0) {
    *(int *)(unaff_EBP + -0x18) = extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x14) = 0x4e414d45;
    *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666784;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar3 = FUN_00464f5b(unaff_EBP + -0x1c,piVar2,1,0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00465055();
    *(int *)(unaff_EBP + -0x10) = iVar3;
    if (iVar3 != 0) goto LAB_00416dc9;
  }
  else {
    puVar4 = (undefined4 *)FUN_00420048(iVar3);
    iVar3 = FUN_00420096(*(undefined4 *)(unaff_EBP + 8));
    puVar5 = (undefined4 *)(iVar3 + (int)puVar4);
    for (; puVar4 < puVar5; puVar4 = (undefined4 *)((int)puVar4 + bVar1 + 5)) {
      bVar1 = *(byte *)(puVar4 + 1);
      FUN_00416ddd(*puVar4,puVar4 + 1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0041842c(unaff_EBP + -0x6c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
  }
  *(undefined1 *)(extraout_ECX + 0xc) = 0;
LAB_00416dc9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

