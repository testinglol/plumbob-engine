
void FUN_0058038e(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int *piVar3;
  int unaff_EBP;
  undefined *puVar4;
  
  FUN_00634c24();
  if (DAT_006f63cf != '\0') {
    FUN_005d4956(s__none__006d0298);
    piVar3 = *(int **)(extraout_ECX + 0xc0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if ((piVar3 != (int *)0x0) || (piVar3 = *(int **)(extraout_ECX + 0xc4), piVar3 != (int *)0x0)) {
      uVar1 = (**(code **)(*piVar3 + 0x1c))();
      FUN_005d499c(uVar1);
    }
    puVar4 = &DAT_006c08dc;
    uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
    FUN_005bc69b(s_cSampleChannel__NoteOn__Sample_f_006d0270);
    FUN_005bc69b(uVar1);
    FUN_005bc69b(puVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  if (DAT_006e504c != '\0') {
    FUN_005d4956(s__none__006d0298);
    piVar3 = *(int **)(extraout_ECX + 0xc0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if ((piVar3 != (int *)0x0) || (piVar3 = *(int **)(extraout_ECX + 0xc4), piVar3 != (int *)0x0)) {
      uVar1 = (**(code **)(*piVar3 + 0x1c))();
      FUN_005d499c(uVar1);
    }
    FUN_004d402a(*(undefined4 *)(unaff_EBP + -0x28));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  uVar1 = (**(code **)(**(int **)(extraout_ECX + 0xc0) + 0x74))();
  (**(code **)(**(int **)(extraout_ECX + 0xc0) + 0x98))(0);
  iVar2 = **(int **)(extraout_ECX + 0xbc);
  *(undefined4 *)(unaff_EBP + -0x10) = **(undefined4 **)(extraout_ECX + 0xc0);
  iVar2 = (**(code **)(iVar2 + 0x88))(0x2c,1);
  (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x20))(uVar1,iVar2 != 0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

