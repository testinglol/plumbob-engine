
int * FUN_005e938a(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 0x18) == 2) {
    uVar2 = FUN_005d4956(s_Vertical_Scrollbar_006d77bc);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar3 = (int *)FUN_005e7743();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x34))(0,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    uVar2 = FUN_005d4956(s_Horizontal_Scrollbar_006d77a4);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    piVar3 = (int *)FUN_005e7743();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x38))(0,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_005b8770();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  (**(code **)(*piVar3 + 0x60))(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  piVar3[2] = (int)piVar3;
  (**(code **)(*piVar3 + 0x1ac))(uVar2);
  (**(code **)(*piVar3 + 0x1b0))(*(undefined4 *)(unaff_EBP + 0x10));
  (**(code **)(*piVar3 + 0x1a8))(*(undefined4 *)(unaff_EBP + 0x14));
  (**(code **)(*(int *)(extraout_ECX + -0xd4) + 0x20))(piVar3);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

