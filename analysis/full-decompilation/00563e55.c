
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00563e55(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int *piVar3;
  int *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 8);
  if (iVar4 == 3) {
    pvVar2 = operator_new(0x1ac);
    *(void **)(unaff_EBP + 8) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005f7201(extraout_ECX[0x50]);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (piVar3 != (int *)0x0) {
      FUN_004cb1a2(200,*(undefined4 *)(extraout_ECX[0x50] + 0x20));
      iVar4 = extraout_ECX[0x4d] + _DAT_006f5be0;
      *(int *)(unaff_EBP + -0x10) =
           *(int *)(extraout_ECX[0x50] + 0x20) / 2 + extraout_ECX[0x4e] + _DAT_006f5be4;
      *(int *)(unaff_EBP + -0x14) = iVar4;
      FUN_005f78d8(unaff_EBP + -0x14);
      (**(code **)(*piVar3 + 0x90))(0x2000,1);
      FUN_005d4956(*(undefined4 *)(unaff_EBP + 0xc));
      iVar4 = *piVar3;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      (**(code **)(iVar4 + 0x9c))(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      (**(code **)(*extraout_ECX + 0x20))(piVar3);
    }
  }
  else {
    pvVar2 = operator_new(0x194);
    *(void **)(unaff_EBP + 8) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005e372a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (piVar3 != (int *)0x0) {
      FUN_005a5631(*(undefined4 *)(&DAT_00670c2c + iVar4 * 4),unaff_EBP + 8,4);
      (**(code **)(*piVar3 + 0x19c))(*(undefined4 *)(unaff_EBP + 8),4,1);
      FUN_004cb21d(extraout_ECX[0x4d] + *(int *)(&DAT_006f5bc8 + iVar4 * 8),
                   *(int *)(&DAT_006f5bcc + iVar4 * 8) + extraout_ECX[0x4e]);
      uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined1 *)((int)piVar3 + 0x16b) = 1;
      FUN_005d4956(uVar1);
      *(undefined4 *)(unaff_EBP + -4) = 3;
      FUN_005dd9c8(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

