
int * FUN_005e9462(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  pvVar3 = operator_new(0x110);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  piVar6 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_005e9913();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  iVar2 = *piVar6;
  uVar5 = puVar1[3];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  (**(code **)(iVar2 + 0x60))(*puVar1,puVar1[1],puVar1[2],uVar5);
  (**(code **)(*piVar6 + 0x9c))(unaff_EBP + -0x20);
  piVar4 = piVar6 + 0x35;
  (**(code **)(piVar6[0x35] + 0x18))(*(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  (**(code **)(*piVar4 + 0x1c))(*(undefined4 *)(unaff_EBP + 0x10));
  (**(code **)(*piVar4 + 0xc))(1,1);
  (**(code **)(*piVar6 + 0x90))(0x10,0);
  (**(code **)(*piVar4 + 0x14))(*(char *)(unaff_EBP + 0x14) == '\0');
  piVar4 = (int *)FUN_005e7743();
  uVar5 = (**(code **)(*piVar4 + 0x44))(1);
  FUN_005e9fa4(uVar5);
  iVar2 = *(int *)(unaff_EBP + -0x10);
  piVar6[2] = (int)piVar6;
  piVar4 = (int *)(iVar2 + -0xd4);
  (**(code **)(*piVar4 + 0x20))(piVar6);
  (**(code **)(*piVar4 + 0x50))(piVar6);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar6;
}

