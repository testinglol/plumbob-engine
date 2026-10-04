
int FUN_005cfafc(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = uVar2;
  puVar1 = (undefined4 *)FUN_005caed9();
  iVar4 = *(int *)(unaff_EBP + 0x10);
  *(undefined4 *)(extraout_ECX + 0x14) = *puVar1;
  *(undefined4 *)(extraout_ECX + 0x18) = puVar1[1];
  *(undefined4 *)(extraout_ECX + 0x14) = *(undefined4 *)(unaff_EBP + 0x18);
  *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)(unaff_EBP + 0x1c);
  if (iVar4 == 0) {
    uVar2 = FUN_005cacf9();
    *(undefined4 *)(unaff_EBP + 0x10) = uVar2;
  }
  piVar3 = (int *)FUN_005cad0d();
  iVar4 = (**(code **)(*piVar3 + 0x20))
                    (piVar3,*(int *)(extraout_ECX + 8) + 0xc60,*(undefined4 *)(unaff_EBP + 0x10),
                     (undefined4 *)(extraout_ECX + 0x38),0);
  *(int *)(extraout_ECX + 4) = iVar4;
  if (iVar4 == 0) {
    puVar1 = *(undefined4 **)(extraout_ECX + 0x38);
    uVar2 = (**(code **)*puVar1)(puVar1,&DAT_00677298,extraout_ECX + 0x34);
    *(undefined4 *)(extraout_ECX + 4) = uVar2;
    pvVar5 = operator_new(0x10);
    *(void **)(unaff_EBP + 0x10) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005d4035();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0xc) = piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = extraout_ECX;
      pvVar5 = operator_new(0x20);
      *(void **)(unaff_EBP + 0x10) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar5 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005d276d();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(extraout_ECX + 0x10) = iVar4;
      if (iVar4 != 0) {
        FUN_00476033(extraout_ECX);
        iVar4 = FUN_005d285c();
        *(int *)(extraout_ECX + 4) = iVar4;
        if (iVar4 == 0) {
          FUN_005cafe5(extraout_ECX);
          iVar4 = 0;
        }
        goto LAB_005cfc03;
      }
    }
    iVar4 = -0x64f4ffff;
    *(undefined4 *)(extraout_ECX + 4) = 0x9b0b0001;
  }
LAB_005cfc03:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

